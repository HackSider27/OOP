#include "../3c/Binary.h"

using namespace Prog3c;

void input(Binary& c, bool first = true) {
	std::cout << Prog3c::quest();

	int n{};
	std::cin >> n;
	while ( (!std::cin.good()) || (n<1) || (n>2) ) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Incorrect input!" << std::endl;
		std::cin >> n;
	}
		std::cout << "Enter the " << (first ? "first" : "second") << " number: " << std::endl;

		if (n == 1)
		{
			long int num;
			std::cin >> num;

			c = Binary(num); 
			//printf_s("%d", c.GetSZ());
		}
		else if (n == 2)
		{
			string str;
			char* _arr;

			std::cin >> str;
			int sz = str.length();
			//_arr = new char[sz];


			c = Binary(str.c_str());
		}
}

void menu(Binary& b1, const Binary& b2, bool first = true)
{
	std::string ord = first ? "first" : "second";
	try {
		std::cout << "1. Increment of " << ord << " number: ";
		std::cout << ++b1 << std::endl;
		--b1;
		std::cout << std::endl;

		std::cout << "2. Dicrement of " << ord << " number: ";
		std::cout << --b1 << std::endl;
		++b1;
		std::cout << std::endl;
	}
	catch (std::overflow_error& ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << "3. Additinal code of " << ord << " number: " << b1.GetAdditionalCode(b1.GetSZ()) << std::endl;

	std::cout << "4. Sign of " << ord << " number: " << (b1.Sign() ? '+' : '-') << std::endl;

	try {
		std::cout << "5. The sum of two numbers: ";
		std::cout << b1 + b2 << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
}

int main() {
	Binary a, b;
	while (true) {
		input(a);
		input(b, false);

		std::cout << "What number do u want to make operitions with?\n";

		int l{};
		std::cin >> l;
		if ((!std::cin.good()) || (l > 2) || (l < 1)) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "Incorrect input!" << std::endl;
		}
		else {
			if (l == 1)
				menu(a, b);
			else
				menu(b, a, false);
		}

		std::cout << std::endl;
	}
}