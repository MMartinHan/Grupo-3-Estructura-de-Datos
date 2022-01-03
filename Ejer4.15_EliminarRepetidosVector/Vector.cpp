#include "Vector.h"

int Vector::particion(vector<int>& array, int inicio, int fin) {
    int pivote = array[inicio];
    int i = inicio + 1;
    for (int j = i; j <= fin; j++) {
        if (array[j] < pivote) {
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[inicio], array[i - 1]);
    return i - 1;
}

void Vector::quickSort(vector<int>& array, int inicio, int fin) {
    if (inicio < fin) {
        int pivote = particion(array, inicio, fin);
        quickSort(array, inicio, pivote - 1);
        quickSort(array, pivote + 1, fin);
    }
}

void Vector::imprimirArreglo(vector<int>array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Vector::eliminar_duplicados(vector<int>array) {
    std::sort(array.begin(), array.end());
    auto last = std::unique(array.begin(), array.end());
    array.erase(last, array.end());
    imprimirArreglo(array);
}