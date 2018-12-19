## 讨论合约 （eosvrcomment）

用户可以互相评论，也可以给自己写说明，或者用来给自己存储数据。每一对评价都可以使用 EVD 进行支持或反对。

合约代码在目录 comments 下。

#### 使用方式

##### comment 

一个用户用一段话评价另一个用户或自己；

```
# guest1111111 评价 guest1111112
cleos push action eosvrcomment comment '{"from":"guest1111111", "to":"guest1111112", "memo":"hello, good."}' -p guest1111111
```


##### transfer 

给某个评价以 EVD 支持或者反对；

```
# guest1111111 在 eosvrcomment 这个评价合约下，对 guest1111112 使用 2 EVD 进行支持评价
cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"eosvrcomment", "quantity": "2.0000 EVD", "memo":"+guest1111112"}' -p guest1111111

```


##### withdraw 

收回给某个评价的 EVD 支持或者反对；

```
# guest1111111 在 eosvrcomment 这个评价合约下，收回对 guest1111112 评价花费的所有 EVD
cleos push action eosvrcomment withdraw '{"from":"guest1111111", "to":"guest1111112"}' -p guest1111111

```
