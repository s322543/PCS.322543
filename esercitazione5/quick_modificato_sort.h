#include "is_sorted.h"
#include <vector>
#include <iostream>
#include <cmath>



//Quicksort
template <typename T>
void quick_modificato_sort(std::vector<T>& vec, int p, int r) { //p è il primo indice del vettore e r è l'ultimo indice del vettore
   
    if (vec.size()<16){ //soglia per cui l'insertion sorte è più efficente  scelgo 10 perchè stampando a terminale ho notato che per dim minori di 10 i sort quadradici sono più veloci del quick sort 
        insertion_sort(vec);
    }
    else{
        if ( p<r) {
            int q=partition(vec,p,r); 
            quick_modificato_sort(vec,p,q-1);
            quick_modificato_sort(vec,q+1,r);
        }
    }
}