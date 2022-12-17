#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"../card/card.h"
#include"../terminal/terminal.h"
#include"../server/server.h"
#include"../application/application.h"

ST_terminalData_t cardexpiredtest;
ST_cardData_t carddatetest;
ST_transaction_t tttt;
EN_transState_t tsts;

uint8_t STATEOFTRANSACTION[5][30] = { "APPROVED", "DECLINED_INSUFFECIENT_FUND", "DECLINED_STOLEN_CARD", "FRAUD_CARD", "INTERNAL_SERVER_ERROR" };

EN_transState_t recieveTransactionData(ST_transaction_t* transData) {
	FILE* accounts_DB = NULL;

	accounts_DB = fopen("../database/Accounts-DB.txt", "r+");
	if (accounts_DB == NULL)
	{
		printf("\nError opening file.\n");
		transData->transState = INTERNAL_SERVER_ERROR;
		return INTERNAL_SERVER_ERROR;
	}
	uint8_t hos[20] = { 0 }, sos[8] = { 0 }, fos[32] = { 0 };
	float ln;
	do {
		fgets(hos, 17, accounts_DB);

		if (!strcmp(transData->cardHolderData.primaryAccountNumber, hos)) {
			fseek(accounts_DB, 2, SEEK_CUR);
			fgets(sos, 8, accounts_DB);
			if (!strcmp(sos, "blocked")) {
				transData->transState = DECLINED_STOLEN_CARD;
				return DECLINED_STOLEN_CARD;
			}
			else {
				fseek(accounts_DB, 2, SEEK_CUR);
				fgets(fos, 32, accounts_DB);
				int i = strlen(fos) + 1;
				ln = atof(fos);
				if (ln >=cardexpiredtest.transAmount) {

					ln = ln - (cardexpiredtest.transAmount);

					transData->currentbalance = ln;
					
					_gcvt(ln, strlen(fos), fos);

					fseek(accounts_DB, -i, SEEK_CUR);
					
					fputs(fos, accounts_DB);
				}
				else {

					transData->transState = DECLINED_INSUFFECIENT_FUND;

					return DECLINED_INSUFFECIENT_FUND;
				}
			}
			transData->transState = APPROVED;
			return APPROVED;
		}



	} while (!feof(accounts_DB));

	transData->transState = FRAUD_CARD;
			return FRAUD_CARD;

	fclose(accounts_DB);
}
EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_transaction_t* accountRefrence) {
	FILE* accounts_DB = NULL;

	accounts_DB = fopen("../database/Accounts-DB.txt", "r");
	uint8_t hos[20] = { 0 };

	do {
		fgets(hos, 17, accounts_DB);

		if (!strcmp(cardData->primaryAccountNumber, hos)) {
			strcpy(accountRefrence->cardHolderData.primaryAccountNumber, cardData->primaryAccountNumber);

			return SERVER_OK;
		}
	
			

	} while (!feof(accounts_DB));
	strcpy(accountRefrence->cardHolderData.primaryAccountNumber, cardData->primaryAccountNumber);

	return ACCOUNT_NOT_FOUND;

	fclose(accounts_DB);

}
EN_serverError_t isBlockedAccount(ST_transaction_t* accountRefrence) {
	FILE* accounts_DB = NULL;
	accounts_DB = fopen("../database/Accounts-DB.txt", "r");

	uint8_t hos[20] = { 0 }, sos[8] = { 0 };
	do {
		fgets(hos, 17, accounts_DB);

		if (!strcmp(accountRefrence->cardHolderData.primaryAccountNumber, hos)) {
			fseek(accounts_DB, 2, SEEK_CUR);
			fgets(sos, 8, accounts_DB);
		}
			if (!strcmp(sos, "blocked")) {
				accountRefrence->transState = BLOCKED_ACCOUNT;

				return BLOCKED_ACCOUNT;
			}
			
			
	} while (!feof(accounts_DB));
	accountRefrence->transState = SERVER_OK;
	
		return SERVER_OK;
				
	fclose(accounts_DB);
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_transaction_t* accountRefrence) {
	FILE* accounts_DB = NULL;

	accounts_DB = fopen("../database/Accounts-DB.txt", "r");
	
	uint8_t hos[20] = { 0 }, fos[32] = { 0 };
	float ln=0;
	do {
		fgets(hos, 17, accounts_DB);

		if (!strcmp(accountRefrence->cardHolderData.primaryAccountNumber, hos)) {
			fseek(accounts_DB, 11, SEEK_CUR);

			fgets(fos, 32, accounts_DB);

			ln = atof(fos);
			if (ln >= termData->transAmount) {
				accountRefrence->transState = SERVER_OK;

				return SERVER_OK;
			}
			else {
				accountRefrence->transState = LOW_BALANCE;

				return LOW_BALANCE;
			}
		}
	} while (!feof(accounts_DB));
	fclose(accounts_DB);
}
EN_serverError_t saveTransaction(ST_transaction_t* transData) {
	FILE* transactions_DB = NULL;
	transactions_DB = fopen("../database/transactions-DB.txt", "a");
	fputs("\n#########################", transactions_DB);
	fprintf(transactions_DB, "\nTransaction Date:%s",cardexpiredtest.transactionDate);
	fprintf(transactions_DB, "\nTransaction Amount:%.2f", cardexpiredtest.transAmount);
	//uint8_t STATEOFTRANSACTION[5][30] = { "APPROVED", "DECLINED_INSUFFECIENT_FUND", "DECLINED_STOLEN_CARD",
	//"FRAUD_CARD", "INTERNAL_SERVER_ERROR" };
	fprintf(transactions_DB, "\nTransaction State:%s", STATEOFTRANSACTION[tsts]);
	fprintf(transactions_DB, "\nTerminal Max Amount:%.2f", cardexpiredtest.maxTransAmount);
	fprintf(transactions_DB, "\nCardholder Name:%s", carddatetest.cardHolderName);
	fprintf(transactions_DB, "\nPan:%s", carddatetest.primaryAccountNumber);
	fprintf(transactions_DB, "\nCard Expiration Date:%s", carddatetest.cardExpirationDate);
	fputs("\n#########################", transactions_DB);
	exit(1);
}
void listSavedTransactions(void) {
	FILE* list = NULL;
	uint8_t str[30];
	list = fopen("../database/transactions-DB.txt", "r");
	while (!feof(list))
	{
		fgets(str, 29, list);
			printf("%s", str);
	}
	fclose(list);
}

void recieveTransactionDataTest(void) {
	printf("Tester Name : Taher Elsheikh ");
	printf("\nFunction Name : recieveTransactionData");

	/*
	 test1 ="1231231231231231"// not found in DB
	 test2 ="2222222222222222"// account balance is 2500.00 and transactionamount is 3000.00 (DECLINED_INSUFFECIENT_FUND)
	 test3 ="2525252525252525"//blocked account 
	 test4 ="1313131313131313"//account balance is 5000.00 and transactionamount is 3000.00 and running (APPROVED)
	*/
	EN_transState_t errortest;
	errortest = recieveTransactionData(&tttt);
	if (errortest == FRAUD_CARD) {
		printf("\nTest Case 1 :account did'nt exist ");
		printf("\nInput Data :%s", carddatetest.primaryAccountNumber);
		printf("\nExpected Result :FRAUD_CARD");
		printf("\nActual Result :FRAUD_CARD");
	}
	else if ((errortest == DECLINED_INSUFFECIENT_FUND)) {
		printf("\nTest Case 2 :transaction declined due insuffecient funds");
		printf("\nInput Data :%.2f", cardexpiredtest.transAmount);
		printf("\nExpected Result :DECLINED_INSUFFECIENT_FUND");
		printf("\nActual Result :DECLINED_INSUFFECIENT_FUND");
	}
	else if ((errortest == DECLINED_STOLEN_CARD)) {
		printf("\nTest Case 3 :this card issued to be stolen ");
		printf("\nInput Data :%s", carddatetest.primaryAccountNumber);
		printf("\nExpected Result :DECLINED_STOLEN_CARD");
		printf("\nActual Result :DECLINED_STOLEN_CARD");
	}
	else if( (errortest == APPROVED)) {
		printf("\nTest Case 4 :transaction prosses is ok");
		printf("\nInput Data :%s", carddatetest.primaryAccountNumber);
		printf("\nExpected Result :APPROVED");
		printf("\nActual Result :APPROVED");
	}
	else if( (errortest == INTERNAL_SERVER_ERROR)) {
		printf("\nTest Case 4 :error!! in saving transaction");
		printf("\nInput Data :%s", carddatetest.primaryAccountNumber);
		printf("\nExpected Result :INTERNAL_SERVER_ERROR");
		printf("\nActual Result :INTERNAL_SERVER_ERROR");
	}
	else { ; }

}

void isValidAccountTest(void) {
	EN_serverError_t errortest;

	printf("\nTester Name : Taher Elsheikh ");
	printf("\nFunction Name : isValidAccount ");

	errortest = isValidAccount(&carddatetest, &tttt);

	if (errortest == ACCOUNT_NOT_FOUND) {
		printf("\nTest Case 1 :account ot found in dataase");
		printf("\nInput Data :%s", tttt.cardHolderData.primaryAccountNumber);
		printf("\nExpected Result :ACCOUNT_NOT_FOUND");
		printf("\nActual Result :ACCOUNT_NOT_FOUND");
	}
	errortest = isValidAccount(&carddatetest, &tttt);
	if (errortest == SERVER_OK) {
		printf("\nTest Case 2 :account is exist ");
		printf("\nInput Data :%s", tttt.cardHolderData.primaryAccountNumber);
		printf("\nExpected Result :SERVER_OK");
		printf("\nActual Result :SERVER_OK");
	}

}
void isBlockedAccountTest(void) {
	EN_serverError_t errortest;

	printf("\nTester Name : Taher Elsheikh ");
	printf("\nFunction Name : isBlockedAccount ");

	errortest = isBlockedAccount(&tttt);

	if (errortest == BLOCKED_ACCOUNT) {
		printf("\nTest Case 1 :this account is blocked");
		printf("\nInput Data :%s", tttt.cardHolderData.primaryAccountNumber);
		printf("\nExpected Result :BLOCKED_ACCOUNT");
		printf("\nActual Result :BLOCKED_ACCOUNT");
	}
	errortest = isBlockedAccount(&tttt);
	if (errortest == SERVER_OK) {
		printf("\nTest Case 2 :this account is running ");
		printf("\nInput Data :%s", tttt.cardHolderData.primaryAccountNumber);
		printf("\nExpected Result :SERVER_OK");
		printf("\nActual Result :SERVER_OK");
	}

}
void isAmountAvailableTest(void) {
	EN_serverError_t errortest;

	printf("\nTester Name : Taher Elsheikh ");
	printf("\nFunction Name : isAmountAvailable ");

	errortest = isAmountAvailable(&cardexpiredtest ,&tttt);

	if (errortest == LOW_BALANCE) {
		printf("\nTest Case 1 :your balance is insufficient");
		printf("\nInput Data :%f", cardexpiredtest.transAmount);
		printf("\nExpected Result :LOW_BALANCE");
		printf("\nActual Result :LOW_BALANCE");
	}
	errortest = isAmountAvailable(&cardexpiredtest, &tttt);
	if (errortest == SERVER_OK) {
		printf("\nTest Case 2 :your balance is ok ");
		printf("\nInput Data :%f", cardexpiredtest.transAmount);
		printf("\nExpected Result :SERVER_OK");
		printf("\nActual Result :SERVER_OK");
	}

}