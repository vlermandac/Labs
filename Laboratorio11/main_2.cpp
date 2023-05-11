#include <iostream>
#include <map> // BST O(nlog n)
#include <unordered_map> // Hash table O(1)
#include "arbolBinarioBusqueda.h"

using namespace std;

int main(){

	int n;
	ArbolBinarioBusqueda arbol;
  map<string, int> diccionario; // nombre - edad

	std::cout << "Cantidad de nodos a insertar: ";
	std::cin >> n;

	for(int i = 0; i < n; i++){

    string name;
		int val;
		std::cout << "Nombre a insertar: ";
		std::cin >> name;

    //diccionario.insert({name, val});
    if(diccionario.count(name) == 0){ // Si no esta en el mapa
      diccionario[name]++; // sumar uno al nombre
    }

	}

  for(auto p : diccionario){
    cout<<"key: "<<p.first<<". value: "<<p.second<<endl;
  }
		
	return 0;
}
