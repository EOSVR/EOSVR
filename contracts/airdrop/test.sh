#!/bin/sh

npm test || exit

cll set contract eosvrairdrop ../airdrop/

cll push action eosvrairdrop reg '{"from":"wsdfz5"}' -p wsdfz5

echo OK



