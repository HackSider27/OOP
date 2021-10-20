#include "Epic.h"
#include<iostream>
#include<sstream>

int main() {
	Prog2::Circles C;
	Prog2::Epic E(1, 1, 1);

	int fl1 = 1;
	double fi = 0;
	double x, y;

	while (fl1) {
		std::cout << "Your Epicycloid is: " << std::endl;
		std::string s = E.equa1();
		std::string k = E.equa2();
		std::cout << s << std::endl;
		std::cout << k << std::endl;
		std::cout << "Limited radiuses of Epicycloid: R1=" << E.Rd() << " R2=" << E.rd() << std::endl;
		std::cout << "Type of epicycloid is" << E.Type(C) << std::endl;
		std::cout << "The epicycloid is ";
		E.feature();


		int fl2 = 1;
		while (fl2) {
			std::cout << "Enter fi to calculate the value of radius of curvature and sectorial area or precc ctrl+Z to quit:" << std::endl;
			double Rad;
			double S;

			std::cin >> fi;
			fl2 = std::cin.good();
			if (!fl2)
				continue;
			try {
				E.CoordXY(C, fi, x, y);
				std::cout << "Coordinats of Epicycloid with such parameters: x=" << x << " y=" << y << std::endl;
				Rad = E.Cur(C, fi);
				S = E.Seg(C, fi);
				std::cout << "Radius of curvature is " << Rad << " and sectorial area is " << S << std::endl;
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
		}

		std::cin.clear();
		std::cout << "Enter new r, R and d for Epicycloid to continue or press ctrl+Z to quit:" << std::endl;
		std::cin >> C.r >> C.R >> C.d;
		if (std::cin.good()) {
			try {
				E.setC(C);
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
		}
		else
			fl1 = 0;
	}
	return 0;
}