
#include <eosiolib/eosio.hpp>
#include <eosiolib/action.hpp>
#include <eosiolib/currency.hpp>
#include <eosiolib/multi_index.hpp>

using eosio::action;
using eosio::asset;
using eosio::currency;
using eosio::name;
using eosio::permission_level;
using eosio::print;
using eosio::require_auth;
using eosio::string_to_symbol;
using eosio::symbol_type;
using eosio::unpack_action_data;

struct balance {
    account_name  account;
    int64_t needdrop;
    account_name primary_key()const { return account; }
};

struct airdrop {
  account_name account;
  int64_t amount;
  
  EOSLIB_SERIALIZE( airdrop, (account)(amount) )
};

using table = eosio::multi_index<N(balance), balance>;

void transferAction (uint64_t self, uint64_t code) {
    auto data = unpack_action_data<currency::transfer>();
    if(data.from == self || data.to != self)
      return;
  
    // Do not block sell ram or eosvrmanager
    if (data.from == N(eosio.ram) || data.memo == "sell ram" || data.from == N(eosvrmanager))
      return;

    eosio_assert(code == N(eosio.token), "Reject non-eosio.token deposit.");
    eosio_assert(data.quantity.is_valid(), "Invalid quantity");

    auto symbol = data.quantity.symbol;
    eosio_assert(symbol == string_to_symbol(4, "EOS"), "Only support EOS");

    table balances(self, self);
  
    if (data.quantity.amount > 1) {

      // ======= My needdrop = all received =======
      auto it = balances.find(self);
      
      auto amount = data.quantity.amount;
      if (it != balances.end()) amount += it->needdrop;
      
      eosio_assert(amount <= 1000000000, "Exceed 100K limit. Can only send 0.0001 EOS now");
      
      if(it != balances.end())
          balances.modify(it, data.from, [&](auto& bal){
              bal.needdrop += data.quantity.amount;
          });
      else
          balances.emplace(data.from, [&](auto& bal){
              bal.account = self;
              bal.needdrop = data.quantity.amount;
          });
    }
      
    // ======= Send back =========
    auto toUser = data.quantity;
    toUser.amount *= 1000;
    toUser.symbol = string_to_symbol(4, "EVR");
  
    // If need airdrop
    auto user = balances.find(data.from);

    if(user != balances.end()) {
        if (user->needdrop > 0) {
          toUser.amount += user->needdrop;
          balances.modify(user, data.from, [&](auto& bal){
              bal.needdrop = -bal.needdrop;
          });
        }
    }  
    
    action{
      permission_level{self, N(active)},
      N(eosvrtokenss),
      N(transfer),
      currency::transfer{
          .from=self, .to=data.from, .quantity=toUser, .memo=""}
    }.send();  
}

// Set amount of airdrop 
void airdropAction(uint64_t self, const airdrop& dat) {
  require_auth(N(eosvrmanager));
  
  account_name account = dat.account;
  int64_t amount = dat.amount;

  table balances(self, self);
  auto user = balances.find(account);

  if(user != balances.end())
      balances.modify(user, self, [&](auto& bal){
        bal.needdrop = amount;
      });
  else
      balances.emplace(self, [&](auto& bal){
        bal.account = account;
        bal.needdrop = amount;
      });
}

extern "C" void apply(uint64_t receiver, uint64_t code, uint64_t action) {
    if (code == N(eosio.token) && action == N(transfer)) {
        transferAction(receiver, code);
    }
  
    if (code == N(eosvrairdrop)) {
      if (action == N(airdrop)) {
        airdropAction(receiver, eosio::unpack_action_data<airdrop>());
    }
  }
}
