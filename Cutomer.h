#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include "Person.h"

class Customer : public Person {
private:
	bool clubMember;

public:
	friend class CoffeeShop;
	// ctor
	Customer(const std::string& name, const std::string& phoneNumber, bool clubMember = false);

	// getters
	bool isClubMember() const { return clubMember; }

	// setters
	void setClubMember(bool clubMember);

	// functions
	void toOs(std::ostream& os) const override;
};

#endif