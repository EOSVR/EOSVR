## 信用方案实现 - EVD

[English](README.md)

#### 简介

EVD是一种部署在EOS链上的[信用解决方案](intro-cn.md)。

它可以证明一个账户拥有者的有限可信：

- 互相锁定：一个账户可以锁定另一个账户的信用点；

- 限制转出：用户可以设置账户每个月允许转出的百分比；

- [跨链传输](sidelink-cn.md)：允许多个EOS链间进行交易。比如一个EOS主链上的账户A，可以把EVD传输给另一个EOS链上的账户B。

这使得部署一个大范围、低成本的信用网络成为可行。

更多合约信息: [合约EVD](evd-cn.md)：


#### 支持APP

[APP EOSVR](app-cn.md) 实现了上述合约的功能，它是一个可用于 Windows, MacOS, iPhone/iPad, Android 多平台的APP，用户可用它来进行传输，锁定（复仇），或者信用证明。

这个APP还在开发中，APP的源码将开源。之后，对这个APP代码做贡献也将能获取 EVD。


#### 获取方式

1，EVD 与之前发布的 EVR 1:1 兑换，向帐号 evrexchanges 发送 EVR 或者 EVD，它就会返回相应的另一种。

```
# 1000 EVR 换 1000 EVD
cleos push action eosvrtokenss transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"1000.0000 EVR","memo":""}' -p guest1111111
# 1000 EVD 换 1000 EVR
#cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"1000.0000 EVD","memo":""}' -p guest1111111
```

EVR 加载的是最基础的 eosio.token 合约，没有转账限制，也没要互锁等功能。EVD 才有这些功能。用户可以在它们之间进行1:1转换。

2，通过 [eosvrmarkets](ebancor.md) 或者其他类似去中心化交易合约，可以将 EOS 换成 EVR，同样 EVR 也可以用同样的方法换成 EOS，[eosvrmarkets](ebancor.md) 还在测试中，只放置了一小部分的代币。可以用下面命令来试试：

```
# 将 1 EOS to 转成一些 EVR
cleos push action eosio.token transfer '{"from":"guest1111111", "to":"eosvrmarkets","quantity":"1.0000 EOS","memo":""}' -p guest1111111
```

3，贡献获取方式

这种获取方式类似于挖矿，但不是通过计算算力，而是计算对 EVD 项目的贡献量。方式为通过对 EVR 系统做各种贡献（比如：推广，提供支持，写新功能，找错误，修改错误，提供解决方案等），然后将贡献证明写在讨论合约 （eosvrcomment，evradvancers，appadvancers 等）中。已有 EVD 的用户可以对这些贡献进行评价，最后根据排名给予奖励。

详见合约 [eosvrrewards](reward-cn.md)。

更多关于 [EVR/EVD分配方案](evd_distribute-cn.md)。


#### 相关合约

- [eoslocktoken](evd-cn.md): EVD 合约，实现了互锁、限制转账、延时转账等功能；
```
# guest1111111 互锁 guest1111112 的 100 EVD
cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"guest1111112","quantity":"100.0000 EVD","memo":"#LOCK#"}' -p guest1111111
```

- [evrexchanges](exchange-cn.md): 交换 EVR 和 EVD 的合约；
```
# 1000 EVR 换 1000 EVD
cleos push action eosvrtokenss transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"1000.0000 EVR","memo":""}' -p guest1111111
```

- [eosvrmarkets](ebancor-cn.md): 交换 EVR 与 EOS 的合约，类似Bancor的机制；
```
# guest1111111 将 1 EOS 换成 EVR
cleos transfer guest1111111 eosvrmarkets "1.0000 EOS" -p guest1111111
```

- [eosvrcomment](comment-cn.md): 讨论用合约，每个人可以评论自己和其他人，也可以使用 EVD 来对讨论进行评分；
```
# guest1111111 给自己写一段介绍: "I am guest1."
cleos push action eosvrcomment comment '{"from":"guest1111111", "to":"guest1111111", "memo":"I am guest1."}' -p guest1111111
```

- [eosvrrewards](reward-cn.md): 奖励用合约，奖励发起人可以使用这个合约对讨论用合约（eosvrcomment 或其他）的前几名进行奖励；
```
# eosvrcomment 发起的 Reward: 奖励共 2000 EVD，每天发送奖励给 eosvrcomment 排名的前5名，每人每次最多100 EVD
cleos push action eoslocktoken transfer '{"from":"eosvrcomment", "to":"eosvrrewards","quantity":"2000.0000 EVD","memo":"500,eosvrcomment,86400,5,1,10"}' -p eosvrcomment
```

