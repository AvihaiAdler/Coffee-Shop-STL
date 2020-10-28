#include "CookieCoffee.h"

CookieCoffee::CookieCoffee(const Cookie& cookie, const Coffee& coffee, double discountPercent, bool groundCookie) :
	Product(cookie), Cookie(cookie), Coffee(coffee)
{
	this->discountPercent = discountPercent;
	this->groundCookie = groundCookie;
}

bool CookieCoffee::setDiscountPercent(double discountPercent)
{
	if (discountPercent < 0)
		return false;
	this->discountPercent = discountPercent;
	return true;
}

void CookieCoffee::toOs(std::ostream& os) const
{
	os <<"Product name: cookie coffee\n" << "Discount percent: " << discountPercent << "\tGround in the coffee: " << (groundCookie != 0 ? "True" : "False") << std::endl;
}

