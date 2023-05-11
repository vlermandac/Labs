#ifndef ARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_H

#include <iostream>

class Nodo{

	public:
		int valor;
		Nodo *izq;
		Nodo *der;
		Nodo *padre;
		Nodo(int valor);              // Constructor valor raiz
		Nodo(int valor, Nodo *padre); // Constructor nodo no raiz
		~Nodo();                      // Destructor
};


class ArbolBinarioBusqueda{
	public:
		ArbolBinarioBusqueda();       // Constructor
		~ArbolBinarioBusqueda();      // Destructor
		bool insertar(int valor);     // No acepta valores repetidos
		Nodo *buscar(int valor);      // Si no existe, return null
		void inOrder();

	private:
		Nodo *raiz;                            // ptr a primer nodo
		bool insertar(int valor, Nodo *n);      // Insertar un nodo en el nodo *n
		Nodo *buscar(int valor, Nodo *n);       // Buscar valor en el nodo *n
		void inOrder(Nodo *n);                  // Recorrido inOrder desde el nodo *n
		Nodo *mayor(Nodo *n);                   // Retorna el nodo de mayor valor
};

#endif
