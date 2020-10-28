#pragma warning(disable : 4996)
#include "Person.h"

Person::Person(const std::string& name, const std::string& phoneNumber)
{
	if (!setName(name))
		throw std::string("Invalid Name");
	if (!setPhoneNumber(phoneNumber))
		throw std::string("Invalid Phone number");
}

Person::Person(const Person& other)
{
	*this = other;
}

const Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		setName(other.name);
		setPhoneNumber(other.phoneNumber);
	}
	return *this;
}

const Person& Person::operator=(Person&& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->phoneNumber = other.phoneNumber;

		other.name = nullptr;
		other.phoneNumber = nullptr;
	}
	return *this;
}

bool Person::operator==(const Person& other) const
{
	if (this == &other)
		return true;
	if (name == other.name && phoneNumber == other.phoneNumber)
		return true;
	return false;
}

bool Person::setName(const std::string& name)
{
	if (isdigit(name.at(0)))
		return false;
	this->name = name;
	return true;
}

bool Person::setPhoneNumber(const std::string& phoneNumber)
{
	if (!isdigit(phoneNumber[0]) || phoneNumber[0] != '0')
		return false;
	this->phoneNumber = phoneNumber;
	return true;
}

void Person::toOs(std::ostream& os) const
{
	os << name << "\t" << phoneNumber << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	person.toOs(os);
	return os;
}