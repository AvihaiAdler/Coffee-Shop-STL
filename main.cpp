#include "functions.h"
#include "CoffeeShop.h"

void custom_terminate()
{
	std::cout << "Something went wrong" << std::endl;
	exit(1);
}

int main()
{
	set_terminate(custom_terminate);
	try
	{
		CoffeeShop shop = initCoffeeShop();
		//CoffeeShop shop = initCoffeeShopDebug();

		menu(shop);
	}
	catch (std::string& msg)
	{
		std::cout << msg << std::endl;
	}

	return 0;
}
