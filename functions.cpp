#include <iostream>
#include "functions.h"
#include "Salad.h"
#include "Coffee.h"
#include "Cookie.h"
#include "CookieCoffee.h"
#include "Shift.h"
#include "Cutomer.h"
#include "Employee.h"
#include "Order.h"
#include "CoffeeShop.h"

using namespace std;

const int STRING_SIZE = 255;
extern const char* sFlourType[];
extern const char* sDressingType[];

CoffeeShop initCoffeeShop()
{
	char name[STRING_SIZE];
	char city[STRING_SIZE], streetName[STRING_SIZE];
	int streetNum;

	// enter coffeeshop details
	cout << "Enter Coffee-Shop name" << endl;
	cin.getline(name, STRING_SIZE);

	cout << "Enter Address details:" << endl;
	cout << "Enter City:" << endl;
	cin.getline(city, STRING_SIZE);

	cout << "Enter Street name:" << endl;
	cin.getline(streetName, STRING_SIZE);

	cout << "Enter Street number:" << endl;
	cin >> streetNum;

	return CoffeeShop(name, Address(city, streetName, streetNum));
}

//Debug
CoffeeShop initCoffeeShopDebug()
{
	return CoffeeShop("Mozarela", Address("Tel Aviv", "Karlibch", 10));
}

// coffeeshop menu
void menu(CoffeeShop& shop)
{
	int choice = -1;
	bool shiftOpen = false;

	while (choice != 0)
	{
		// get choice from user
		cout << "Shop Menu" << endl;
		cout << "===============" << endl;

		cout << "Enter your choice:" << endl;
		cout << "1 - Show coffee shop details" << endl;
		cout << "2 - Show employees details" << endl;
		cout << "3 - Show customers details" << endl;
		cout << "4 - Show products details" << endl;
		cout << "5 - Show shifts details" << endl;
		cout << "6 - Add new product to coffee shop" << endl;
		cout << "7 - Add new employee to coffee shop" << endl;
		cout << "8 - Add new customer to coffee shop" << endl;
		cout << "9 - Shift menu" << endl;
		cout << "0 - Quit" << endl;

		if (!(cin >> choice))
		{
			cin.clear();
			cin.ignore();
			choice = -1;
		}

		switch (choice)
		{
		case 1:
			// 1. show coffeeshop details
			showCoffeeShop(shop);
			break;
		case 2:
			// 2. show employees details
			showEmployees(shop.getEmployees());
			break;
		case 3:
			// 3. show customers details
			showCustomers(shop.getCustomers());
			break;
		case 4:
			// 4. show products details
			showProducts(shop.getProducts());
			break;
		case 5:
			// 5. show shifts details
			showShifts(shop);
			break;
		case 6:
			// 6. add new product to coffee shop
			addProductMenu(shop);
			break;
		case 7:
			// 7. add new employee to coffee shop
			addEmployee(shop);
			break;
		case 8:
			// 8. add new customer to coffee shop
			addCustomer(shop);
			break;
		case 9:
			// 9. shift menu
			// open shift if none is open
			if (!shiftOpen)
				openShift(shop);
			shiftOpen = shiftMenu(shop);
			break;
		case 0:
			// exit menu
			cout << "Thank you for using the Coffee Shop System, goodbye." << endl;
			return;
		default:
			// show unknown choice msg
			cout << "Invalid choice, try again." << endl;
			break;
		}
	}
}

// return true if shift is still open
bool shiftMenu(CoffeeShop& shop)
{
	int choice = -1;

	// get current shift
	Shift& shift = shop.getCurrentShift();

	while (choice)
	{
		// get choice from user
		cout << "Shift Menu" << endl;
		cout << "===============" << endl;

		cout << "Enter your choice:" << endl;
		cout << "1 - Show daily menu" << endl;
		cout << "2 - Make order" << endl;
		cout << "3 - Add employee to shift" << endl;
		cout << "4 - Add product to dailyMenu" << endl;
		cout << "5 - Close shift" << endl;
		cout << "0 - Quit" << endl;

		if (!(cin >> choice))
		{
			cin.clear();
			cin.ignore();
			choice = -1;
		}

		switch (choice)
		{
		case 1:
			// 1. show daily menu
			showProducts(shift.getDailyMenu());
			break;
		case 2:
			// 2. make order
			makeOrder(shop, shift);
			break;
		case 3:
			// 3. add employee to shift
			addEmployeesToShift(shop, shift);
			break;
		case 4:
			// 4. add product to dailyMenu
			addProductToDailyMenu(shop, shift);
			break;
		case 5:
			// 5. close shift
			return false;
		case 0:
			// exit shift menu
			return true;
		default:
			// show unknown choice msg
			cout << "Invalid choice, try again." << endl;
			break;
		}
	}
	return true;
}

void openShift(CoffeeShop& shop)
{
	int day, month, year;
	double discount;

	// init shift
	cout << "Enter club discount: " << endl;
	cin >> discount;

	cout << "Enter Date details: " << endl;
	cout << "day: " << endl;
	cin >> day;
	cout << "month: " << endl;
	cin >> month;
	cout << "year: " << endl;
	cin >> year;

	Date date(day, month, year);
	shop.openShift(discount, date);
}


void showCoffeeShop(CoffeeShop& shop)
{
	cout << "Coffee shop details are:" << shop << endl;
}

bool showEmployees(const vector<Employee>& employees)
{
	if (employees.size() == 0)
	{
		cout << "No employees founded" << endl;
		return false;
	}

	cout << "The employees are:" << endl;
	int index = 1;
	for (auto employee : employees)
	{
		cout << index << ". " << employee << endl;
		index++;
	}
	return true;
}

bool showCustomers(const vector<Customer>& customers)
{
	if (customers.size() == 0)
	{
		cout << "No custumers founded" << endl;
		return false;
	}

	cout << "The customers are:" << endl;
	int index = 1;
	for (auto customer : customers)
	{
		cout << index << ". " << customer << endl;
		index++;
	}
	return true;
}

bool showProducts(const vector<const Product*>& products)
{
	if (products.size() == 0)
	{
		cout << "No proucts founded" << endl;
		return false;
	}

	cout << "The products are:" << endl;

	for (int i = 0; i < (int)products.size(); i++)
	{
		cout << i + 1 << ". " << *products.at(i) << endl;
	}
	return true;
}

const Product* showProductsByType(CoffeeShop& shop, const std::string& productType)
{
	int choice, counter = 1;

	if (shop.getProducts().size() == 0)
		throw std::string("Product list is empty");

	for (auto product : shop.getProducts())
	{
		cout << counter << ". " << *product << endl;
		counter++;
	}

	cin >> choice;
	return shop.getProducts()[choice - 1];
}

bool showShifts(CoffeeShop& shop)
{
	if (shop.getShifts().size() == 0)
	{
		cout << "No shifts founded" << endl;
		return false;
	}

	cout << "The shifts of the coffee shop are:" << endl;
	int index = 1;
	for (auto shift : shop.getShifts())
	{
		cout << index << ". " << shift << endl;
		index++;
	}
	return true;
}

void addProductMenu(CoffeeShop& shop)
{
	int choice = -1;

	while (choice != 0)
	{
		// get choice from user
		cout << "Choose product type to add:" << endl;
		cout << "1 - Coffee" << endl;
		cout << "2 - Cookie" << endl;
		cout << "3 - Salad" << endl;
		cout << "4 - CookieCoffee" << endl;
		cout << "0 - Quit" << endl;

		while (getchar() != '\n');
		if (!(cin >> choice))
		{
			cin.clear();
			cin.ignore();
			choice = -1;
		}

		switch (choice)
		{
		case 1:
			// 1. add coffee product to coffee shop
			addProduct(shop, typeid(Coffee));
			break;
		case 2:
			// 2. add cookie product to coffee shop
			addProduct(shop, typeid(Cookie));
			break;
		case 3:
			// 3. add salad product to coffee shop
			addProduct(shop, typeid(Salad));
			break;
		case 4:
			// 4. add CookieCoffee product to coffee shop
			addCookieCoffee(shop);
			break;
		case 0:
			// exit menu
			return;
		default:
			// show unknown choice msg
			cout << "Invalid choice, try again." << endl;
			break;
		}
	}
}

bool addProduct(CoffeeShop& shop, const type_info& productType)
{
	char name[STRING_SIZE];
	int calories;
	double cost, price;
	int choice;

	while (getchar() != '\n');

	cout << "Enter product's name" << endl;
	cin.getline(name, STRING_SIZE);

	cout << "Enter product's calories" << endl;
	cin >> calories;

	cout << "Enter product's cost" << endl;
	cin >> cost;

	cout << "Enter product's price" << endl;
	cin >> price;

	if (productType == typeid(Coffee))
		shop.addNewProduct(Coffee(name, calories, cost, price));
	else if (productType == typeid(Salad))
		shop.addNewProduct(Salad(name, calories, cost, price));
	else if (productType == typeid(Cookie))
	{
		cout << "Select cookie flour type index" << endl;

		while (true)
		{
			for (int i = 0; i < (int)Cookie::eFlourType::enumTypeEnd; i++)
				cout << i + 1 << ". " << sFlourType[i] << endl;

			cin >> choice;

			if (choice < 1 || choice > (int)Cookie::eFlourType::enumTypeEnd)
				cout << "Invalid choice" << endl;
			else break;
		}

		shop.addNewProduct(Cookie(name, calories, cost, price, (Cookie::eFlourType)(choice - 1)));
	}

	return true;
}

bool addCookieCoffee(CoffeeShop& shop)
{
	const Product* p1, *p2;
	int tmp;
	double discountPercent;
	char choice;

	while (getchar() != '\n');

	cout << "Enter product's discount percent:" << endl;
	cin >> tmp;
	discountPercent = (double)tmp / 100;

	cout << "Choose from existing Cookie product:" << endl;
	p1 = showProductsByType(shop, std::string("Cookie"));//typeid(Cookie));

	cout << "Choose from existing Coffee product:" << endl;
	p2 = showProductsByType(shop, std::string("Coffee")); //typeid(Coffee));

	cout << "Would you like to grind the cookie in the coffee? Y/N" << endl;
	cin >> choice;

	shop.addNewProduct(
		CookieCoffee(
			*dynamic_cast<const Cookie*>(p1),
			*dynamic_cast<const Coffee*>(p2),
			discountPercent,
			choice == 'Y' ? true : false));

	return true;
}

void addEmployee(CoffeeShop& shop)
{
	char name[STRING_SIZE];
	char phoneNumber[STRING_SIZE];
	double shiftSalary;
	int day, month, year;

	while (getchar() != '\n');

	cout << "Enter employee's name" << endl;
	cin.getline(name, STRING_SIZE);

	cout << "Enter employee's phone number" << endl;
	cin.getline(phoneNumber, STRING_SIZE);

	cout << "Enter employee's shift salary" << endl;
	cin >> shiftSalary;

	cout << "Enter employee's hire date details: " << endl;
	cout << "day: " << endl;
	cin >> day;
	cout << "month: " << endl;
	cin >> month;
	cout << "year: " << endl;
	cin >> year;

	shop.addNewEmployee(Employee(name, phoneNumber, shiftSalary, Date(day, month, year)));
}

void addCustomer(CoffeeShop& shop)
{
	char name[STRING_SIZE];
	char phoneNumber[STRING_SIZE];
	char club[STRING_SIZE];
	bool clubMember;

	while (getchar() != '\n');

	cout << "Enter customer's name" << endl;
	cin.getline(name, STRING_SIZE);

	cout << "Enter customer's phone number" << endl;
	cin.getline(phoneNumber, STRING_SIZE);

	cout << "Is club member? true/false" << endl;
	cin.getline(club, STRING_SIZE);
	clubMember = (club == "true" ? true : false);
	shop.addNewCustomer(Customer(name, phoneNumber, clubMember));

}

void makeOrder(CoffeeShop& shop, Shift& shift)
{
	Product* p;
	const Employee* theEmployee;
	const Customer* theCustomer;
	int choice;
	char milk[STRING_SIZE];
	bool withMilk;
	int numOfSugar;

	while (getchar() != '\n');

	cout << "Enter employee to be incharge of the order" << endl;
	if (showEmployees(shift.getEmployees()))
	{
		cin >> choice;
		theEmployee = &shift.getEmployees()[choice - 1];
	}
	else
	{
		return;
	}

	cout << "Enter customer making the order" << endl;
	if (showCustomers(shop.getCustomers()))
	{
		cin >> choice;
		theCustomer = &shop.getCustomers()[choice - 1];
	}
	else
	{
		return;
	}

	// create order
	Order theOrder(*theEmployee, *theCustomer);

	cout << "The daily menu items" << endl;
	if (!showProducts(shift.getDailyMenu()))
	{
		return;
	}

	while (choice != -1)
	{
		cout << "choose items indice you wish to order, -1 to stop" << endl;
		cin >> choice;

		if (choice<-1 || choice > (int)shift.getDailyMenu().size()) {
			cout << "Invalid product index" << endl;
			continue;
		}

		if (choice != -1)
		{
			p = shift.getDailyMenu().at(choice - 1)->clone();
			if (typeid(*p) == typeid(Coffee))
			{
				cout << "With milk? true/false" << endl;
				cin.getline(milk, STRING_SIZE);
				withMilk = (milk == "true" ? true : false);
				while (getchar() != '\n');
				cout << "How many sugar spoons?" << endl;
				cin >> numOfSugar;
				Coffee* temp = dynamic_cast<Coffee*>(p);
				temp->setMilk(withMilk);
				temp += numOfSugar;
				p = temp;
			}
			else if (typeid(*p) == typeid(Salad))
			{
				cout << "Select salad dressing type index" << endl;

				while (true)
				{
					for (int i = 0; i < (int)Salad::eDressingType::enumTypeEnd; i++)
						cout << i + 1 << ". " << sDressingType[i] << endl;

					cin >> choice;

					if (choice < 1 || choice > (int)Salad::eDressingType::enumTypeEnd)
						cout << "Invalid choice" << endl;
					else break;
				}

				Salad* temp = dynamic_cast<Salad*>(p);
				temp->addDressing(Salad::eDressingType(choice - 1));

				p = temp;

			}
			else if (typeid(*p) == typeid(CookieCoffee))
			{
				cout << "With milk? True/False" << endl;
				cin >> withMilk;
				cout << "How many sugar spoons?" << endl;
				cin >> numOfSugar;
				CookieCoffee* temp = dynamic_cast<CookieCoffee*>(p);
				temp->setMilk(withMilk);
				temp += numOfSugar;
				p = temp;
			}
			else {} // its a cookie

			theOrder.addItem(*p);
		}
	}

	shift.addOrder(theOrder);
}

void addEmployeesToShift(CoffeeShop& shop, Shift& shift)
{
	int choice = 1;

	// show all Employees in the coffeeshop
	showEmployees(shop.getEmployees());

	// choose employees to add
	while (choice != -1)
	{
		cout << "choose employee indice you wish to add, -1 to stop" << endl;
		cin >> choice;

		if (choice<-1 || choice > (int)shop.getEmployees().size()) {
			cout << "Invalid employee index" << endl;
			continue;
		}

		if (choice != -1)
		{
			if (shift.addEmployeeToShift(shop.getEmployees()[choice - 1]))
			{
				cout << shop.getEmployees()[choice - 1].getName() << " added to shift! " << endl;
			}
			else
			{
				cout << " Employee already exists in shift!" << endl;
			}
		}
	}

}
void addProductToDailyMenu(CoffeeShop& shop, Shift& shift)
{
	int choice = 1;

	// show all products in the coffeeshop
	showProducts(shop.getProducts());

	// choose products to add
	while (choice != -1)
	{
		cout << "choose product indice you wish to add, -1 to stop" << endl;
		cin >> choice;

		if (choice<-1 || choice > (int)shop.getProducts().size()) {
			cout << "Invalid product index" << endl;
			continue;
		}

		if (choice != -1)
		{
			if (shift.addProductToMenu(*shop.getProducts().at(choice-1)))
			{
				cout << shop.getProducts().at(choice - 1)->getName() << " added to daily menu! " << endl;
			}
			else
			{
				cout << " Product already exists in daily menu!" << endl;
			}
		}
	}
}

