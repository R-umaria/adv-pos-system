// CoffeeOrder.h
#ifndef COFFEEORDER_H
#define COFFEEORDER_H

#include <string>
#include <vector>
#include <utility>

class CoffeeOrder {
public:
    // Constructor
    CoffeeOrder();

    // Methods to manage coffee orders
    void addOrder(const std::string& size, int quantity, const std::string& additions);
    void displayMenu();
    void processOrder();
    void displayCheckoutSummary();

private:
    std::vector<std::pair<std::string, std::pair<int, std::string>>> menu;
    void processAdditions(std::string& additions);
    void handleAddition(char choice, int& addAmount, std::string& coffeeAddition, std::string& additions);
    void displayAdditionsMenu();
};

#endif // COFFEEORDER_H
