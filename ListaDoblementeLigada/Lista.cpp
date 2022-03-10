#include "Lista.h"

Lista::Lista()
{
	primero = NULL;
	ultimo = NULL;
	tamano = 0;
}

bool Lista::EstaVacia()
{
	return tamano == 0;
}

int Lista::ObtenerTamano()
{
	return tamano;
}

void Lista::InsertaAlInicio(int dato)
{
	Nodo* nuevo = new Nodo(dato);

	if (EstaVacia())
	{
		primero = ultimo = nuevo;
	}
	else
	{
		nuevo->sig = primero;
		primero->ant = nuevo;
		primero = nuevo;
	}

	tamano++;
}

void Lista::InsertaAlFinal(int dato)
{
	Nodo* nuevo = new Nodo(dato);

	if (EstaVacia())
	{
		primero = ultimo = nuevo;
	}
	else
	{
		nuevo->ant = ultimo;
		ultimo->sig = nuevo;
		ultimo = nuevo;
	}

	tamano++;
}

void Lista::InsertaEnPosicion(int dato, int pos)
{
	if (pos < 1 || pos > tamano + 1)
	{
		std::cout << "La posicion ingresada es invalida" << std::endl;
	}
	else if (pos == 1)
	{
		InsertaAlInicio(dato);
	}
	else if (pos == tamano + 1)
	{
		InsertaAlFinal(dato);
	}
	else
	{
		Nodo* nuevo = new Nodo(dato);
		Nodo* aux = primero;

		for (int i = 0; i < pos - 2; i++)
		{
			aux = aux->sig;
		}

		nuevo->sig = aux->sig;
		aux->sig->ant = nuevo;
		aux->sig = nuevo;
		nuevo->ant = aux;

		tamano++;
	}
}

void Lista::Mostrar()
{
	Nodo* aux = primero;

	while (aux != NULL)
	{
		std::cout << aux->dato << std::endl;
		aux = aux->sig;
	}
}

int Lista::ObtenerDato(int pos)
{
	if (pos < 1 || pos > tamano)
	{
		return -1;
	}
	else
	{
		Nodo* aux = primero;

		for (int i = 0; i < pos - 1; i++)
		{
			aux = aux->sig;
		}

		return aux->dato;
	}
}

int Lista::Eliminar(int pos)
{
	if (pos < 1 || pos > tamano)
	{
		return -1;
	}
	else if (pos == 1)
	{
		Nodo* aux = primero;
		primero = primero->sig;
		primero->ant = NULL;
		int tmp = aux->dato;
		delete(aux);
		tamano--;
		return tmp;
	}
	else if (pos == tamano)
	{
		Nodo* aux = ultimo;
		ultimo = ultimo->ant;
		ultimo->sig = NULL;
		int tmp = aux->dato;
		delete(aux);
		tamano--;
		return tmp;
	}
	else
	{
		Nodo* aux = primero;
		Nodo* aux2 = primero;

		for (int i = 0; i < pos - 1; i++)
		{
			aux = aux2;
			aux2 = aux2->sig;
		}

		aux->sig = aux2->sig;
		aux2->sig->ant = aux;
		int tmp = aux2->dato;
		delete (aux2);
		tamano--;
		return tmp;
	}
}

int Lista::EliminarTodo()
{
	Nodo* aux = primero;

	while (primero != NULL)
	{
		aux = primero;
		primero = primero->sig;
		delete (aux);
	}

	ultimo = NULL;
	int tmp = tamano;
	tamano = 0;
	return tmp;
}

void Lista::Ordenar()
{
	Nodo* aux = primero;
	Nodo* aux2 = aux->sig;

	while (aux->sig != NULL)
	{
		aux2 = aux->sig;

		while (aux2 != NULL)
		{
			if (aux->dato > aux2->dato)
			{
				int tmp = aux->dato;
				aux->dato = aux2->dato;
				aux2->dato = tmp;
			}

			aux2 = aux2->sig;
		}

		aux = aux->sig;
	}
}