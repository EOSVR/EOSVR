## EVD Distribution Plan

[中文](evd_distribute-cn.md)

### Introduction

EVD is a token in EOS chain. It can:

- Tranfer across-chain: EVD can transfer across different EOS side-chains. Other tokens do not support now.

- The total amount of liquid tokens is fixed in all chains: Because all EVD issued in side-chains, should be the same as the EVD tokens transfer (burn) to eoslocktoken.

Example: In main-chain, account eossidelink1 transfer (burn) 10000 EVD to eoslocktoken and mark it with sidechain ID. And in side-chain, it should issue at most 10000 EVD if there is no another account burn EVD for it.

The distribution of EVD is for the account who contribute to EVD system. More contribution, more EVD.


### Distribution Plan

- Same as EVR, there will be 10G EVD issued by account eoslocktoken in EOS main-chain. All EVD are in account: evrexchange. It is a exchange contract. If an account transfer 1 EVR to it, it will return 1 EVD to the account. And all liquid EVD plus EVR are still 10G;

- 1G EVR have changed to EVD and put into account: eosvr1111111. These EVD have been locked 0.5G for one year, and another 0.5G for two years. And the account have set the limitation that it can only transfer 1% per month after locks timeout. 

Command to check: ```cleos get table eoslocktoken eosvr1111111 timelockss```


- 1.1 G EVR are used for airdrop, experiments and EVR start plan. They are in account: eosvrairdrop.

  - EVR start plan only received less than 300 EOS and failed. All efforts will change to EVD plan. EVR will still be a useful token because EVR can not be locked by another user and many users may like them;

  - In the airdrop started in July of 2018, the account (giztqobxgege) who received most token get 3.5M EVR. EVD plan will continue the airdrop with a limitation of at most 3.5M EVR per account. (Only 22 accounts are influenced by this change)
  
  - Airdrop deadline is end of 2018. And the way of airdrop is still same: Genesis accounts can send 0.0001 EOS to eosvrairdrop and it will return EVR by the amount of EOS when mainnet started. Airdrop is only available for the account which amount of EOS >= 100.

  
  - After airdrop end, all remain EVR in eosvrairdrop will change to EVR and put into comment account: evradvancer2. Like the following.


- The remain 7.9G EVR will change into EVD and reward the accounts who contribute to EVD system in the following years. Reward contract is [eosvrrewards](reward.md).



#### Reward accounts details

EVD and related APP are all open-source. Everyone can make them better to get rewards.

Account eosvrrewards contains [the reward contract](reward.md), it will record all reward list that is opening. View them with:

```
cleos get table eosvrrewards eosvrrewards rewardss
```

Every reward will send to different discuss contract, every discuss contract will discuss different types of contributions. The account have EVD can vote these discuss;

The following are several discuss account:

- eosvrcomment: Test only. 2000 EVD, send 4 times per day, and send to first 5 accounts evenly. At most 500 EVD will reward every time. And one account can get at most 100 every time.

- evradvancer1: Advance plan 1 (No start). 10M EVD, send 50 times per week, and send to first 20 accounts evenly. At most 200K EVD will reward every time. And one account can get at most 10K every time.
  
  ```
  cleos push action eoslocktoken transfer '{"from":"eosvrairdrop", "to":"eosvrrewards","quantity":"10000000.0000 EVD","memo":"200000,evradvancer1,592200,20,1,10"}' -p eosvrairdrop
  ```
  
- evradvancer2: Advance plan 2（No start）. Will use the remain EVR of evr airdrop to reward. Plan to send reward per week in two years.
  

- evradvancers: Main reward plan (No start). Will put 7.9G EVD, and send 100 times every week. It will take more than 2 years. And this plan is important , it only give reward when everyone agree:
    
  - [rewardtype](reward.md#rewardtype) will use 41, it is: against vote is 10 times as for vote. 
    
  - rewardlimit is 3 instead of 10. It is: rewarded EVD = (support after multi weight) * 3 / 1000. Because weight can be at most 10 (When set transfer limitation to 1% per month), 1000 EVD support can get at most 1000 * 10(weight) * 3(rewardlimit) / 1000 = 30 EVD per week.
    
  ```
  cleos push action eoslocktoken transfer '{"from":"eosvrairdrop", "to":"eosvrrewards","quantity":"7900000000.0000 EVD","memo":"80000000,evradvancers,592200,20,31,3"}' -p eosvrairdrop
  ```

#### Contract Lock

The following contracts will give control to eosio to lock contracts after they are well tested.

- EVR contract: eosvrtokenss (Locked)

- EVR/EVD exchange contract: [evrexchanges](exchange.md) (Testing, maybe lock at the early of 2019)

- EVR/EOS exchange contract: [eosvrmarkets](ebancor.md) (Testing, maybe lock at the early of 2019)

- EVD contract: [eoslocktoken](evd.md) (Testing, maybe lock at the early of 2019)


