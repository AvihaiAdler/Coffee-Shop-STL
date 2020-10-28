#include <string>
#include "Product.h"

Product::Product(const std::string& name, int calories, double cost, double price)
{
	if (!setName(name))
		throw std::string("Invalid product name");
	if (!setCalories(calories))
		throw std::string("Invalid Calories values");
	if (!setCost(cost))
		throw std::string("Cost value must be higher than 0");
	if (!setPrice(price))
		throw std::string("Price value must be higher than 0");
}

Product::Product(const Product& other)
{
	*this = other;
}

Product::Product(Product&& other)
{
	*this = other;
}

const Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		setName(other.name);
		setCalories(other.calories);
		setCost(other.cost);
		setPrice(other.price);
	}
	return *this;
}

const Product& Product::operator=(Product&& other)
{
	this->name = other.name;

	setCalories(other.calories);
	setCost(other.cost);
	setPrice(other.price);
	return *this;
}

bool Product::operator==(const Product& other) const
{
	return name == other.name;
}

bool Product::setName(const std::string& name)
{
	if (isdigit(name[0]))
		return false;
	this->name = name;
	return true;
}

bool Product::setCalories(int calories)
{
	if (calories < 0)
		return false;
	this->calories = calories;
	return true;
}

bool Product::setCost(double cost)
{
	if (cost <= 0)
		return false;
	this->cost = cost;
	return true;
}

bool Product::setPrice(double price)
{
	if (price <= 0)
		return false;
	this->price = price;
	return true;
}

void Product::toOs(std::ostream& os) const
{
	os << "Product name: " << name << "\nCalories: " << calories << "\tCost: " << cost << "\tPrice: " << price << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Product& product)
{
	product.toOs(os);
	return os;
}
