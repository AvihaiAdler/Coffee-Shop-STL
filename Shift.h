#ifndef __SHIFT_H__
#define __SHIFT_H__

#include <iostream>
#include "date.h"
#include "order.h"
#include <vector>

class Shift {
private:
	const int SIZE_MULTIPLIER = 2;
	double clubDiscountPercent;
	Date shiftDate;

	int employeesMaxSize;
	std::vector<Employee> employees;

	int dailyMenuMaxSize;
	std::vector<const Product*> dailyMenu;

	int ordersMaxSize;
	std::vector<Order> orders;

	Employee* shiftManager;
public:
	// ctor
	Shift(double clubDiscountPercent, const Date& shiftDate);
	// copy ctor
	Shift(const Shift& other);
	// assignment operator
	const Shift& operator=(const Shift& other);
	// move assignment operator
	const Shift& operator=(Shift&& other) = delete;

	// getters
	double getClubDiscountPercent() const { return clubDiscountPercent; }
	const Date* getShiftDate() const { return &shiftDate; }
	const std::vector<Employee>& getEmployees() const { return employees; }
	const std::vector<const Product*>& getDailyMenu() const { return dailyMenu; }
	const std::vector<Order>& getOrders() const { return orders; }

	// setters
	bool setClubDiscountPercent(double clubDiscountPercent);

	// functions
	bool addProductToMenu(const Product& product);
	bool addEmployeeToShift(const Employee& employee);
	bool addOrder(const Order& order);
	const Employee* getShiftManager() const;
	double getShiftProfit() const;
	friend std::ostream& operator<<(std::ostream& os, const Shift& shift);
};

#endif