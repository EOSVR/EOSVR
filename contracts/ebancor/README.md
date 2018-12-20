## EOSVR BANCOR

Use bancor algorithm to exchange EVR <-> EOS. Referenced from EOS bancor.

### Usage

```
  #EOS to EVR
  cleos transfer account1 eosvrmarkets "10.0000 EOS"

  #EVR to EOS
  cleos push action eosvrtokenss transfer '{"from":"account1", "to":"eosvrmarkets","quantity":"10.0000 EVR","memo":""}' -p account1
```


### LIMITATION

Add limitation of EOS -> EVR: 1 EOS at most can get 1000 EVR.

Do not have limitation in EVR -> EOS.

