## EOSVR Wallet

[中文版](wallet-cn.md)

EOSVR wallet is a EOS wallet changed from the demo version of EOSVR. It is a complete decentralized wallet. No server except EOS mainnet needed. It provided:

- Create lots of EOS Accounts

- [Offline mode](offline-wallet.md) if want more safety

- Can use common user+password style, instead of private key system which is hard to use by normal users

- Easy to change password (private key)

- Transfer EOS

- Resources EOS Management (CPU, Net, RAM). Including unlock genesis account, and manual refund the account which auto-refund failed

- Airdrop for [EVR](evr.md)


#### Installation

IOS is Enterprise APPS. In Settings -> General -> Device Management, need to authorize the APP.

- [IOS](https://evr.oss-cn-zhangjiakou.aliyuncs.com/setup/download.html)

- [Github IOS](http://eosnames.shop/download.html)


Android

- [Android APK](http://evr.oss-cn-zhangjiakou.aliyuncs.com/setup/eosvr.apk)

- [Github Android APK](https://github.com/EOSVR/EOSVR/raw/master/bin/eosvr.apk)


Mac

- [Mac](http://evr.oss-cn-zhangjiakou.aliyuncs.com/setup/EOS_VR.dmg)

- [Github Mac](http://github.com/EOSVR/EOSVR/raw/master/bin/EOS_VR.dmg)


Windows

- [Windows](http://evr.oss-cn-zhangjiakou.aliyuncs.com/setup/eosvr.zip)

- [Github Windows](http://github.com/EOSVR/EOSVR/raw/master/bin/eosvr.zip)



#### Test account

Can use an account guest1111113 for test.

May transfer a few EOS tokens to this account at times for testing. Use it to create your account freely.


#### Safety

- Use offline mode to avoid the loss private key.

- EOSVR do NOT have any server except web servers in web.

- This APP will NOT connect to any server except the EOS mainnet API site which you can change in settings. So it is impossible for EOSVR to stole custom's private key.

- You can change your password in APP if you are afraid that maybe someone have stolen your private key.
When you change password, the APP will create a new private key with your username and password and replace
the old one. And if you lose your private key, you can still recover it from your username and password.


#### Private Key and Password

In APP, private key is created by username + password + salt (settings). When you enter the same username + password in another iPhone or Android device which have the same salt, you still can get your account. It is easy to transfer your account between your devices and do not need to remember your private key any more.

Although, it is not so safe as original private key mode. It is much easier and user-friendly to customs.

For the people who require high safety, they still can use the [offline private key mode](offline-wallet.md).
