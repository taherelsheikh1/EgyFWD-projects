#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"../card/card.h"
#include"../terminal/terminal.h"
#include"../server/server.h"
#include"../application/application.h"
#include<ctype.h>
ST_terminalData_t terminaldatetest;
ST_terminalData_t cardexpiredtest;
ST_cardData_t carddatetest;

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	uint8_t transdate[15] = { 0 };
	printf("\n");
	scanf(" %s", transdate);
	if (transdate == NULL || strlen(transdate) < 10 || strlen(transdate) > 10 || transdate[2] != '/' || transdate[5] != '/'|| transdate[6] < '2'||
		isdigit(transdate[0]) == 0 || isdigit(transdate[1]) == 0 || isdigit(transdate[3]) == 0 || isdigit(transdate[4]) == 0|| 
		isdigit(transdate[6]) == 0 || isdigit(transdate[7]) == 0 || isdigit(transdate[8]) == 0 || isdigit(transdate[9]) == 0||
		transdate[0]>'3'||((transdate[0]=='3')&&(transdate[1]>'1'))||transdate[3] > '1' || ((transdate[3] == '1') && (transdate[4] > '2')) ||
		((transdate[0] == '0') && (transdate[1] == '0')) ||(transdate[3] == '0') && (transdate[4] == '0')||
		((transdate[6] == '0') && (transdate[7] == '0')&& (transdate[8] == '0')&& (transdate[9] == '0'))) {
		strcpy(termData->transactionDate, transdate);

		return WRONG_DATE;
	}
	else
	{
		strcpy(termData->transactionDate, transdate);
		return TERMINAL_OK;
	}

	
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {

	if ((((termData->transactionDate[8] == cardData->cardExpirationDate[3]) &&(termData->transactionDate[9] == cardData->cardExpirationDate[4]))&&
		(( termData->transactionDate[3] >= cardData->cardExpirationDate[0]) && (termData->transactionDate[4] > cardData->cardExpirationDate[1] )))||
		(termData->transactionDate[8] >=  cardData->cardExpirationDate[3] && termData->transactionDate[9] >= cardData->cardExpirationDate[4])){
		return EXPIRED_CARD ;
	}
	else
	{
		return TERMINAL_OK;
	}
	
}
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
	float amount;
	scanf(" %f", &amount);
	if (amount <= 0)
	{
		termData->transAmount = amount;

		return INVALID_AMOUNT;
	}
	else
	{
		termData->transAmount = amount;
		return TERMINAL_OK;
	}
}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount) {
	if (maxAmount <= 0) {
		termData->maxTransAmount = maxAmount;

	return INVALID_MAX_AMOUNT;
	}
	else
	{
		termData->maxTransAmount = maxAmount;

		return TERMINAL_OK;
	}
}


EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
	if (termData->transAmount > termData->maxTransAmount) {
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}


}

void getTransactionDateTest(void) {
	printf("Tester Name : Taher Elsheikh ");
	printf("\nFunction Name : getTransactionDate ");
	/*
	 test1 = '\0'
	 test2="25/10/25"
	 test3="25-10-2025"
	 test4=" aa/aa/aaaa"
     test5="00/00/0000"
     test6="41/11/2022"
     test7="11/14/2022"
	 test8="12/12/2022"
	*/
	EN_terminalError_t errortest;
	errortest = getTransactionDate(&terminaldatetest);
	if (errortest == WRONG_DATE) {
		printf("\nTest Case 1 :NULL");
		printf("\nInput Data :%s", terminaldatetest.transactionDate);
		printf("\nExpected Result :WRONG_DATE");
		printf("\nActual Result :WRONG_DATE");
	}
	errortest = getTransactionDate(&terminaldatetest);
	if (errortest == WRONG_DATE) {
		printf("\nTest Case 2 :TRANSACTION DATE IS LESS THAN 10 CHARACTERs");
		printf("\nInput Data :%s", terminaldatetest.transactionDate);
		printf("\nExpected Result :WRONG_DATE");
		printf("\nActual Result :WRONG_DATE");
	}
	errortest = getTransactionDate(&terminaldatetest);
	if (errortest == WRONG_DATE) {
		printf("\nTest Case 3 :TRANSACTION DATE IS IN WRONG FORMAT");
		printf("\nInput Data :%s", terminaldatetest.transactionDate);
		printf("\nExpected Result :WRONG_DATE");
		printf("\nActual Result :WRONG_DATE");
	}
	errortest = getTransactionDate(&terminaldatetest);
	if (errortest == WRONG_DATE) {
		printf("\nTest Case 4 :TRANSACTION DATE IS IN WRONG FORMAT(contains alphapets)");
		printf("\nInput Data :%s", terminaldatetest.transactionDate);
		printf("\nExpected Result :WRONG_DATE");
		printf("\nActual Result :WRONG_DATE");
	}
	errortest = getTransactionDate(&terminaldatetest);
	if (errortest == WRONG_DATE) {
		printf("\nTest Case 5 :TRANSACTION DATE IS IN WRONG FORMAT(days=00 or moth=00 or years=00)");
		printf("\nInput Data :%s", terminaldatetest.transactionDate);
		printf("\nExpected Result :WRONG_DATE");
		printf("\nActual Result :WRONG_DATE");
	}
	errortest = getTransactionDate(&terminaldatetest);
	if (errortest == WRONG_DATE) {
		printf("\nTest Case 6 :TRANSACTION DATE IS IN WRONG FORMAT(days more than 31)");
		printf("\nInput Data :%s", terminaldatetest.transactionDate);
		printf("\nExpected Result :WRONG_DATE");
		printf("\nActual Result :WRONG_DATE");
	}
	errortest = getTransactionDate(&terminaldatetest);
	if (errortest == WRONG_DATE) {
		printf("\nTest Case 7 :TRANSACTION DATE IS IN WRONG FORMAT(months more than 12)");
		printf("\nInput Data :%s", terminaldatetest.transactionDate);
		printf("\nExpected Result :WRONG_DATE");
		printf("\nActual Result :WRONG_DATE");
	}
	errortest = getTransactionDate(&terminaldatetest);
	if (errortest == TERMINAL_OK) {
		printf("\nTest Case 8 :NAME IS IN CORRECT FORMAT");
		printf("\nInput Data :%s", terminaldatetest.transactionDate);
		printf("\nExpected Result :TERMINAL_OK");
		printf("\nActual Result :TERMINAL_OK");
	}

}
void isCardExpiredTest(void) {
	printf("\nTester Name : Taher Elsheikh ");
	printf("\nFunction Name : isCardExpired ");
	
	EN_terminalError_t errortest;
	errortest = isCardExpired(&carddatetest,&cardexpiredtest);
	if (errortest == EXPIRED_CARD) {
		printf("\nTest Case 1 :card expiration date is before the transaction date(years) or (months)");
		printf("\nInput Data :%s - %s", carddatetest.cardExpirationDate, cardexpiredtest.transactionDate);
		printf("\nExpected Result :EXPIRED_CARD");
		printf("\nActual Result :EXPIRED_CARD");
	}
	errortest = isCardExpired(&carddatetest, &cardexpiredtest);
	if (errortest == TERMINAL_OK) {
		printf("\nTest Case 3:card expiration date is valid ");
		printf("\nInput Data :%s - %s", carddatetest.cardExpirationDate, cardexpiredtest.transactionDate);
		printf("\nExpected Result :TERMINAL_OK");
		printf("\nActual Result :TERMINAL_OK");
	}

}
void getTransactionAmountTest(void) {
	EN_terminalError_t errortest;

	errortest = getTransactionAmount(&cardexpiredtest);
	printf("\nTester Name : Taher Elsheikh ");
	printf("\nFunction Name : getTransactionAmount ");

	
	if (errortest == INVALID_AMOUNT) {
		printf("\nTest Case 1 :invalid transaction amount");
		printf("\nInput Data :%.2f", cardexpiredtest.transAmount);
		printf("\nExpected Result :INVALID_AMOUNT");
		printf("\nActual Result :INVALID_AMOUNT");
	}
	errortest = getTransactionAmount(&cardexpiredtest);
	if (errortest == TERMINAL_OK) {
		printf("\nTest Case 2 :transaction amount is valid ");
		printf("\nInput Data :%.2f",cardexpiredtest.transAmount);
		printf("\nExpected Result :TERMINAL_OK");
		printf("\nActual Result :TERMINAL_OK");
	}

}
void isBelowMaxAmountTest(void) {
	EN_terminalError_t errortest;

	errortest = isBelowMaxAmount(&cardexpiredtest);
	printf("\nTester Name : Taher Elsheikh ");
	printf("\nFunction Name : isBelowMaxAmount ");

	
	if (errortest == EXCEED_MAX_AMOUNT) {
		printf("\nTest Case 1 :transaction amount exceed max amount");
		printf("\nInput Data :%.2f > %.2f", cardexpiredtest.transAmount,cardexpiredtest.maxTransAmount);
		printf("\nExpected Result :EXCEED_MAX_AMOUNT");
		printf("\nActual Result :EXCEED_MAX_AMOUNT");
	}
	errortest = isBelowMaxAmount(&cardexpiredtest);
	if (errortest == TERMINAL_OK) {
		printf("\nTest Case 2 :transaction amount is suitable ");
		printf("\nInput Data :%.2f < %.2f",cardexpiredtest.transAmount,cardexpiredtest.maxTransAmount);
		printf("\nExpected Result :TERMINAL_OK");
		printf("\nActual Result :TERMINAL_OK");
	}

}
void setMaxAmountTest(void) {
	printf("\nTester Name : Taher Elsheikh ");
	printf("\nFunction Name : setMaxAmount ");
	float maxamount = MAX_AMOUNT;

	EN_terminalError_t errortest;
	errortest = setMaxAmount(&cardexpiredtest, maxamount);
	if (errortest == INVALID_MAX_AMOUNT) {
		printf("\nTest Case 1 :INVALID SETTING MAX AMOUNT ");
		printf("\nInput Data :%.2f ", cardexpiredtest.maxTransAmount);
		printf("\nExpected Result :INVALID_MAX_AMOUNT");
		printf("\nActual Result :INVALID_MAX_AMOUNT");
	}
	errortest = setMaxAmount(&cardexpiredtest, maxamount);
	if (errortest == TERMINAL_OK) {
		printf("\nTest Case 2 :MAX AMOUNT IS OK");
		printf("\nInput Data :%.2f ", cardexpiredtest.maxTransAmount);
		printf("\nExpected Result :TERMINAL_OK");
		printf("\nActual Result :TERMINAL_OK");
	}

}