#include "server.h"
char index;
extern ST_accountsDB_t DataBase[255];
extern ST_transaction trans[255];
EN_transStat_t recieveTransactionData(ST_transaction* transData) {
if (isValidAccount(&transData->cardHolderData) == ACCOUNT_NOT_FOUND)
{
	transData->transState = DECLINED_STOLEN_CARD;
	return DECLINED_STOLEN_CARD;
}
if (isAmountAvailable(&transData->terminalData) == LOW_BALANCE)
{
	transData->transState = DECLINED_INSUFFECIENT_FUND;

	return DECLINED_INSUFFECIENT_FUND;
}
transData->transState = APPROVED;
DataBase[index].balance -= transData->terminalData.transAmount;
printf("New balance is %f\n", DataBase[index].balance);

return APPROVED;
}


EN_serverError_t isValidAccount(ST_cardData_t* cardData) {
	char found = 0, exist = 1;
	for (char i = 0; i < 11; i++)
	{
		exist = 1;
		for (char j = 0; j < 20; j++)
		{
			if (DataBase[i].primaryAccountNumber[j] != cardData->primaryAccountNumber[j])
			{
				exist = 0;
				break;
			}
		}
		if (exist)
		{
			found = 1;
			index = i;
			break;
		}
	}
	if (!found)
	{
		printf("Account is not Exist  \n");
		return ACCOUNT_NOT_FOUND;

	}
	else
	{
		printf("Account is Exist\n");
		return OK3;
	}

}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
	if (termData->transAmount > DataBase[index].balance)
	{
		printf("low balance \n");
		return LOW_BALANCE;
	}
	else
	{
		printf("balance is exist\n");
		return OK3;
	}
}
EN_serverError_t saveTransaction(ST_transaction* transData) {
	transData->transactionSequenceNumber++;
}
EN_serverError_t getTransaction(int transactionSequenceNumber, ST_transaction* transData) {
	return APPROVED;
}