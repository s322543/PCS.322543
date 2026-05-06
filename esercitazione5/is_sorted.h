
#pragma once
//verifica che un vettore sia ordinato
#include <optional>
#include <vector>
//bool valore di ritorno buleano 
template <typename T>
bool is_sorted(const std::vector<T>& vec) {  //vec è un vettore di tipo T 
    if (vec.size() == 0) {
        return true; //un vettore vuoto è considerato ordinato 
    }
    for (size_t i = 1; i < vec.size(); ++i) { //size_t è tipo di dato 
        if (vec[i] < vec[i - 1]) {
            return false; //non è ordinaogt 
        }
    }
    return true; //vero se è ordinato 
}
