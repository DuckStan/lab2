// Application.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "..\Library\Curve.h"

int main()
{
    lab2::Curve c(1, 2);
    lab2::Parameters p(3);
    int fl1 = 1;
    char* s = NULL;
    while (fl1) {
        std::cout << "Your Lemniscate of Buta is:" << std::endl;
        s = c.frm();
        std::cout << s << std::endl;
        delete[] s;
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
