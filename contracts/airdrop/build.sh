#!/bin/sh

npm test || exit

cll set contract eosvrairdrop ../airdrop/ || exit

echo OK



