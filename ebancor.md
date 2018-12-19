## EVR BANCOR （eosvrtokenss）

Use Bancor algorithm to exchange two tokens. Reference the bancor code in EOS contract.

Code is in folder ebancor.

### Usage

```
#EOS to EVR
cleos transfer abcdabcdabcd eosvrmarkets "10.0000 EOS"

#EVR to EOS
cleos push action eosvrtokenss transfer '{"from":"abcdabcdabcd", "to":"eosvrmarkets","quantity":"10.0000 EVR","memo":""}' -p abcdabcdabcd
```


### Limit

To make it consistency, in the change of EOS to EVR have a limitation. One EOS can get at most 1000 EVR.

No other limitation.

