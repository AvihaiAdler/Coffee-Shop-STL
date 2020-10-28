#ifndef __ADDRESS_H__
#define __ADDRESS_H__

#include <iostream>
#include <string>

class Address {
private:
	std::string city;
	std::string streetName;
	int streetNumber;
public:
	// ctor
	Address(const std::string& city, const std::string& streetName, int streetNumber);

	// getters
	const std::string& getCity() const { return city; }
	const std::string& getStreetName() const { return streetName; }
	int getStreetNumber() const { return streetNumber; }

	//setters
	bool setCity(const std::string& city);
	bool setStreet(const std::string& street);

	// functions
	friend std::ostream& operator<<(std::ostream& os, const Address& address);
};

#endif