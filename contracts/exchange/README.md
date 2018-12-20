## EVR Exchange to other tokens 1:1

EVD can exchange by EVR 1:1 when transfer EVR or EVD to evrexchanges.

Example:

```

cleos push action eosvrtokenss transfer '{"from":"account1", "to":"evrexchanges","quantity":"100.0000 EVR","memo":""}' -p account1

cleos push action eoslocktoken transfer '{"from":"account1", "to":"evrexchanges","quantity":"100.0000 EVD","memo":""}' -p account1

```



