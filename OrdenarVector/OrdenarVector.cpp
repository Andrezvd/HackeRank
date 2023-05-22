// OrdenarVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::vector<int>v;
    int cle ,a,b,c;
    std::cin >> cle;
    for (int i = 0; i < cle; i++) {
        int w;
        std::cin >> w;
        v.push_back(w);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < cle; i++) {
        std::cout << v[i] << " ";
    }

    //BORRARLE COSAS AL VECTOR

    std::cin >> a >> b >> c;
    v.erase(v.begin() + (a - 1));
    v.erase(v.begin() + (b - 1), v.begin() + (c - 1));

    std::cout << v.size() << std::endl;
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    return 0;

    return 0;
}

