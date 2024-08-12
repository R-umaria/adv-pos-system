// CoffeeOrder.cpp
#include "CoffeeOrder.h"
#include <iostream>
#include <limits> // for std::numeric_limits
#include <cctype> // for std::tolower

using namespace std;

// Constructor
CoffeeOrder::CoffeeOrder() {}

// Add an order to the menu
void CoffeeOrder::addOrder(const string& size, int quantity, const string& additions) {
    menu.push_back(make_pair(size, make_pair(quantity, additions)));
}

// Display the main menu
void CoffeeOrder::displayMenu() {
    cout << "Main Menu:" << endl;
    cout << "Q: Quantity" << endl;
    cout << "S: Small" << endl;
    cout << "M: Medium" << endl;
    cout << "L: Large" << endl;
    cout << "X: Extra Large" << endl;
    cout << "P: Pay Now" << endl;
}

// Process the coffee order based on user input
void CoffeeOrder::processOrder() {
    char choice;
    int quantity;
    string size;
    string coffeeAddition;
    int addAmount;
    string additions = "";

    while (true) {
        cout << "\nSelect an option (Q, S, M, L, X, P): ";

        if (!(cin >> choice)) {
            cout << "Enter a valid option!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        choice = tolower(choice); // Convert choice to lowercase for consistency

        if (choice == 'p') {
            break;
        }
        else if (choice == 'q') {
            cout << "Enter quantity: ";
            if (!(cin >> quantity)) {
                cout << "Invalid input. Please enter a valid quantity (integer)." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (quantity == 0) {
                quantity = 1; // Default quantity
            }

            cout << "Select size (S, M, L, X): ";
            cin >> choice;
            choice = tolower(choice);

            switch (choice) {
            case 's': size = "Small"; break;
            case 'm': size = "Medium"; break;
            case 'l': size = "Large"; break;
            case 'x': size = "Extra Large"; break;
            default:
                cout << "Invalid size option. Defaulting to Small." << endl;
                size = "Small";
            }

            processAdditions(additions);
            addOrder(size, quantity, additions);
            additions = ""; // Reset for the next coffee selection

        }
        else if (choice == 's' || choice == 'm' || choice == 'l' || choice == 'x') {
            size = (choice == 's') ? "Small" :
                (choice == 'm') ? "Medium" :
                (choice == 'l') ? "Large" :
                "Extra Large";
            quantity = 1; // Default quantity

            processAdditions(additions);
            addOrder(size, quantity, additions);
            additions = ""; // Reset for the next coffee selection

        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
}

// Display available additions and handle user input
void CoffeeOrder::processAdditions(string& additions) {
    char choice;
    int addAmount;
    string coffeeAddition;

    while (true) {
        displayAdditionsMenu();
        cin >> choice;
        choice = tolower(choice);

        if (choice == 'n') break;

        if (choice == 'c' || choice == 'm' || choice == 's') {
            cout << "How much? : ";
            if (!(cin >> addAmount) || addAmount <= 0) {
                cout << "Invalid input. Defaulting to 1." << endl;
                addAmount = 1;
            }
        }

        handleAddition(choice, addAmount, coffeeAddition, additions);
    }
}

// Display additions menu
void CoffeeOrder::displayAdditionsMenu() {
    cout << "\nCoffee addition \nB: Black \nC: Cream \nM: Milk \nS: Sugar \nR: Regular \nD: Double Double \nT: Triple Triple \nN: Next" << "\nChoice: ";
}

// Handle the selection of coffee additions
void CoffeeOrder::handleAddition(char choice, int& addAmount, string& coffeeAddition, string& additions) {
    switch (choice) {
    case 'b': coffeeAddition = "Black"; break;
    case 'c': coffeeAddition = "Cream " + to_string(addAmount); break;
    case 'm': coffeeAddition = "Milk " + to_string(addAmount); break;
    case 's': coffeeAddition = "Sugar " + to_string(addAmount); break;
    case 'r': coffeeAddition = "Regular"; break;
    case 'd': coffeeAddition = "Double Double"; break;
    case 't': coffeeAddition = "Triple Triple"; break;
    default:
        cout << "Invalid coffee addition option!" << endl;
        return; // Return early to re-prompt
    }

    if (!additions.empty()) {
        additions += ", ";
    }
    additions += coffeeAddition;
}

// Display the checkout summary
void CoffeeOrder::displayCheckoutSummary() {
    cout << "\n\n+-------------------+\n";
    cout << "| Checkout Summary: |";
    cout << "\n+-------------------+\n\n";
    for (const auto& item : menu) {
        cout << item.second.first << " * " << item.first << " (" << item.second.second << ")" << endl;
    }
    cout << "\n+-------------------+\n\n";
}
