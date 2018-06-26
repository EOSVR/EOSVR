## EVR Token

[中文版](evr-cn.md)

EVR Token is a basic token for EOSVR ecosystem. Represent user's contribution to EOSVR. 

EOSVR will issue 10,000,000,000 EVR. 

- 1,000,000,000 will be used to airdrop of EOS mainnet with 1:1.

- 3,000,000,000 will use to construct the EOSVR world and improve the ecosystem of EOSVR.

- 6,000,000,000 will be locked 1 to 3 years from July 2018. Every year 2,000,000,000 EVR will be unlocked. And these EVR will improve the ecosystem of EOSVR. 

EVR token is issued by account "eosvrtokenss" . Its permission will be transfered to eosio to lock contract.


### Airdrop Plan

Airdrop will open after 2018/07/01. EOSVR will send EVR to the registered user every several days (in most cases, will be 2 times per week). Airdrop method:

- All genesis account can send 0.0001 EOS to eosvrairdrop to register. Will return EVR by the amount of EOS when mainnet started. Airdrop is only available for the account which amount of EOS >= 50.

- Other account can not register in this way, but the EOS send to eosvrairdrop will be returned 100 times EVR. More details are in following chapter.

Airdrop will be available in 2018.


### Start-up Plan

EOSVR need some EOS to develop and deploy in EOS mainnet. So account eosvrairdrop also can receive the donate of EOS. In return, it will return 1000 times EVR.

The completion of start-up plan need 50K EOS, and the limitation of donation is 200K EOS. After receive 200K EOS, account eosvrairdrop will not receive more donation. And can only send 0.0001 EOS for airdrop registration.

These are written in contract of eosvrairdrop. And can check the source code in airdrop folder of github.

Once project start, will follow the [roadmap](roadmap.md). And if the plan do not complete, the project may defer or cancel.


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


