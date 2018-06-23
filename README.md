# EOSVR

[中文版](README-cn.md)

[EOSVR 0.2 Demo](https://github.com/EOSVR/EOSVR/blob/master/wallet-cn.md), can use as EOS wallet.


Draft：2018/05/14 

#### Abstract

EOSVR is a virtual world based in EOS chain. Like Ready Player One, people are able to access the virtual world, communicate with others, and build virtual objects together through versatile devices, including: iPhone, Android, PC, Mac, or VR helmet. 

EOSVR reduces the maintanance cost and enhances user experiences by utilizing the decentralizing technology.


#### Background

People need to communicate in network, but currently all app is centralized. Because server, bandwidth, maintain and regulation cost lots of money, centralized platform need to use the data privately. User need register a new account when they play in a new platform. And all data between these platform can not sync.

Example: User need an account in facebook, also need an account in amazon. The friendship information in facebook can not be used by amazon. And the bought information in amazon can not be used by facebook.

And in an decentralized app, encrypted user's data stored in lots of machines. User only need one account, and can allow certain user data in certain platform. At this time, user can login by one account in decentralized facebook and amazon. And use all user data in all platform. Such as: friendship, habit, etc.

Blockchain is a implementation of decentralized technique, and EOS is the new block chain technology. It uses DPOS consensus, instead of POW consensus of BTC or ETH that take most of machine resource into useless mathematical problem. So it can trade thousands of times per second, and can deploy useful app. At the same time, BTC cost nearly tens of billions of dollars per year, and can only trade 7 times per second.

On the other side, users especially young man need more real virtual world. They need more personalized character to find their friends in network. One world liked "Ready Player One" is what they need. In it, users can use their favorite character to enter real world and talk with their friends face-to-face.

But in real world, how to avoid harm user is a big problem. In EOSVR, decentralized audit use to solve this problem.


### EOSVR Components

EOSVR has the following components:

- EOS Chain, use to store user data, including token and titles, etc.

- Client, show the virtual world. User enter the world by it. Planned to support Windows, Mac, iOS, Android, also support VR Helmet like HTC vive and Oculus.

- File storage , use to store user's model, pictures and media files , etc. It supports private server to decentralize.

- Room server , use to sync user's motion data and voice data. It will be open-source.


#### Virtual World

EOSVR provide a 3D spaces to let different users talk together, like "Ready Player One".

User can show their customed model, or customed emotion. And talk with other users.

User can trade models with each other with token.


#### Scenario

EOSVR allow user to create scenario and owner of scenario can set the parameters of the world. Example: gravity, if allow a stranger enter world, price of entrance, etc.

Scenario is deployed in a room server, user can publish the room server in EOS chain to allow other user to join.

Room server is open-source and everyone can deploy their room server.


#### Record and Replay

EOSVR client can record the motions of users in it, and play them later. Because it only records the motion of objects, it will be very small compared with traditional video. And these record is 3D and user can view it in all directions freely.

User can make 3D animation with it. 

Also the record can be traded with other user, also can use in a complaint. (The following)

Record is only in EOSVR client, not in server. And user can sign it and put the signature to EOS chain to validate it.


### Audit

It is very important to avoid psychological harm in a virtual world:

- Some one feel bad with certain model and indelicacy.
  
- Some one feel bad with discriminatory words or actions.
  
- Some one feel bad when other is too near.

- Some one can not allow children talk with other without their eyes. And on the contrary, children can not allow their parent watch them at all time.

We need a balance to let all people feel better, at least no bad.


Audit is a way to reduce the harm. But traditional audit is central and cost a lot. We need a decentral way to audit. The following is the design:

1，Comment: users can comment other (agree or disagree) when they feel happy or unhappy.

- Agree: give token to other,

- Disagree: a user can lock his(her) token, to lock another user's token;

Example: John do not like the action of Mike just now. John can lock Mike's 10 tokens by locking his 10 tokens. If Mike only has 9 unlock token, he will be drive out of game.


2，Complaint: users can record what occur just now (example: within 2 minutes) and publish the record. Everyone can judge the record and comment to someone in the record.

A bad environment will harm users who have lots of token, and they tend to protect the effiency of the virtual world and do the justice.

In special environment, such as private zone, users can invalidate the ability of comment and Complaint, to avoid the abuse of them.


3, Guardian：Parent can provide an account to their children, and they can watch all actions of this account at any time and can take control of the account at any time. If young men do not like the watch of parent, they can create an account themselves.


#### District 

With different habit and interest, user can separate into different district.

Also different district has different rules, including:

1, Complaint effect, cost .vs. lock is not always 1 .vs. 1

2, In a Complaint, can have the limit of locking token

3, Delegate in Complaint, users can select several judge who have more locking multi effect than normal users

4，Different token. User need to cost/get this token when stay in the district.

    
    
#### Contract

A contract is some computer codes, execute these code will get expected result.

Because all users can see the contract, everyone can check contract and prove their profit.

EOSVR use contract to validate Comment and Complaint.


#### Conclusion

EOSVR is a decentralize app that can communicate with each other, and can trade and audit automatically.

