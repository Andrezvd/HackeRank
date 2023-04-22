// AprenderC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "f_quicksort.h"

void quicksort(int arr[], int left, int right);

int main()
{
    int arr[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Hello World HOW ARE U  BROOOOOOOS!\n";
    
    quicksort(arr, 0, n - 1);

    std::cout << "Array ordenado:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
