## EVR Exchange Contract (evrexchanges)

Let EVD can change to EVR and change back 1:1.

Code:
[https://github.com/EOSVR/sidechain/tree/master/contracts/exchange](https://github.com/EOSVR/sidechain/tree/master/contracts/exchange)

#### Example

```
cleos push action eosvrtokenss transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"100.0000 EVR","memo":""}' -p guest1111111

cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"100.0000 EVD","memo":""}' -p guest1111111
```



