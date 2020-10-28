#ifndef __SALAD_H__
#define __SALAD_H__

#include "Product.h"

class Salad : public Product
{
public:
	enum class eDressingType { VINEGRET, SOY, THOUSAND_ISLAND, enumTypeEnd };
private:
	eDressingType dressing;

public:
	// ctor
	Salad(const std::string& name, int calories, double cost, double price, eDressingType dressing = eDressingType::enumTypeEnd);

	// clone
	virtual Product* clone() const override { return new Salad(*this); }
	virtual const std::string getType() const override { return std::string("Salad"); }

	// getters
	eDressingType getDressing() const { return dressing; }

	// functions
	bool addDressing(eDressingType dressing);

	void toOs(std::ostream& os) const override;
	//	friend ostream& operator<<(ostream& os, const Salad& salad);
};

#endif
