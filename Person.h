#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include <string>

class Person {
protected:
	std::string name, phoneNumber;

	Person(const Person& other);
	const Person& operator=(const Person& other);
	const Person& operator=(Person&& other);

public:
	// ctor
	Person(const std::string& name, const std::string& phoneNumber) noexcept(false);

	// operators
	virtual bool operator==(const Person& other) const;

	// getters
	const std::string& getName() const { return name; }
	const std::string& getPhoneNumber() const { return phoneNumber; }

	// setters
	bool setName(const std::string& name);
	bool setPhoneNumber(const std::string& phoneNumber);

	// functions
	virtual void toOs(std::ostream& os) const; //= 0;
	friend std::ostream& operator<<(std::ostream& os, const Person& person);
};

#endif
