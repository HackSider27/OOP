#ifndef _Epic_H_

#define _Epic_H_

#include<math.h>
#include<iostream>
#include<sstream>
#pragma once

namespace Prog2 {
	struct Circles{
		double r, R, d; 
		Circles(double r0 = 1, double R0 = 1, double d0=1) :r(r0), R(R0), d(d0){}
	};

	//определяем окружность
	class Epic {
	private:
		Circles C; //r-s of circle
	public:
		Epic();
		Epic(double r, double R, double d ); //определение эпициклойды
		//Epic(const Point& p0, double rad = 1);
		//Epic(double x0, double y0, double rad = 1);

		/*setters*/
		Epic& setC(Circles C0);

		/*getters*/
		double getR() const { return C.R; }
		double getr() const { return C.r; }

		/*other methods*/
		std::string equa1()const;
		std::string equa2()const;
		void CoordXY(Circles& C, double fi, double& x, double& y)const;
		double Rd() const{ return C.R + C.r - C.d; } 
		double rd() const{ return C.R + 2 * C.r - C.d; }
		double Cur(Circles& C, double fi)const;
		std::string Type(Circles& C)const;
		double Seg(Circles& C, double fi)const;
		void feature() const {std::cout<< "not astroida" << std::endl;};
	};
}
#endif


