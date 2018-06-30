## EOSVR Demo

[English](wallet.md)

了解到目前手机EOS钱包缺少的问题，我们将我们的Demo版经过一些修改，使得它可以方便给EOS用户使用。它有如下功能：

- 创建并管理大量用户；

- 支持[离线钱包（冷钱包）](offline-wallet.md)模式，保证私钥的安全；

- 可以使用传统的帐号、密码系统，而不是对于普通人来说十分不方便的私钥体系；

- 可以轻易修改密码（私钥）；

- 转账；

- 资源管理（内存、CPU、带宽）。包括解锁初始帐号的资源，手动取回被锁的EOS等；

- 帐号的购买与出售 [链接](http://eosnames.shop)；

- 申请空投[EVR](evr-cn.md)代币；



#### 安装 

- [IOS安装](https://test.gvrcraft.com/download.html) 

- [Github IOS](http://eosnames.shop/download.html)

IOS是企业版，需要进行企业信任。在 设置 -> 通用 -> 设备管理 中进行信任操作。


- [Android安装](https://test.gvrcraft.com/eosvr.apk)

- [Github Android APK](https://github.com/EOSVR/EOSVR/raw/master/bin/eosvr.apk)


- [Mac安装](http://test.gvrcraft.com/EOS_VR.dmg)

- [Github Mac](http://github.com/EOSVR/EOSVR/raw/master/bin/EOS_VR.dmg)



### 公用帐号

对新手来说，可以使用我们的测试帐号 guest1111113来实验功能，在导入私钥时，点击『导入体验帐号』即可。

我们会不定期的给这个帐号转一点EOS代币，如果你正好在用，可以随意用来建立自己的帐号。



### 如何保证安全性

- [离线钱包（冷钱包）](offline-wallet.md)技术保证了私钥的安全；

- 随时可以修改密码（私钥），如果用户觉得私钥可能会泄露，他可以立刻修改；

- 用户可以在设置中自定义自己的salt值（务必记下来，因为迁移机器时需要），这样一来，即使今后私钥算法被泄露，也大大增加了黑客破解的难度。因为黑客不止要知道你的用户名，密码，还要知道你的salt；

- 本APP的设计基于完全的去中心化设计，目前版本除了连接EOS主网（连接可以在APP中配置）外，并不连接任何其他服务器。而EOSVR本身除了几个网页服务器外，也没有任何后台服务器，所以也不可能进行私钥的盗取；



### 私钥与密码

你在APP中可以像之前的传统帐号一样，使用用户名和密码进行操作。它的实质是使用用户名，密码和salt来计算出唯一对应的一个私钥来。这样你可以轻松地对一个帐号进行设备迁移，并且不用进行抄写私钥什么的操作了。

如果需要更高的加密要求，可以用[离线钱包（冷钱包）](offline-wallet.md)的方式。

