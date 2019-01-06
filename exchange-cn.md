## EVR 交换合约 (evrexchanges)

使得另一种代币（EVD）可以与 EVR 1:1 交换。

代码:
[https://github.com/EOSVR/sidechain/tree/master/contracts/exchange](https://github.com/EOSVR/sidechain/tree/master/contracts/exchange)


#### 使用示例

```
cleos push action eosvrtokenss transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"100.0000 EVR","memo":""}' -p guest1111111

cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"100.0000 EVD","memo":""}' -p guest1111111
```



