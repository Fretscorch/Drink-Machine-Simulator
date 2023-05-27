/* Programmer Name: Connor Hathaway
* 
*  Description: This program simulates buying drinks from a vending machine. It will first ask the user if they would like
*  to buy a drink. If they answer yes, it will prompt them to input money into the machine. Once they are done inputting
*  money, the program will display a list of drinks for the user to choose from, along with how much each one costs. They
*  will select what drink they want, how many of it they want, and get their drinks. The user will then be prompted if they
*  want to buy anymore drinks. All the while, the program is keeping a total track of how much money the machine has collected,
*  which is displayed in a report along with the remaining quantity of each drink once the user is done.
* 
*  Date: 3/17/23
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Initiliazing all the data in a structure with arrays
struct DrinkList {
    string drinkName[5] = { "1) Cola", "2) Root Beer", "3) Orange Soda", "4) Grape Soda", "5) Bottled Water" };
    float drinkCost[5] = { 1.00, 1.00, 1.00, 1.00, 1.50 };
    int drinkNum[5] = { 20, 20, 20, 20, 20 };
};

class DrinkMachine {

public:
    void displayChoices();
    void buyDrink();
private:
    float inputMoney();
    void dailyReport();
};

// Function to list the drinks for the user to pick from
void displayChoices() {
    int i;
    DrinkList drinkList;

    cout << "\nDrink Name      Price" << endl;

    for (i = 0; i < 5; i++) {
        cout << drinkList.drinkName[i] << "     " << fixed << setprecision(2) << drinkList.drinkCost[i] << endl;
    }
}

// Function to handle the user inputting money
float inputMoney(float money) {
    float moneyInput = 0;
    float totalMoney = 0;
    char userSelect = 0;

    do {
        cout << "\nHow much money would you like to put in? $";
        cin >> moneyInput;
        totalMoney += moneyInput + money;
        cout << "\nWould you like to keep inserting money? Y/N: ";
        cin >> userSelect;
    } while (userSelect == 'Y' || userSelect == 'y');

    cout << "\nYou have $" << fixed << setprecision(2) << totalMoney << " to spend." << endl;

    return totalMoney;
}

// Report of the money the machine made and how many of each drink is left once the user is done
void DailyReport(float profit, int cola, int root, int orange, int grape, int water) {
    DrinkList drinkList;

    cout << drinkList.drinkName[0] << "     " << fixed << setprecision(2) << cola << endl;
    cout << drinkList.drinkName[1] << "     " << fixed << setprecision(2) << root << endl;
    cout << drinkList.drinkName[2] << "     " << fixed << setprecision(2) << orange << endl;
    cout << drinkList.drinkName[3] << "     " << fixed << setprecision(2) << grape << endl;
    cout << drinkList.drinkName[4] << "     " << fixed << setprecision(2) << water << endl;
    cout << "\nProfits collected: $" << profit << endl;
    return;
}

// Main function to handle the sale(s). Calls the inputMoney function as part of it
void buyDrink() {
    float drinkMoney = 0;
    char drinkSelect = 0;
    int quantity = 0;
    char userSelect = 0;
    float moneyCollected = 0;
    DrinkList drinkList;

    do {
        drinkMoney = inputMoney(drinkMoney); // Initializes money for the user to spend
        displayChoices(); // Lists the drinks for the user to choose from

        cout << "\nWhat drink would you like to buy? Enter a number from 1 to 5. ";
        cin >> drinkSelect;
        cout << "\nHow many of this drink would you like to buy? ";
        cin >> quantity;

        if (drinkSelect == '1') {
            
            if ((drinkMoney - (drinkList.drinkCost[0] * quantity)) < 0) {
                cout << "\nNot enough money. Returning all inputted money.";
                drinkMoney = 0;
                cout << "\nYou have $" << drinkMoney << " left.";
            }
            else if ((drinkList.drinkNum[0] - quantity) < 0) {
                cout << "Not enough of this drink left. There is " << drinkList.drinkNum[0] << " of this drink left.\n";
                cout << "Returning all inputted money.";
                drinkMoney = 0;
                cout << "\nYou have $" << drinkMoney << " left.";
            }
            else {
                drinkMoney -= (drinkList.drinkCost[0] * quantity);
                drinkList.drinkNum[0] -= quantity;
                moneyCollected += (drinkList.drinkCost[0] * quantity);
                cout << "\nYour drink(s) has been dispensed! Enjoy!";
                cout << "\nYou have $" << drinkMoney << " left.";
            }
        }

        else if (drinkSelect == '2') {
            
            if ((drinkMoney - (drinkList.drinkCost[1] * quantity)) < 0) {
                cout << "\nNot enough money. Returning all inputted money.";
                drinkMoney = 0;
                cout << "\nYou have $" << drinkMoney << " left.";
            }
            else if ((drinkList.drinkNum[1] - quantity) < 0) {
                cout << "Not enough of this drink left. There is " << drinkList.drinkNum[0] << " of this drink left.\n";
                cout << "Returning all inputted money.";
                drinkMoney = 0;
                cout << "\nYou have $" << drinkMoney << " left.";
            }
            else {
                drinkMoney -= (drinkList.drinkCost[1] * quantity);
                drinkList.drinkNum[1] -= quantity;
                moneyCollected += (drinkList.drinkCost[1] * quantity);
                cout << "\nYour drink(s) has been dispensed! Enjoy!";
                cout << "\nYou have $" << drinkMoney << " left.";
            }
        }

        else if (drinkSelect == '3') {
            if ((drinkMoney - (drinkList.drinkCost[2] * quantity)) < 0) {
                cout << "\nNot enough money. Returning all inputted money.";
                drinkMoney = 0;
                cout << "\nYou have $" << drinkMoney << " left.";
            }
            else if ((drinkList.drinkNum[2] - quantity) < 0) {
                cout << "Not enough of this drink left. There is " << drinkList.drinkNum[0] << " of this drink left.\n";
                cout << "Returning all inputted money.";
                drinkMoney = 0;
                cout << "\nYou have $" << drinkMoney << " left.";
            }
            else {
                drinkMoney -= (drinkList.drinkCost[2] * quantity);
                drinkList.drinkNum[2] -= quantity;
                moneyCollected += (drinkList.drinkCost[2] * quantity);
                cout << "\nYour drink(s) has been dispensed! Enjoy!";
                cout << "\nYou have $" << drinkMoney << " left.";
            }
        }

        else if (drinkSelect == '4') {
            if ((drinkMoney - (drinkList.drinkCost[3] * quantity)) < 0) {
                cout << "\nNot enough money. Returning all inputted money.";
                drinkMoney = 0;
                cout << "\nYou have $" << drinkMoney << " left.";
            }
            else if ((drinkList.drinkNum[3] - quantity) < 0) {
                cout << "Not enough of this drink left. There is " << drinkList.drinkNum[0] << " of this drink left.\n";
                cout << "Returning all inputted money.";
                drinkMoney = 0;
                cout << "\nYou have $" << drinkMoney << " left.";
            }
            else {
                drinkMoney -= (drinkList.drinkCost[3] * quantity);
                drinkList.drinkNum[3] -= quantity;
                moneyCollected += (drinkList.drinkCost[3] * quantity);
                cout << "\nYour drink(s) has been dispensed! Enjoy!";
                cout << "\nYou have $" << drinkMoney << " left.";
            }
        }

        else if (drinkSelect == '5') {
            if ((drinkMoney - (drinkList.drinkCost[4] * quantity)) < 0) {
                cout << "\nNot enough money. Returning all inputted money.";
                drinkMoney = 0;
                cout << "\nYou have $" << drinkMoney << " left.";
            }
            else if ((drinkList.drinkNum[4] - quantity) < 0) {
                cout << "Not enough of this drink left. There is " << drinkList.drinkNum[0] << " of this drink left.\n";
                cout << "Returning all inputted money.";
                drinkMoney = 0;
                cout << "\nYou have $" << drinkMoney << " left.";
            }
            else {
                drinkMoney -= (drinkList.drinkCost[4] * quantity);
                drinkList.drinkNum[4] -= quantity;
                moneyCollected += (drinkList.drinkCost[4] * quantity);
                cout << "\nYour drink(s) has been dispensed! Enjoy!";
                cout << "\nYou have $" << drinkMoney << " left.";
            }
        }
        else {
            cout << "\nNot a valid selection. Please try again.";
        }
        cout << endl;
        cout << "\nWould you like to keep buying drinks? Y/N: ";
        cin >> userSelect;
        if (userSelect == 'N' || userSelect == 'n') { // Done after a sale or sales have been made, thus there is data to report
            cout << endl;
            DailyReport(moneyCollected, drinkList.drinkNum[0], drinkList.drinkNum[1], drinkList.drinkNum[2], drinkList.drinkNum[3], drinkList.drinkNum[4]);
            return;
        }
        while (userSelect != 'Y' && userSelect != 'y' && userSelect != 'N' && userSelect != 'n') {
            cout << "Please type in either Y or N. ";
            cin >> userSelect;
        }
    } while (userSelect == 'Y' || userSelect == 'y');
}

int main()
{
    char buySelect = 0;

    cout << "Would you like to buy a drink? Y/N: ";
    cin >> buySelect;

    do {
        if (buySelect == 'Y' || buySelect == 'y') {
            buyDrink();
            break;
        }
        else if (buySelect == 'N' || buySelect == 'n') {
            break; // Ends the program
        }
        else {
            cout << "\nInvalid selection. Please enter Y or N.";
            continue;
        }
    } while (buySelect == 'Y' || buySelect == 'y');
    return 0;
}
