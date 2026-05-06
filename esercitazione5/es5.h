#include "is_sorted.h"
#include <vector>
#include <iostream>
#include <cmath>

//parte esercitazione 5 template di Mergesort e Quicksort
//Merge
template <typename T>
void merge(std::vector<T>& vec, int p, int q, int r){ //p è il primo, q il centro, r l'ultilmo numero 
    int n1=q-p+1; //n1 size vettore  di sx che si crea dopo che divido
    int n2=r-q;//n2 size vettore di dx che si crea dopo che divido
    std::vector<T> vecL(n1); //vettore di sx
    std::vector<T> vecR(n2); 
    for (int i=0;i<n1;i++) {
        vecL[i]=vec[p+i];
    }
    for (int j=0; j<n2; j++){
        vecR[j]=vec[q+j+1];
    }
     

    int i=0; //indice per il vettore di sx
    int j=0; //indice per; il vettore di dx
    int k=p;
        //fusione
        while(i<n1 && j<n2){
            if (vecL[i]<=vecR[j]){
                vec[k]=vecL[i];
                i++;

            }
            else {
                vec[k]=vecR[j];
                j++;
            }
            k++;
        }
        //se ci sono elementi rimasti nel vettore di sinistra li copia
        while(i<n1){
            vec[k]=vecL[i];
            i++;
            k++;
        }
        //stessa cosa con il vettore di destra
        while(j<n2){
            vec[k]=vecR[j];
            j++;
            k++;
        }

}

//Mergesort
template <typename T>
void merge_sort(std::vector<T>& vec, int p, int r ){  //r sarà size(Vec)-1 e p il primo valore del vettore 
    if (p<r) {
        int q=floor((p+r)/2); //q è il punto di centro  dove viene divisio il vettore 
        merge_sort(vec,p,q); //rifa quello di sopra
        merge_sort(vec,q+1,r);
        merge(vec,p,q,r);     
    }
}

//Partition
template <typename T>
int partition(std::vector<T>& vec, int p, int r) {
    T pivot=vec[r]; //pivot 
    int i=p-1;//indice per il primo elemento del vettore
    for( int j=p; j<r; j++){
        if (vec[j]<pivot +1 ) {
            i++;
            std::swap(vec[i], vec[j]);

        }
    }
    std::swap(vec[i+1], vec[r]);
    return i+1; //nuovo rango del pivot
}

//Quicksort
template <typename T>
void quick_sort(std::vector<T>& vec, int p, int r) { //p è il primo indice del vettore e r è l'ultimo indice del vettore
    if ( p<r) {
        int q=partition(vec,p,r); 
        quick_sort(vec,p,q-1);
        quick_sort(vec,q+1,r);
    
    }
}





// parte dell'esercitazione 4
//Bubble sort 
template <typename T> 
void bubble_sort(std::vector<T>& vec) {
    for( size_t i=0; i<vec.size()-1;i++) {
        for (size_t j=0; j<vec.size()-i-1; j++) {
            if (vec[j]>vec[j+1]) {
                std::swap(vec[j],vec[j+1]);
            }
        }
    }
}

//insertion sort 
template <typename T>
void insertion_sort(std::vector<T>& vec) {
    for (size_t j=1; j<vec.size(); j++){ //nel codice c'è 2
        T key = vec[j];
        int i = j - 1;
        while (i >= 0 && vec[i] > key) {
            vec[i + 1] = vec[i];
            i--;
        }
        vec[i + 1] = key;
    }
}

//selection sort  
template <typename T>
void selection_sort(std::vector<T>& vec) {
    for (size_t i=0; i<vec.size()-1; i++) {
        size_t min_index = i;
        for (size_t j=i+1; j<vec.size(); j++) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        std::swap(vec[i], vec[min_index]);
    }
}