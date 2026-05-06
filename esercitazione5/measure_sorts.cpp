 
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
#include "timecounter.h"
#include "es5.h"
#include "randfiller.h"
#include "is_sorted.h"
#include "quick_modificato_sort.h"

int main(void) {
    timecounter tc; /* instantiate the timecounter */
    randfiller rf; 
    int n_vett=100;
    int soglia=-1; 
    
    

    for(int dim=2; dim<=100; dim++) { 
        std::vector<std::vector<int>> box_vecs;
       
        for(int i=0; i<n_vett; i++){
        std::vector<int> vec(dim); 
        rf.fill(vec, -100, 100); //riempio il vettore con valori random tra -100 e 100
        box_vecs.push_back(vec);
        }
        std::vector<std::vector<int>> vb=box_vecs; //alias per bubble sort
        std::vector<std::vector<int>> vi=box_vecs;
        std::vector<std::vector<int>> vs=box_vecs;
        std::vector<std::vector<int>> v_merge=box_vecs;
        std::vector<std::vector<int>> v_quick=box_vecs;
        std::vector<std::vector<int>> v_quick_modificato=box_vecs;
        std::vector<std::vector<int>> v=box_vecs;
        
        //bubble sort 
        tc.tic();
        for (int i=0; i<n_vett;i++){
            
            bubble_sort(vb[i]); //applico bubble sort al vettore
        }
       double media_bubble=tc.toc()/n_vett;
       
       //sinsertion sort
       tc.tic();
        for (int i=0; i<n_vett;i++){
            insertion_sort(vi[i]); //applico insertion sort al vettore
        }
       double media_insertion=tc.toc()/n_vett;
       
       //selection sort 
        tc.tic();
        for (int i=0; i<n_vett;i++){
             
            selection_sort(vs[i]); 
        }
       double media_selection=tc.toc()/n_vett;

       //merge sort 
        tc.tic();
        for (int i=0; i<n_vett;i++){
            merge_sort(v_merge[i], 0, dim-1); 
        }
         double media_merge=tc.toc()/n_vett;

        //quick sort 
        tc.tic();
        for (int i=0; i<n_vett;i++){    
            quick_sort(v_quick[i], 0, dim-1); 
        }
        double media_quick=tc.toc()/n_vett;

        //std::sort
        tc.tic();
        for(int i=0; i<n_vett; i++){
            
            std::sort(v[i].begin(), v[i].end());
        }
        double media_std=tc.toc()/n_vett;

        //quick sort modificato
        tc.tic();
        for (int i=0; i<n_vett;i++){
            
            quick_modificato_sort(v_quick_modificato[i], 0, dim-1); 
        }
        double media_quick_modificato=tc.toc()/n_vett;


        std::cout << "dimensione:" << dim << "\n" << "tempo medio bubble_sort: "<< media_bubble << "\n" 
                                            << "tempo medio insertion_sort: "<< media_insertion <<"\n" 
                                            << "tempo medio selection_sort: " << media_selection << "\n" 
                                            << "tempo medio merge_sort: "<< media_merge <<"\n" 
                                            << "tempo medio quick_sort: " << media_quick << "\n"
                                            <<"tempo medio std::sort: "<< media_std << "\n"
                                            <<"tempo medio quick_modificato "<< media_quick_modificato << "\n";

    //uso insertion sort come riferimento perchè il il più veloce tra gli algoritmi quadratici 
      if (media_quick >  media_insertion) {
        std::cout <<"gli algoritmi quadratici sono più veloci del quick sort per dimensiione: "<< dim<< "\n";
        } //noto che è alcune volte è  meno efficente dell'insertion, ma questo dipende da come sono stati generati i numeri random

        if (media_merge > media_insertion){
        std::cout <<"gli algoritmi quadratici sono più veloci del merge sort per dimensione: " << dim <<"\n";
        }

        if(soglia ==-1 && media_quick <media_insertion ) {
            soglia=dim;
        }
      
    }
    if(soglia !=-1){
        std::cout <<"la soglia è: " << soglia << "\n";
    }
     return 0;
}



