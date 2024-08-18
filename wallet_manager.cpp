#include <iostream>
#include <fstream> // File
#include <ctime> // Date dd/mm/yyyy
using namespace std;

// Number of banknotes of various denominations
struct euro_paper
{
    int fivehundred = 0; // Number of 500 euro banknotes
    int twohundred = 0;  // Number of ...
    int onehundred = 0;
    int fifty = 0;
    int twenty = 0;
    int ten = 0;
    int five = 0;
};

// Number of coins of various denominations
struct euro_coins
{
    int two = 0; // Number of 2 euro coins
    int one = 0; // Number of ...
    int fifty_c = 0;
    int twenty_c = 0;
    int ten_c = 0;
    int five_c = 0;
    int two_c = 0;
    int one_c = 0;
};

// Prototypes
void input(euro_paper &paper, euro_coins &coins);
double calculate(const euro_paper &paper, const euro_coins &coins);
void save_balance(double total_balance);

int main()
{
    char choice;

    // Loop to restart the program based on user choice
    do {
        // Instantiate a structure for banknotes and coins
        euro_paper paper; 
        euro_coins coins;

        input(paper, coins); // Call for entering the number of banknotes and coins

        // Calculate the total balance using the entered data and print it
        double total_balance = calculate(paper, coins); 
        cout << "\nWallet = " << total_balance << " euros." << endl;

        save_balance(total_balance); // Save the total balance to the file (wallet.txt)

         // Ask the user if they want to perform a new money count using the choice variable defined above
        cout << "\nDo you want to do a new count? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y'); // Repeat the loop if the user chooses 'y' or 'Y'

    return 0;
}

// Function to enter the number of banknotes and coins
void input(euro_paper &paper, euro_coins &coins)
{
    cout << "BANKNOTES:" << endl;
    // The user records the entry for each type of banknote
    cout << "No. of 500 Euro: "; cin >> paper.fivehundred;
    cout << "No. of 200 Euro: "; cin >> paper.twohundred;
    cout << "No. of 100 Euro: "; cin >> paper.onehundred;
    cout << "No. of 50 Euro: "; cin >> paper.fifty;
    cout << "No. of 20 Euro: "; cin >> paper.twenty;
    cout << "No. of 10 Euro: "; cin >> paper.ten;
    cout << "No. of 5 Euro: "; cin >> paper.five;

    cout << "\nCOINS:" << endl; 
    // The user records the entry for each type of coin
    cout << "No. of 2 Euro: "; cin >> coins.two;
    cout << "No. of 1 Euro: "; cin >> coins.one;
    cout << "No. of 50 Cent: "; cin >> coins.fifty_c;
    cout << "No. of 20 Cent: "; cin >> coins.twenty_c;
    cout << "No. of 10 Cent: "; cin >> coins.ten_c;
    cout << "No. of 5 Cent: "; cin >> coins.five_c;
    cout << "No. of 2 Cent: "; cin >> coins.two_c;
    cout << "No. of 1 Cent: "; cin >> coins.one_c;

    // Handle incorrect input (e.g., entering a non-int value as defined in the structures)
    if(cin.fail()) { 
        cin.clear(); // Reset the error state of the input stream
        cin.ignore(10000, '\n'); // Discard invalid input
        cout << "Error in input. Please try again.\n"; 
        input(paper, coins); // Recall the function to allow the user to re-enter data
    }
}

// Function to calculate the total balance of the wallet
double calculate(const euro_paper &paper, const euro_coins &coins)
{
    // Arrays containing the nominal values of banknotes and coins
    const int note_values[] = {500, 200, 100, 50, 20, 10, 5};
    const int banknotes[] = {paper.fivehundred, paper.twohundred, paper.onehundred, paper.fifty, paper.twenty, paper.ten, paper.five};

    const double coin_values[] = {2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
    const int coins_array[] = {coins.two, coins.one, coins.fifty_c, coins.twenty_c, coins.ten_c, coins.five_c, coins.two_c, coins.one_c};

    // Total banknotes and coins. Initialized to 0
    int total_banknotes = 0;
    double total_coins = 0;

    // Total banknotes
    for(int i = 0; i < 7; i++) {
        total_banknotes += banknotes[i] * note_values[i];
    }

    // Total coins
    for(int i = 0; i < 8; i++) {
        total_coins += coins_array[i] * coin_values[i];
    }

    return total_banknotes + total_coins; // Final TOTAL 
}

// Function to save the total balance to a file
void save_balance(double total_balance)
{
    time_t t = time(0); // Get the current time
    tm* now = localtime(&t); // Convert the time to local format
    char date[11]; 
    strftime(date, sizeof(date), "%d/%m/%Y", now); // Format the date as day/month/year

    ofstream file("wallet.txt", ios::app); // Open the file in append mode (app) to add data without overwriting previously saved values

    if (file.is_open()) { // Check if the file was opened correctly
        file << date << "\t" << total_balance << " euros." << endl; // Write the date and balance to the file
        file.close(); // Close the file
        cout << "\nThe total balance has been saved to the 'wallet.txt' file." << endl;
    } else {
        cout << "Unable to open the file!" << endl; // Report an error if the file does not open
    }
}
