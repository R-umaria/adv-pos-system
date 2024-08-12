// an Advance POS system in which errors can be reduced using speech detection and more.
// 
// this is a project's core idea


#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    vector<pair<char, int>> menu;
    char choice;
    int quantity;

    cout << "Main Menu:" << endl;
    cout << "S: Small" << endl;
    cout << "M: Medium" << endl;
    cout << "L: Large" << endl;
    cout << "X: Extra Large" << endl;
    cout << "P: Pay Now" << endl;

    while (true) {
        cout << "\nSelect an option (S, M, L, X, P): ";
        cin >> choice;

        if (choice == 'P') {
            break;
        }
        else if (choice == 'S' || choice == 'M' || choice == 'L' || choice == 'X') {
            cout << "Enter quantity (press 0 to skip, default is 1): ";
            cin >> quantity;

            if (quantity == 0) {
                quantity = 1;
            }

            menu.push_back(make_pair(choice, quantity));
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    cout << "\nCheckout Summary:\n";
    for (const auto& item : menu) {
        switch (item.first) {
        case 'S': cout << "Small: " << item.second << endl; break;
        case 'M': cout << "Medium: " << item.second << endl; break;
        case 'L': cout << "Large: " << item.second << endl; break;
        case 'X': cout << "Extra Large: " << item.second << endl; break;
        }
    }

    return 0;
}
