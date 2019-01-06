## 用户数据规则

[English](id.md)

为了让用户可信，一个用户的数据需要有如下部分：

- 用户名[@侧链]：作为标识，让大家可以找到我；

- 用户对自己的介绍：证明这个账户是我的，比如可以写：我在北京鼓楼大街XX号附近卖烧饼，我穿着蓝色大衣；

- 用户头像：给自己或者店铺拍个照片，让大家一眼能认出我；

- 信用点及转账限制：有信用点，并且还不能全部转走。那么，如果做了坏事，受害者就可以将这个帐号的信用点进行锁定；


### 全链用户统一名称

为了多链的用户名统一，定义了下面的方式：

- 统一用户名：[链中帐号名]@[侧链连接者帐号名]。在主链中，没有@以及后面的字符串；

- 为了简化，使用 "_" 符号来表示帐号中的重复字符。a_b 表示：abbbb... 直到填满12个字符。

- 如果 "_" 后面没有字符，默认为字符a；即：a_ 与 _a 的效果一致

注意：这个简化只在网页等面向用户的情况下使用，在EOS合约中仍然使用原来的12位字符串；

比如：

主链中的帐号 "aaa111111111" 的统一用户名为： "aaa_1"

一条侧链的连接者为 link11111111, 侧链中的帐号为 "hello2222222", 那么它的统一用户名为："hello_2@link_1"

一条侧链的连接者为 link33333333, 侧链中的帐号为 "xiaomingming", 那么它的统一用户名为："xiao_ming@link_3"

一条侧链的连接者为 link12121212, 侧链中的帐号为 "xiaozhangzha", 那么它的统一用户名为："xiao_zhang@link_12"


### 在自我介绍中使用链接

为了把用户们连接起来，一个帐号可以引用别的帐号或者别的链接。只要把下面的写在单独的一行中即可：

- @[统一的用户名]

- http(s)://XXX

Example:

@eosvrcomment@eoslinker111
https://www.baidu.com

```
cleos push action eosvrcomment comment '{"from":"index1111111", "to":"index1111111", "memo":"Index (索引): \n\n@eoslinker111 Linker of the first EOS side-chain in testing. 第一条在实验中的EOS侧链。\n\n@eosvrcomment Contracts of comment and self-introduction. 评论及自我介绍用的合约。\n\n@guest1111113@eoslinker111 A test account in EOS side-chain. 一个在EOS侧链上的测试帐号。\n\nTrust solution Introduction:\nhttps://github.com/EOSVR/EOSVR/blob/master/intro.md\n\n信用系统介绍：\nhttps://github.com/EOSVR/EOSVR/blob/master/intro-cn.md"}' -p index1111111
```


### 更多信息

[信用解决方案介绍](intro-cn.md)

[用EVD来解决信用解决方案](README-cn.md)

[跨链介绍](sidechain-cn.md)

