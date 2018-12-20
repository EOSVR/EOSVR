#include "exchange.hpp"

const uint64_t MANAGER_ACCOUNT = N(eosvrmanager);

const uint64_t ISSUER_ACCOUNT1 = N(eosvrtokenss);
const uint64_t ISSUER_ACCOUNT2 = N(eoslocktoken);
const auto TOKEN_SYMBOL1 = string_to_symbol(4, "EVR");
const auto TOKEN_SYMBOL2 = string_to_symbol(4, "EVD");
const uint64_t rate_1to2 = 1;
const uint64_t rate_2to1 = 1;

struct impl {


void transferAction (uint64_t _self, uint64_t code) {
  auto data = unpack_action_data<currency::transfer>();

  // When setup, use manager account to put EVD into it.
  if(data.from == _self || data.to != _self || data.from == MANAGER_ACCOUNT)
    return;

  account_name from = data.from;
  account_name to = data.to;

  require_auth(from);

  eosio_assert(data.quantity.is_valid(), "Invalid quantity");
  eosio_assert(data.memo.length() == 0, "memo must be empty in exchange");

  if (code == ISSUER_ACCOUNT1) {
    eosio_assert(data.quantity.symbol == TOKEN_SYMBOL1, "Invalid symbol1");

    auto back = asset(data.quantity.amount * rate_1to2, TOKEN_SYMBOL2);
    action{
        permission_level{_self, N(active)},
        ISSUER_ACCOUNT2,
        N(transfer),
        currency::transfer{
            .from=_self, .to=from, .quantity=back, .memo="Exchange 1 to 2"}
    }.send();
  } else {
    eosio_assert(data.quantity.symbol == TOKEN_SYMBOL2, "Invalid symbol2");

    auto back = asset(data.quantity.amount * rate_2to1, TOKEN_SYMBOL1);
    action{
        permission_level{_self, N(active)},
        ISSUER_ACCOUNT1,
        N(transfer),
        currency::transfer{
            .from=_self, .to=from, .quantity=back, .memo="Exchange 2 to 1"}
    }.send();
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
