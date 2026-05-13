#pragma once
#include <map>
#include <iostream> //per std::ostream
#include<stdexcept> //per le eccezioni
#include <set>
#include <vector>
#include <algorithm> //std::find

template<typename I> 
class unidirected_edges //ci va qualcosa non so cosa 
{
    I nodo_from; //nodo di partenza 
    I nodo_to; //nodo di arrivo ordinarli dal più grande al più piccolo perchè non direzionato
    
    public: 
    // costruttore di defoult mi deve garantire che from sia sempre minore di to
        unidirected_edges(I a, I b) { //a=valore del nodo from e b= valore nodo to 
            if (a<b) {
            nodo_from=a;
            nodo_to=b;
            }
            else{
            nodo_from=b;
            nodo_to=a;
            }
        }

        I from() const {return nodo_from;} //metodo per restituire il nodo di partenza
        I to() const {return nodo_to;}


     bool operator<(const unidirected_edges& other) const
    {
        if (nodo_from<other.nodo_from) return true;
        if (nodo_from>other.nodo_from) return false;
        return nodo_to<other.nodo_to; //se nodo from è uguale confornot edge_to
    }
   
    bool operator==(const unidirected_edges& other) const
    {
        return nodo_from==other.nodo_from && nodo_to==other.nodo_to; //due archi sono uguali se hanno gli stessi nodi di partenza e arrivo
    }

    //creo un template così che l'operatore << riesca ad accedere ai membri privati 
    
    friend std::ostream& operator<<(std::ostream& os, const unidirected_edges<I>& edge) {
        os <<"(" << edge.nodo_from << ","<< edge.nodo_to << ") \n"; //stampa 
        return os;
    };
};


    

template<typename I> 
class unidirected_graph {
 
 std::map<I, std::set<I>> lista_adiacenza;  //mappa associa a ogni nodo un set di nodi vicini 
 std::set<unidirected_edges<I>> archi_set;//set di archi per evitare duplicati 
 std::vector<unidirected_edges<I>> archi_lista; //vettore di archi
public:
//costruttore di default 
    unidirected_graph()= default; 

//costruttore di copia
    unidirected_graph(const unidirected_graph& other)
    :lista_adiacenza(other.lista_adiacenza), archi_set(other.archi_set) {}

//metodo neighbours() restituisce i vicini di un nodo
    std::set<I>  neighbours(const I nodo) const { //cost serve per dire che il metodo non modifica l'oggetto
        auto itor =lista_adiacenza.find(nodo); //creo un iteratore per cercacare 
           if(itor== lista_adiacenza.end()) return {};
              return itor->second; //se il nodo è presente restituisco il set di vicini (itor->second fa andare l'iteratore leggendo nodo restituisc il set di vicini visto che è dentro alla lista di adiacenza)
 }
//metodo add_edge() permette di aggiungere un arco al grafo
    void add_edge(I u, I v) {
        unidirected_edges<I> nuovo_arco(u,v);
        if (archi_set.find(nuovo_arco)==archi_set.end()){ //controllo se l'arco è gia presente 
            archi_set.insert(nuovo_arco);//uso insert perchè è un set
            archi_lista.push_back(nuovo_arco); //aggiungo l'arco al vettore di archi uso push_back perchè è un vettore 
        
            lista_adiacenza[u].insert(v); //aggiungo v come vicino di u
            lista_adiacenza[v].insert(u);//aggiungo u con vicino di v
        } 
    }      


//metodo all_edges() restituisce tutti gli archi 
    const std::set<unidirected_edges<I>>& all_edges() const {
        return archi_set; //restituisco il set di archi 
    }


//metodo all_nodes() restituisce tutti i nodi 
    std::set<I> all_nodes() const {
        std::set<I> nodi_set; //creo un set di nodi 
        for (const auto& nodo: lista_adiacenza){ //range-based for loop per scorrere la mappa di adiacenza
            nodi_set.insert(nodo.first); //.first mi permette di accedere al nodo (che è la mia key della mappa) e lo inserisco nel set di nodi 
            }
            return nodi_set;
    }
   

//metodo edge_number() che restituisce la numerazione all'interno del grafo 
    int edge_number(const unidirected_edges<I>& arco) const {
        int n=archi_lista.size();
        for( int i=0; i<n; ++i) { //scorro il vettore di archi scrivo ++i così che restituisca la posizione dell'arco dopo che il ciclo è finito
            if (archi_lista[i] == arco) return  i;
        }   
        return -1;
    }


//metodo edge_at() che, dato un numero d’arco, restituisce il corrispondente oggetto arco all’interno del grafo,
    unidirected_edges<I> edge_at(int i) const {
        int n=archi_lista.size();
        assert(i>=0 && i<n);
        return archi_lista[i];
    }
//operatore-  permette di calcolare la differenza tra due grafi
    unidirected_graph operator-(const unidirected_graph& other) const {
        unidirected_graph result;
        for (const auto& arco: this->archi_lista) {  //arco: archi indica che scorro il vettore dei archi del grafo
            if (other.archi_set.find(arco) == other.archi_set.end()) { //controllo se l'arco non è presente nel set di archi dell'altro grafo 
                result.add_edge(arco.from(), arco.to()); //aggiunge tutti gli archi di G che G'(other) non ha 
            }
        }
        return result;
    }
};


//add_node() non è stato implementato perchè non è necessario, se aggiungo un arco con add_edge automaticamente aggiungo anche i nodi