#!/bin/sh

npm test || exit

cleos set contract evrexchanges ../exchange/ || exit

echo OK



