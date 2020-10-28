#ifndef __PRODUCT_H__
#define __PRODUCT_H__
#include<iostream>

class Product
{
protected:
	std::string name;
	int calories;
	double cost, price;
public:
	// ctor
	Product(const std::string& name, int calories, double cost, double price) noexcept(false);
	// copy ctor
	Product(const Product& other);
	// move ctor
	Product(Product&& other);
	// assignment operator
	virtual const Product& operator=(const Product& other);
	// move assignment operator
	virtual const Product& operator=(Product&& other);

	// operators
	bool operator==(const Product& other) const;

	// clone
	virtual Product* clone() const = 0;// { return new Product(*this); }
	virtual const std::string getType() const = 0;

	// getters
	const std::string& getName() const { return name; }
	int getCalories() const { return calories; }
	double getCost() const { return cost; }
	double getPrice() const { return price; }

	// setters
	bool setName(const std::string& name);
	bool setCalories(int calories);
	bool setCost(double cost);
	bool setPrice(double price);

	// functions
	virtual void toOs(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Product& product);
};

#endif