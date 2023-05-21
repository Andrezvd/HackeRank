// Clases Abstractas Y poliformismo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};


class LRUCache : public Cache
{
public:
    LRUCache(int c) {
        cp = c;
    }

    void set(int k, int v) {
        Node* N;

        if (mp.empty()) {
            //MAPA VACIO
            N = new Node(k, v);
            tail = head = N;
            mp[k] = N;

            return;
        }

        auto it = mp.find(k);

        if (it != mp.end()) {
            //ESTA EN EL MAPA
            it->second->value = v; // ACTUALIZAMOS EL VALOR

            if (head == it->second) {
                //ES LA CABEZA
                return;
            }

            it->second->prev->next = it->second->next;

            if (tail == it->second) {
                //ES LA COLA
                tail = tail->prev;
            }
            else {
                //ESTAN EN MEDIO
                it->second->next->prev = it->second->prev;
            }

            it->second->next = head;
            it->second->prev = nullptr;
            head->prev = it->second;
            head = it->second;
        }
        //SI NO ESTA EN EL MAPA
        else {
            //CREO EL NODO APUNTANDO A NULLPTR Y A LA CABEZA
            N = new Node(head->prev, head, k, v);
            head->prev = N;
            head = N;
            mp[k] = N;

            if (mp.size() > cp) {
               //SI EL TAMAÑO EXCEDE DEBO ELIMINAR EL ULTIMO NODO
                tail = tail->prev;
                mp.erase(tail->next->key);
                delete tail->next;
                tail->next = nullptr;
            }
        }
    }

    int get(int k) {
        auto it = mp.find(k);
        if (it != mp.end()) {
            return it->second->value;
        }

        return -1;
    }
};

int main() {
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}

