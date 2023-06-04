// StudentdHoraries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop {
    int start_time, duration, endtime;
};

struct Available_Workshops {
    int nWorkshops;
    vector<Workshop*> wks;

    Available_Workshops(int num) {
        nWorkshops = num;
        wks.resize(num);
    }

    ~Available_Workshops()
    {  
        for (int i = 0; i < nWorkshops; i++)
        {
            delete wks[i];
        }
    }
   
};

Available_Workshops* initialize(int start[],int duration[], int num) {
    Available_Workshops* avwks = new Available_Workshops(num);
    for (int i = 0; i < num; i++)
    {
        Workshop* wk = new Workshop;
        wk->start_time = start[i];
        wk->duration = duration[i];
        wk->endtime = start[i] + duration[i];
        avwks->wks[i] = wk;
    }
    return avwks;
}

bool compare(Workshop* a, Workshop* b) {
    return a->endtime < b->endtime;
}

const int CalculateMaxWorkshops(Available_Workshops* ptr) {
    sort(ptr->wks.begin(), ptr->wks.end(), compare);
    
    int totalavwk=0;
    int horasalida = 0;

    for (int i = 0; i < ptr->nWorkshops; i++)
    {
        if (ptr->wks[i]->start_time >= horasalida) {
            horasalida = ptr->wks[i]->endtime;
            totalavwk++;
        }
    }
    return totalavwk;
}

int main(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
