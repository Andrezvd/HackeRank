// FilasConVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <deque> 
#include <algorithm>
#include <vector>

void printKMax(const std::vector<int> &arr, int n, int k) {
    std::deque<int> dq;
    int i = 0;
    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    for (; i < n; ++i) {
        std::cout << arr[dq.front()]<<" ";
        while (!dq.empty() && dq.front() <= (i - k))
            dq.pop_front();

        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }
    std::cout << arr[dq.front()] << std::endl;

}

int main() {
    int t; // Number of test cases
    std::cin >> t;
    while (t > 0) {
        int n, k; // Size of array (n) and subarray (k)
        std::cin >> n >> k;
        std::vector<int> arr(n); // Create a dynamic array of size n
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];// Populate the array
        }
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
