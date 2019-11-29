#ifndef _MYBANK_H_
#define _MYBANK_H_


/**
*Declaration of struct - Customers
*status - N is for No open account, Y is for an open account
*amount - How much money does a customer have
*/
#define size 50

typedef struct 
{
	char status;
	double amount;
}Customers;

extern Customers arr[size];

/**
*myBank.c Functions
*/
int isValidNum(int);
void O(double);
void B(int);
void D(int , double);
void W(int , double);
void C(int);
void I(int);
void P();
void E();

#endif



