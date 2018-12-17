## EVR 交换合约 (evrexchanges)

使得另一种代币（EVD）可以与 EVR 1:1 交换。

合约代码在目录 exchange 下。

#### 使用示例

```
cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"100.0000 EVR","memo":""}' -p guest1111111

cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"100.0000 EVD","memo":""}' -p guest1111111
```



