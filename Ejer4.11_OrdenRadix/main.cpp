#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <list>
#include <conio.h>

#define siz 10

using namespace std;

void Radix(int [], int);
void print(int [], int);
void radix_sort(int [], int );
void radixSortA( vector<string> & arr, int stringLen );

vector<vector<int>> Vec;

int main()
{
    //RADIX - ENTEROS
    int NumeroDeElementos;
    cout<<"\t\t|~|INGRESO DE NUMEROS|~|"<<endl;
    cout<<"Numeros por Ingresar: "<<endl;
    cin>>NumeroDeElementos;
    int Numeros[NumeroDeElementos];
    for(int i=0; i<NumeroDeElementos; i++){
        cout<<"Numero ["<<i+1<<"]: ";
        cin>>Numeros[i];
    }
    radix_sort(Numeros, NumeroDeElementos);
    print(Numeros, NumeroDeElementos);

    //RADIX - STRING
    int tamLista;
    cout<<"\n\n|======================================================|"<<endl;
    cout<<"\n\t\t|~|INGRESO DE NOMBRES|~|"<<endl;
    cout<<"Tamanio de la lista: "<<endl;
    cin>>tamLista;
    vector<string> lista;
    string palabra;
    //ingreso de datos
    for(int i=0; i<tamLista; i++){
        cout<<"Nombre ["<<i+1<<"]: ";
        cin>>palabra;
        lista.push_back(palabra);
    }
    //radix para string
    radixSortA(lista, tamLista);
    //impresion de datos
    cout<<"\t\t| - | LISTA ORDENADA | - |"<<endl;
    for(int i=0; i<tamLista; i++){
        cout<<"- "<<lista[i]<<endl;
    }
    cout<<"\n|======================================================|"<<endl;
    return 0;
}

//radix simple
void Radix(int a[], int n){
    Vec.resize(10);
    int temp, m=0;
    for(int i=0; i<7; i++){
        for(int j=0; j<n; j++){
            temp=(int)(a[j]/pow(10,i))%10;
            Vec[temp].push_back(a[j]);
        }
        for(int k=0; k<10; k++){
            for(int l=0;l<Vec[k].size(); l++){
                a[m]=Vec[k][l];
                m++;
            }
            Vec[k].clear();
        }
        m=0;
    }
    print(a, n);
}

void print(int a[], int tam){
    cout<<"\t\t| - | NUMEROS ORDENADOS | - |"<<endl;
    for(int i=0;i<tam;i++){
        cout<<"\t["<<a[i]<<"] ";
    }
}

//funtion to find largest element
int largest(int arr[], int n) {
  int large = arr[0], i;
  for (i = 1; i < n; i++) {
    if (arr[i] > large)
      large = arr[i];
  }
  return large;
}


//radix sort function, takes array data and count of elements
void radix_sort(int arr[], int n) {
  int bucket[siz][siz], bucket_count[siz];
  int i, j, k, remainder, NOP = 0, divisor = 1, large, pass;
  large = largest(arr, n);
  while (large > 0) {
    NOP++;
    large /= siz;
  }
  for (pass = 0; pass < NOP; pass++) // Initialize the buckets
  {
    for (i = 0; i < siz; i++)
      bucket_count[i] = 0;
    for (i = 0; i < n; i++) {
      // sort the numbers according to the digit at passth place
      remainder = (arr[i] / divisor) % siz;
      bucket[remainder][bucket_count[remainder]] = arr[i];
      bucket_count[remainder] += 1;
    }
    // collect the numbers after Nth PASS pass
    i = 0;
    for (k = 0; k < siz; k++) {
      for (j = 0; j < bucket_count[k]; j++) {
        arr[i] = bucket[k][j];
        i++;
      }
    }
    divisor *= siz;
  }
}

void radixSortA( vector<string> & arr, int stringLen )
{
    const int BUCKETS = 256;

    vector<vector<string>> buckets( BUCKETS );

    for( int pos = stringLen - 1; pos >= 0; --pos )
    {
        for( string & s : arr )
            buckets[ s[ pos ] ].push_back( std::move( s ) );

        int idx = 0;
        for( auto & thisBucket : buckets )
        {
            for( string & s : thisBucket )
                arr[ idx++ ] = std::move( s );

            thisBucket.clear( );
        }
    }
}

