#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "randfiller.h"
#include "es4.h"
#include "is_sorted.h"

//bubble_sort 

//devo creare i test unitari per verificare che i tre algoritmi di ordinamento funzionano e devono returnare EXIT_FAILURE se non funzionano e EXIT_SUCCESS se funzionano 
//devo creare 100 vettori con 100 size diverse e con valori random e verificare se sono ordinati dopo aver applicato i tre algoritmi di ordinamento 
int main() { //devo inizializzare il vettore con valori random e poi testarlo 
    std::srand(std::time(nullptr)); 
    for(int t=0; t<100; t++) { 
        int n=std::rand() %100 +1; //size del vettore da 1 a 100
        std::vector<int> vec(n); //creo un vettore di interi di size n
        randfiller rf; 
        rf.fill(vec, -100, 100); 
        
            bubble_sort(vec); //applico bubble sort al vettore
            if (!is_sorted(vec)) { //verifico se il vettore è ordinato 
                std::cerr <<"bubble sort non funziona \n"; //se non è ordinato stampo questo messaggio 
                return EXIT_FAILURE; // returna Exit_failure
            } 
    }
    //devo testare anche un vettore stringa 
    std::vector<std::string> vecs={"Torino", "roma", "Napoli", "firenze", "Milano","Bologna", "ancona", "Palermo", "Pavia", "Trapani"}; //alcuni nomi sono in minuscolo e altri in maiuscolo per vedere come mi ordina le stringe
    bubble_sort(vecs); 
    if (!is_sorted(vecs)) {
        std::cerr<< "bubble_sort su un vettore stringa non funziona \n";
        return EXIT_FAILURE;
    }
     return EXIT_SUCCESS;
}
//dopo aver testato i codici devo usare in un file a parte timecounter.h e timecounter.cpp per misurare il tempo di esecuzione dei tre algoritmi di ordinamento 
//cmake  e poi make test 