// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

vector<string> tag_stack;
map<string, string> attrs;


void insert_attr(string& name, string& val) {
    string full;
    for (string& str : tag_stack)
        full += str + ".";
    full.pop_back();
    full += "~" + name;
    attrs[full] = val;

}

int main() {
    int n, q;
    std::cout << "ingrese los dos valores" << std::endl;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        if (cin.peek() == '/') { // close
            string cn; cin >> cn;
            tag_stack.pop_back();
        }
        else { //open'
            string name;
            cin >> name;
            if (name.back() == '>') { //no attrs
                name.pop_back();
                tag_stack.push_back(name);
            }
            else {
                tag_stack.push_back(name);

                for (;;) {
                    string attr_name, attr_val, eq;
                    cin >> attr_name >> eq >> attr_val;
                    if (attr_val.back() == '>') { //last attr
                        attr_val.pop_back();
                        attr_val.pop_back();
                        attr_val = attr_val.substr(1);
                        insert_attr(attr_name, attr_val);
                        break;
                    }
                    else {
                        attr_val.pop_back();
                        attr_val = attr_val.substr(1);
                        insert_attr(attr_name, attr_val);
                    }
                }
            }

        }
    }

    for (int i = 0; i < q; ++i) {
        string quer;
        cin >> quer;
        if (attrs.find(quer) != attrs.end())
            cout << attrs[quer] << endl;
        else
            cout << "Not Found!" << endl;
    }


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
