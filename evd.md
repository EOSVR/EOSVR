## EVD （eoslocktoken）

EVD 合约，实现了互锁、限制转账、延时转账、交易锁等功能。

合约代码在目录 locktoken 下。

#### 功能及示例

普通转账功能与 eosio.token 一致。 下面这些是在 transfer 命令中的新功能：

1，允许给自己转帐的命令，这将会：

  a，刷新当前帐号，如果有延期到达的token到期了，将会刷新token量；
  
  b，如果在 memo 中有 #LIMIT# ，将设置每个月可以转出多少百分比的token，最小值是1，表示每个月只能转出 1% 。为了防止将限制设大后转出，限制只能设为比当前更小的数；

示例:

```
# account1将自己的限制设为每个月最多转出一半token。
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account1","quantity":"0.0000 EVD","memo":"#LIMIT#50"}' -p account1
```

2, 给其他人转账时，如果加上 #LOCK#，将锁定对方的token，而不是转账；

示例:
```
# account1 锁了 account2 的 100 EVD
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account2","quantity":"100.0000 EVD","memo":"#LOCK# I do not agree with your comments."}' -p account1
```

4, 给其他人转账时，如果加上 #UNLOCK#，将解锁对方的代币，而不是转账；

示例：
```
# account1 解锁了 account2 的 100 EVD
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account2","quantity":"100.0000 EVD","memo":"#UNLOCK# OK"}' -p account1
```
注意: 只能 unlock 已经 lock 了的代币。

5, 给其他人转账时，如果加上 #TIME#，这笔转账将一段时间后才到账；

示例：
```
# 这100 EVD 将在1天后到账
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account2","quantity":"100.0000 EVD","memo":"#TIME# 86400"}' -p account1
```

6, 所有可以被转账(或投票)的代币 = 当前代币 - eoslocktoken 中记录的被锁定代币；

7, 如果 A 锁定了 B，B也可以给A 90%的代币，并移除这个锁。memo 中加上 #CONFIRM# 即可；

示例：

```
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account2","quantity":"0.0001 EVD","memo":"#CONFIRM#"}' -p account1
```

这可以用在一些场所的消费中，店家将客人应支付的款项直接锁定。客人只要同意这些支付信息就可以了。

8，如果需要给一个子链的传输帐号做抵押，那么给 eoslocktoken 转账即可，memo中填写子链的 chain_id：

```
cleos push action eoslocktoken transfer '{"from":"account1", "to":"eoslocktoken","quantity":"1.0000 EVD","memo":"b6a3a2e75f6fc47e7ef8b413ae4ee6eb3a8fefcd01c0b0ecdf688563cfa5f493"}' -p account1
```

注意：一个帐号要抵押的子链 chain_id 必须第一次时写对，因为之后无法更改，再转账给 eoslocktoken 只会增加抵押的数量。

<div id="hash"></div>
9，#HASH# 表示哈希时间锁，设置一笔带密码的交易。在一段时间内任何人只要公布了密码，交易就会成功。否则，任何人都可以在时间到后回滚交易。

```
# account1 发送 account2 10个EVD，1天到期
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account2","quantity":"10.0000 EVD","memo":"#HASH#2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824,86400"}' -p account1

# 揭示了密码，交易完成 (任何人都可以揭示)
cleos push action eoslocktoken confirm '{"from":"account1", "to":"account2","key":"hello,world"}' -p account3

# 或者时间到以后，有人取消了交易 (任何人都可以取消)
cleos push action eoslocktoken confirm '{"from":"account1", "to":"account2","key":""}' -p account3

```


### 限制加权

当用户给自己的帐号设置 50% 以下的限制时，账户的代币不会被立刻取出，这时的投票比起那些随时可以被转走的帐号，有更大的加权。具体如下：
 ( 具体代码在合约 comments 中)

```

25 - 50: 1;

11 - 24: 2;

5 - 10: 3;

2 - 4: 9 - limit;

1: 10;

Other: 0.1;

```

#### 状态检查

用户数据共有三个表: lockss， timelockss 和 depositss，可用类似如下的命令进行查询。

```
cleos get table eoslocktoken account1 lockss

cleos get table eoslocktoken account1 timelockss

# 这个命令不包括被锁的代币
cleos get currency balance eoslocktoken account1

# 被锁的代币查询 (查询单个需要用 -L 和 -U 参数)
cleos get table eoslocktoken eoslocktoken lockss

# 查询抵押EVD的子链 (查询单个需要用 -L 和 -U 参数)
cleos get table eoslocktoken eoslocktoken depositss
```

#### 合约代币分配

详见 [EVR/EVD分配方案](evd_distribute.md)
