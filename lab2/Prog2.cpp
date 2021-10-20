#include <strstream>

#include<iostream>
#include <string.h>

#include "Epic.h"

namespace Prog2 {
	Epic::Epic() : C(1, 1, 1) {}
	Epic::Epic(double r, double R, double d) {
		Circles C(r, R, d);
		setC(C);
	}

	Epic& Epic::setC(Circles C0) {
		if ((C0.r <= 0) || (C0.R <= 0))
			throw std::exception("Invalid radius");
		C = C0;
		return *this;
	}

	std::string Epic::Type(Circles& C)const {
		std::stringstream p;
		if (C.r <= 0)
			throw std::exception("Invalid radius");
		if (C.d == C.r)
			p << " common";
		if (C.d < C.r)
			p << " shortened";
		if (C.d > C.r)
			p << " elongated";
		return p.str();
	}

	std::string Epic::equa1()const {
		std::stringstream s;
		s << "x= ";
		if ((C.r != 0) || (C.R != 0))
			s << (C.R + C.r) << " * cos(fi) - " << C.d << " * cos(" << C.R + C.r << " * fi/" << C.r << ")";
		else
			s << "Epicycloid not found...";
		return s.str();
	}

	std::string Epic::equa2()const {
		std::stringstream k;
		k << "y= ";
		if ((C.r > 0) || (C.R > 0))
			k << (C.R + C.r) << " * sin(fi) - " << C.d << " * sin(" << C.R + C.r << " * fi/" << C.r << ")";
		return k.str();
	}

	double Epic::Seg(Circles& C, double fi)const {
		return ((C.R + C.r + C.d * C.d / C.r) * fi - C.d * (C.R + 2 * C.r) * sin(C.R * fi / C.r) / C.R) * (C.R + C.r) / 2;
	}

	double Epic::Cur(Circles& C, double fi)const {
		return (C.r + C.R) * pow(C.r * C.r + C.d * C.d - 2 * C.d * cos(C.R * fi / C.r), 3 / 2) / abs(C.r * C.r * C.r + C.d * C.d * (C.r + C.R) - C.d * C.r * (C.R + 2 * C.r) * cos(C.R * fi / C.r));
	}

	void Epic::CoordXY(Circles& C, double fi, double& x, double& y) const {
		x = (C.R + C.r) * cos(fi) - C.d * cos((C.R + C.r) * fi / C.r);
		y = (C.R + C.r) * sin(fi) - C.d * sin((C.R + C.r) * fi / C.r);
	}
}