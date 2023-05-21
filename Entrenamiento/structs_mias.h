#pragma once
#ifndef MIHEADER_H
#define MIHEADER_H

/*CODIGO */


struct Nodo {
	Nodo* next;
	Nodo* prev;
	int key;
	int value;
	Nodo(Nodo* n, Nodo* p, int k, int v) :next(n), prev(p), key(k), value(v){};
	Nodo(int k, int v) :next(nullptr), prev(nullptr), key(k), value(v){};
};
#endif