# EOSVR

Draft：2018/05/14 

#### Abstract

EOSVR is a virtual world based in EOS chain. User can enter the virtual world by iPhone, Android, PC, Mac or VR helmet. Use a customed virtual role to talk with other and create virtual objects.

It has decentralized server, and decentralized regulation. It reduces the cost of maintain world, and user have better experience than traditional app.


#### Background

People need to communicate in network, but currently all app is centralized. Because server, bandwidth, maintain and regulation cost lots of money, centralized platform need to use the data privately. User need register a new account when they play in a new platform. And all data between these platform can not sync.

Example: User need an account in facebook, also need an account in amazon. The friendship information in facebook can not be used by amazon. And the bought information in amazon can not be used by facebook.

And in an decentralized app, encrypted user's data stored in lots of machines. User only need one account, and can allow certain user data in certain platform. At this time, user can login by one account in decentralized facebook and amazon. And use all user data in all platform. Such as: friendship, habit, etc.

Blockchain is a implementation of decentralized technique, and EOS is the new block chain technology. It uses DPOS consensus, instead of POW consensus of BTC or ETH that take most of machine resource into useless mathematical problem. So it can trade thousands of times per second, and can deploy useful app.

On the other side, users especially young man need more real virtual world. They need more personalized character to find their friends in network. One world liked "Ready Player One" is what they need. In it, users can use their favorite character to enter real world and talk with their friends face-to-face.



#### EOSVR Components

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

Also the record can be traded with other user, also can use in a trial. (The following)

Record is only in EOSVR client, not in server. And user can sign it and put the signature to EOS chain to validate it.


#### Audit

It is very important to avoid psychological harm in a virtual world:

- Some one feel bad with certain model and indelicacy.
  
- Some one feel bad with discriminatory words or actions.
  
- Some one feel bad when other is too near.

- Some one can not allow children talk with other without their eyes. And on the contrary, children can not allow their parent watch them at all time.

We need a balance to let all people feel better, at least no bad.

Trial is a way to 

审核就是一种避免其中的人受到伤害的手段，但传统的审核都是中心化的，而且费时费力。我们需要一种去中心化的审核方式，所以制定了下面这几个用户可以有的权力： 

1，复仇：人们可以对让他们不高兴的动作进行复仇，但复仇不能被滥用； 

2，审判：人们可以录下他们刚刚经历的事情（比如2分钟内），让所有的人都可以对这段经历进行审判，以此来防止侵害的发生；

3，豁免：在特殊情况下，比如私人区域，人们可以约定复仇和审判无效化，以防止复仇和审判被滥用； 

4, 监察：监护人可以让提供给孩子他们的一个帐号，但这个帐号他们可以监察所有行动。对于孩子们来说，自己花钱去建立一个帐号或许是他们摆脱监护人的方法。


#### 复仇与审判 

由于拥有代币多的人对社区有更多的认同感，更能代表社区的利益。所以可以通过代币的互锁来实现用户自发的审核。

- 复仇：人们可以通过锁定自己的代币，来使得其他人的代币被锁定； 

  比如：小明觉得小王的行为不好，他可以锁定自己10个代币，来换取小王10个代币的锁定，这时，如果小王只有9个代币，这9个将都被锁定，并且由于未锁定的代币数不足0个，他将在1分钟后被强制下线。 


- 审判：人们觉得正义在自己这方的时候，可以对之前一段场景（比如：2分钟）进行录像，并把录像公之于众，让大家来对录像中出现的所有人进行评价，并使用自己的代币来锁定 被审判者（所有录像中出现的人物）的代币； 为了避免有人故意截取片段来混淆视听，录像必须足够长； 

- 豁免：录像只允许在公共空间进行，在隐私空间，录像可能会侵犯用户的合理权力，所以在这些地方，需要对录像进行禁止。而因此就无法进行审判。这时，我们称之为豁免。
私有空间的规则可以由主人进行修改，比如：是否允许录像、是否允许复仇。 

复仇和被复仇的人，都可以将双方拉上审判。 


#### 审判分区 

由于不同的人有不同的圈子和生活习惯，如果不进行分类，他们之间会起冲突。比如：一个人如果听到一些对别人常见，但他来说是侮辱性的词语，会对他的精神造成冲击，从而损失效率。 

所以在不同区域，需要区域所有者进行设置不同审判规则，包括： 

1，赞同者和反对者的效果比例（不一定都是 1:1） 

2，赞同和反对上限，即对被审判者的宽容程度（上限低的更加宽容，不赞成太多的惩罚；赞同上限 大于反对上限的更加宽容） 

3，审判代理加成，允许投票来选择一些用户，他们的票有更大的倍数 （类似法官） 

4，区域代币： 
    
    不同的区域可以发行区域代币，在区域中的人会持续消耗或者获得该代币； 
    
    投票也使用该代币； 
    
    当代币数量少于一个值（可以是负数）时，用户将被驱逐。 
    
    
#### 智能合约

智能合约可以看成一段多方共同约定的计算机代码，执行这段代码可以得到一定的结果。 

由于合约的代码是透明的，多方都可以检查合约代码，并确保自己的利益得到保证。 

EOSVR 将使用 智能合约 来维护 复仇 和 审判 的正确性。


#### 结论 

EOSVR 是一个能充分满足人们交流需求的去中心化 DAPP，能实现自动化的监管、交易。

