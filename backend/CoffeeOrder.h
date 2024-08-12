// CoffeeOrder.h
#ifndef COFFEEORDER_H
#define COFFEEORDER_H

#include <string>
#include <vector>
#include <utility>

class CoffeeOrder {
public:
    CoffeeOrder();

    // Methods to manage coffee orders
    void addOrder(const std::string& size, int quantity, const std::string& additions);
    void displayMenu();
    void processOrder();
    void displayCheckoutSummary();
    void saveOrderToFile();
    void loadPreviousOrders();
    void viewOrderHistory();

private:
    std::vector<std::pair<std::string, std::pair<int, std::string>>> menu;
    std::string currentOrderFileName;

    void processAdditions(std::string& additions);
    void handleAddition(char choice, int& addAmount, std::string& coffeeAddition, std::string& additions);
    void displayAdditionsMenu();
    void writeOrderToFile();
};

#endif // COFFEEORDER_H
