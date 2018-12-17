## EVD 奖励合约（eosvrrewards）

此合约用来：

- 给 [comments 合约](comment.md) 设置奖励；

- 给 comments 的前几名发送奖励；


### 设置奖励

直接将 EVD 发送给奖励合约（eosvrrewards），可以设置奖励。memo 中可以设置奖励的具体参数：

参数依次为：
  一次可发放的最多代币数量，评价合约，奖励间隔（秒），每次得到奖励的最大人数，奖励种类，每一千支持能得到的最多奖励

它们的默认值为：
  30 EVD, eosvrcomment, 86400*7(7 days), 10(10个用户), 0(平均分配、可回撤), 10 (1%支持)

示例：

```
# guest1111111 将用 10万 EVD 来奖励在 eosvrrewards 合约中最受支持的 10个人，每天奖励一次，每次共有1万 EVD发放，平分给10个人（type：0）
# 所以，每人每次最多得到 1000 EVD。
# 同时，guest1111111 在之后随时可以终止这个奖励活动(type=0时, 可回撤).
cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"eosvrrewards","quantity":"100000.0000 EVD","memo":"10000,eosvrcomment,84600,10,0"}' -p guest1111111
```


### 奖励类型

奖励的发起者如果在奖励运行了一段时间后觉得不满意，可以选择撤回还没有发出的奖励。但只有偶数的类型可回撤，奇数的不可回撤。

比如：0可以撤回，1不行。

下面是奖励的各种类型：

- 2-3, 第一名 50%, 第二名 25% , 其余平均；

- 其他, 平均分配。但当 type > 20 时，最大收益 = (支付 - 反对 * (type / 2 - 10)) * 支持转化率(默认1%)

比如：EVD的主reward（evradvancers），就会使用 type = 41, 表示：不可撤回并且反对者的投票可以10倍有效于支持者。

```
# 实验，0.1G ，500K每周
cleos push action eoslocktoken transfer '{"from":"eosvrairdrop", "to":"eosvrrewards","quantity":"100000000.0000 EVD","memo":"500000,eosvrcomment,592200,20,41,10"}' -p eosvrairdrop

# 全部，7.9G , 80M每周
cleos push action eoslocktoken transfer '{"from":"eosvrairdrop", "to":"eosvrrewards","quantity":"7900000000.0000 EVD","memo":"80000000,evradvancers,592200,20,31,3"}' -p eosvrairdrop
```



