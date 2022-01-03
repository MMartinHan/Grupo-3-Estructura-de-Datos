#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int busquedaBinaria(int numeros[], int tam, int dato);

int busquedaBinaria(int numeros[], int tam, int dato){
    int inf, sup, mitad;
    inf=0;
    sup=tam;
    while(inf<=sup){
        mitad=(inf+sup)/2;
        if(numeros[mitad] == dato){
            break;
        }
        if(numeros[mitad]>dato){
            sup=mitad;
            mitad = (inf+sup)/2;
        }
        if(numeros[mitad]<dato){
            inf = mitad;
            mitad = (inf+sup)/2;
        }
    }
    return mitad;
}

int main()
{
    int dato=0;
    int mitad=0;
    int tam=0;
    int datoArray=0;
    bool encontrado=false;

    //Creacion e Ingreso de datos en el arreglo
    cout<<"Ingrese el numero de datos por ingresar: "<<endl;
    cin>>tam;
    int numeros[tam];

    for(int i=0; i<tam; i++){
        cout<<"Ingrese el numero: "<<endl;
        cin>>datoArray;
        numeros[i]=datoArray;
    }

    cout<<"Ingrese el numero a buscar: ";
    cin>>dato;

    for(int j=0; j<tam; j++){
        if(numeros[j]==dato){
            encontrado=true;
        }
    }

    if(encontrado==true){
        mitad=busquedaBinaria(numeros, tam, dato);
        cout<<"El numero ha sido encontrado en la posicion: "<<mitad+1<<endl;
    }
    else{
        cout<<"No se encontro el numero en el arreglo."<<endl;
    }

    return 0;
}
