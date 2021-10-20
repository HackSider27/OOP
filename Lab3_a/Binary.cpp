#include "../3a/Binary.h"

using namespace Prog3a;

void input(Binary& b, bool first = true)
{
	std::cout << Prog3a::quest();

	int n{};
	std::cin >> n;
	if (!std::cin.good()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Incorrect input!" << std::endl;
	}
	else {
		std::cout << "Enter the " << (first ? "first" : "second") << " number: " << std::endl;

		if (n == 1)
		{
			int num{};
			std::cin >> num;

			b = Binary(num);
		}
		else if (n == 2)
		{
			char _arr[15]{};
			std::cin >> _arr;

			b = Binary(_arr);
		}
	}
}

void menu(Binary& b1, const Binary& b2, bool first = true)
{
	std::string ord = first ? "first" : "second";
	try {
		std::cout << "1. Increment of " << ord << " number: ";
		Binary::print(std::cout, b1.incr());
		std::cout << std::endl;
		b1.dicr();

		std::cout << "2. Dicrement of " << ord << " number: ";
		Binary::print(std::cout, b1.dicr());
		std::cout << std::endl;
		b1.incr();
	}
	catch (std::overflow_error& ex) {
		std::cout << ex.what() << std::endl;
	}

	std::cout << "3. Additinal code of " << ord << " number: " << b1.GetAdditionalCode() << std::endl;

	std::cout << "4. Sign of " << ord << " number: " << (b1.Sign() ? '+' : '-') << std::endl;

	try {
		std::cout << "5. The sum of two numbers: ";
		Binary::print(std::cout, b1.Add(b2));
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
		if ((!std::cin.good()) || (l>2) || (l<1) ) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "Incorrect input!" << std::endl;
		}
		else{
			if (l == 1)
				menu(a, b);
			else
				menu(b, a, false);
		}

		std::cout << std::endl;
	}
}