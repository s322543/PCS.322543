#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include "es5.h"
#include "randfiller.h"
#include "is_sorted.h"


int main() { //devo inizializzare il vettore con valori random e poi testarlo 
    std::srand(std::time(nullptr)); 
    for(int t=0; t<100; t++) { 
        int n=std::rand() %100 +1; //size del vettore da 1 a 100
        std::vector<int> vec(n); //creo un vettore di interi di size n
        randfiller rf; 
        rf.fill(vec, -100, 100); 
        
            merge_sort(vec, vec.size()-vec.size(),  vec.size()-1 ); //applico marge sort al vettore
            if (!is_sorted(vec)) { //verifico se il vettore è ordinato 
                std::cerr <<"merge sort non funziona \n"; //se non è ordinato stampo questo messaggio 
                return EXIT_FAILURE; // returna Exit_failure
            } 
    }
    //devo testare anche un vettore stringa 
    std::vector<std::string> vecs={"Torino", "roma", "Napoli", "firenze", "Milano","Bologna", "ancona", "Palermo", "Pavia", "Trapani"}; //alcuni nomi sono in minuscolo e altri in maiuscolo per vedere come mi ordina le stringe
    merge_sort(vecs, vecs.size()-vecs.size(), vecs.size()-1 );
    if (!is_sorted(vecs)) {
        std::cerr<< "merge_sort su un vettore stringa non funziona \n";
        return EXIT_FAILURE;
    }
     return EXIT_SUCCESS;
}



