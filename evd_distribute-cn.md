## EVD发放计划

[English](evd_distribute.md)

### 介绍

EVD是EOS链中的一种代币。它可以：

- 跨链传输：EVD可以跨链传输，传统代币因为没有互相锁定和限制流动的机制，暂时不支持；

- 总量一定：所有流通中的EVD数量，等于主网中的发行量。因为所有侧链上的允许发行的EVD代币总量，等于主网中被传输（焚毁）到 eoslocktoken 帐号中的EVD数量。

比如：主网上有一个 eoslinker111 帐号，它传输了10000EVD到 eoslocktoken 作为抵押。那么在子网 sidechain1上，应该给它发布 10000EVD。之后，这个子网如果没有其他帐号做抵押，最多只能有10000 EVD。

EVD发放的原则是对EVD系统做出更多贡献的，将得到更多的EVD。


### 分配方案

- 一共将发行 100亿（10G） EVD (与EVR一样)；

- 其中的10亿，将作为创始团队奖励以及系统维护，已经进行了时间锁定。1年后解锁5亿，2年后解锁剩余的5亿。且设置了转出限制，每月最多转出 1% 。可参考：

```
cleos get table eoslocktoken eosvr1111111 timelockss
```

- 有0.5亿被用于对EOS主网的 1:1 空投（从2018年7月开始的空投已经结束）、交易所搭建以及各种实验中；

- 剩余89.5亿，将全部作为奖励计划而在接下来的几年逐渐释放，用来奖励EVD相关生态系统的建设。
奖励合约： [eosvrrewards](https://github.com/EOSVR/sidechain/blob/master/contracts/rewards/README-cn.md)


#### 奖励详细说明

EVD 及其相关APP 将是完全开源的，奖励将用于促进 EVD 的代码优化和生态发展。

其中 eosvrrewards 合约为[奖励合约](https://github.com/EOSVR/sidechain/blob/master/contracts/rewards/README-cn.md)，将记录所有奖励信息。下面可以查看所有当前正在进行的奖励；

```
cleos get table eosvrrewards eosvrrewards rewardss
```

而每个奖励将针对不同的 comments 合约进行，每个comments 合约（类似论坛）约定记录不同种类的贡献或内容，根据得到赞同的数量进行排名；

下面是进行奖励的列表：

- eosvrcomment: 奖励测试。

- evdadvancer1, evradvancers, evdpopulariz : 推进计划。分别投入 50M, 50M 和 100M，每3天发放一次，总共持续1年以上，每次给前20名平均发送。需要申请，反对倍数3。
  
  ```
  # Example
  cleos push action eoslocktoken transfer '{"from":"eosvrmanager", "to":"eosvrrewards","quantity":"100000000.0000 EVD","memo":"1000000,evdpopulariz,259200,10,15,10"}' -p eosvrmanager
  ```

- evdadvancers: EVD推进主计划。共投入 8.75G （87.5亿） EVD，发放 100次以上，每周发放一次，总共持续2年以上，每次给最多20名平均发送，每次奖励最多 100M EVD。
但这个主计划比较保守，大家都赞同的奖励才允许被接收。所以需要申请，反对倍数6。具体如下：
    
  - [奖励类型（rewardtype）](https://github.com/EOSVR/sidechain/blob/master/contracts/rewards/README-cn.md#奖励类型)将使用 21, 这表示：反对者的投票将6倍有效于支持者。假设一个提议有人反对，那么他的反对票将乘以6。

  - 必须先申请才能获取奖励，申请多少，每次能够获取的最大数量就是多少。[详细说明](https://github.com/EOSVR/sidechain/blob/master/contracts/rewards/README-cn.md#奖励类型)
    
  - 奖励限制系数将使用 5，而不是默认的10，这表示：投票后得到的EVD上限 = 加权后的赞同 * 5 / 1000。由于权重乘上限制最多为10（每个月1-10%的限制），所以，1000 EVD的拥有者投票，最多一周可以收到的奖励 = 1000 * 10(权重加成) * 5(rewardlimit，限制系数) / 1000 = 50。
    
  ```
  cleos push action eoslocktoken transfer '{"from":"eosvrmanager", "to":"eosvrrewards","quantity":"8750000000.0000 EVD","memo":"100000000,evdadvancers,604800,20,21,5"}' -p eosvrmanager
  ```

注意：由于在测试中，所以EVD推进主计划不接受投票。请在 evdadvancer1 下申请贡献。具体细节待定。

#### 合约锁定

下列合约，都将在测试完毕后，将控制权移交给 eosio ，从而达到锁定合约的目的。

- EVR 合约帐号 eosvrtokenss (已锁定)

- EVR/EVD 交换合约 [evrexchanges](exchange-cn.md) (测试中，估计将在2019年初锁定)

- EVD/EOS 交换合约 [eosvrmarkets](https://github.com/EOSVR/sidechain/blob/master/contracts/sidebancor/README-cn.md) (测试中，估计将在2019年初锁定)

- EVD 合约帐号 [eoslocktoken](https://github.com/EOSVR/sidechain/blob/master/contracts/locktoken/README-cn.md) （测试中，估计将在2019年第一季度锁定）

- EVD 奖励合约 [eosvrrewards](https://github.com/EOSVR/sidechain/blob/master/contracts/rewards/README-cn.md) (测试中，估计将在2019年第一季度锁定）
