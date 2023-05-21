#include "structs_mias.h"
#include <map>
#pragma once
#ifndef MIHEADER2_H
#define MIHEADER2_H

//CODIGO
class Cache {
	protected:
		std::map<int, Nodo*>mp;
		int cp;
		Nodo* head;
		Nodo* tail;
		virtual void set(int,int)=0;
		virtual int get(int)=0;
};

class LRUCache : public Cache {
	public:
		LRUCache(int c) {
			cp = c;
		}

	void set(int k, int v) {
		Nodo* N;

		//Cuando el mapa ta vacio
		if (mp.empty()) {
			N = new Nodo(k, v);
			head = tail = N;
			mp[k] = N;
			return;
		}
		//SI NO ESTA VACIO
		auto it = mp.find(k);
		//PERO YA EXISTE EN EL MAPA
		if (it != mp.end()) {
			it->second->value = v; //LE ACTUALIZAMOS EL VALOR

			//SI ES EL PRIMER ELEMENTO
			if (it->second == head) {
				return;
			}
			
			//SI ES EL ULTIMO ELEMENTO
			it->second->prev->next = it->second->next; //Acomodamos el puntero al anterior

			if (it->second == tail) {
				tail = tail->prev;

			}//SI ESTA EN EL MEDIO
			else {
				it->second->next->prev = it->second->prev; //ACOMODAMOS EL PUNTERO AL SIGUIENTE
			}

			it->second->prev = nullptr;
			it->second->next = head;
			head->prev = it->second;
			head = it->second;
		}
		else {
			//NO ESTA EN EL MAPA
			N = new Nodo(head, head->prev, k, v);
			head->prev = N;
			head = N;
			mp[k] = N;

			if (mp.size() > cp) {  //POP 
				tail = tail->prev;
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
#endif // !MIHEADER2_H
