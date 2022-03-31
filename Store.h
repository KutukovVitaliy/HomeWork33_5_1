//
// Created by kvitadmin on 31.03.2022.
//

#ifndef HOMEWORK33_5_1_STORE_H
#define HOMEWORK33_5_1_STORE_H
#include <map>

class Store {
private:
    std::map<std::string, int> basket;
    std::map<std::string, int> storage;
public:
    Store();
    void PrintArticles() const;
    void PrintBasket() const;
    bool AddGood(std::string article, int quantity);
    bool RemoveGood(std::string article, int quantity);
};


#endif //HOMEWORK33_5_1_STORE_H
