#pragma once
#ifndef _CURVE_H_
#define _CURVE_H_

#include <math.h>
#include <iostream>

namespace lab2{
	struct Parameters {
		double c, m;
		Parameters(double c0 = 2, double m0 = 1) : c(c0), m(m0) {}
	};
	class Curve{
	private:
		Parameters p; // main parameters
		//double a, b; // derived parameters
	public:
		//constructors
		Curve();
		Curve(const Parameters& p0);
		Curve(double c0, double m0);
		//setters
		Curve& setP(const Parameters& p0);
		//getters
		Parameters getP() const { return p; }
		//other methods
		double area()const;
		int type()const;
		double distance(double fi)const;
		char* frm() const;
	};
}
#endif
