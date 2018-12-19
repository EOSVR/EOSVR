## Trust Solution - EVD

#### Introduction

EVD is a [trust solution](intro.md). It has all functions of trust solution:

- Lock each other: One account can lock the token of another account;

- Delay transfer: User can create a transfer with delay;

- Limit the transfer: User can set the percent of tokens that can transfer per month;

- Sync the transfer: To support the transfer across-chain, user can setup a transfer with a password and timeout. After that, user can reveal the password and confirm all related transfer, or do not reveal and fail all related transfer;

- Fast execution: It is on EOS block-chain and a transfer only take several seconds. The confirmation of a transfer only takes less than one minute.

- [Across Chain](sidelink.md): It allows a EOS chain can transfer EVD to another EOS chain. Such as: Account A in EOS main chain can transfer EVD to account B in another EOS chain, and transfer back. 

This made it possible to create a wide-spread, low-cost trust network.

[More info of contract EVD](evd.md).

#### APP Support

[APP EOSVR](app.md) will be the interface of trust solution. It is an APP used in Windows, MacOS, iPhone/iPad, Android. User can use it to transfer/lock/unlock EVD, and prove they are trustable.

It is in development. After release , it will be Open-Source. The contribution to this APP will be [rewarded](reward.md) too.


#### How to get it

1，EVD will be changed from EVR 1:1. Just transfer to contract: evrexchanges with EVR or EVD, it will return the same amount of another token. Example:

```
# 1000 EVR -> 1000 EVD
cleos push action eosvrtokenss transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"1000.0000 EVR","memo":""}' -p guest1111111
```

EVR used the system contract like eosio.token. It does not have limit of transfer, and no lock feature. Some users may want to hold it instead of EVR.

2, EOS can change to EVR and change back from contract [eosvrmarkets](ebancor.md). It is in testing now and only have several token in it.


3，Get EVD by reward

It likes mining. But it does not need very fast machine. It need contribution to EVD project. If someone contribute to EVD project, he can write the proof in discuss contract like (eosvrcomment, evradvancers, appadvancers, etc). The account with EVD can comment and support them with EVD. The account with higher support will get rewards.

More info: [Contract eosvrrewards](reward.md)

More info about [EVR/EVD distribution](evd_distribute.md)


#### Related contracts

- [eoslocktoken](evd.md): EVD contract;
```
# guest1111111 lock guest1111112 with 100 EVD
cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"guest1111112","quantity":"100.0000 EVD","memo":"#LOCK#"}' -p guest1111111
```

- [evrexchanges](exchange.md): Exchange EVR with EVD;
```
# 1000 EVR -> 1000 EVD
cleos push action eosvrtokenss transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"1000.0000 EVR","memo":""}' -p guest1111111
```

- [eosvrmarkets](ebancor.md): Exchange EVR with EOS with bancor mode;
```
# guest1111111 change 1 EOS to several EVR
cleos transfer guest1111111 eosvrmarkets "1.0000 EOS" -p guest1111111
```

- [eosvrcomment](comment.md): Discuss contract, everyone can use it to discuss another, also can use it to support/against another with EVD;
```
# guest1111111 write a description to himself: "I am guest1."
cleos push action eosvrcomment comment '{"from":"guest1111111", "to":"guest1111111", "memo":"I am guest1."}' -p guest1111111
```

- [eosvrrewards](reward.md): Reward contract, an reward provider can use it to send rewards to others;
```
# eosvrcomment provide a reward of 2000 EVD. It will send rewards to the top 5 in eosvrcomment every day. At this time, everyone can get at most 100 EVD per day.
cleos push action eoslocktoken transfer '{"from":"eosvrcomment", "to":"eosvrrewards","quantity":"2000.0000 EVD","memo":"500,eosvrcomment,86400,5,1,10"}' -p eosvrcomment
```

