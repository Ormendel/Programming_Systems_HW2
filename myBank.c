#include <stdio.h>
#include "myBank.h"


/**
*The functions below: O(Open),B(Balance),D(Desposit),W(Withdraw),C(Close),I(Update account's balances by Interest_rate),P(Print),E(Erase and exit)
*The function isValidNum helps us to check validation of num, according to the demands in the assignment: return 1 if valid, 0 otherwise.
*/

int openA=0;//counting how much open account exist

int isValidNum(int id)
{
	/**
	*key: 0 - not valid because not in range
	*key: 1 - valid (in range and an open account)
	*key: 2 - not valid because not an open account
	*/
	int key=1;
	if(id<901||id>950)
		key=0;
	else if(arr[id-901].status=='N')
		key=2;
	return key;
}
void O(double amount)
{
	if(amount<0)
		printf("Can't open a new account with invalid amount (<0)\n");
	else if(openA==50)
		printf("There is no option for opening new account because all are already taken.\n");
	else
	{
		int i=0;
		while(i<50&&arr[i].status=='Y')
			i++;	
		arr[i].status='Y';	
		arr[i].amount=amount;
		printf("Success! . Customer number is: #%d\n",i+901);
		openA++;	
	}
}

/**
*Balance of customer
*id_customer represents account_number
*/

void B(int id_customer)
{
	int check=isValidNum(id_customer);
	switch(check)
	{
		case 0: printf("%d does not exist\n",id_customer);
			break;
		case 1: printf("The balance for customer #%d is: %0.2f\n",id_customer,arr[id_customer-901].amount);
			break;
		default://check is 2
			printf("%d does not exist\n",id_customer);
			break;
	}
}

/**
*Despositing 
*/

void D(int id_customer, double amount)
{
	if(amount<=0)
		printf("Cannot desposit amount smaller or equal to zero\n");
	else//the given amount is positive and id_customer is valid and status is Y (open account)
	{
		printf("Customer #%d: adding %f to %0.2f...\n",id_customer,amount,arr[id_customer-901].amount);
		arr[id_customer-901].amount+=amount;
		printf("Success!\n");
		B(id_customer);
	}			
}

/**
*Withdraw
*/
void W(int id_customer, double amount)
{
	if(amount<=0)
		printf("Cannot desposit amount smaller or equal to zero\n");
	else//the given amount is positive and id_customer is valid and status is Y (open account)
	{
		if(arr[id_customer-901].amount-amount<0)
			printf("Not enough cash, has %0.2f but wants to withdraw %f\n",arr[id_customer-901].amount, amount);
		else
		{
			arr[id_customer-901].amount-=amount;
			printf("Success!\n");
			B(id_customer);
		}
	}
}

/**
*Close
*/
void C(int id_customer)
{
	int check=isValidNum(id_customer);
	switch(check)
	{
		case 0: printf("%d does not exist\n",id_customer);
		break;
		case 1://Everything is ok, closing...
			arr[id_customer-901].status='N';
			arr[id_customer-901].amount=0;
			printf("Account #%d has been closed successfully!\n",id_customer);
			openA--;
		break;
		default://check is 2
			printf("%d does not exist\n",id_customer);
		break;
	}
}
void I(int interest_rate)
{
	int counter=0;
	if(interest_rate==0)	
		printf("No change in accounts\n");
	else if(interest_rate<0)
		printf("ERR: interest_rate has to be positive\n");
	else
	{
		int i;
		double calc;
		for(i=0;i<50&&arr[i].status=='Y';i++)
		{
			calc=((double)(100+interest_rate))/100;
			arr[i].amount=arr[i].amount*calc;//Updating with interest_rate
			counter++;
		}
		if(counter!=0)
			printf("Finished updating all open accounts successfully!\n");
		else
			printf("There are no open accounts, therefore the function did nothing\n");
	}					
}

/**
*Printing all open accounts
*/
void P()
{
	int i;
	int counter=0;
	if(openA==0)
		printf("There are no open accounts, therefore the function did nothing\n");
	else
	{
		for(i=0;i<50&&counter!=openA;i++)
		{
			if(arr[i].status=='Y')
			{
				B(i+901);
				counter++;
			}
		}
		printf("Finished printing all open accounts!\n");
	}
}

/**
*Erase all open accounts and exit
*/
void E()
{
	int i;
	int counter=0;
	if(openA==0)
		printf("There are no open accounts, therefore the function did nothing\n");
	else
	{
		for(i=0;i<50&&counter!=openA;i++)
		{
			if(arr[i].status=='Y')
			{
				C(i+901);
				counter++;
			}
		}
		printf("Finished closing all open accounts!\n");
	}
}

