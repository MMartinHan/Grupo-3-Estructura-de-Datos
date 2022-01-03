/*
    Universidad de las Fuerzas Armadas ESPE
    Nombre del programa: Ejercicio 8.4.3
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

int bBinaria(int *x,int t)
{
    int mitad,izq,der;
    izq=0;der=20-1;
    while(izq<=der)
    {
        mitad = (izq+der)/2;
        if(t>x[mitad])izq = mitad+1;
        else if(t<x[mitad]) der = mitad-1;
        else return mitad;
    }
    return -1;
}

int main(){
    int numero,clave;
    int A[20];
    for (int i = 0; i < 20; i++) {
        cout<<"Ingrese el numero "<<i+1<<": "<<endl;
        cin>>numero;
        A[i] = numero;
    }
    cout << endl << "Y el array de valores ordenados es: " << endl;
    quickSort(A, 0, 19);
    for (int i = 0; i < 20; i++) {
        cout << A[i] << " ";
    }
    cout<<""<<endl;
    cout << "Indique un valor a buscar y se le devolvera el indice: " << endl;
    cin >> clave;
    int indice = bBinaria(A,clave);
    if(indice==-1){
        cout<<"El valor no se encuentra en el arreglo"<<endl;
    }else{
        cout<<"El valor se encuentra en el indice "<<indice<<endl;
    }
    return 0;

}