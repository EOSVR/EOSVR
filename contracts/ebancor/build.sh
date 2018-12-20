#!/bin/sh

npm test || exit

cleos set contract eosvrmarkets ../ebancor/ || exit

echo OK



