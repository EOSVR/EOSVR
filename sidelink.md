## EVD Side-chain Solution

#### Introduction

Trust system may need several Giga accounts with several millions tps (transaction per seconds), but currently tps of EOS mainnet is only 4000. To increase tps, EVD use side-chain solution for it.

Side-chain use the EVD in an account in EOS mainnet to endorse the side-chain is limited trustable, and increase the tps of whole EOS network.

Like EOS mainnet, Side-chains are controlled by BPs (Block Producer) too. And all across-chain transfers are controlled by linker. The linker can be several in a side-chain. They must have accounts in both chains. 

Linker will check if there are across-chain transfer and work in both chains to complete them. To prove the correction of transfer, will use [Hashed Time Lock Contract(HTLC)](#Hashed Time Lock Contract) to sync the transfer.

To a simple EOS chain, it will be very low for a user. Example: 30K RAM and 10 transaction per day will only cost 0.02$ in one year. Link lots of EOS chain in this way, and we can setup an wide-spread, low-cost trust system.


#### Steps of Setup

1, Setup of side-chain is same as main-net. Side-chain is also controlled by BPs too;

2, BPs of side-chain have accounts with same name in mainnet. These accounts have EVD in it with transfer limitation to endorse the side-chain;

3, Account A in mainnet can apply for linker by:

  a, In mainnet, transfer several EVD to account eoslocktoken (EVD contract). The memo of transfer is chain_id of side-chain. Because eoslocktoken will be locked, no one can transfer EVD out of it except mainnet BPs. It is a [one-way seg](#QA)；
  
  b, In side-chain, BPs use eoslocktoken issue same amount of EVD to account A, and mark A as a linker of this side-chain;
  
  Note: account A can not burn all EVD. It must have half EVD to support the across-chain transfer.
  
4, Linker A deploy a server with its private-keys and run the following:

  a, Check if there is a transfer to it in mainnet with [Hash Time Lock](#Hashed Time Lock Contract). If yes, create a transfer with same Hash Time Lock;
  
  b, Check if someone confirm the transfer A created. If yes, confirm its source transfer with the same password;
  
  c, Check if any transfer A created is timeout. If yes, confirm it is cancelled;
  
  d, Check and run a-c in side-chain too.
  

5, How to find side-chains:

  a, Show all linker with side-chain id : ``` cleos get table eoslocktoken eoslocktoken depositss ```

  b, Get side-chain address in linker's description in eosvrcomment: ``` cleos get table eosvrcomment account1 commentss ```


These are scripts to create side-chains.


#### Scripts to create side-chains
  
Please setup the following manually:

- Setup a EOS chain;

- BPs of EOS side-chain have EVD and limitation;

- Linker send(burn) EVD to eoslocktoken and set its description (eosvrcomment);

- BPs of side-chain issue EVD to linker in side-chain;
  

Run linker script in linux（tested in CentOS 7.3;

```
# Change config.js , write correct private keys , main-net address and side-chain address;

# Run linker
node linker.js

# DONE

```

(Script is in develop)

  
#### Across-chain transfer

If A is linker, B in side-chain want to transfer EVD to C in mainnet. Steps are following:

1, In side-chain, B transfer to A with memo "#HASH#{HASH},{timeout},{DEST}";

2, Linker A finds the transfer. In main-chain, A transfer to C with same HASH;

3, B found there is a transfer A -> C in mainnet, and B confirm this transfer with its password of Hash Lock;

4, Linker A finds the confirm of transfer A->C, and A get the password from the confirmation and confirm the transfer B->A in side-chain; All transfer are completed;

5, If in step 3, B do not confirm. Both transactions will be cancelled by linker A;

More info in [eoslocktoken](evd.md).


#### Hashed Time Lock Contract

- Before a transaction, a user use a random text as password, and hash it to create a hash code;

- User put this hash code to a transaction and promise the transaction will confirm only when the password is revealed in a certain time;

- Other related transactions can also use this hash code and promise;

- The first user can wait all related transactions are ready, then reveal the password. After the password is revealed, all users can confirm the transaction.


[More info: EVD](evd.md#hash)。


#### Verification of side-chain

Everyone can verify a side-chain before use it. The verification like the following:

- Correction contracts. Check the hash code of eoslocktoken and make sure they are same as main-chain. Command: ```cleos get code eoslocktoken```

Note: If in side-chain have deployed other contracts in eoslocktoken, side-chain must prove these code are not malicious. It is better not deploy other contract in eoslocktoken.

- Check all EVD issued by eoslocktoken, is equal or smaller than all linkers send to eoslocktoken with same side chain id.

Main chain
```cleos get table eoslocktoken eoslocktoken depositss```

Side chain
```cleos get table eoslocktoken EVD stat```


#### Exception

If BPs in side-chain issue EVD more than burned in main-chain, these EVD will damage linkers and users of side-chain. But this will not influence main-chain. At this time:

- Lock the EVD of BPs of side-chain;

- Linker will stop the across-chain transfer;

- Other account in main-chain can copy the record of side-chain, rollback the wrong issue operations, and reopen a new side-chain;


#### Other block-chain token as side-chain

Because BTC, ETH is slow to transfer, it is possible to help customs to transfer small amount of tokens in side-chain of EOS to make it faster. Big amount of token transfer can still use the old way.

Steps like the following:

- Account X1 in EOS chain have many EVD and limitation of transfer set. It is limited trustable;

- At ETH-chain, owner of X1 have an account: X2;

- In ETH-chain, user A2 want to transfer some ETH to user A1 in EOS-chain. A2 can send ETH to X2, and X1 find this transfer and can send same EETH to A1;

- If X do not transfer correctly, A can lock its EVD in eos main-chain;

In block-chains that do not support hash time lock contract, we can also use EVD to endorse them.


#### QA

Q: Why one-way peg, why not two-way peg ?

A: Two-way peg need an account that have privilege to send back. It is a centralized account and hard to decide who can own this account.

Q: Why use EVD as across-chain token? Why not use EOS?

A: EVD support many features that EOS do not support, such as: lock each other. This make it easy to use in across-chain transfer.
And EOS is used for vote, CPU and RAM. A side-chain also need EOS to calculate CPU, RAM. They have different price and hard to transfer across-chain.

Q: Where is the script to build side-chain?

A: In development. Plan to release preview version at the end of 2018.

