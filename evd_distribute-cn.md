## EVD发放计划

[English](evd_distribute.md)

### 介绍

EVD是EOS链中的一种代币。它可以：

- 跨链传输：EVD可以跨链传输，传统代币因为没有互相锁定和限制流动的机制，暂时不支持；

- 总量一定：所有流通中的EVD数量，等于主网中的发行量。因为所有侧链上的允许发行的EVD代币总量，等于主网中被传输（焚毁）到 eoslocktoken 帐号中的EVD数量。

比如：主网上有一个 eossidelink1 帐号，它传输了10000EVD到 eoslocktoken 作为抵押。那么在子网 sidelink1上，应该给它发布 10000EVD。之后，这个子网如果没有其他帐号做抵押，最多只能有10000 EVD。

EVD发放的原则是对EVD系统做出更多贡献的，将得到更多的EVD。


### 分配方案

- 与EVR一样，一共将发行 100亿（10G） EVD，并且全部 EVD 都放在 evrexchange 合约中，这个合约给它转1EVR，它就会返回1EVD。即：EVR与EVD以1：1兑换，总共流通的EVD + EVR 还是 100亿；

- EVR中的10亿，将作为创始团队奖励以及系统维护，已经转换为 EVD 并进行了时间锁定。1年后解锁5亿，2年后解锁剩余的5亿。且设置了转出限制，每月最多转出 1% 。可参考： ```cleos get table eoslocktoken eosvr1111111 timelockss```


- EVR中11亿被用于EOS主网的 1:1 空投以及各种实验、EVR启动计划，被放在合约 eosvrairdrop 中。

  - 目前启动计划只收到了不到300个EOS，已经失败，所以将转向EVD系统。EVR将作为一种与EVD等值的储存类代币而存在，因为它们不能被锁定。

  - 在2018年中开始的空投操作中，得到EVR最多的用户是 giztqobxgege，得到了3.5M 个EVR。由于EVD不能过于集中，我们决定将空投获取的 EVR 数量上限设置为每个账户最多3.5M。
  
  - 空投截止日期仍然是：2018年底。而空投方式不变，所有EOS创始帐号向 eosvrairdrop 账户发送0.0001 EOS即可。
  
  - 空投结束后，eosvrairdrop 中剩余的EVR将被转为EVD并放入奖励计划（evradvancer2）中，可参考下面的：奖励详细说明。


- 剩余79亿EVR将被转为EVD，在接下来的几年内，作为奖励计划而逐渐释放，用来奖励EVD相关生态系统的建设。奖励合约： [eosvrrewards](reward-cn.md)



#### 奖励详细说明

EVD 及其相关APP 将是完全开源的，奖励将用于促进 EVD 的代码优化和生态发展。

其中 eosvrrewards 合约为[奖励合约](reward-cn.md)，将记录所有奖励信息。下面可以查看所有当前正在进行的奖励；

```
cleos get table eosvrrewards eosvrrewards rewardss
```

而每个奖励将针对不同的 comments 合约进行，每个comments 合约（类似论坛）约定记录不同种类的贡献或内容，根据得到赞同的数量进行排名；

下面是计划进行奖励的列表：

- eosvrcomment: 奖励测试（已部署）。共有2000 EVD，连续4天每天发放一次，每次给前五名帐号平均发放，每次奖励最多500 EVD，即每个人最多100个。

- evradvancer1: 推进计划1（未部署）。共计划投入 10M EVD，连续发放50次，每周发放一次，总共持续1年左右，每次给前20名平均发送，每次奖励最多200K EVD，即每人最多10K EVD。这是实验性质的推进计划。
  
  ```
  cleos push action eoslocktoken transfer '{"from":"eosvrairdrop", "to":"eosvrrewards","quantity":"10000000.0000 EVD","memo":"200000,evradvancer1,592200,20,1,10"}' -p eosvrairdrop
  ```
  
- evradvancer2: 推进计划2（未部署）。计划使用空投剩余的EVR，先全部换成 EVD，再全部投入这个奖励计划。同样是每周发放一次，持续两年。
  

- evradvancers: 推进主计划（未部署）。共计划投入 7.9G （79亿） EVD，发放 100次，每周发放一次，总共持续2年以上，每次给前20名平均发送，每次奖励最多 80M EVD，即每人最多奖励 4M EVD 一次。但这个主计划要比较保守，大家都赞同的奖励才允许被接收。所以：
    
  - [奖励类型（rewardtype）](reward-cn.md#奖励类型)将使用 41, 这表示：反对者的投票将10倍有效于支持者。假设一个提议有人反对，那么他的反对票将乘以10。
    
  - 奖励限制系数将使用 3，而不是默认的10，这表示：投票后得到的EVD上限 = 加权后的赞同 * 3 / 1000。由于权重最多为10（1%每个月的限制），所以，1000 EVD的投票，最多一周可以收到的奖励 = 1000 * 10(权重) * 3(rewardlimit，限制系数) / 1000 = 30。
    
  ```
  cleos push action eoslocktoken transfer '{"from":"eosvrairdrop", "to":"eosvrrewards","quantity":"7900000000.0000 EVD","memo":"80000000,evradvancers,592200,20,31,3"}' -p eosvrairdrop
  ```

#### 合约锁定

下列合约，都将在测试完毕后，将控制权移交给 eosio ，从而达到锁定合约的目的。

- EVR 合约帐号 eosvrtokenss (已锁定)

- EVR/EVD 交换合约 [evrexchanges](exchange-cn.md) (测试中，估计将在2019年初锁定)

- EVR/EOS 交换合约 [eosvrmarkets](ebancor-cn.md) (测试中，估计将在2019年初锁定)

- EVD 合约帐号 [eoslocktoken](evd-cn.md) （测试中，估计将在2019年第一季度锁定）


