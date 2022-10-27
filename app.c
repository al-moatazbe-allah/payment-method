#define _CRT_SECURE_NO_WARNINGS
#include "app.h"
ST_cardData_t cardData;
ST_terminalData_t termData;
ST_terminalData_t* TD = &termData;
void appStart(void)
{
	char x, y, z, m,J;
		
		printf("Enter the card holder name\n");
		scanf_s("%s", cardData.cardHolderName, 25);
		getCardHolderName(&cardData);
		fflush(stdin);
		printf("Enter the card expiration date\n");
		scanf_s("%s", cardData.cardExpirationDate, 6);
		getCardExpiryDate(&cardData);
		fflush(stdin);
		printf("Enter the card primary acount number\n");
		scanf_s("%s", cardData.primaryAccountNumber, 20);
		getCardPAN(&cardData);
		fflush(stdin);
		printf("Enter the transaction date\n");
		scanf_s("%s", termData.transactionDate, 11);
		getTransactionDate(&termData);

		x = isCardExpired(cardData, termData);
		if (x == EXPIRED_CARD)
		{
			exit(0);
		}
		fflush(stdin);
		printf("Enter the max transaction amount\t");
		scanf("%f",&TD->maxTransAmount);
		setMaxAmount(&termData);

		printf("Enter the transaction amount\t");
		scanf("%f", &TD->transAmount);
		getTransactionAmount(&termData);
		y = isBelowMaxAmount(&termData);
		if (y == EXCEED_MAX_AMOUNT)
		{
			exit(0);
		}
		
		ST_transaction trans[255] =
		{
			{cardData,termData,APPROVED,1}
		};
		
		recieveTransactionData(trans);
		
		
}