#include "Address.h"

Address::Address(const std::string& city, const std::string& streetName, int streetNumber)
{
	if (!setCity(city))
		setCity("Unknown");
	if (!setStreet(streetName))
		setStreet("Unknown");
	this->streetNumber = streetNumber;
}

std::ostream& operator<<(std::ostream& os, const Address& address)
{
	os << "Address: " << address.city << "\t" << address.streetName << "\t" << address.streetNumber << std::endl;
	return os;
}

bool Address::setCity(const std::string& city)
{
	this->city = city;
	return true;
}

bool Address::setStreet(const std::string& streetName)
{
	this->streetName = streetName;
	return true;
}
