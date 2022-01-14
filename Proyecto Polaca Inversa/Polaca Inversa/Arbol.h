/***********************************************************************
 * Module:  Arbol.h
* @author Grupo 3
* @date 11/1/2021
 * Purpose: Declaration of the class Arbol
 ***********************************************************************/

#include <string>
#if !defined(__ArbolesBinarios_Arbol_h)
#define __ArbolesBinarios_Arbol_h

typedef std::string T;

#include "Nodo.h"
#include "Nodo.cpp"

class Arbol
{
public:

	Arbol();
   	void insertar(T);
   	void insertar(Nodo * , T);
   	bool vacio();
   	Nodo* getRaiz(void);
   	void setRaiz(Nodo* newRaiz);
   	void inorder(Nodo* nodo);
	void eliminar(Nodo * nodo, T );
	
private:
   Nodo * raiz;


};

#endif
