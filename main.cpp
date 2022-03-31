#include <iostream>
#include <map>
#include "Store.h"

bool CheckCommand(std::string command);
int main() {
    std::string command;
    Store newStore;
    while(true)
    {
        std::cout << "Input command(add, remove, exit): ";
        std::cin >> command;
        if(command == "exit") break;

    }
    return 0;
}
