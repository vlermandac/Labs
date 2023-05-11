#include "arbolBinarioBusqueda.h"

// ---- Metodos Clase Nodo ---- //

// Constructor nodo raiz
Nodo::Nodo(int valor){   // O(1)

	izq = NULL;
	der = NULL;
	padre = NULL;
	this -> valor = valor;
}


// Constructor Nodo no raiz
Nodo::Nodo(int valor, Nodo *padre){   // O(1)

	izq = NULL;
	der = NULL;
	this -> padre = padre;
	this -> valor = valor;
}

// Destructor
Nodo::~Nodo(){      // O(1)

	delete izq;
	delete der;
}



// ---- Metodos Clase ArbolBinarioBusqueda ---- //

// Constructor
ArbolBinarioBusqueda::ArbolBinarioBusqueda(){   // O(1)
	raiz = NULL;
}

// Destructor
ArbolBinarioBusqueda::~ArbolBinarioBusqueda(){   // O(1)
	// Eliminar todos los nodos hacia abajo (implementar, soy flojo)
	delete raiz;
}

// Publico: Insertar un valor en el arbol
bool ArbolBinarioBusqueda::insertar(int valor){     // O(log(n))

	if(raiz == NULL){
		raiz = new Nodo(valor);
		return true;
	}

	return insertar(valor, raiz);
}

// Privado: Insertar un nodo no raiz solo si n !=NULL
bool ArbolBinarioBusqueda:: insertar(int valor, Nodo *n){   // O(log(n))

	// ---- Caso base principal
	// Si el valor está repetido, no se inserta el nodo
	if(valor == n -> valor){
		return false;
	}

	// Si el valor a insertar es menor al del nodo, hacia la izquierda
	if(valor < n -> valor){

		// Si el hijo izquierdo esta vacio, insertar
		if(n -> izq == NULL){
			n -> izq = new Nodo(valor, n);
			return true;
		}

		// Si no está vacio, bajar a la izquierda e intentar insertar
		return insertar(valor, n -> izq);
	}

	// Si el valor a insertar es mayor al del nodo, hacia la derecha
	if(n -> der == NULL){
		n -> der = new Nodo(valor, n);
		return true;
	}

	return insertar(valor, n -> der);
}


// Public: busca el valor en el arbol, retorna NULL si no existe
Nodo *ArbolBinarioBusqueda::buscar(int valor){       // O(log(n))
	
	return buscar(valor, raiz);
}


// Private: busca el valor en un nodo, si no es, baja hasta llegar a una hoja
Nodo *ArbolBinarioBusqueda::buscar(int valor, Nodo *n){    // O(log(n))

	// ---- Casos Base ---- //
	
	// Si es una hoja o raiz, el valor no existe
	if(n == NULL)
		return NULL; 
	
	// Si encontramos el valor, retornar direccion del nodo
	if(n -> valor == valor)
		return n;

	// ---- Casos Recursivos ---- //
	if(valor < n -> valor)
		return buscar(valor, n -> izq);

	return buscar(valor, n -> der);
} 

// Public: Imprimir arbol inOrder
void ArbolBinarioBusqueda::inOrder(){    // O(n)

	std::cout << "In Order:" << std::endl;
	inOrder(raiz);
	std::cout << std::endl;
}

// Private: Imprimir nodo inOrder
void ArbolBinarioBusqueda::inOrder(Nodo *n){  // O(n)
	
	// ---- Caso Base
	// Si llegamos a una hoja, no seguir bajando
	if(n == NULL)
		return;
	inOrder(n -> izq);
	std::cout << n -> valor << " ";
	inOrder(n -> der);
}


// Public: Retorna el nodo mayor del arbol (analogo para el menor)
Nodo *ArbolBinarioBusqueda::mayor(Nodo* n){    // O(log(n))

	if(n == NULL)
		return NULL;

	Nodo *iterador = n;
	while(iterador -> der != NULL)
		iterador = iterador -> der;

	return iterador;
}



















