#pragma once
#include "Vector.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include <algorithm>
using namespace std;
using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::setw;
using std::left;

/**
* @file Vector.h
* @version 1.9.2
* @date 02/01/2021
* @author Anthony Villarreal, Martin Han, Esteban Chablay
* @title 8.4.15(Eliminacion de elementos duplicados de un vector)
*/

/**
* @brief Vector clase dedicada para el ordenamiento y operaciones en el vector
*/
class Vector
{
public:
	/**
	* @brief particion separa el vector
	* @param vector<int> llamado al vector
	* @param int inicio del vector
	* @param int fin del vector
	* @return el vector separado
	*/
	int particion(vector<int>& , int , int );
	/**
	* @brief quickSort ordenamiento de las particiones del vector
	* @param vector<int> llamado al vector
	* @param int inicio del vector
	* @param int fin del vector
	*/
	void quickSort(vector<int>& , int , int );
	/**
	* @brief imprimirArreglo imprime el vector
	* @param vector<int> llamado al vector
	*/
	void imprimirArreglo(vector<int>);
	/**
	* @brief eliminar_duplicados elimina los numeros duplicados en el vector
	* @param vector<int> llamado al vector
	*/
	void eliminar_duplicados(vector<int>);
};

