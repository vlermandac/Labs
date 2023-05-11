#include <iostream>
#include <map> // BST
#include <unordered_map> // Hash table
#include "arbolBinarioBusqueda.h"

int main(){

	int n;
	ArbolBinarioBusqueda arbol;

	std::cout << "Cantidad de nodos a insertar: ";
	std::cin >> n;

	for(int i = 0; i < n; i++){

		int val;
		std::cout << "Valor a insertar: ";
		std::cin >> val;
		bool insertado = arbol.insertar(val);

		if(insertado)
			std::cout << val << " insertado!" << std::endl;
		else{
			std::cout << val << " repetido! intente otro valor" << std::endl;
			i--;   // insertar de nuevo
		}

	}

	arbol.inOrder();
		
	return 0;
}
