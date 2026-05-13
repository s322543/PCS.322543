#include <iostream>
#include <cassert> //per usare asset
#include "unidirected_graph.hpp"
#include <set>
#include <cstdlib> //per testare 

int main(){
    //creo grafo 
    unidirected_graph<int> grafo; 
    grafo.add_edge(1,2);
    grafo.add_edge(2,1); //sto aggiungendo lo stesso arco teoricamente non mi deve aggiungere nulla
    grafo.add_edge(1,3);
    //il test di add_egg è implicito quando testo all_edges 
    
    unidirected_edges<int> e1(1,2);
    unidirected_edges<int> e2(2,1);
    if(e1!=e2){ //voglio vedere se (1,2) e (2,1) sono lo stesso 
        std::cout<<"errore devono essere lo stesso arco \n";
        return EXIT_FAILURE;
    }
    //test dei vicini
    std::set<int> vicini_1= grafo.neighbours(1); //deve restituire 2 e 3 
    //assert(vicini_1.size()==2);
    //std::cout<<"test vicini superato \n";
    
    if(vicini_1.size()!=2){
        std::cout<<"errore numero vicini errato \n";
        return EXIT_FAILURE;
    }
    std::set<int> attesi={2,3}; //controllo se i vicini sono 2 e 3 
    if(vicini_1!=attesi){
        std::cout<<"errore: i vicini di 1 sono errati \n";
        return EXIT_FAILURE;
    }
    
 
    
   

    //test per all_edges e all_nodes
    std::set<unidirected_edges<int>> archi =grafo.all_edges(); 
    std::set<int> nodi= grafo.all_nodes();
    //assert(archi.size()==2);
    //assert(nodi.size()==3);
    //std::cout<<"test all edges superato \n";
    //std::cout<<"test all nodes superato \n";
    if(archi.size()!=2){
        std::cout<<"errore numero archi errato \n";
        return EXIT_FAILURE;
    }
    
     if(nodi.size()!=3){
        std::cout<<"errore numero nodi errato \n";
        return EXIT_FAILURE;
    }
   
    


    //test edge_number e edge_at
    int numero_arco_1_2= grafo.edge_number(unidirected_edges<int>(1,2));
    unidirected_edges<int> arco_at_1= grafo.edge_at(1);
    //assert(numero_arco_1_2==0);
    //assert(arco_at_1==unidirected_edges<int>(1,3));
    //std::cout<<"test edge_number superato \n";
    //std::cout<<"test edge_at superato \n";

     if(numero_arco_1_2!=0){
        std::cout<<"errore indice arco errato \n";
        return EXIT_FAILURE;
    }

    
     if(arco_at_1!=unidirected_edges<int>(1,3)){
        std::cout<<"errore: nome arco errato\n";
        return EXIT_FAILURE;
    }
    

    //test per operatore -
    unidirected_graph<int> grafo2;
    grafo2.add_edge(1,2);
    grafo2.add_edge(2,3);
    unidirected_graph<int> differenza= grafo- grafo2; 
    //assert(differenza.all_edges().size()==1);
    //std::cout <<"test operatore differenza superato \n";
     if(differenza.all_edges().size()!=1){
        std::cout<<"errore grafo differenza sbagliato\n";
        return EXIT_FAILURE;
    }
    assert(differenza.all_edges().find(unidirected_edges<int>(1,3))!=differenza.all_edges().end());
    std::cout<<"il grafico differenza è giusto \n";
     
   
  

        
     return EXIT_SUCCESS; //0; 
}
