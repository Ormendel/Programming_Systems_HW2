/**
*Declaration of struct - Customers
*status - N is for No open account, Y is for an open account
*amount - How much money does a customer have
*/
#define size 50

typedef struct Customers
{
	char status;
	double amount;
}Customers;

Customers arr[size];

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



