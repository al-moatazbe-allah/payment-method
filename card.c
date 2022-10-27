#include "card.h"
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	
	int M = strlen(cardData -> cardHolderName);
	if (M > 24 || M < 20 || M==0) {
		return WRONG_NAME;
	}
	else
	{
		return OK1;
	}

}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	
	int M = strlen(cardData->cardExpirationDate);
	if (M !=5 || M==0) {
		return WRONG_EXP_DATE;
	}
	else
	{
		return OK1;
	}
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	
	int M = strlen(cardData->primaryAccountNumber);
	if (M > 19 || M < 16 || M == 0) {
		return WRONG_PAN;
	}
	else {
		return OK1;
	}
}
