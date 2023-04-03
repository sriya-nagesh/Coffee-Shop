#include <iostream>
using namespace std;

// design variables
string border = "--------------------------------------------------------";
string title = "                       Coffee Shop                       ";
string userInput, choice;
int noOfCupsS, noOfCupsM, noOfCupsL, tnoOfCupsS, tnoOfCupsM, tnoOfCupsL, cups; // sizes
int choiceAdmin, choiceCustomer;											   // switch statements
bool contCustomer, contAdmin, redo;											   // while loops
double smallPrice = 6.00, mediumPrice = 9.50, largePrice = 12.00;			   // prices
double totalPrice, serviceTax, tip, mlitresSold, revenue;					   // calculations

// admin panel and functions
void AdminPanel()
{
	cout << border << endl;
	cout << title << endl;
	cout << "Welcome Admin" << endl;
	cout << border << endl;

	do
	{
		cout << "Please choose what you would like to do" << endl;
		cout << "1. View the total number of cups sold in all sizes" << endl;
		cout << "2. View the amount of coffee sold" << endl;
		cout << "3. View the total number revenue made" << endl;
		cin >> choiceAdmin;

		switch (choiceAdmin)
		{
		case 1:
			cout << "The total amount of small cups sold is " << tnoOfCupsS << endl;
			cout << "The total amount of medium cups sold is " << tnoOfCupsM << endl;
			cout << "The total amount of large cups sold is " << tnoOfCupsL << endl;
			break;
		case 2:
			cout << "The total litres sold " << (mlitresSold / 1000) << " L" << endl;
			break;
		case 3:
			cout << "The total amount of revenue made is RM " << revenue << endl;
			break;
		default:
			break;
		}

		cout << "Would you like to choose another option? (Y/N)" << endl;
		cin >> choice;
		if (choice == "n" || choice == "N")
		{
			cout << "Thank you, you have exited the system!" << endl;
			contAdmin = false;
		}
		else
		{
			contAdmin = true;
		}
	} while (contAdmin);
}

int main()
{
	cout << border << endl;
	cout << title << endl;
	cout << "           Hello, welcome to the coffee shop         " << endl;
	cout << border << endl;
	cout << "       Please enter your name to begin your order!" << endl;
	cin >> userInput;
	cout << "Welcome " << userInput << endl;

	if (userInput == "Admin123" || userInput == "admin123")
	{
		AdminPanel();
	}
	else
	{

		// Customer Interface
		cout << "Would you like to purchase a coffee? (Y/N)" << endl;
		cin >> choice;

		if (choice == "y" || choice == "Y")
		{

			do
			{
				cout << "Please choose your size (1=small,2=medium,3=large)" << endl;
				cin >> choiceCustomer;

				switch (choiceCustomer)
				{
				case 1:
					cout << "Please choose the number of cups you would like" << endl;
					cin >> cups;
					noOfCupsS = noOfCupsS + cups;
					tnoOfCupsS = tnoOfCupsS + cups;
					mlitresSold = mlitresSold + (250 * cups);
					totalPrice = totalPrice + (smallPrice * cups);
					contCustomer = false;
					break;
				case 2:
					cout << "Please choose the number of cups you would like" << endl;
					cin >> cups;
					noOfCupsM = noOfCupsM + cups;
					totalPrice = totalPrice + (cups * mediumPrice);
					tnoOfCupsM = tnoOfCupsM + cups;
					mlitresSold = mlitresSold + (500 * cups);
					contCustomer = false;
					break;
				case 3:
					cout << "Please choose the number of cups you would like" << endl;
					cin >> cups;
					noOfCupsL = noOfCupsL + cups;
					totalPrice = totalPrice + (cups * largePrice);
					tnoOfCupsL = tnoOfCupsL + cups;
					mlitresSold = mlitresSold + (750 * cups);
					contCustomer = false;
					break;
				default:
					cout << "Please choose an available size (1=small,2=medium,3=large)" << endl;
					contCustomer = true;
					break;
				}

				// check of user wants to continue adding to their order
				cout << "Would you like to add more to your order? (Y/N)" << endl;
				cin >> choice;
				if (choice == "y" || choice == "Y")
				{
					contCustomer = true;
				}
				else
				{
					contCustomer = false;

					cout << "Would you like to leave a tip? (Y/N)" << endl;
					cin >> choice;

					if (choice == "y" || choice == "Y")
					{
						cout << "Please enter the amount you would like to tip" << endl;
						cin >> tip;
					}
					else
					{
						tip = 0;
					}
					double change, money;
					serviceTax = (totalPrice / 100) * 6;
					totalPrice = totalPrice + tip + serviceTax;
					revenue = revenue + totalPrice;
					cout << "Your total order is RM" << totalPrice << endl;

					// ensure user pays correct amount
					do
					{
						cout << "Please enter how much you are paying with" << endl;
						cin >> money;

						if (money < totalPrice)
						{
							cout << "Your order is short of RM" << (totalPrice - money) << ". Please enter more" << endl;
							redo = true;
						}
						else
						{
							cout << "Your change is RM " << (money - totalPrice) << endl;
							cout << "Thank you!" << endl;
							redo = false;

							totalPrice = 0;
							noOfCupsS = 0;
							noOfCupsM = 0;
							noOfCupsL = 0;
						}
					} while (redo);
				}
			} while (contCustomer);

			// check if user wants to exit the system
			cout << "Would you like to exit the system? (Y/N)" << endl;
			cin >> choice;
			if (choice == "n" || choice == "N")
			{
				main();
			}
			else
			{
				cout << "Thank you, come again!" << endl;
			}
		}
		else
		{
			cout << "Would you like to exit the system? (Y/N)" << endl;
			cin >> choice;
			if (choice == "n" || choice == "N")
			{
				main();
			}
			else
			{
				cout << "Thank you, come again!" << endl;
			}
		}
	}
	return 0;
}
