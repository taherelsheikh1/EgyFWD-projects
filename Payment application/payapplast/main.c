#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"../card/card.h"
#include"../terminal/terminal.h"
#include"../server/server.h"
#include"../application/application.h"
EN_cardError_t carderrorstate;
ST_cardData_t carddatetest;
EN_terminalError_t terrortest;
ST_terminalData_t cardexpiredtest;
ST_transaction_t tttt;
float maxAmount = MAX_AMOUNT;
//#define _LIST_TRANSACTION
int main() {

	appstart();
	/*IF WE DEFINE _LIST_TRANSACTION THIS WILL BE LIST ALL THE TRANSACTONS IN transaction-DB.TXT*/
#ifdef _LIST_TRANSACTION
	listSavedTransactions();
#endif // _LIST_TRANSACTION

	return 0;
	
}



