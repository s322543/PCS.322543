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
        int q=std::floor((0+n-1)/2); //centro che mi serve dentro il merge 
        
            merge_sort (vec, int 0, q , int vec.size()-1 ); //applico merge sort al vettore che vuole come entrate il vec, il primo indice e l'ultimo indice 
            if (!is_sorted(vec)) { //verifico se il vettore è ordinato 
                std::cerr <<"merge sort non funziona \n"; //se non è ordinato stampo questo messaggio 
                return EXIT_FAILURE; // returna Exit_failure
            } 
    }
    //devo testare anche un vettore stringa 
    std::vector<std::string> vecs={"Torino", "roma", "Napoli", "firenze", "Milano","Bologna", "ancona", "Palermo", "Pavia", "Trapani"}; //alcuni nomi sono in minuscolo e altri in maiuscolo per vedere come mi ordina le stringe
    merge_sort(vecs,int  0, int(std::floor((0+vecs.size()-1)/2)), int vecs.size()-1); 
    if (!is_sorted(vecs)) {
        std::cerr<< "merge_sort su un vettore stringa non funziona \n";
        return EXIT_FAILURE;
    }
     return EXIT_SUCCESS;
}



//per calcolar il tempo 
int main(void) {
    timecounter tc; //instantiate the timecounter
    randfiller rf; 

    for(int n=4; n<=8192; n*=2) { //creo 100 vettori con size diverse multiple di 2 
        std::vector<int> vec(n); //creo un vettore di interi di size 100
        rf.fill(vec, -100, 100); //riempio il vettore con valori random tra -100 e 100
    }
        std::vector<int> vb=vec; //alias per bubble sort
        std::vector<int> vi=vec; //alias per insertion sort
        std::vector<int> vs=vec; //alias per selection sort
        std::vector<int> v_merge=vec; //alias per merge sort
        std::vector<int> v_quick=vec; //alias per il quick sort 
        std::vector<int> v_std=vec;//alias per sort del sistema
     //bubble sort
    tc.tic();
    for (int i=0; i<100; i++){
        bubble_sort(vb[i]);
    }
    double bubble_time =tc.toc();
    double media_bubble =bubble_time/100;

    //insertion sort 
    tc.tic();
    for (int i=0; i<100; i++){
        insertion_sort(vi[i]);
    }
    double insertion_time =tc.toc();
    double media_insertion= insertion_time/100;

    //selection sort
    tc.tic();
    for (int i=0; i<100; i++){
        selection_sort(vs[i]);
    }
    double selection_time=tc.toc();
    double media_selection= selection_time/100;

    //merge sort 
    tc.tic();
    for (int i=0; i<100; i++){
        merge_sort(int v_merge[i],int 0,int(std::floor((v_marge[i].size()-1)/2)),int v_merge[i].size()-1);
    }
    double merge_time= tc.toc();
    double media_merge= merge_time/100;

    //quick sort
    tc.tic();
    for (int i=0; i<100; i++){
        quick_sort(int v_quick[i], int 0,  int v_quick[i].size()-1);
    }
    double quick_time= tc.toc();
    double media_quick = quick_time/100; 

    //sort del sistema 
    tc.tic();
    for (int i=0; i<100; i++){
        std::sort(v_std.begin(), v_std.end());
    }
    double std_time= tc.toc();
    double media_std = std_time/100; 
    
    //stampo i risultati 
    std::cout << "dimensione:" << n << "bubble_sort: "<< media_bubble << ";" 
                                        << "insertion_sort: "<< media_insertion <<";" 
                                        << "selection_sort: " << media_selection << ";" 
                                        << "merge_sort: "<< media_merge <<";" 
                                        << "quick_sort: " << media_quick << ";"
                                        <<"std::sort: "<< media_std << "\n";
    return 0;
}
