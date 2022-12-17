#define _CRT_SECURE_NO_WARNINGS
#include"../application/application.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"../card/card.h"
#include"../terminal/terminal.h"
#include"../server/server.h"
#include"../application/application.h"
#include<dos.h>
#include<ctype.h>
ST_cardData_t nametest;
ST_cardData_t carddatetest;
ST_cardData_t pantest;
EN_cardError_t carderrorstate;
EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
	uint8_t Cardname[40]={0};
	int i;
	printf("\n");
	scanf("%s", Cardname);
	for (i = 0; Cardname[i] != '\0'; i++) {

		if (!isalpha(Cardname[i])) {
			strcpy(cardData->cardHolderName, Cardname);

			return WRONG_NAME;
		}
	}
	if (Cardname == NULL || strlen(Cardname) < 20 || strlen(Cardname) > 24) {
		strcpy(cardData->cardHolderName, Cardname);

		return WRONG_NAME;
	}
	else {
		strcpy(cardData->cardHolderName, Cardname);
		return CARD_OK;
	}
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
	
	uint8_t cardexpirationDate[10] = { 0 };
	printf("\n");
	scanf("%s", cardexpirationDate);
	
	if (cardexpirationDate == NULL || cardexpirationDate[2] != '/' || strlen(cardexpirationDate) != 5||
		isdigit(cardexpirationDate[0])==0 || isdigit(cardexpirationDate[1])== 0 || isdigit(cardexpirationDate[3]) == 0 || isdigit(cardexpirationDate[4]) == 0
		||cardexpirationDate[0] > '1'||((cardexpirationDate[0] == '1')&&( cardexpirationDate[1] > '2'))||((cardexpirationDate[0]== '0') && (cardexpirationDate[1] == '0'))||
		(cardexpirationDate[3] =='0') && (cardexpirationDate[4] == '0')) {
		strcpy(cardData->cardExpirationDate, cardexpirationDate);

		return WRONG_EXP_DATE;
	}
	else
	{
		strcpy(cardData->cardExpirationDate, cardexpirationDate);
		return CARD_OK;
	}
}


EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
	int i;
	uint8_t primaryaccountNumber[30] = { 0 };
	printf("\n");
	scanf("%s", primaryaccountNumber);
	for (i = 0; primaryaccountNumber[i] != '\0'; i++) {

		if (!isdigit(primaryaccountNumber[i])) {
			strcpy(cardData->primaryAccountNumber, primaryaccountNumber);
			return WRONG_PAN;
		}
	}
	if (primaryaccountNumber == NULL || strlen(primaryaccountNumber) < 16 || strlen(primaryaccountNumber) > 19) {
		strcpy(cardData->primaryAccountNumber, primaryaccountNumber);

		return WRONG_PAN;
	}
	else
	{
		strcpy(cardData->primaryAccountNumber, primaryaccountNumber);

		return CARD_OK;
	}
}
void getCardHoldernametest(void) {
	printf("Tester Name : Taher Elsheikh ");
	printf("\nFunction Name : getCardHolderName");
	
	/*
	 nametest1 = '\0';
	 nametest2="taherelsheikh";
	 nametest3="taherelsayedmohamedelsheikh";
	 nametest4="SDSHDGSHD12321313123";
	 nametest5="taherelsayedelsheikh";
	*/
	EN_cardError_t errortest;
	errortest = getCardHolderName(&nametest);
	if (errortest == WRONG_NAME) {
		printf("\nTest Case 1 :NULL");
		printf("\nInput Data :%s",nametest.cardHolderName);
		printf("\nExpected Result :WRONG_NAME");
		printf("\nActual Result :WRONG_NAME");
	}
	errortest = getCardHolderName(&nametest);
	if (errortest == WRONG_NAME) {
		printf("\nTest Case 2 :NAME IS LESS THAN 20 CHARACTERs");
		printf("\nInput Data :%s", nametest.cardHolderName);
		printf("\nExpected Result :WRONG_NAME");
		printf("\nActual Result :WRONG_NAME");
	}
	errortest = getCardHolderName(&nametest);
	if (errortest == WRONG_NAME) {
		printf("\nTest Case 3 :NAME IS MORE THAN 24 CHARACTERs");
		printf("\nInput Data :%s", nametest.cardHolderName);
		printf("\nExpected Result :WRONG_NAME");
		printf("\nActual Result :WRONG_NAME");
	}
	errortest = getCardHolderName(&nametest);
	if (errortest == WRONG_NAME) {
		printf("\nTest Case 4 :NAME IS IN WRONG FORMAT");
		printf("\nInput Data :%s", nametest.cardHolderName);
		printf("\nExpected Result :WRONG_NAME");
		printf("\nActual Result :WRONG_NAME");
	}
	errortest = getCardHolderName(&nametest);
	if (errortest == CARD_OK) {
		printf("\nTest Case 5 :NAME IS IN CORRECT FORMAT");
		printf("\nInput Data :%s", nametest.cardHolderName);
		printf("\nExpected Result :CARD_OK");
		printf("\nActual Result :CARD_OK");
	}

}

void getCardExpiryDatetest(void) {
	printf("\nTester Name : Taher Elsheikh ");
	printf("\nFunction Name : getCardExpiryDate ");
	
	/*
	test1 = '\0';
	test2="11-25";
	test3="11/2025";
	test4="00/00";
    test5="22/22";
	test6="aa/bb";
	test7="11/25";

	*/
	EN_cardError_t errortest;
	errortest = getCardExpiryDate(&carddatetest);
	if (errortest == WRONG_EXP_DATE) {
		printf("\nTest Case 1 :NULL");
		printf("\nInput Data :%s", carddatetest.cardExpirationDate);
		printf("\nExpected Result :WRONG_EXP_DATE ");
		printf("\nActual Result :WRONG_EXP_DATE");
	}
	errortest = getCardExpiryDate(&carddatetest);
	if (errortest == WRONG_EXP_DATE) {
		printf("\nTest Case 2 :Wrong Format");
		printf("\nInput Data :%s", carddatetest.cardExpirationDate);
		printf("\nExpected Result :WRONG_EXP_DATE");
		printf("\nActual Result :WRONG_EXP_DATE");
	}
	errortest = getCardExpiryDate(&carddatetest);
	if (errortest == WRONG_EXP_DATE) {
		printf("\nTest Case 3 :More than 5 characters");
		printf("\nInput Data :%s", carddatetest.cardExpirationDate);
		printf("\nExpected Result :WRONG_EXP_DATE");
		printf("\nActual Result :WRONG_EXP_DATE");
	}
	errortest = getCardExpiryDate(&carddatetest);
	if (errortest == WRONG_EXP_DATE) {
		printf("\nTest Case 4 :Wrong Format(month=00,year=00)");
		printf("\nInput Data :%s", carddatetest.cardExpirationDate);
		printf("\nExpected Result :WRONG_EXP_DATE");
		printf("\nActual Result :WRONG_EXP_DATE");
	}
	errortest = getCardExpiryDate(&carddatetest);
	if (errortest == WRONG_EXP_DATE) {
		printf("\nTest Case 5 :Wrong Format (month)");
		printf("\nInput Data :%s", carddatetest.cardExpirationDate);
		printf("\nExpected Result :WRONG_EXP_DATE");
		printf("\nActual Result :WRONG_EXP_DATE");
	}
	errortest = getCardExpiryDate(&carddatetest);
	if (errortest == WRONG_EXP_DATE) {
		printf("\nTest Case 6 :Wrong Format(alphapets) ");
		printf("\nInput Data :%s", carddatetest.cardExpirationDate);
		printf("\nExpected Result :WRONG_EXP_DATE");
		printf("\nActual Result :WRONG_EXP_DATE");
	}
	errortest = getCardExpiryDate(&carddatetest);
	if (errortest == CARD_OK) {
		printf("\nTest Case 7 :Expiration Date IS IN CORRECT FORMAT");
		printf("\nInput Data :%s", carddatetest.cardExpirationDate);
		printf("\nExpected Result :CARD_OK");
		printf("\nActual Result :CARD_OK");
	}
}
void getCardPANtest(void) {
	printf("\nTester Name : Taher Elsheikh ");
	printf("\nFunction Name : getCardPAN");
	/*
	 test1 = '\0';
	 test2="12121212121212";//less than 16
	 test3="1212121212121212121212";//more than 19
	 test4="23523512221112aa"
	 test5="1212121212121212";//correct pan
	*/
	EN_cardError_t errortest;
	errortest = getCardPAN(&pantest);
	if (errortest == WRONG_PAN) {
		printf("\nTest Case 1 :NULL");
		printf("\nInput Data :%s", pantest.primaryAccountNumber);
		printf("\nExpected Result :WRONG_PAN");
		printf("\nActual Result :WRONG_PAN");
	}
	errortest = getCardPAN(&pantest);
	if (errortest == WRONG_PAN) {
		printf("\nTest Case 2 :PAN IS LESS THAN 16 CHARACTERs");
		printf("\nInput Data :%s", pantest.primaryAccountNumber);
		printf("\nExpected Result :WRONG_PAN");
		printf("\nActual Result :WRONG_PAN");
	}
	errortest = getCardPAN(&pantest);
	if (errortest == WRONG_PAN) {
		printf("\nTest Case 3 :PAN IS MORE THAN 19 CHARACTERs");
		printf("\nInput Data :%s", pantest.primaryAccountNumber);
		printf("\nExpected Result :WRONG_PAN");
		printf("\nActual Result :WRONG_PAN");
	}
	errortest = getCardPAN(&pantest);
	if (errortest == WRONG_PAN) {
		printf("\nTest Case 4 :PAN contain alphapets");
		printf("\nInput Data :%s", pantest.primaryAccountNumber);
		printf("\nExpected Result :WRONG_PAN");
		printf("\nActual Result :WRONG_PAN");
	}
	errortest = getCardPAN(&pantest);
	if (errortest == CARD_OK) {
		printf("\nTest Case 4 :PAN IS IN CORRECT FORMAT");
		printf("\nInput Data :%s", pantest.primaryAccountNumber);
		printf("\nExpected Result :CARD_OK");
		printf("\nActual Result :CARD_OK");
	}

}


	