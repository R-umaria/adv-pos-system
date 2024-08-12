// an Advance POS system in which errors can be reduced using speech detection and more.
// 
// this is a project's core idea


#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> menu = { {'S', 0}, {'M', 0}, {'L', 0}, {'X', 0}, {'P', 0} };
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
        else if (menu.find(choice) != menu.end()) {
            cout << "Enter quantity (press 0 to skip, default is 1): ";
            cin >> quantity;

            if (quantity == 0) {
                quantity = 1;
            }

            menu[choice] += quantity;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    cout << "\nCheckout Summary:\n";
    for (const auto& item : menu) {
        if (item.second > 0) {
            switch (item.first) {
            case 'S': cout << "Small: " << item.second << endl; break;
            case 'M': cout << "Medium: " << item.second << endl; break;
            case 'L': cout << "Large: " << item.second << endl; break;
            case 'X': cout << "Extra Large: " << item.second << endl; break;
            }
        }
    }

    return 0;
}
