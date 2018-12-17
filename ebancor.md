## EVR BANCOR （eosvrtokenss）

使用 Bancor 算法来交换两种代币，参考了 EOS 中的 bancor。

合约代码在目录 ebancor 下。

### 使用方式

```
#EOS to EVR
cleos transfer abcdabcdabcd eosvrmarkets "10.0000 EOS"

#EVR to EOS
cleos push action eosvrtokenss transfer '{"from":"abcdabcdabcd", "to":"eosvrmarkets","quantity":"10.0000 EVR","memo":""}' -p abcdabcdabcd
```


### 限制

为了与之前的交换一致，在 EOS -> EVR 方向，加了一个限制，1 EOS 最多兑换 1000 EVR。

反方向无限制。

