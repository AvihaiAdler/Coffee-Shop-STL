#ifndef __COFFEESHOP_H__
#define __COFFEESHOP_H__

#include <iostream>
#include "Address.h"
#include "Shift.h"

class CoffeeShop {
private:
	const int SIZE_MULTIPLIER = 2;
	std::string name;
	Address address;

	int customersMaxSize;
	std::vector<Customer> customers;

	int employeesMaxSize;
	std::vector<Employee> employees;

	int shiftsMaxSize;
	std::vector<Shift> shifts;

	int productsMaxSize;
	std::vector<const Product*> products;

public:
	// ctor
	CoffeeShop(const std::string& name, const Address& address);
	// copy ctor
	CoffeeShop(const CoffeeShop& other) = delete;
	CoffeeShop(CoffeeShop&& other);
	// move ctor
	CoffeeShop(const std::string& name, Address&& address);
	// assignment operator
	const CoffeeShop& operator=(const CoffeeShop& other) = delete;
	// move assignment operator
	const CoffeeShop& operator=(CoffeeShop&& other) = delete;

	// getters
	const std::string& getName() const { return name; }
	const Address* getAddress() const { return &address; }
	const std::vector<Customer>& getCustomers() const { return customers; }
	const std::vector<Employee>& getEmployees() const { return employees; }
	const std::vector<Shift>& getShifts() const { return shifts; }
	const std::vector<const Product*>& getProducts() const { return products; }
	//const std::vector<Product*>& getProducts1() { return products; }

	// setters
	bool setName(const std::string& name);
	bool setAddress(const Address& address);

	// functions
	bool addNewEmployee(const Employee& employee);
	bool addNewEmployee(Employee&& employee);
	bool addNewProduct(const Product& product);
	bool addNewProduct(Product&& product);
	bool addNewCustomer(const Customer& customer);
	bool addNewCustomer(Customer&& customer);
	bool openShift(double clubDiscountPercent, const Date& date);
	Shift& getCurrentShift();
	friend std::ostream& operator<<(std::ostream& os, const CoffeeShop& coffeeShop);
};

#endif