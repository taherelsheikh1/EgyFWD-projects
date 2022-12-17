#ifndef _SERVER_H
#define _SERVER_H
#include <string.h>
#include"../card/card.h"
#include "../terminal/terminal.h"

typedef unsigned char uint8_t;

typedef enum EN_transState_t
{
    APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;
typedef enum EN_accountState_t
{
    RUNNING,
    BLOCKED
}EN_accountState_t;
typedef enum EN_serverError_t
{
    SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t;
typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transState_t transState;
    float currentbalance;
}ST_transaction_t;
EN_transState_t recieveTransactionData(ST_transaction_t* transData);
EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_transaction_t* accountRefrence);
EN_serverError_t isBlockedAccount(ST_transaction_t* accountRefrence);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_transaction_t* accountRefrence);
EN_serverError_t saveTransaction(ST_transaction_t* transData);
void recieveTransactionDataTest(void);
void isValidAccountTest(void);
void isBlockedAccountTest(void);
void isAmountAvailableTest(void);
void listSavedTransactions(void);

#endif //_SERVER_H
