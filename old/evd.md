[中文](evd-cn.md)

### EVD Token

To strength the credit of token, add functions based of eosio.token as following:

1, Support delay transfer token. Example: A can transfer token to B and set B can receive it tomorrow.

2, Support lock token by others. Example: A can use 10 EVD to lock 10 EVD of B. After locked, B can not transfer these 10 EVD to other, and can not use it to lock other.

3, Support transfer limition per day. Example: A can set the limitation of EVD transfer to 10000 EVD per day. Also can set the limitation to 1% EVD of total EVD per day;

EVD can exchange to EVR by 1:1. Just send EVD or EVR to contract: evrexchanges, another token will return.

EVD contract: eoslocktoken is testing now. Will release at about middle of October.
