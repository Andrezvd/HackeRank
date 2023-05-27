// FILASCOLAS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque> 
#include <algorithm>

void printKMax(int* arr, int n, int k) {
    std::deque<int> deq;
    int i = 0;

    for (i = 0; i < k; i++) {
        while (!deq.empty() && arr[i] >= arr[deq.back()])
            deq.pop_back();

        deq.push_back(i);
    }

    for (; i < n; ++i) {
        std::cout << arr[deq.front()] << " ";

        while (!deq.empty() && deq.front() <= i - k)
            deq.pop_front();

        while (!deq.empty() && arr[i] >= arr[deq.back()])
            deq.pop_back();

        deq.push_back(i);
    }
    std::cout << arr[deq.front()] << std::endl;
}

int main() {
    int t; // Number of test cases
    std::cin >> t;
    while (t > 0) {
        int n, k; // Size of array (n) and subarray (k)
        std::cin >> n >> k;
        int* arr = new int[n]; // Create a dynamic array of size n
        for (int i = 0; i < n; i++)
            std::cin >> arr[i]; // Populate the array
        printKMax(arr, n, k);
        delete[] arr; // Deallocate the memory allocated for the array
        t--;
    }
    return 0;
}
