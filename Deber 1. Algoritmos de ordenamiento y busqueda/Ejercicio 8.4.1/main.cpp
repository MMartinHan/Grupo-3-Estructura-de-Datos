/*
    Universidad de las Fuerzas Armadas ESPE
    Nombre del programa: Ejercicio 8.4.1
    Autor: Grupo 3
    Fecha de creacion: 3/1/2022
    Fecha de modificacion: 3/1/2022
    Nrc: 7167
    Materia: Estructura de Datos
*/

#include <iostream>  
#include <stdlib.h>

using namespace std;

void quickSort(int *A, int izq, int der) {  
 //En C y C++ los arrays son punteros, por lo que hay que poner '*A'.
    int piv = A[izq];
    int i = izq;
    int j = der;
    int aux;

    while (i < j) {
        while (A[i] <= piv && i < j) i++;
            while (A[j] > piv) j--;
                if (i < j) {
                    aux  = A[i];
                    A[i] = A[j];
                    A[j] = aux;
                }
            }

        A[izq] = A[j];
        A[j] = piv;
            if (izq<j - 1)
                quickSort(A, izq, j - 1);
            if (j + 1 <der)
                quickSort(A, j + 1, der);
}

int main(){
    int A[14]={33, 45, 67, 8, 12, 32, 56, 7, 9, 10, 22, 45, 98, 9};
    cout << endl << "Y el array de valores ordenados es: " << endl;
    quickSort(A, 0, 13);
    for (int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    return 0;

}