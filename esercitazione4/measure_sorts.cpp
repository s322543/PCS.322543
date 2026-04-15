
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
#include "timecounter.h"
#include "es4.h"
#include "randfiller.h"


//per calcolar il tampo 
int main(void) {
    timecounter tc; /* instantiate the timecounter */
    randfiller rf; 
    for(int n=4; n<=8192; n*=2) { //creo 100 vettori con size diverse da 1 a 1000{}
        std::vector<int> vec(n); //creo un vettore di interi di size 1000
        rf.fill(vec, -100, 100); //riempio il vettore con valori random tra -100 e 100
        
        std::vector<int> vb=vec; //alias per bubble sort
        std::vector<int> vi=vec; //alias per insertion sort
        std::vector<int> vs=vec; //alias per selection sort
        std::vector<int> v_std=vec;//alias per sort del sistema
        
        tc.tic();       //inizio timer  
        bubble_sort(vb); //applico bubble sort al vettore
        double secs_bubble = tc.toc(); //stop the timecounter,mi da il tempo di esecuzione del bubble sort
       

        tc.tic();       //inizio timer  
        insertion_sort(vi); //applico insertion sort al vettore
        double secs_insertion = tc.toc(); //stop the timecounter,mi da il tempo di esecuzione del bubble sort
        

        tc.tic();       //inizio timer  
        selection_sort(vs); //applico selection sort al vettore
        double secs_selection = tc.toc(); //stop the timecounter,mi da il tempo di esecuzione del bubble sort
        

        tc.tic();
        std::sort(v_std.begin(), v_std.end()); //applico sort del STL al vettore
        double secs_std= tc.toc();

        std::cout << "dimensione:" << n << "bubble_sort: "<< secs_bubble << ";" 
                                        << "insertion_sort: "<< secs_insertion <<";" 
                                        << "selection_sort: " << secs_selection << ";" 
                                        <<"std::sort: "<< secs_std << "\n";

       }
     return 0;
}
