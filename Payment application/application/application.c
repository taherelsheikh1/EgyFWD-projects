#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"../card/card.h"
#include"../terminal/terminal.h"
#include"../server/server.h"
#include"../application/application.h"
#include<dos.h>
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
float maxamount = MAX_AMOUNT;
EN_transState_t tsts;
ST_transaction_t tttt;
EN_cardError_t carderrorstate1, carderrorstate2, carderrorstate3;
ST_cardData_t carddatetest;
EN_terminalError_t terrortest1, terrortest2, terrortest3, terrortest4, terrortest5;
ST_terminalData_t cardexpiredtest;
EN_serverError_t serr1,serr2,serr3;
void appstart(void) {
	uint8_t STATEOFTRANSACTION[5][30] = { "APPROVED", "DECLINED_INSUFFECIENT_FUND", "DECLINED_STOLEN_CARD", "FRAUD_CARD", "INTERNAL_SERVER_ERROR" };
	setMaxAmount(&cardexpiredtest, maxamount);
	printf("PLEASE ENTER CARD HOLDER'S NAME: ");
	carderrorstate1 = getCardHolderName(&carddatetest);
	if (carderrorstate1 == WRONG_NAME) {
		printf("\nPLEASE RE-ENTER A VALID CARD HOLDER'S NAME : ");
		carderrorstate1 = getCardHolderName(&carddatetest);
	}
		if (carderrorstate1 == WRONG_NAME) { exit(1); }
		else {
			printf("\nPLEASE ENTER CARD EXPIRATION DATE IN THIS FORMAT MM/YY:");
			carderrorstate2 = getCardExpiryDate(&carddatetest);
		}
	
		if (carderrorstate2 == WRONG_EXP_DATE) {
			printf("\nPLEASE RE-ENTER A VALID CARD EXPIRATION DATE IN THIS FORMAT : ");
			carderrorstate2 = getCardExpiryDate(&carddatetest);
		}
		if (carderrorstate2 == WRONG_EXP_DATE) { exit(1); }
		else
		{
			printf("\nPLEASE ENTER YOUR CARD PAN: ");
			carderrorstate3 = getCardPAN(&carddatetest);
		}
	
		if (carderrorstate3 == WRONG_PAN) {
			printf("\nPLEASE RE-ENTER A VALID CARD PAN : ");
			carderrorstate3 = getCardPAN(&carddatetest);
		}
		if (carderrorstate3 == WRONG_PAN) { exit(1); }
		else
		{
			printf("\nPLEASE ENTER TRANSACTION DATE IN THIS FORMAT DD/MM/YYYY :");
			terrortest1 = getTransactionDate(&cardexpiredtest);

		}	
		if (terrortest1 == WRONG_DATE) {
			printf("\nPLEASE RE-ENTER TRANSACTION DATE IN THIS FORMAT DD/MM/YYYY :");
			terrortest1 = getTransactionDate(&cardexpiredtest);
		}
		if (terrortest1 == WRONG_DATE) { exit(1); }
		else
		{
			printf("\nVERFING CARD DATA ............\nTHANK YOU FOR YOUR PATIENT...");
			terrortest2 = isCardExpired(&carddatetest, &cardexpiredtest);
		}

	
	if (terrortest2 == EXPIRED_CARD) {
		printf("\nTHIS CARD IS EXPIRED \nTHANK YOU FOR BANKING WITH US");
		exit(1);
	}
	else
	{
		printf("\nPLEASE ENTER YOUR TRANSACTION AMOUNT IN THISH FORMAT XXXXXXX.XX :");
		terrortest3 = getTransactionAmount(&cardexpiredtest);

	}
	if (terrortest3 == INVALID_AMOUNT) {
		printf("\nPLEASE RE-ENTER AVALID TRANSACTION AMOUNT :");
		terrortest3 = getTransactionAmount(&cardexpiredtest);
	}
		if (terrortest3 == INVALID_AMOUNT) { exit(1); }
		else
		{
			terrortest4 = isBelowMaxAmount(&cardexpiredtest);

		}
			
		if (terrortest4 == EXCEED_MAX_AMOUNT) {
			printf("\nSORRY YOUR AMOUNT EXCEED THE MAXIMUM AMOUNT .");
			printf("\nPLEASE RE-ENTER AVALID TRANSACTION AMOUNT (MAX=%.2f):",maxamount);
			terrortest3 = getTransactionAmount(&cardexpiredtest);
		}
		if (terrortest3 == TERMINAL_OK)
		{
			terrortest4 = isBelowMaxAmount(&cardexpiredtest);
		}
		if (terrortest4 == TERMINAL_OK) {
			printf("\nPLEASE WAIT YOUR TRANSACTION IS PROCESSING.... ");

			serr1 = isValidAccount(&carddatetest, &tttt);
		}
		if (serr1 == ACCOUNT_NOT_FOUND) {

			tsts = recieveTransactionData(&tttt);
		}
			if (tsts == DECLINED_INSUFFECIENT_FUND) {
				printf("\nWE ARE SORRY YOUR BALANCE IS NOT ENOUGH..");
				saveTransaction(&tttt);

			}
			else if (tsts == DECLINED_STOLEN_CARD)
			{
				printf("\nTHIS CARD IS STOLEN WE CAN'T GIVE IT BACK");
				saveTransaction(&tttt);

			}
			else if (tsts == FRAUD_CARD)
			{
				printf("\nTHIS CARD IS NOT AVAILABLE PLEASE CHECK YOU BANK FOR SUPPORT ");
				saveTransaction(&tttt);

			}
			else if (tsts == INTERNAL_SERVER_ERROR)
			{
				printf("\nWE ARE SO SORRY THERE IS MALFUNCTION PLZ TRY AGAIN LATER ");
				saveTransaction(&tttt);

			}
			else
			{
				serr2 = isBlockedAccount(&tttt);

			}
		

			if (serr2 == BLOCKED_ACCOUNT) {
				tsts = recieveTransactionData(&tttt);
			}
			if (tsts == DECLINED_INSUFFECIENT_FUND) {
				printf("\nWE ARE SORRY YOUR BALANCE IS NOT ENOUGH..");
				saveTransaction(&tttt);

			}
			else if (tsts == DECLINED_STOLEN_CARD)
			{
				printf("\nTHIS CARD IS STOLEN WE CAN'T GIVE IT BACK");
				saveTransaction(&tttt);

			}
			else if (tsts == FRAUD_CARD)
			{
				printf("\nTHIS CARD IS NOT AVAILABLE PLEASE CHECK YOU BANK FOR SUPPORT ");
				saveTransaction(&tttt);

			}
			else if (tsts == INTERNAL_SERVER_ERROR)
			{
				printf("\nWE ARE SO SORRY THERE IS MALFUNCTION PLZ TRY AGAIN LATER ");
				saveTransaction(&tttt);

			}
			else
			{

				serr3 = isAmountAvailable(&cardexpiredtest, &tttt);

			}
			

			if (serr3 == LOW_BALANCE)
			{
				tsts = recieveTransactionData(&tttt);
			}
					if (tsts == DECLINED_INSUFFECIENT_FUND) {
						printf("\nWE ARE SORRY YOUR BALANCE IS NOT ENOUGH..");
						saveTransaction(&tttt);


					}
					else if (tsts == DECLINED_STOLEN_CARD)
					{
						printf("\nTHIS CARD IS STOLEN WE CAN'T GIVE IT BACK");
						saveTransaction(&tttt);

											}
					else if (tsts == FRAUD_CARD)
					{
						printf("\nTHIS CARD IS NOT AVAILABLE PLEASE CHECK YOU BANK FOR SUPPORT ");
						saveTransaction(&tttt);
					}
					else if (tsts == INTERNAL_SERVER_ERROR)
					{
						printf("\nWE ARE SO SORRY THERE IS MALFUNCTION PLZ TRY AGAIN LATER ");
						saveTransaction(&tttt);

					}
					else
					{
						tsts = recieveTransactionData(&tttt);
						saveTransaction(&tttt);

					
					}
								
		}
	
		