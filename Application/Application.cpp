#include <iostream>
#include "..\Library\Curve.h"
#include <sstream>

int main()
{
    lab2::Curve c(1, 2);
    lab2::Parameters p(3);
    int fl1 = 1;
    char* s = NULL;
    while (fl1) {
        std::cout << "Your Lemniscate of Buta is:" << std::endl;
        c.frm();
        std::cout << std::endl;
        //delete[] s;
        std::cout << "area: " << c.area() << std::endl;
        int type=0;
        type = c.type();
        std::cout << "type: ";
        switch (type)
        {
        case 0:
            std::cout << " Lemniscate of Bernoulli " << std::endl;
            break;
        case 1:
            std::cout << " circle " << std::endl;
            break;
        case 2:
            std::cout << "elleptical" << std::endl;
            break;
        case 3:
            std::cout << "hyperbolical" << std::endl;
            break;
        default:
            std::cout << "Unknown" << std::endl;
            break;
        }
        //std::cout << "perimeter: " << c.perimeter() << std::endl;
        int fi;
        std::cout << "Input angle(in radians):" << std::endl;
        std::cin >> fi;
        std::cout << "distance: "; 
        double d = 0;
        try {
            d=c.distance(fi);
        }
        catch (std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        std::cout << d << std::endl;
        std::cout << "Enter new c, m to continue or press ctrl+Z to quit:" << std::endl;
        std::cin >> p.c >> p.m;
        if (std::cin.good()) {
            //c.setP(p);
            try {
                c.setP(p);
            }
            catch (std::exception& ex)
            {
                std::cout << ex.what() << std::endl;
            }
        }
        else
            fl1 = 0;
    }
    return 0;
}
