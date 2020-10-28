#include "Coffee.h"

Coffee::Coffee(const std::string& name, int calories, double cost, double price, bool withMilk, int sugarSpoons) :
	Product(name, calories, cost, price)
{
	if (sugarSpoons < 0)
		throw std::string("Spoon value must be higher than 0");
	this->withMilk = withMilk;
	this->sugarSpoons = sugarSpoons;
}

const Coffee& Coffee::operator+=(int sugarSpoons)
{
	addSugar(sugarSpoons);
	return *this;
}

bool Coffee::addSugar(int sugarSpoons)
{
	if (sugarSpoons <= 0)
		return false;
	this->sugarSpoons += sugarSpoons;
	return true;
}

bool Coffee::setMilk(bool isWithMilk)
{
	return withMilk = isWithMilk;
}

void Coffee::toOs(std::ostream& os) const
{
	Product::toOs(os);
	os << "Milk: " << (withMilk == 0 ? "False" : "True") << "\tSugar: " << sugarSpoons << " spoons\n";
}