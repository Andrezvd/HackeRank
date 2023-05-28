// SOBREESCRITURA DE OPERADORES.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Complex
{
public:
    int a, b;
 /**
 * TOMA LOS DOS ENTREROS DE LA CADENA STRING.
 *
 * TOMA UNA CADENA STRING LA ITERA.
 * PARA TOMAR SUS VALORES ENTEROS Y LOS ASIGNA A LA CLASE COMPLEX.
 *
 * @Param String Descripción del primer parámetro.
 * @set Agrega a complex el primer entero obetenido.
 */
    void set(string& input) { 
        int i = 0;
        int v1 = 0;
        while (input[i] != '+') {
            v1 = v1 * 10 + input[i] - '0';
            ++i;
        }

        int v2 = 0;
        while (input[i] == '+' || input[i] == 'i') {
            ++i;
        }
        while (i != input.size()) {
            v2 = v2 * 10 + input[i] - '0';
            ++i;
        }
        a = v1;
        b = v2;
    }

};

Complex operator + (Complex& x, Complex& y) {
    Complex c;
    c.a = x.a + y.a;
    c.b = x.b + y.b;
    return c;
};

ostream& operator << (ostream& out, Complex& c) {
    out << c.a << "+" << "i" << c.b << endl;
    return out;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Complex a, b;
    string input, input2;
    cin >> input >> input2;
    a.set(input);
    b.set(input2);
    Complex c = a + b;
    cout << c;
    return 0;
}