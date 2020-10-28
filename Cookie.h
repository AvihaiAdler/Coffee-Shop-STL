#ifndef __COOKIE_H__
#define __COOKIE_H__

#include <iostream>
#include "Product.h"

class Cookie : virtual public Product
{
public:
	enum class eFlourType { WHITE, WHOLE_WHEAT, GLUTEN_FREE, enumTypeEnd };
protected:
	eFlourType flour;

public:
	// ctor
	Cookie(const std::string& name, int calories, double cost, double price, eFlourType flour = eFlourType::WHITE);

	// clone
	virtual Product* clone() const override { return new Cookie(*this); }
	virtual const std::string getType() const override { return std::string("Cookie"); }

	// getters
	eFlourType getFlourType() const { return flour; }

	// functions
	void toOs(std::ostream& os) const override;
};

#endif