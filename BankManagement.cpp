#include <iostream>
#include <cstring>
using namespace std;

int add = 0;
struct date // Structure for a date.
{
	int date, month, year;
};
struct Account //Structure for a bank account.
{
	int acc_no;
	char pass[20];
	char name[20];
	struct date dob;
	char phone[20];
	float amt;
} a[100];
void clear();								//Function to clear screen.
void menu();								//Function to Display menu.
void title();								//Function to Display title.
void thanks();								//Function to thnak user for using this system.
void thanks_exit();							//Function to thnak user for using this system and exit the program.
void fordelay(int j);						//Function to generate a time game of 1 second.
void create();								//Function to create a bank account.
int testacc_no(int acc);					//Function to test validity of bank account.
int checkacc_no(int acc);					//Function to check for similar account number.
void update();								//Function to uodate account details.
void checkpass(char password[20], int acc); //Function to check if password is matching.
void view();								//Funcyion to view account details.
void remove();								//Function to delete an account.
void transac();								//Function to perform a transaction.
void check_amt(float amt, int acc);			//Function to check for available balance in the account.
void end();									//Function to end the code.

int main()
{
	clear();
	return 0;
}

void clear()
{
	system("cls");
	title();
	menu();
}
void menu()
{
	char ch;
	cout << "|**********************************************************************************************************************|" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|                                                  -----MAIN MENU-----                                                 |" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|                                                  1. Create a new account                                             |" << endl;
	cout << "|                                                  2. Update existing account                                          |" << endl;
	cout << "|                                                  3. View details of an existing account                              |" << endl;
	cout << "|                                                  4. Remove an existing account                                       |" << endl;
	cout << "|                                                  5. Perform a transaction                                            |" << endl;
	cout << "|                                                  6. Exit                                                             |" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|**********************************************************************************************************************|" << endl;
	cout << "Enter your Choice: ";
	cin >> ch;
	switch (ch) //Using switch case to navigate through menu.
	{
	case '1':
		create();
		break;
	case '2':
		update();
		break;
	case '3':
		view();
		break;
	case '4':
		remove();
		break;
	case '5':
		transac();
		break;
	case '6':
		end();
	}
}
void title()
{
	cout << "|**********************************************************************************************************************|" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|                                            WELCOME TO PIGGY BANK OF INDIA                                            |" << endl;
	cout << "|                                           AUTOMATED BANK MANAGEMENT SYSTEM                                           |" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|**********************************************************************************************************************|" << endl;
}
void thanks()
{
	cout << "\n\n\n";
	cout << "|**********************************************************************************************************************|" << endl;
	cout << "|                        Thank You for using advanced automated bank account management system.                        |" << endl;
	cout << "|                        Enter any key to go back to menu.                                                             |" << endl;
	cout << "|**********************************************************************************************************************|" << endl;
	fflush(stdin);
	getchar();
	clear();
}
void thanks_exit()
{
	cout << "\n\n\n";
	cout << "|**********************************************************************************************************************|" << endl;
	cout << "|                        Thank You for using advanced automated bank account management system.                        |" << endl;
	cout << "|                        Enter any key to exit the program.                                                            |" << endl;
	cout << "|**********************************************************************************************************************|" << endl;
	fflush(stdin);
	getchar();
}
void fordelay(int j)
{
	long int i, l;
	for (i = 0; i < 4; i++)
	{
		for (l = 0; l < j * j * j; l++)
			;
		cout << ".";
	}
	cout << "\n\n\n";
}
void create()
{
	system("cls");
	title();
	int accno;
	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|                                                -----ADD ACCOUNT-----                                                 |" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "Enter desired 4 digit acc no.: ";
	cin >> accno;
	fflush(stdin);
	if (checkacc_no(accno) != -1) //Using if and if-else to check conditions.
	{
		cout << "Account Number Already in use! Please enter a different account number.";
		thanks();
	}
	if (testacc_no(accno))
		a[add].acc_no = accno;
	else
	{
		cout << "Please Enter a Valid account Number.";
		thanks();
	}
	cout << "Enter a password.: ";
	cin >> a[add].pass;
	cout << "Enter your Name.: ";
	cin >> a[add].name;
	cout << "Enter Date of Birth(dd mm yyyy): ";
	cin >> a[add].dob.date >> a[add].dob.month >> a[add].dob.year;
	fflush(stdin);
	cout << "Enter your Phone Number: ";
	cin >> a[add].phone;
	cout << "Enter amount to be deposited. $ ";
	cin >> a[add].amt;
	fflush(stdin);
	cout << "Creating Account";
	fordelay(750);
	cout << "New Account for account number " << a[add++].acc_no << " has been created." << endl;
	cout << "Printing receipt for deposit. " << endl;
	cout << "Proceed to Counter 1 to deposit the money entered above.";
	thanks();
}
int testacc_no(int acc)
{
	int i;
	for (i = 0; acc; acc /= 10, i++)
		;
	if (i == 4)
		return 1;
	else
		return 0;
}
int checkacc_no(int acc)
{
	int i;
	for (i = 0; i <= add; i++) //Using loops to traverse through database and perform a search.
	{
		if (acc == a[i].acc_no)
			return i;
	}
	return -1;
}
void update()
{
	system("cls");
	title();

	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|                                                -----UPDATE ACCOUNT-----                                              |" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	int i, u = 0, accno;
	char ch = 'N', pass[20];
	cout << "Enter your 4 digit acc no.: ";
	cin >> accno;
	fflush(stdin);
	if (checkacc_no(accno) == -1)
	{
		cout << "Account Number does not exist! Please enter a different account number.";
		thanks();
	}
	else
		i = checkacc_no(accno);
	cout << "Enter your Password: ";
	cin >> pass;
	checkpass(pass, i);
	cout << "Enter the information you would like to update in your account." << endl;
	cout << "1. Name" << endl;
	cout << "2. Phone Number" << endl;
	cout << "3. Password" << endl;
	cin >> u;
	fflush(stdin);
	switch (u)
	{
	case 1:
		goto name;
		break;
	case 2:
		goto phone;
		break;
	case 3:
		goto pass;
		break;
	default:
		cout << "Enter a Valid Option.";
		thanks();
		break;
	}
name:
	cout << "Current Name for account is " << a[i].name << "." << endl;
	cout << "Would you like to change it?(Y/N)  ";
	cin >> ch;
	fflush(stdin);
	if (ch == 'Y')
	{
		cout << "Enter the new name for this account.: ";
		cin >> a[i].name;
		cout << "Changing Name";
		fordelay(750);
		cout << "Name for account number " << a[i].acc_no << " changed succesfully to " << a[i].name << "." << endl;
	}
	thanks();
phone:
	cout << "Current Phone Number for account is " << a[i].phone << "." << endl;
	cout << "Would you like to change it?(Y/N)  ";
	cin >> ch;
	fflush(stdin);
	if (ch == 'Y')
	{
		cout << "Enter the new phone number for this account.: ";
		cin >> a[i].phone;
		cout << "Changing Phone Number";
		fordelay(750);
		cout << "Phone Number for account number " << a[i].acc_no << " changed succesfully to " << a[i].phone << "." << endl;
	}
	thanks();
pass:
	cout << "Enter current password for verification." << endl;
	cin >> pass;
	checkpass(pass, i);
	cout << "Would you like to change your password?(Y/N)  ";
	cin >> ch;
	fflush(stdin);
	if (ch == 'Y')
	{
		cout << "Enter the new password for this account.: ";
		cin >> a[i].pass;
		cout << "Changing Password";
		fordelay(750);
		cout << "Password for account number " << a[i].acc_no << " is changed succesfully.";
	}
	thanks();
}
void checkpass(char password[20], int acc)
{
	if (strcmp(password, a[acc].pass))
	{
		cout << "Wrong Password!! Try Again." << endl;
		thanks();
	}
}
void view()
{
	system("cls");
	title();

	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|                                                -----ACCOUNT DETAILS-----                                             |" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	int i, accno;
	char pass[20];
	cout << "Enter your 4 digit acc no.: ";
	cin >> accno;
	fflush(stdin);
	if (checkacc_no(accno) == -1)
	{
		cout << "Account Number does not exist! Please enter a different account number.";
		thanks();
	}
	else
		i = checkacc_no(accno);
	cout << "Enter your Password: ";
	cin >> pass;
	checkpass(pass, i);
	cout << "Loading Account";
	fordelay(750);
	cout << "Account Number:\t\t" << a[i].acc_no << endl;
	cout << "Account Name:\t\t " << a[i].name << endl;
	cout << "Date of Birth:\t\t " << a[i].dob.date << "-" << a[i].dob.month << "-" << a[i].dob.year << endl;
	cout << "Phone Number:\t\t " << a[i].phone << endl;
	cout << "Amount Available:\t $" << a[i].amt;
	thanks();
}
void remove()
{
	system("cls");
	title();

	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|                                                -----DELETE ACCOUNT-----                                              |" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	int i, accno;
	char ch = 'N', pass[20];
	cout << "Enter your 4 digit acc no.: ";
	cin >> accno;
	fflush(stdin);
	if (checkacc_no(accno) == -1)
	{
		cout << "Account Number does not exist! Please enter a different account number.";
		thanks();
	}
	else
		i = checkacc_no(accno);
	cout << "Enter your Password: ";
	cin >> pass;
	checkpass(pass, i);
	cout << "Do you wish to delete this account. Amount balance will be reduced to 0 and can be received from Counter 3." << endl;
	cout << "Proceed to Continue?(Y/N)  ";
	cin >> ch;
	fflush(stdin);
	if (ch == 'Y')
	{
		cout << "Enter current password for verification." << endl;
		cin >> pass;
		checkpass(pass, i);
		cout << "Deleting Account";
		fordelay(750);
		cout << "Account Deleted Succesfully." << endl;
		cout << "Printing Receipt for withdrawal of amount " << a[i].amt << endl;
		cout << "Proceed to Counter 3 the for further instructons.";
	}
	thanks();
}
void transac()
{
	system("cls");
	title();

	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|                                                -----PERFORM A TRANSACTION-----                                       |" << endl;
	cout << "|                                                                                                                      |" << endl;
	cout << "|----------------------------------------------------------------------------------------------------------------------|" << endl;
	int i, j, t = 0, accno;
	float amt = 0;
	char ch, pass[20];
	cout << "Enter your 4 digit acc no.: ";
	cin >> accno;
	fflush(stdin);
	if (checkacc_no(accno) == -1)
	{
		cout << "Account Number does not exist! Please enter a different account number.";
		thanks();
	}
	else
		i = checkacc_no(accno);
	cout << "Enter your Password: " << endl;
	cin >> pass;
	checkpass(pass, i);
	cout << "Enter the type of transaction to proceed with." << endl;
	cout << "1.Deposit to Account." << endl;
	cout << "2.Withdraw from Account." << endl;
	cout << "3.Transfer money to another account." << endl;
	cin >> t;
	fflush(stdin);
	switch (t)
	{
	case 1:
		goto deposit;
		break;
	case 2:
		goto withdraw;
		break;
	case 3:
		goto transfer;
		break;
	default:
		cout << "Enter a Valid Option.";
		thanks();
		break;
	}
deposit:
	cout << "Enter the amount to be deposited.: $";
	cin >> amt;
	fflush(stdin);
	cout << "Proceed with Transaction?(Y/N)  ";
	cin >> ch;
	fflush(stdin);
	if (ch == 'Y')
	{
		cout << "Completing transacton";
		fordelay(750);
		a[i].amt += amt;
		cout << "Transaction has been completed." << endl;
		cout << "Printing receipt for deposit." << endl;
		cout << "Proceed to Counter 1 to deposit the money entered above.";
	}
	thanks();
withdraw:
	cout << "Enter the amount to be withdarwn.: $";
	cin >> amt;
	fflush(stdin);
	check_amt(amt, i);
	cout << "Proceed with Transaction?(Y/N)  ";
	cin >> ch;
	fflush(stdin);
	if (ch == 'Y')
	{
		cout << "Enter current password for verification.: ";
		cin >> pass;
		checkpass(pass, i);
		cout << "Completing transacton";
		fordelay(750);
		a[i].amt -= amt;
		cout << "Transaction has been completed." << endl;
		cout << "Printing receipt for withdrawal." << endl;
		cout << "Proceed to Counter 2 to recive the money entered above.";
	}
	thanks();
transfer:
	cout << "Enter 4 digit acc no. to tranfer money to: ";
	cin >> accno;
	fflush(stdin);
	if (checkacc_no(accno) == -1)
	{
		cout << "Account Number does not exist! Please enter a different account number.";
		thanks();
	}
	else
		j = checkacc_no(accno);
	cout << "Enter the amount to be tranferred.: $";
	cin >> amt;
	fflush(stdin);
	check_amt(amt, i);
	cout << "Proceed with Transaction?(Y/N)  ";
	cin >> ch;
	fflush(stdin);
	if (ch == 'Y')
	{
		cout << "Enter current password for verification." << endl;
		cin >> pass;
		checkpass(pass, i);
		cout << "Completing transacton";
		fordelay(750);
		a[i].amt -= amt;
		a[j].amt += amt;
		cout << "Transaction has been completed." << endl;
		cout << "Printing receipt for tranfer.";
	}
	thanks();
}
void check_amt(float amt, int acc)
{
	if (amt > a[acc].amt)
	{
		cout << "You do no have sufficient funds for the transaction! Please try again.";
		thanks();
	}
}
void end()
{
	thanks_exit();
	exit(0);
}