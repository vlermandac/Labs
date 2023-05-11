all: arbol

arbol: arbolBinarioBusqueda.o main.o
	g++ main.o arbolBinarioBusqueda.o -o arbol.out
	rm *.o

arbolBinarioBusqueda.o: arbolBinarioBusqueda.h
	g++ -c arbolBinarioBusqueda.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f arbol.out *.o
