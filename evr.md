## EVR Token

[中文版](evr-cn.md)

EVR Token is a basic token for EOSVR ecosystem. Represent user's contribution to EOSVR. 

EOSVR will issue 10,000,000,000 EVR. 

- 3,000,000,000 will be controlled by EOSVR group, including:

  1, 1,000,000,000 will be used to airdrop of EOS mainnet with 1:1.
  Airdrop will stop at 2018/10/15. After that all remain EVR will put to reward plan. (Contract: eosvrrewards)

  2, 1,000,000,000 will use for activity. 
  Will reserve 100,000,000 in account: eosvr1111111. All other EVR will put to reward plan.

  3, 1,000,000,000 will reward to the EOSVR group. And will lock 1 year and can not trade.
  Has transferred to [EVD](evd-cn.md) and lock 500M for 1 year, lock another 500M for 2 years. Can track by:
      cleos get table eoslocktoken eosvr1111111 timelockss

- After the basic features of EOSVR finished, the remain 7,000,000,000 EVR will be released through trade system. And will send to the user who improve the EOS ecosystem. All trade reasons and results are in EOS chain and it is transparent. The user who have EVR token can decide the trade details and if a trade is successful.

EVR token is issued by account "eosvrtokenss" . Its permission will be transfered to eosio to lock contract.


### Airdrop Plan

Airdrop will open after 2018/07/01. Airdrop method:

- All genesis account can send 0.0001 EOS to eosvrairdrop to register. Will return EVR by the amount of EOS when mainnet started. Airdrop is only available for the account which amount of EOS >= 100.

- Other account can not register in this way, but the EOS send to eosvrairdrop will be returned 1000 times EVR. More details are in following chapter.

Airdrop will be available in October 2018.


### Start-up Plan

Do not receive enough EOS. We will change the plan.


### Other tokens in EOSVR

EOSVR worlds have a [lock](README.md#Audit) system. So in most world, users can lock other users' token. EVR will not be locked. And it can change to other region's token.

Before a user enter other world, he may change some of his EVR to another token.


### Trade Objects

In EOSVR system, the following objects can trade:

1, User's 3D Model that can shown in EOSVR world:

  A original model has different version with different address to download;
  
  Other users also can create model based on a model. In this way, it is the child of old one, need give a part of token to parent;
  
  Original model can create many copied models. Each of these copied models has an unique id and can only trade. Copied model can not copy more.

  
2, Scene (Or room server)

  It may have several mode. Example, take token per hours;
  
  Can also send token per hours. And user can only be kicked out by [Lock System](README.md#Audit);
  

3，User's interaction

  Example, user's voice bind, or allow one fly to another at any time, etc；
  

4, Trade outside of EOSVR world


5, New feature of EOSVR

  a. Maybe users need some new feature or programs. All users can agree/against for these features by token;
  
  b. When feature finished, the users who paid token will decide if it is finished.

  c，If there are both agree and against users, conflict tokens will be lock for a long time (example 1 month) to avoid the abuse.


These are implemented by different contracts.


### Trade World

A trade world will be in EOSVR world. In it, users can change TRD token by EVR token.

TRD support lock others. If there are any conflict in trade, one can lock another user's token.

At this time, a user with good name will be easier to trade. And we should avoid to trade with the random name users, because they may cheat you and run.


### EVR Distribute Contract

Some DAPP may use EVR to distribute the output, example: [name shop](https://github.com/eosaccount/eosnameshops/blob/master/README.md) 

User can send their EVR to eosvrstorage. And when eosvrstorage receive token, user will receive token based on the amount of EVR. 

This contract will be open-source and deploy on EOS mainnet at two weeks after EOSVR start-up finished.
