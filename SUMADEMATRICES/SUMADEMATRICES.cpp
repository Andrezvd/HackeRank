// SUMADEMATRICES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


class Matrix {
public:
    std::vector<std::vector<int>> a;
    Matrix() {};
    Matrix(std::vector<std::vector<int>> v) : a(v) {};

    Matrix operator +(Matrix& otra) {
        for (int i = a.size() - 1; i >= 0; i--) {
            for (int j = a[0].size(); j >= 0; j--) {
                a[i][j] += otra.a[i][j];
            }
        }
        return *this;
    }
};


int main() {
    int cases, k;
    std::cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        std::cin >> n >> m;
        for (i = 0; i < n; i++) {
            std::vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                std::cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++) {
            std::vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                std::cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                std::cout << result.a[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
