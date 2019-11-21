# Programming_Systems_HW2

## This project is about arrays and loops.

## Note: The implement in the project is by struct and not by matrix.

### The project represents a bank account managment, (aka customer) and has the following functions:

O(Open): Firstly we need to check if there is an available number between 901 to 950 for the customer. If so the amount which this function receives from the user is also valid (>=0), a new account is created and shown in the screen.

B(Balance): receives account number and prints the current balance in that account.

W(Withdraw): receive amount from the user to withdraw and the account number, and prints the new balance. 

C(Close): receives an account number, checks validation. If the account is open - the function closes the account and all data in that account is erased immidiately.

I(Interest): receives interest_rate (from integer type) from the user and adds it to all open accounts.
The interest_rate represents precentages.
 
P(Print): prints all open account if there are(by calling to function B)
 
E(Exit): closes all open accounts(by using function C) and exit the program afterwards.

## Authors : Or Mendel and Reuven Klavan
