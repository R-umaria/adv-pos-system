// an Advance POS system in which errors can be reduced using speech detection and more.
// 
// this is a project's core idea


#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <limits> // for std::numeric_limits

using namespace std;

int main() {
    vector<pair<string, pair<int, string>>> menu; // Stores size, quantity, and coffee addition
    char choice;
    int quantity;
    string size;
    string coffeeAddition;
    int addAmount;
    string additions = "";

    cout << "Main Menu:" << endl;
    cout << "Q: Quantity" << endl;
    cout << "S: Small" << endl;
    cout << "M: Medium" << endl;
    cout << "L: Large" << endl;
    cout << "X: Extra Large" << endl;
    cout << "P: Pay Now" << endl;

    while (true) {
        cout << "\nSelect an option (Q, S, M, L, X, P): ";

        // Input validation for char
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

            while (true) {
                cout << "\nCoffee addition \nB: Black \nC: Cream \nM: Milk \nS: Sugar \nR: Regular \nD: Double Double \nT: Triple Triple \nN: Next" << "\nChoice: ";
                cin >> choice;
                choice = tolower(choice);

                if (choice == 'n') break;

                if (choice == 'c' || choice == 'm' || choice == 's') {
                    cout << choice << ": ";
                    if (!(cin >> addAmount) || addAmount <= 0) {
                        cout << "Invalid input. Defaulting to 1." << endl;
                        addAmount = 1;
                    }
                }

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
                    continue; // Re-prompt if invalid option is selected
                }

                // Append the addition to the list of additions
                if (!additions.empty()) {
                    additions += ", ";
                }
                additions += coffeeAddition;
            }

            menu.push_back(make_pair(size, make_pair(quantity, additions)));
            additions = ""; // Reset for the next coffee selection
        }
        else if (choice == 's' || choice == 'm' || choice == 'l' || choice == 'x') {
            size = (choice == 's') ? "Small" :
                (choice == 'm') ? "Medium" :
                (choice == 'l') ? "Large" :
                "Extra Large";
            quantity = 1; // Default quantity

            while (true) {
                cout << "\nCoffee addition \nB: Black \nC: Cream \nM: Milk \nS: Sugar \nR: Regular \nD: Double Double \nT: Triple Triple \nN: Next" << "\nChoice: ";
                cin >> choice;
                choice = tolower(choice);

                if (choice == 'n') break;

                if (choice == 'c' || choice == 'm' || choice == 's') {
                    cout << "How much? (1, 2, 3...): ";
                    if (!(cin >> addAmount) || addAmount <= 0) {
                        cout << "Invalid input. Defaulting to 1." << endl;
                        addAmount = 1;
                    }
                }

                switch (choice) {
                case 'b': coffeeAddition = "Black"; break;
                case 'c': coffeeAddition = "Cream " + to_string(addAmount); break;
                case 'm': coffeeAddition = "Milk " + to_string(addAmount); break;
                case 's': coffeeAddition = "Sugar " + to_string(addAmount); break;
                case 'r': coffeeAddition = "Regular"; break;
                case 'd': coffeeAddition = "Double Double"; break;
                case 't': coffeeAddition = "Triple Triple"; break;
                default:
                    cout << "Invalid coffee addition option. Please try again." << endl;
                    continue; // Re-prompt if invalid option is selected
                }

                // Append the addition to the list of additions
                if (!additions.empty()) {
                    additions += ", ";
                }
                additions += coffeeAddition;
            }

            menu.push_back(make_pair(size, make_pair(quantity, additions)));
            additions = ""; // Reset for the next coffee selection
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    cout << "\n\n+-------------------+\n";
    cout << "| Checkout Summary: |";
    cout << "\n+-------------------+\n\n";
    for (const auto& item : menu) {
        cout << item.second.first << " * " << item.first << " (" << item.second.second << ")" << endl;
    }
    cout << "\n+-------------------+\n\n";
    return 0;
}
