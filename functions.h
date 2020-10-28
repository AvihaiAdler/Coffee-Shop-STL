#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <iostream>
using namespace std;

#include "CoffeeShop.h"

enum class eProductType { COFFEE, COOKIE, SALAD };

// initialize cofeeshop from user input
CoffeeShop initCoffeeShop();
CoffeeShop initCoffeeShopDebug();

// coffeeshop menu
void menu(CoffeeShop& shop);

// shift menu
bool shiftMenu(CoffeeShop& shop);

// 1.
void showCoffeeShop(CoffeeShop& shop);
// 2.
bool showEmployees(const vector<Employee>& employees);
// 3.
bool showCustomers(const vector<Customer>& customers);
// 4.
bool showProducts(const vector<const Product*>& products);
const Product* showProductsByType(CoffeeShop& shop, const std::string& productType)noexcept(false);
// 5.
bool showShifts(CoffeeShop& shop);
// 6.
void addProductMenu(CoffeeShop& shop);
bool addProduct(CoffeeShop& shop, const type_info& productType);
bool addCookieCoffee(CoffeeShop& shop);
// 7.
void addEmployee(CoffeeShop& shop);
// 8.
void addCustomer(CoffeeShop& shop);
// 9.
void openShift(CoffeeShop& shop);
// 10.
void makeOrder(CoffeeShop& shop, Shift& shift) noexcept(false);

void addEmployeesToShift(CoffeeShop& shop, Shift& shift);
void addProductToDailyMenu(CoffeeShop& shop, Shift& shift);

#endif