#include "Cutomer.h"

Customer::Customer(const std::string& name, const std::string& phoneNumber, bool clubMember) :
	Person(name, phoneNumber)
{
	setClubMember(clubMember);
}

void Customer::setClubMember(bool clubMember)
{
	this->clubMember = clubMember;
}

void Customer::toOs(std::ostream& os) const
{
	Person::toOs(os);
	os << "Club member:\t" << isClubMember() << std::endl;
}