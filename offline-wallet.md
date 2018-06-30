### Offline wallet

Offline wallet can allow your store your private key in one smartphone in offline mode.
And can sign the transaction in another online smartphone by offline wallet.

Download: [EOSVR Wallet 0.2](https://github.com/EOSVR/EOSVR/blob/master/wallet-cn.md)

The following are steps.

#### Offline wallet

1, Disconnect network;

2, In page "Import User", click "Rand" button to generate random private key;

3, Click "Import offline", will create a role with name "offline N";

4, Click the "..." button at the right of "Copy" button. Click "Copy PublicKey";

It will show a QRCode;


#### Online wallet

1, In page "Import User", import a user that have some token in it. Maybe you can try the guest account by "Import Guest3";

2, Select guest1111113 , and click "Scan Code";

3, Scan the QRCode of offline phone. It will take you to page "Register User".

4, Enter the UserName and make sure it is OK. Click "Create" to create it.

5, OK. The observer account created.

Currently, the observer account only support:

- Transfer to another account;

- Buy / Sell RAM;

- Delegate / Undelegate Bandwidth and CPU;

Can NOT create user from an observer account.


#### Transfer

1, When transfer to other account, click "Trade" in main page;

2, Enter the account that will transfer to, enter the amount of token to transfer;

3, Click "Confirm", enter the trade password.

4, After QRCode of transaction appeared, use the offline phone to scan the QRCode;

5, Offline phone will show a QRCode that is the signature of this transaction;

6, Use your online phone, click side to disapear the QRCode, and click "Scan code" to scan the signature;

7, Wait the transfer complete.

