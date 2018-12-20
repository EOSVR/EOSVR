
#include <eosiolib/eosio.hpp>
#include <eosiolib/action.hpp>
#include <eosiolib/multi_index.hpp>
#include "eosio.token.hpp"
#include <string>

using namespace eosio;

using std::string;

//#include <eosiolib/currency.hpp>
// Add Old currency:transfer support
class currency {
  public:
     struct transfer
     {
        account_name from;
        account_name to;
        asset        quantity;
        string       memo;

        EOSLIB_SERIALIZE( transfer, (from)(to)(quantity)(memo) )
     };
};



