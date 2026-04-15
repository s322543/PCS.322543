#include "is_sorted.h"
#include <vector>
#include <iostream>
//qua devo fare i tre argortmi  bubble sort, insertion sort e selection sort

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