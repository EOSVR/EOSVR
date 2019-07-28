## Trust Solution - EVD

[中文](README-cn.md)

[APP Download](http://eosvr.io/index.html)

#### Introduction

EVD is a token in EOS chain to implement [trust solution](intro.md). 

It can prove the account is trustworthy by:

- Lock each other: One account can lock the token of another account;

- Limit the transfer: User can set the percent of tokens that can transfer out of account per month;

- [Across-Chain](sidechain.md): It allows a EOS chain can transfer EVD to another EOS chain. Example:
Account A in EOS main chain can transfer EVD to account B in another EOS side-chain, and transfer back.

This made it possible to create a wide-spread, low-cost trust network.

#### More Links

[Contract EVD](https://github.com/EOSVR/sidechain/blob/master/contracts/locktoken/README.md)

[Script to build EOS Sidechain and related contracts](https://github.com/EOSVR/sidechain)


#### APP Support

APP EOSVR will be the interface of trust solution. It is an APP used in Windows, MacOS, iPhone/iPad, Android. Users can use it to transfer/lock/unlock EVD, and prove they are trustworthy.

It is in development, [APP Download](http://eosvr.io/index.html)


#### How to get it

1，EVD will be changed from EVR 1:1. Just transfer to contract: evrexchanges with EVR or EVD, it will return the same amount of another token. Example:

If attended the airdrop in July, 2018, can get EVD by EVR as:

```
# 1000 EVR -> 1000 EVD
cleos push action eosvrtokenss transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"1000.0000 EVR","memo":""}' -p guest1111111
```

Note: EVR used the system contract like eosio.token. It does not have limit of transfer, and no lock feature. Some users may want to hold it instead of EVD.


2, EOS can change to EVD and change back by contract [eosvrmarkets](https://github.com/EOSVR/sidechain/blob/master/contracts/sidebancor/README.md). Try it like:

```
# Change 1 EOS to some EVD
cleos transfer guest1111111 eosvrmarkets "10.0000 EOS"

# Change 10 EVD to EOS
cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"eosvrmarkets","quantity":"10.0000 EVD","memo":""}' -p guest1111111

```

This is a de-centralized contract. Because it need both tokens in this account to start to exchange, anyone can invest or withdraw the investment.
At the same time, exchange takes 5 over one thousand fee as the bonus of investors. [More info](https://github.com/EOSVR/sidechain/blob/master/contracts/sidebancor/README.md).

3，Get EVD by reward

It likes mining. But it does not need fast servers. It need contribution to EVD project. If someone contribute to EVD project, he can write the proof in comment contract like (eosvrcomment, evdadvancer1, evdadvancers, etc). The account with EVD can comment and support them with EVD. The account with higher support score will get rewards.

It is in experiment and will reward very carefully.

More info about [EVD distribution](evd_distribute.md)


#### Related contracts

- [eoslocktoken](https://github.com/EOSVR/sidechain/blob/master/contracts/locktoken/README.md): EVD contract;
```
# guest1111111 lock guest1111112 with 100 EVD
cleos push action eoslocktoken transfer '{"from":"guest1111111", "to":"guest1111112","quantity":"100.0000 EVD","memo":"#LOCK#"}' -p guest1111111
```

- [evrexchanges](exchange.md): Exchange EVR with EVD;
```
# 1000 EVR -> 1000 EVD
cleos push action eosvrtokenss transfer '{"from":"guest1111111", "to":"evrexchanges","quantity":"1000.0000 EVR","memo":""}' -p guest1111111
```

- [eosvrmarkets](https://github.com/EOSVR/sidechain/blob/master/contracts/sidebancor/README.md): Exchange EVD with EOS with bancor mode;
```
# guest1111111 change 1 EOS to several EVD
cleos transfer guest1111111 eosvrmarkets "1.0000 EOS" -p guest1111111
```

- [eosvrcomment](https://github.com/EOSVR/sidechain/blob/master/contracts/comments/README.md): Comment contract, everyone can use it to comment another, also can use it to support/against another with EVD;
```
# guest1111111 write a description to himself: "I am guest1."
cleos push action eosvrcomment comment '{"from":"guest1111111", "to":"guest1111111", "memo":"I am guest1."}' -p guest1111111
```

### Contact

Mail: contact@eosvr.io
