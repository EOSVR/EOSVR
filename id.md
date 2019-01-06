## Unified Account Name of Across-Chain and Simplify

[中文](id-cn.md)

To make an account trustworthy, it needs the following:

- ID[@SideChain Linker Account]: It is an identity to let others find me;

- Self Introduction: Prove it is my account, such as: I am a candy seller at 9 Street, Brooklyn, New York. And I am in blue;

- Portrait: Takes a photo of me or my shops, and let others can know me quickly;

- Trust points and limitation of transfer: If I have trust points and can not transfer all of them, and if I do evil, victims can lock my trust points to revenge.


### Unify the account name

To unify the name of across chain accounts, defines the following:

- Unified name: [Account Name]@[Side Chain Linker Name]. In main-chain, do not have "@" and following characters;

- To simplify, use "_" to represent the repeated characters. Example: a_b represent abbbbbb... till fill 12 characters;

- If "_" do not follow any character, default character is a. It said "a_" is same as "_a".

Note: This is only used in website or app. Do NOT use in EOS contracts. In contracts, still use the old way.

Example:

The unified name of account "aaa111111111" in main chain is "aaa_1";

Account "hello2222222" is in a side chain which linker is "link11111111". Its unified name is "hello_2@link_1";

Account "xiaomingming" is in a side chain which linker is "link33333333". Its unified name is "xiao_ming@link_3";

Account "xiaozhangzha" is in a side chain which linker is "link12121212". Its unified name is "xiao_zhang@link_12";

### Links in description

To link accounts together, account can refer to other accounts or links. Just write the following in a single line:

- @[Unified account name]

- http(s)://XXX

Example:

@eosvrcomment@eoslinker111
https://www.google.com

```
cleos push action eosvrcomment comment '{"from":"index1111111", "to":"index1111111", "memo":"Index (索引): \n\n@eoslinker111 Linker of the first EOS side-chain in testing. 第一条在实验中的EOS侧链。\n\n@eosvrcomment Contracts of comment and self-introduction. 评论及自我介绍用的合约。\n\n@guest1111113@eoslinker111 A test account in EOS side-chain. 一个在EOS侧链上的测试帐号。\n\nTrust solution Introduction:\nhttps://github.com/EOSVR/EOSVR/blob/master/intro.md\n\n信用系统介绍：\nhttps://github.com/EOSVR/EOSVR/blob/master/intro-cn.md"}' -p index1111111
```

### More Information

[Trust solution](intro.md)

[Trust solution - EVD](README.md)

[Sidechain](sidechain.md)

