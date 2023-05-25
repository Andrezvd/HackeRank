// LIMITESENVECTORES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define toStr(x) #x
#define io(c) std::cin>>c
#define foreach(v,i) for(int i=0;i<v.size();i++)


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>


#if !defined toStr || !defined io || !defined foreach
#error Missing preprocessor definitions
#endif 


int main() {
	int n,q,query;
	io(n);
	std::vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}

	io(q);

	for (int i = 0; i < q; i++) {
		io(query);
		std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), query);
		if (query != *it) {
			std::cout << toStr(ESTE NUMERO DEBERIA IR EN LA POSICION : ) << " " << (it-v.begin()+1);
		}
		else {
			std::cout << toStr(ESTE NUMERO ESTA EN LA POSICION : ) << " " << (it-v.begin()+1);
		}

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
