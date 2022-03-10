#pragma once
#include <iostream>

class Nodo
{
	int dato;
	Nodo* ant;
	Nodo* sig;

	friend class Lista;
public:
	Nodo(int _dato);
};

