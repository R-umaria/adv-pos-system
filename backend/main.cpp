// an Advance POS system in which errors can be reduced using speech detection and more.
// 
// this is a project's core idea

// main.cpp
#include "CoffeeOrder.h"
#include <iostream>

using namespace std;

int main() {
    CoffeeOrder coffeeOrder;

    while (true) {
        coffeeOrder.displayMenu(); // Display menu once per iteration
        coffeeOrder.processOrder(); // Process user input and orders
    }

    return 0;
}
