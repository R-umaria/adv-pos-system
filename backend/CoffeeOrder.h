// CoffeeOrder.h
#ifndef COFFEEORDER_H
#define COFFEEORDER_H

#include <string>
#include <vector>
#include <utility>

class CoffeeOrder {
public:
    CoffeeOrder();

    void displayMenu(); // Display the main menu
    void processOrder(); // Process user input and orders

private:
    void addOrder(const std::string& size, int quantity, const std::string& additions); // Add an order to the menu
    void processAdditions(std::string& additions); // Process additions to the coffee
    void displayAdditionsMenu(); // Display additions menu
    void handleAddition(char choice, int& addAmount, std::string& coffeeAddition, std::string& additions); // Handle additions
    void displayCheckoutSummary(); // Display the checkout summary
    void saveOrderToFile(); // Save the current order to a file
    void viewOrderHistory(); // View previous orders from the file

    std::vector<std::pair<std::string, std::pair<int, std::string>>> menu; // Stores size, quantity, and coffee addition
    const std::string currentOrderFileName; // File to store orders
};

#endif // COFFEEORDER_H
