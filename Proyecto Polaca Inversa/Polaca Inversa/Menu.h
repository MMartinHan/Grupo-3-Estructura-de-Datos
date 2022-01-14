/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* @file Menu.h
* @author Grupo 3
* @date 11/1/2021
* @brief Declaracion de Menu
*/
#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include "Console.h"



class Menu{

public:
	//template<class... Args>
	int makeMenu(int nargs,...);

private:
	Console screen;

};




#endif
