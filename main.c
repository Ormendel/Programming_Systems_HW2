#include <stdio.h>
#include "myBank.h"

void Menu()
{
	printf("O for open new account,\n");
	printf("B for check Balance,\n");
	printf("D for Despositing,\n");
	printf("W for Withdraw money,\n");
	printf("C for Closing account,\n");	
	printf("I for upgrade account with Interest rate,\n");
	printf("P for Printing all open accounts,\n");
	printf("E for closing all open accounts and Exit.\n");
}

int main()
{	
	//Initialize accounts in array
	int i;
	for(i=0;i<50;i++)
	{
		arr[i].status='N';//No open account
		arr[i].amount=0;//Default
	}
	char act;
	double amount;
	double interest_rate;
	int acc_num;
	int check;
	do
	{
		printf("Enter char:\n");
		Menu();
		scanf("%c",&act);
		switch(act)
		{
			case 'O':
				if(arr[49].status=='Y')
					printf("There is no option for opening new account because all are already taken.\n");
				else
				{
					printf("Enter amount to put in a new account:\n");
					scanf("%lf",&amount);	
					O(amount);
					printf("\n");
				}
			break;
			case 'B':
					printf("Enter account number between 901 to 950\n");
					scanf("%d",&acc_num);
					B(acc_num);
					printf("\n");
			break;
			case 'D':
					printf("Enter account number between 901 to 950\n");
					scanf("%d",&acc_num);
					check=isValidNum(acc_num);
					if(check==1)
					{
						printf("Enter amount to desposit in bank:\n");
						scanf("%lf",&amount);
						D(acc_num,amount);
						printf("\n");
					}
					else
						printf("%d does not exist\n",acc_num);				
			break;
			case 'W':
					printf("Enter account number between 901 to 950\n");
					scanf("%d",&acc_num);
					check=isValidNum(acc_num);
					if(check==1)
					{
						printf("Enter amount to withdraw from bank:\n");
						scanf("%lf",&amount);
						W(acc_num,amount);
						printf("\n");
					}
					else
						printf("%d does not exist\n",acc_num);		
			break;
			case 'C':
					printf("Enter account number between 901 to 950\n");
					scanf("%d",&acc_num);
					C(acc_num);
					printf("\n");
			break;
			case 'I':
					printf("Enter Interest rate\n");
					scanf("%lf",&interest_rate);
					I(interest_rate);
					printf("\n");
			break;
			case 'P':
				printf("Printing open accounts:\n");
				P();
				printf("\n");
			break;
			case 'E':
				printf("Closing open accounts:\n");
				E();
				printf("\n");
			break;

			default:
				 printf("ERR; Please try again!\n");
			break;
		}
		getchar();//SKIP LINE		
		printf("\n");
	}
	while(act!='E');
	printf("Bye Bye ! :)\n");
	return 0;
}
