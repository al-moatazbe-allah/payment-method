#include "terminal.h"
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
	
	int M = strlen(termData->transactionDate);
	if(M!=10) {
		return WRONG_DATE;
	}
	else
	 {
		return OK2;
	}
}
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	if (cardData.cardExpirationDate[0] <= '1')
	{
		
			if (cardData.cardExpirationDate[3] > termData.transactionDate[8]) {
				return OK2;
			}
			else if (cardData.cardExpirationDate[3] == termData.transactionDate[8])
			{
				if (cardData.cardExpirationDate[4] > termData.transactionDate[9]) {
					return OK2;
				}
				else if (cardData.cardExpirationDate[4] == termData.transactionDate[9])
				{
					if (cardData.cardExpirationDate[0] > termData.transactionDate[3])
					{
						return OK2;
					}
					else if (cardData.cardExpirationDate[0] == termData.transactionDate[3])
					{
						if (cardData.cardExpirationDate[1] >= termData.transactionDate[4])
						{
							return OK2;
						}
						else
						{
							printf("expired1");
							return EXPIRED_CARD;
						}
					}
					else
					{
						printf("expired2");
						return EXPIRED_CARD;
					}

				}
				else
				{
					printf("expired3");
					return EXPIRED_CARD;
				}
			}
			else
			{
				printf("expired4");
				return EXPIRED_CARD;
			}

	}
	else
	{
		printf("expired6");
		return EXPIRED_CARD;
	}

}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) 
{
	
	if (termData->transAmount <= 0) {
		return INVALID_AMOUNT;
	}
	else
	{
		return OK2;
	}
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t*termData)
{
	if (termData->maxTransAmount >= termData->transAmount)
	{
		return OK2;
	}
	else
	{
		return EXCEED_MAX_AMOUNT;
	}
}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) 
{

	if (termData->maxTransAmount <= 0.0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else
	{
		return OK2;
	}
}