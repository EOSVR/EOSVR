## EVD Reward Contract（eosvrrewards）

[中文](reward-cn.md)

It is to set rewards and send rewards to top accounts supported in [discuss contract](comment.md);


### Set rewards

Send EVD to eosvrrewards to set rewards, settings of rewards should be:

  Maximum token per reward, Discuss Contract, Reward Interval(Second), Maximum number of accounts who can get reward, Reward Type, Reward Limit

Default values are:
  30 EVD, eosvrcomment, 86400*7(7 days), 10(10 accounts), 0(average and can rollback), 10 (1%)

Example:

```
# guest1111111 use 100K EVD to reward top 10 in eosvrcomment everyday. Every time 10K EVD will send to 10 accounts average.
# Everyone can get 1000 EVD at most;
# And, guest1111111 can stop this reward at any time (rewardtype=0).
cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"eosvrrewards","quantity":"100000.0000 EVD","memo":"10000,eosvrcomment,84600,10,0"}' -p guest1111111
```


### Reward type

Only rewardtype is even, reward provider can withdraw the reward that do not send to others. If rewardtype is odd, it can not be revoked.

Example: 0 can revoke, 1 can not revoke.

When reward type is 2 or 3, the first account get 50%, second get 25%, others get the remain evenly;

In other condition, all accounts get reward evenly. 

When type > 20, maximum reward of one account = (For - Against * (type / 2 - 10)) * rewardLimit(default: 10) / 1000 

Example: evradvancers will use rewardtype = 41, it represent: vote of against is 10 times of for.

```
# Example, 0.1G EVD with 500K rewards per week
cleos push action eoslocktoken transfer '{"from":"eosvrairdrop", "to":"eosvrrewards","quantity":"100000000.0000 EVD","memo":"500000,eosvrcomment,592200,20,41,10"}' -p eosvrairdrop
```



