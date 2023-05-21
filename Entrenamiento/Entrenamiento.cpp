// Entrenamiento.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include "structs_mias.h"
#include "class_cache.h"

int main()
{
    int n, capacity, i;
    std::cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        std::string command;
        std::cin >> command;
        if (command == "get") {
            int key;
            std::cin >> key;
            std::cout << l.get(key) << std::endl;
        }
        else if (command == "set") {
            int key, value;
            std::cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}


