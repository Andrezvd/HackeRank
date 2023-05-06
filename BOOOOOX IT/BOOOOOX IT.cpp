// BOOOOOX IT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Box {
private:
    int l, b, h;
public:
    Box() {
        l = b = h = 0;
    }
    Box(int lenght, int breatg, int height) {
        l = lenght;
        b = breatg;
        h = height;
    }
    Box(Box& B) {
        l = B.l;
        b = B.b;
        h = B.h;
    }
    int getLenght() {
        return l;
    }
    int getBroadth() {
        return b;
    }
    int getHeight() {
        return h;
    }
	long long CalculateVolume() {
		return (long long)l * b * h;
	}
    friend bool operator < (Box& A, Box& B) {
        if (A.l < B.l || A.b < B.b && A.l == B.l || A.h < B.h && A.b == B.b && A.l == B.l) {
            return (true);
        }
		else {
			return (false);
		}
    }
    friend ostream& operator << (ostream& s, Box B) {
        s << B.l << " " << B.b;
        return s;
    }
};

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
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
