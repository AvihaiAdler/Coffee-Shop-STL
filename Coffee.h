#ifndef __COFFEE_H__
#define __COFFEE_H__

#include "Product.h"

class Coffee : virtual public Product
{
protected:
	bool withMilk;
	int sugarSpoons;
public:
	// ctor
	Coffee(const std::string& name, int calories, double cost, double price, bool withMilk = false, int sugarSpoons = 0) noexcept(false);

	// operators
	const Coffee& operator+=(int sugarSpoons);

	// clone
	virtual Product* clone() const override { return new Coffee(*this); }
	virtual const std::string getType() const override { return std::string("Coffee"); }

	// getters
	bool getWithMilk() const { return withMilk; }
	int getSugarSpoons() const { return sugarSpoons; }

	// functions
	bool addSugar(int sugarSpoons = 1);
	bool setMilk(bool isWithMilk);

	void toOs(std::ostream& os) const override;
};

#endif
