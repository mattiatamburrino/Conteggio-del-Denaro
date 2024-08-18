# My Money Counter

**My Money Counter** is an intermediate-level C++ program designed to help you accurately calculate the total amount of cash you have on hand.

## How It Works

1. 💵 **Enter Banknotes**: Input the quantity of each type of banknote you possess.
2. 🪙 **Enter Coins**: Input the quantity of each type of coin you have.
3. 💰 **Get the Total**: The program calculates and provides the total cash amount.

The final total is saved in the **wallet.txt** file for easy reference. Each entry in this file will be accompanied by the **date of the saving**, allowing you to track changes over time.

### Supported Currencies

Currently, the program operates exclusively with Euro banknotes and coins. In the future, I plan to introduce support for other major currencies.

- 💶 **Euro** (€)

Sure, here’s a polished version of your README in English:

## How to Run the Program

To run the program, you need an IDE. I recommend using Visual Studio Code. Next, install MinGW by following the official guide here: [MinGW Installation Guide](https://code.visualstudio.com/docs/cpp/config-mingw). After setting up MinGW, open the folder containing my project in Visual Studio Code. 

In the terminal, compile the program by typing:
```
g++ wallet_manager.cpp
```
This command will generate an executable file named `a.exe`. To run the program, simply type:
```
.\a.exe
```
