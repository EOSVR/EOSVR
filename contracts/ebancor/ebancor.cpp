#include "ebancor.hpp"

const uint64_t ISSUER1 = N(eosvrtokenss);
const uint64_t SYMBOL1 = string_to_symbol(4, "EVR");

const uint64_t ISSUER2 = N(eosio.token);
const uint64_t SYMBOL2 = string_to_symbol(4, "EOS");

// Manager account can send EOS or EVR to contract account without back token.
// It can extend the pool of ebancor.
const uint64_t MANAGER_ACCOUNT = N(eosvrmanager);

const uint64_t MAX_1To2 = 0;
const uint64_t MAX_2To1 = 1000;

struct impl {

int64_t getBalance(uint64_t issuer, uint64_t symbol, uint64_t _self) {
    eosio::token t(issuer);
    const auto sym_name = eosio::symbol_type(symbol).name();
    return t.get_balance(_self, sym_name ).amount;  
}
    
int64_t getBancorToken(int64_t deposit2, uint64_t _self, 
                       uint64_t issuer1, uint64_t symbol1,
                       uint64_t issuer2, uint64_t symbol2,
                       uint64_t max) {
  const auto balance1 = getBalance(issuer1, symbol1, _self);
  const auto balance2 = getBalance(issuer2, symbol2, _self);

  if (balance1 <= 0 || balance2 <= 0) return -1;

  if (deposit2 * 3 > balance2) return -1; // Out of Range. (Input must be within 1/3 total)

  auto init_out = balance1 * 1.0 / balance2 * deposit2;
    
  auto final_price = (balance1 - init_out) * 1.0 / (balance2 + deposit2);
  
  if (max > 0 && final_price > max) final_price = max;
  
  int64_t final_out = final_price * deposit2;
  return final_out;  
}
  
int64_t getToken_1To2(int64_t deposit1, uint64_t _self) {
  return getBancorToken(deposit1, _self, ISSUER2, SYMBOL2, ISSUER1, SYMBOL1, MAX_1To2);
}    

int64_t getToken_2To1(int64_t deposit2, uint64_t _self) {
  return getBancorToken(deposit2, _self, ISSUER1, SYMBOL1, ISSUER2, SYMBOL2, MAX_2To1);
}
  
void transferAction (uint64_t _self, uint64_t code) {
    auto data = unpack_action_data<currency::transfer>();
    if(data.from == _self || data.to != _self)
      return;

    eosio_assert(data.quantity.is_valid(), "Invalid quantity");
  
    // Manager account will transfer without token back.
    if (data.from == MANAGER_ACCOUNT)
      return;
  
    auto symbol = data.quantity.symbol;
  
    account_name from = data.from;
    account_name to = data.to;

    require_auth(from);      
  
    if (code == ISSUER1) {
        // 1 To 2
        eosio_assert(symbol == SYMBOL1, "Invalid symbol1");

        auto backToken = getToken_1To2(data.quantity.amount, _self);
        eosio_assert(backToken > 0, "Must greater than 0");

        auto back = asset( backToken, SYMBOL2 );

        action{
            permission_level{_self, N(active)},
            ISSUER2,
            N(transfer),
            currency::transfer{
              .from=_self, .to=data.from, .quantity=back, .memo="Exchange"}
        }.send();
    } else if (code == ISSUER2) {
        // 2 To 1
        eosio_assert(symbol == SYMBOL2, "Invalid symbol2");

        auto backToken = getToken_2To1(data.quantity.amount, _self);
        eosio_assert(backToken > 0, "Must greater than 0");

        auto back = asset( backToken, SYMBOL1 );

        action{
            permission_level{_self, N(active)},
            ISSUER1,
            N(transfer),
            currency::transfer{
              .from=_self, .to=data.from, .quantity=back, .memo="Exchange"}
        }.send();
    } else {
      eosio_assert(false, "Do not transfer other token");
    }
}


void apply( uint64_t receiver, uint64_t code, uint64_t action ) {
    if (action == N(transfer)) {
        transferAction(receiver, code);
    }
}


};



extern "C" {
  void apply(uint64_t receiver, uint64_t code, uint64_t action) {
    impl().apply(receiver, code, action);
  }
}
