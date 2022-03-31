#include <iostream>
#include <map>
#include "Store.h"

bool CheckCommand(std::string command);
int main() {
    std::string command, article;
    int quantity;
    Store newStore;

    while(true)
    {
        try
        {
            newStore.PrintArticles();
            newStore.PrintBasket();
            std::cout << "Input command(add, remove, exit): ";
            std::cin >> command;
            if(command == "exit") break;
            else if(command != "add" )
            {
                if (command != "remove")
                {
                    throw std::invalid_argument("Invalid command! Try again.");
                }
            }
            std::cout << "Input article: ";
            std::cin >> article;
            std::cout << "Input quantity: ";
            std::cin >> quantity;
            if(command == "add") newStore.AddGood(article, quantity);
            else if(command == "remove") newStore.RemoveGood(article, quantity);
        }
        catch (std::exception& ex){
            std::cerr << ex.what() << std::endl;
        }
    }
    return 0;
}
