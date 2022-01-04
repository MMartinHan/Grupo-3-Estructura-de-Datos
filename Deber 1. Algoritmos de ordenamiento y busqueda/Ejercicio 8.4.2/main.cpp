/*
    Universidad de las Fuerzas Armadas ESPE
    Nombre del programa: Ejercicio 8.4.2
    Autor: Grupo 3
    Fecha de creacion: 3/1/2022
    Fecha de modificacion: 3/1/2022
    Nrc: 7167
    Materia: Estructura de Datos
*/

#include <iostream>  
#include <stdlib.h>
#include <time.h>

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

int buscasecuencial(int *a,int ele)
{
for(int i=0;i<30;i++)
if(ele==a[i]){
    return 1;
}
return 0;
}

int main(){
    int A[30];
    srand(time(NULL));
    cout << " El array de valores es: " << endl;
    for (int i = 0; i < 30; i++) {
        A[i] = rand()%(50-1+1)+1;
        cout << A[i] << " ";
    }
    //cout << endl << "Y el array de valores ordenados es: " << endl;
    quickSort(A, 0, 29);
    /*for (int i = 0; i < 30; i++) {
        cout << A[i] << " ";
    }*/
    int elem;
    cout<<"Ingrese elemento a buscar ";
    cin>>elem;
    if(buscasecuencial(A,elem)==1){
        cout<<"Elemento encontrado ";
    }else{
        cout<<"Elemento no encontrado ";
    }
    return 0;

}