/* UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
Nombre del programa: 8.4.15(Eliminacion de elementos duplicados de un vector)
Autores: Anthony Villarreal, Martin Han, Esteban Chablay
Fecha de creacion: 02/01/2021
Fecha de modificacion: 02/01/2021
7167 ESTRUCTURA DE DATOS
*/
#include "Vector.h"

using namespace std;

int main() {
    Vector v;
    vector<int>arreglo = { 10, 23, 10, 324, 10, 10, 424, 649, 110, 110, 129, 40, 424 };
    cout << "---Vector---" << endl;
    v.imprimirArreglo(arreglo);
    cout << "---Vector Ordenado---" << endl;
    v.quickSort(arreglo, 0, arreglo.size() - 1);
    v.imprimirArreglo(arreglo);
    cout << "---Vector sin repeticiones Ordenado---" << endl;
    v.eliminar_duplicados(arreglo);
    return 0;
}
