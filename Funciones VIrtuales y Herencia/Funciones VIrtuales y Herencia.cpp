// Funciones VIrtuales y Herencia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <string>

class Person {
protected:
    string name;
    int age;
public:
    Person() {}
    virtual void getdata() {}
    virtual void putdata() {}

    ~Person() {};
};

class Professor : public Person {
private:
    int publications, cur_id;
    static int id;

public:
    Professor() {
        id++;
        cur_id = id;
    }

    void getdata() override {
        cin >> name >> age >> publications;
    }
    void putdata() override {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }

    ~Professor() {};
};

class Student : public Person {
private:
    const int MAX = 6;
    int* marks = new int[MAX];
    int cur_id;
    static int id;
public:
    Student() {
        id++;
        cur_id = id;
    }
    void getdata() override {
        cin >> name >> age;

        for (int i = 0; i < MAX; i++) {
            cin >> marks[i];
        }
    }
    void putdata() override {
        cout << name << " " << age << " ";
        int sum = 0;
        for (int i = 0; i < MAX; i++) {
            sum += marks[i];
        }
        cout << sum << " " << cur_id << endl;
    }

    ~Student() {
        delete[] marks;
    };

};

int Professor::id = 0;
int Student::id = 0;

int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    vector<Person*> per(n);

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}