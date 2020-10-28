#include "CoffeeShop.h"

CoffeeShop::CoffeeShop(const std::string& name, const Address& address) : address(address)
{
	setName(name);
	customersMaxSize = SIZE_MULTIPLIER;
	employeesMaxSize = SIZE_MULTIPLIER;
	shiftsMaxSize = 3;
	productsMaxSize = SIZE_MULTIPLIER;
}

CoffeeShop::CoffeeShop(CoffeeShop&& other) : address(std::move(other.address))
{
	if (this != &other)
	{
		customersMaxSize = other.customersMaxSize;
		employeesMaxSize = other.employeesMaxSize;
		shiftsMaxSize = other.shiftsMaxSize;
		productsMaxSize = other.productsMaxSize;

		name = other.name;
		customers = other.customers;
		employees = other.employees;
		products = other.products;
		shifts = other.shifts;
	}
}

CoffeeShop::CoffeeShop(const std::string& name, Address&& address) : address(std::move(address))
{
	setName(name);
	customersMaxSize = SIZE_MULTIPLIER;
	employeesMaxSize = SIZE_MULTIPLIER;
	shiftsMaxSize = 3;
	productsMaxSize = SIZE_MULTIPLIER;
}

// setters
bool CoffeeShop::setName(const std::string& name)
{
	this->name = name;
	return true;
}

bool CoffeeShop::setAddress(const Address& address)
{
	if (&this->address == &address)
		return false;

	this->address = address;
	return true;
}

bool CoffeeShop::addNewEmployee(const Employee& employee)
{
	if (employees.size() == employeesMaxSize)
	{
		employeesMaxSize *= SIZE_MULTIPLIER;
		employees.reserve(employeesMaxSize);
	}
	employees.push_back(employee);
	return true;
}

bool CoffeeShop::addNewEmployee(Employee&& employee)
{
	if (employees.size() == employeesMaxSize)
	{
		employeesMaxSize *= SIZE_MULTIPLIER;
		employees.reserve(employeesMaxSize);
	}
	employees.push_back(employee);
	return true;
}

bool CoffeeShop::addNewProduct(const Product& product)
{
	if (products.size() == productsMaxSize)
	{
		productsMaxSize *= SIZE_MULTIPLIER;
		products.reserve(productsMaxSize);
	}
	products.push_back(&product);
	return true;
}

bool CoffeeShop::addNewProduct(Product&& product)
{
	if (products.size() == productsMaxSize)
	{
		productsMaxSize *= SIZE_MULTIPLIER;
		products.reserve(productsMaxSize);
	}
	products.push_back(product.clone());
	return true;
}

bool CoffeeShop::addNewCustomer(const Customer& customer)
{
	if (customers.size() == customersMaxSize)
	{
		customersMaxSize *= SIZE_MULTIPLIER;
		customers.reserve(customersMaxSize);
	}
	customers.push_back(customer);
	return true;
}

bool CoffeeShop::addNewCustomer(Customer&& customer)
{
	Customer tmp = Customer(customer.getName(), customer.getPhoneNumber(), customer.isClubMember());
	return addNewCustomer(tmp);
}

bool CoffeeShop::openShift(double clubDiscountPercent, const Date& date)
{
	if (shifts.size() == shiftsMaxSize)
	{
		shiftsMaxSize *= SIZE_MULTIPLIER;
		shifts.reserve(shiftsMaxSize);
	}
	shifts.push_back(Shift(clubDiscountPercent, date));
	return true;
}

Shift& CoffeeShop::getCurrentShift() 
{
	return shifts.back();
}

std::ostream& operator<<(std::ostream& os, const CoffeeShop& coffeeShop)
{
	os << "Coffee Shop: " << coffeeShop.name << "\nNumber of employees: " << coffeeShop.getEmployees().size() <<
		"\nShifts: " << coffeeShop.getShifts().size() << std::endl;

	if (coffeeShop.shifts.size() != 0)
	{
		int counter = 1;
		for (auto shift : coffeeShop.getShifts())
		{
			std::cout << counter << ". " << shift << std::endl;
			counter++;
		}
			
	}


	if (coffeeShop.products.size() != 0)
	{
		int counter = 1;
		os << "Products list:\n";
		for (auto product : coffeeShop.products)
		{
			std::cout << counter << ". " << product << std::endl;
			counter++;
		}
			
	}

	return os;
}