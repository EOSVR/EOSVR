## EOSVR Airdrop

1, Prepare from base account

```
cleos set account permission eosvrairdrop active '{"threshold": 1,"keys": [{"key": "EOS7r2Aa9BnBoR6g4HFy1KiVHhgosQosqbQ4KLVrhzeW8br4dujXw","weight": 1}],"accounts": [{"permission":{"actor":"eosvrairdrop","permission":"eosio.code"},"weight":1}]}' owner -p eosvrairdrop@owner
```

2, Other users transfer EOS token to eosvrairdrop


3, Get current register accounts

```
cleos get table eosvrairdrop eosvrairdrop balance
```

4, Do airdrop by eosvrmanager

The following will airdrop 320 EVR to gggggggggggg.

```
cleos push action eosvrairdrop airdrop '{"account":"gggggggggggg","amount":3200000}' -p eosvrmanager
```

5, Check current currency

```
cleos get currency balance eosvrtokenss gggggggggggg
```



