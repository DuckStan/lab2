#include "pch.h"
#include "Curve.h"
#include <strstream>
#include <stdio.h>
#include <string.h>
#include <math.h>

namespace lab2 {
	//constructors
	Curve::Curve() :p(2, 1) {};
	Curve::Curve(const Parameters& p0){
		if ((p0.c == 0) && (p0.m == 0)) {
			throw std::exception("Invalid parameters");
		}
		p = p0;
	}
	Curve::Curve(double c0, double m0) {
		if ((c0 == 0) && (m0 == 0)) 
			throw std::exception("Invalid parameters");
		
		p.c = c0;
		p.m = m0;
	}
	//setters
	Curve& Curve::setP(const Parameters& p0) {
		if ((p0.c == 0) && (p0.m == 0)) {
			throw std::exception("Invalid parameters");
		}
		p = p0;
		return *this;
	};
	
	//setters
	//Curve& Curve::setP(const Parameters& p0) { p = p0; return *this; }
	
	//other methods
	double Curve::area() const{
		if ((p.c) == (2*p.m*p.m)) {
			if (p.m != 0) {
				return (3.14159 * p.m * p.m);
			}
		//	else throw std::exception("area can not be calculated");
		}
		if ((p.c) > (2 * p.m * p.m)) {
			return ((3.14159) * (p.c));
		}
		if ((p.c) < (2 * p.m * p.m)) {
			return ((p.c * atan(sqrt(1 + (p.c / (2 * p.m * p.m - p.c))))) + (sqrt(4 * p.m * p.m * p.m * p.m - p.c * p.c)) / 2);
		}

		return 0;
	}
	int Curve::type() const{
		if (p.c == 0) return 0;
		if (p.c == 2 * p.m * p.m) return 1;
		if (p.c > 2 * p.m * p.m) return 2;
		if (p.c < 2 * p.m * p.m) return 3;
		return 0;
	}
	double Curve::distance(double fi)const {
		if ((fi > 3.14159) || (fi < -3.14159)) throw std::exception("invalid angle");
		if (p.c == 0) {
			if ((fi >= 1) || (fi <= -1)) throw std::exception("invalid angle");
			int k = 2 * fi; 
			return sqrt(2 * p.m * p.m * cos(k)); 
		}
		//if ((fi > 3.14159) || (fi < -3.14159)) throw std::exception("invalid angle");
		if (p.c == 2 * p.m * p.m) return p.m;
		if (p.c > 2 * p.m * p.m) return sqrt( ((2*p.m*p.m+p.c) * cos(fi)*cos(fi))+((p.c-2*p.m*p.m) * sin(fi) * sin(fi)) );
		if (p.c < 2 * p.m * p.m) return sqrt(((2 * p.m * p.m + p.c) * cos(fi) * cos(fi)) + ((2 * p.m * p.m - p.c) * sin(fi) * sin(fi)));
		return 0;
	}
	char* Curve::frm() const {
		const char* s1 = "(p)^2 -  cos^2(fi) +  sin^2(fi) = ";
		int l = strlen(s1) + 1;
		size_t Size = 20;
		char num[20]; 
		sprintf_s(num, 20, "%.2f", 2*p.m*p.m + p.c); 
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", 2*p.m*p.m - p.c); 
		l += strlen(num);
		
		char* s = new char[l];
		
		sprintf_s(s, l, "p^2 = ");

		int k = strlen(s);
		if (p.c == 0) {
			sprintf_s(s, l - k, "%.2fcos(2*fi)", 2 * p.m * p.m);
			return s;
		}
		//else
		//sprintf_s(s, l, "(x - %.2f) ^ 2", p.x);
		if (p.c > 2*p.m*p.m) {
			sprintf_s(s + k, l - k, "%.2fcos^2(fi) + %.2fsin^2(fi)", 2*p.m*p.m + p.c, p.c - 2*p.m*p.m);
			return s;
		}
		//else
		//sprintf_s(s + k, l - k, " + (y - %.2f) ^ 2", p.y);
		//k = strlen(s);
		if (p.c < 2 * p.m * p.m) {
			sprintf_s(s + k, l - k, "%.2fcos^2(fi) - %.2fsin^2(fi)", 2 * p.m * p.m + p.c, 2 * p.m * p.m - p.c);
			return s;
		}
		if (p.c == 2 * p.m * p.m) {
			double m = p.m * p.m;
			sprintf_s(s + k, l - k, "%.2f", m);
			return s;
		}
	}



}
