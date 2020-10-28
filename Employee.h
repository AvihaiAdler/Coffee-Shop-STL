#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "Person.h"
#include "Date.h"

class Employee : public Person {
private:
	const int MINIMUN_WAGE_PER_HOUR = 25;
	double shiftSalary;
	Date hireDate;

public:
	friend class CoffeeShop;
	// ctor
	Employee(const std::string& name, const std::string& phoneNumber, double shiftSalary, const Date& hireDate) noexcept(false);
	Employee(const Employee& other);
	const Employee& operator=(const Employee& other);
	const Employee& operator=(Employee&& other);

	// operators
	bool operator<(const Employee& other) const;
	bool operator>(const Employee& other) const;
	const Employee* operator*(const Employee& other) const { return &other; }
	virtual bool operator==(const Employee& other) const;

	// getters
	double getShiftSalary() const { return shiftSalary; }
	const Date* getHireDate() const { return &hireDate; }

	// setters
	bool setShiftSalary(double shiftSalary);

	// functions
	int getSeniority() const;
	void toOs(std::ostream& os) const override;
};

#endif