## EVD Distribution Plan

[中文](evd_distribute-cn.md)

### Introduction

EVD is a token in EOS chain. It can:

- Tranfer across-chain: EVD can transfer across different EOS side-chains. Other tokens do not support now.

- The total amount of liquid tokens is fixed in all chains: Because all EVD issued in side-chains, should be the same as the EVD tokens transfer (burn) to eoslocktoken.

Example: In main-chain, account eoslinker111 transfer (burn) 10000 EVD to eoslocktoken and mark it with sidechain ID. And in side-chain, it should issue at most 10000 EVD if there is no another account burn EVD for it.

The distribution of EVD is for the account who contribute to EVD system. More contribution, more EVD.


### Distribution Plan

- There is 10G (Same as EVR) EVD  issued by account eoslocktoken in EOS main-chain.

- 1G have put into account: eosvr1111111 with delayed transfer. These EVD have been locked 0.5G for one year, and another 0.5G for two years. And the account have set the limitation that it can only transfer 1% per month after locks timeout.

Command to check:

```
cleos get table eoslocktoken eosvr1111111 timelockss
```


- 1.1G are used for airdrop, experiments and EVR start plan. They are in account: eosvrairdrop.

  - EVR start plan only received less than 300 EOS and failed. All efforts will change to EVD plan. EVR will still be a useful token because EVR can not be locked by another user and many users may like them;

  - The airdrop started in July of 2018 have finished. All remain EVR in eosvrairdrop will change to EVR and put into comment account: evradvancer2. Like the following.


- The remain 7.9G will change into EVD and reward the accounts who contribute to EVD system in the following years. Reward contract is [eosvrrewards](https://github.com/EOSVR/sidechain/blob/master/contracts/rewards/README.md).



#### Reward accounts details

EVD and related APP are all open-source. Everyone can make them better to get rewards.

Account eosvrrewards contains [the reward contract](https://github.com/EOSVR/sidechain/blob/master/contracts/rewards/README.md), it will record all reward list that is opening. View them with:

```
cleos get table eosvrrewards eosvrrewards rewardss
```

Every reward will send to different discuss contract, every discuss contract will discuss different types of contributions. The account have EVD can vote these discuss;

The following are several discuss account:

- eosvrcomment: Test only.

- evdadvancer1, evradvancers, evdpopulariz : Improvement plan. Used 50M, 50M and 100M EVD, send every 3 days and about last more than 1 year. Will send to top 20.
Need apply and against multiply by 3.
  
  ```
  cleos push action eoslocktoken transfer '{"from":"eosvrmanager", "to":"eosvrrewards","quantity":"100000000.0000 EVD","memo":"1000000,evdpopulariz,259200,10,15,10"}' -p eosvrmanager
  ```

- evdadvancers: Main reward plan. Will put 8.75G EVD, and send 100 times every week. It will take more than 2 years.
And this plan is important, it needs apply and against multiply by 6. More details:

  - [rewardtype](https://github.com/EOSVR/sidechain/blob/master/contracts/rewards/README.md#reward_type) will use 21, it is: vote of opponents have 6 times effect.

  - Account must apply first, or no reward. [More details](https://github.com/EOSVR/sidechain/blob/master/contracts/rewards/README.md#reward_type).

  - rewardlimit is 5 instead of 10. It is: rewarded EVD = (support after multi weight) * 5 / 1000.
  Because weight can be at most 10 (When set transfer limitation to 1% per month), 1000 EVD support can get at most 1000 * 10(weight) * 5(rewardlimit) / 1000 = 50 EVD per week.
    
  ```
  cleos push action eoslocktoken transfer '{"from":"eosvrmanager", "to":"eosvrrewards","quantity":"8750000000.0000 EVD","memo":"100000000,evdadvancers,604800,20,21,5"}' -p eosvrmanager
  ```

Note: It is in testing and please do not apply to evdadvancers. Can apply in evdadvancer1 for rewards. Some details about reward is still uncertain now.


#### Contract Lock

The following contracts will give control to eosio to lock contracts after they are well tested.

- EVR contract: eosvrtokenss (Locked)

- EVR/EVD exchange contract: [evrexchanges](exchange.md) (Testing, maybe lock at the early of 2019)

- EVD/EOS exchange contract: [eosvrmarkets](https://github.com/EOSVR/sidechain/blob/master/contracts/sidebancor/README.md) (Testing, maybe lock at the early of 2019)

- EVD contract: [eoslocktoken](https://github.com/EOSVR/sidechain/blob/master/contracts/locktoken/README.md) (Testing, maybe lock at the early of 2019)

- EVD Reward contract: [eosvrrewards](https://github.com/EOSVR/sidechain/blob/master/contracts/rewards/README-cn.md) (Testing, maybe lock at the early of 2019)

