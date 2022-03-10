#pragma once
#include "Nodo.h"

class Lista
{
	Nodo* primero;
	Nodo* ultimo;
	int tamano;

public:
	Lista();
	bool EstaVacia(); // retornar true si la lista esta vacia
	int ObtenerTamano(); // retorna el numero de elementos que tiene la lista
	void InsertaAlInicio(int dato); // Inserta un elemento al inicio de la lista
	void InsertaAlFinal(int dato); // Inserta un elemento al final de la lista
	void InsertaEnPosicion(int dato, int pos); // Inserta un elemento en la posicion indicada
	void Mostrar(); // Mostrar todos los elementos que tenemos en la lista
	int ObtenerDato(int pos); // Retornar el dato de la posicion indicada
	int Eliminar(int pos); // Elimina el elemento de la posicion indicada
	int EliminarTodo(); // Elimina todos los elementos de la lista
	void Ordenar(); // Ordena los elementos de la lista de menor a mayor
};

