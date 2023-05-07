// Clases Abstractas Y poliformismo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


int main()
{
    std::cout << "Hello World!\n";

    int a, b;
    std:: string c, d;

    std::cout << "INGRESE LOS ENTEROS" << std::endl;
    std::cin >>a>>b;
    std::cout << "INGRESE LOS STRING" << std::endl;
    std::cin >> c >> d;

    std::cout <<" "<< "ENTEROS Y STRINGS SIN PUNTEROS: " << &a << " " << b << " " << c << " " << d << std::endl;

    int *e = &a;
    int* f = &b;
    std::string *g=&c, *h=&d;

    std::cout <<" "<< "ENTEROS Y STRINGS CON PUNTEROS: " << e << " " << f << " " << g << " " << h << std::endl;

}

