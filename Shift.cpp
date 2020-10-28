#include "Shift.h"

Shift::Shift(double clubDiscountPercent, const Date& shiftDate) : shiftDate(shiftDate)
{
	if (!setClubDiscountPercent(clubDiscountPercent))
		setClubDiscountPercent(0);

	employeesMaxSize = SIZE_MULTIPLIER;
	dailyMenuMaxSize = SIZE_MULTIPLIER;
	ordersMaxSize = SIZE_MULTIPLIER;
}

Shift::Shift(const Shift& other) : shiftDate(other.shiftDate)
{
	*this = other;
}

const Shift& Shift::operator=(const Shift& other)
{
	if (this != &other)
	{
		shiftDate = other.shiftDate;
		clubDiscountPercent = other.clubDiscountPercent;
		employees = other.employees;
		dailyMenu = other.dailyMenu;
		orders = other.orders;

		employeesMaxSize = other.employeesMaxSize;
		dailyMenuMaxSize = other.dailyMenuMaxSize;
		ordersMaxSize = other.ordersMaxSize;
	}
	return *this;
}

bool Shift::setClubDiscountPercent(double clubDiscountPercent)
{
	if (clubDiscountPercent < 0)
		return false;
	this->clubDiscountPercent = clubDiscountPercent;
	return true;
}

bool Shift::addProductToMenu(const Product& product)
{
	if (dailyMenu.size() == dailyMenuMaxSize)
	{
		dailyMenuMaxSize *= SIZE_MULTIPLIER;
		dailyMenu.reserve(dailyMenuMaxSize);
	}
	dailyMenu.push_back(&product);
	return true;
}

bool Shift::addEmployeeToShift(const Employee& employee)
{		
	if (employees.size() == employeesMaxSize)
	{
		employeesMaxSize *= SIZE_MULTIPLIER;
		employees.reserve(employeesMaxSize);
	}
	employees.push_back(employee);
	return true;
}

bool Shift::addOrder(const Order& order)
{
	if (orders.size() == ordersMaxSize)
	{
		ordersMaxSize *= SIZE_MULTIPLIER;
		orders.reserve(ordersMaxSize);
	}
	orders.push_back(order);
	return true;
}

const Employee* Shift::getShiftManager() const
{
	const Employee* shiftManager = &employees.at(0);
	for (int i = 0; i < (int)employees.size(); i++)
	{
		if (*shiftManager < employees[i])
			shiftManager = &employees[i];
	}
	return shiftManager;
}
double Shift::getShiftProfit() const
{
	double totalProductsCost = 0;
	double totalSales = 0;
	
	auto order_start_itr = orders.begin();
	auto order_end_itr = orders.end();
	for (; order_start_itr != order_end_itr; order_start_itr++)
	{
		totalSales += order_start_itr->getOrderTotal();
		for (int i = 0; i < order_start_itr->getItems().getSize(); i++)
		{
			totalProductsCost += order_start_itr->getItems()[i]->getCost();
		}
	}
	return totalSales - totalProductsCost;
}

std::ostream& operator<<(std::ostream& os, const Shift& shift)
{
	auto start_itr = shift.getEmployees().begin();
	auto end_itr = shift.getEmployees().end();
	os << "Shift at: " << *shift.getShiftDate() << "Employees on shift: " << (int)shift.getEmployees().size() << std::endl;
	
	for (; start_itr != end_itr; start_itr++)
	{
		os << *start_itr << std::endl;
	}
	
	os << "\nNumber of orders processed in shift: " << (int)shift.getOrders().size() << "\nProfit made in the Shift: " << shift.getShiftProfit() <<
		"\nShift Manager: " << *shift.getShiftManager() << std::endl;
	return os;
}