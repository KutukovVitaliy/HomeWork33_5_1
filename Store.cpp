//
// Created by kvitadmin on 31.03.2022.
//

#include "Store.h"
#include <exception>
#include <iostream>

Store::Store() {
    storage.emplace(std::make_pair("0123", 10));
    storage.emplace(std::make_pair("1234", 10));
    storage.emplace(std::make_pair("2345", 10));
    storage.emplace(std::make_pair("3456", 10));
    storage.emplace(std::make_pair("5678", 10));
    storage.emplace(std::make_pair("6789", 10));
}

void Store::PrintArticles() const {
    std::cout << "Articles in the store: " << std::endl;
    for(auto& el : storage){
        std::cout << el.first << " - " << el.second << " ";
    }
    std::cout << std::endl;
}

void Store::PrintBasket() const {
    std::cout << "Articles in the basket: " << std::endl;
    if(basket.empty())
    {

        std::cout << "Basket empty!" << std::endl;
        return;
    }
    for(auto& el : basket){
        std::cout << el.first << " - " << el.second << " ";
    }
    std::cout << std::endl;
}

void Store::AddGood(std::string article, int quantity) {
    if(quantity <= 0)
    {
        throw std::invalid_argument("Invalid quantity!");
    }
    std::map<std::string, int>::iterator storageIt = storage.find(article);
    if(storageIt == storage.end())
    {
        throw std::invalid_argument("Invalid article");

    }
    if(quantity > storageIt->second)
    {
        throw std::invalid_argument("No enough quantity of product!");

    }
    storageIt->second -= quantity;
    if(basket.find(article) != basket.end())
    {
        basket.find(article)->second += quantity;
    }
    else
    {
        basket.emplace(std::make_pair(article, quantity));
    }

}

void Store::RemoveGood(std::string article, int quantity) {
    if(quantity <= 0)
    {
        throw std::invalid_argument("Invalid quantity!");
    }
    std::map<std::string, int>::iterator basketIt = basket.find(article);
    if(basketIt == basket.end())
    {
        throw std::invalid_argument("Invalid article");
    }
    if(quantity > basketIt->second)
    {
        throw std::invalid_argument("No enough quantity of product!");
    }
    basketIt->second -= quantity;
    storage.find(article)->second += quantity;

}