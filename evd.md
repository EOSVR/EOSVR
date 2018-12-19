## EVD （eoslocktoken）

EVD contract, can lock each other, limited transfer, delayed transfer, hash time lock for transfer.

Contract code is in folder locktoken.

#### Features and Examples

Normal transfer is same as eosio.token . The following are new features:

1, When change to self, it will:

  a, Refresh current account, if there is any delayed transfer ready, it will update the amount of token;
  
  b, Write #LIMIT#XXX in memo of transfer, will set the limitation percent of transfer per month. The value is 1-50. Minimum is 1, at this time, can only transfer out 1% tokens per month. To prevent an account change it to a big number and break the restriction, this value can only set to a smaller value. And when the limitation is 1, it can not be set anymore.

Example:

```
# account1 set it can only transfer half of its token per month.
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account1","quantity":"0.0000 EVD","memo":"#LIMIT#50"}' -p account1
```

2, When transfer to another account, use #LOCK# in front of memo to lock the token of another, instead of transfer;

Example:
```
# account1 lock 100 EVD of account2
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account2","quantity":"100.0000 EVD","memo":"#LOCK# I do not agree with your comments."}' -p account1
```

3, When transfer to another account, use #UNLOCK# in front of memo to unlock the token of another, instead of transfer;

Example:
```
# account1 unlock 100 EVD of account2
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account2","quantity":"100.0000 EVD","memo":"#UNLOCK# OK"}' -p account1
```

Note: can only unlock the locked token. If there is no enough locked token, it will fail.

4, When transfer to another account, use #TIME# in front of memo to transfer the token of another with a period of delay;

Example:
```
# These 100 EVD will be ready after 1 day.
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account2","quantity":"100.0000 EVD","memo":"#TIME# 86400"}' -p account1
```

5, Current liquid (can transfer or vote) token = {all tokens} - {locked token recording in contract (eoslocktoken) } ;

6, If A lock B, B can confirm this lock and give 90% tokens to B by adding "#CONFIRM#" in front of memo;

Example:
```
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account2","quantity":"0.0001 EVD","memo":"#CONFIRM#"}' -p account1
```

This may use in some shop. Shop can lock EVD of custom and custom confirm to pay.

8, If need to burn EVD and issue them in a side-chain, transfer EVD to eoslocktoken with chain_id of side-chain written in memo.

```
cleos push action eoslocktoken transfer '{"from":"account1", "to":"eoslocktoken","quantity":"1.0000 EVD","memo":"b6a3a2e75f6fc47e7ef8b413ae4ee6eb3a8fefcd01c0b0ecdf688563cfa5f493"}' -p account1
```

Note: One account can only endorse for one side-chain. And must write correct chain id at the first time. It can not change. Transfer to eoslocktoken again will only increase the amount of EVD burned.

<div id="hash"></div>
9, Put "#HASH#" in front of memo to open a hash time lock transfer. It will not succeed until someone reveal the password which can calculate into checksum of hash. If timeout, anyone can rollback it.

```
# account1 transfer account2 10 EVD with a hash lock of 1 day.
cleos push action eoslocktoken transfer '{"from":"account1", "to":"account2","quantity":"10.0000 EVD","memo":"#HASH#2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824,86400"}' -p account1

# account3 reveal the key and resolve the transfer (Anyone can reveal, include account1 or account2)
cleos push action eoslocktoken confirm '{"from":"account1", "to":"account2","key":"hello,world"}' -p account3

# Or timeout, account3 cancel it (Anyone can cancel)
cleos push action eoslocktoken confirm '{"from":"account1", "to":"account2","key":""}' -p account3

```


### More weight for limitation

When a user set its transfer limitation, its token can not transfer completely to another account. So it get more weight in vote in discuss contract. The weight as the following:
 ( Code is in [discuss contract](comment.md) )

```

25 - 50: 1;

11 - 24: 2;

5 - 10: 3;

2 - 4: 9 - limit;

1: 10;

Other: 0.1;

```

#### Check Status

There are five tables in contract: lockss， timelockss, depositss, hashlockss, hashss, should check as the following:

```
cleos get table eoslocktoken account1 lockss

cleos get table eoslocktoken account1 timelockss

# This will not include locked token by another account
cleos get currency balance eoslocktoken account1

# Locked token (May need -L and/or -U)
cleos get table eoslocktoken eoslocktoken lockss

# Check burned token for side-chain (May need -L and/or -U)
cleos get table eoslocktoken eoslocktoken depositss
```

#### EVD Distribution

[EVR/EVD distribution](evd_distribute.md)

