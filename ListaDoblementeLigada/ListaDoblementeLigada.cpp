
#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
    Lista* lista = new Lista();
    int opc = 0;

    while (opc != 10)
    {
        system("cls");
        cout << "1. Inserta al inicio" << endl;
        cout << "2. Inserta al final" << endl;
        cout << "3. Inserta en posicion" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Obtener tamano" << endl;
        cout << "6. Obtener dato" << endl;
        cout << "7. Eliminar" << endl;
        cout << "8. Eliminar todo" << endl;
        cout << "9. ordenar" << endl;
        cout << "10. Salir" << endl;

        cout << endl;
        cout << "Elija la opcion deseada: ";
        cin >> opc;
        system("cls");

        switch (opc)
        {
        case 1:
        {
            int dato;
            cout << "Ingrese el dato que quiere insertar: ";
            cin >> dato;

            lista->InsertaAlInicio(dato);

            break;
        }
        case 2:
        {
            int dato;
            cout << "Ingrese el dato que quiere insertar: ";
            cin >> dato;

            lista->InsertaAlFinal(dato);

            break;
        }
        case 3:
        {
            int dato, pos;
            cout << "Ingrese el dato que quiere insertar: ";
            cin >> dato;
            cout << "Ingrese la posicion donde quiere insertar: ";
            cin >> pos;

            lista->InsertaEnPosicion(dato, pos);

            break;
        }
        case 4:
        {
            if (lista->EstaVacia())
            {
                cout << "La lista esta vacia" << endl;
            }
            else
            {
                cout << "Lista de elementos: " << endl;
                lista->Mostrar();
            }
            break;
        }
        case 5:
        {
            int tamano = lista->ObtenerTamano();

            cout << "Hay " << tamano << " elementos en la lista" << endl;

            break;
        }
        case 6:
        {
            if (lista->EstaVacia())
            {
                cout << "La lista esta vacia" << endl;
            }
            else
            {
                int pos;
                cout << "Ingrese la posicion donde quiere insertar: ";
                cin >> pos;

                int dato = lista->ObtenerDato(pos);

                if (dato == -1)
                {
                    cout << "La posicion ingresada es invalida" << endl;
                }
                else
                {
                    cout << "El dato en la posicion " << pos << " es: " << dato;
                }
            }

            break;
        }
        case 7:
        {
            if (lista->EstaVacia())
            {
                cout << "La lista esta vacia" << endl;
            }
            else
            {
                int pos;
                cout << "Ingrese la posicion donde quiere insertar: ";
                cin >> pos;

                int dato = lista->Eliminar(pos);

                if (dato == -1)
                {
                    cout << "La posicion ingresada es invalida" << endl;
                }
                else
                {
                    cout << "El dato " << dato << " fue eliminado" << endl;
                }
            }

            break;
        }
        case 8:
        {
            if (lista->EstaVacia())
            {
                cout << "La lista esta vacia" << endl;
            }
            else
            {
                int eliminados = lista->EliminarTodo();

                cout << eliminados << " fueron eliminados" << endl;
            }

            break;
        }
        case 9:
        {
            if (lista->EstaVacia())
            {
                cout << "La lista esta vacia" << endl;
            }
            else
            {
                lista->Ordenar();

                cout << "Nuevo orden: " << endl;
                lista->Mostrar();
            }

            break;
        }
        }

        cin.get();
        cin.get();
    }
}
