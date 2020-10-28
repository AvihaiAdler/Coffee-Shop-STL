#ifndef __COOKIECOFFEE_H__
#define __COOKIECOFFEE_H__

#include "Cookie.h"
#include "Coffee.h"

class CookieCoffee : public Cookie, public Coffee {
private:
	bool groundCookie;
	double discountPercent;

public:
	// ctor
	CookieCoffee(const Cookie& cookie, const Coffee& coffee, double discountPercent = 0, bool grindCookie = false);

	// clone
	virtual Product* clone() const override { return new CookieCoffee(*this); }
	virtual const std::string getType() const override { return std::string("CookieCoffee"); }

	// getters
	bool isGrindCookie() const { return groundCookie; }
	double getDiscountPercent() const { return discountPercent; }

	// setters
	bool setDiscountPercent(double discountPercent);

	// functions
	virtual void toOs(std::ostream& os) const override;
	//	friend ostream& operator<<(ostream& os, const CookieCoffee& cookieCoffee);
};

#endif
