#include <iostream>
#include <cmath>

//algoritmo di ordinamento 

 //2.definire un array double di lunghezza N=10 riempio con valori a piacere, calcolare minimo, massimo, media e deviazione standard. 

 //creo tre funzioni separate per calcolare minimo, massimo e la somma, con dei cicli for

  //libreria per la funzione sqrt


 //SECONDO ME HO SBAGLIATO AD ELIMINARE LE FUNZIONI MIN, MAX ECC...
using namespace std;
int main() 
{
    static const int N =4;
    double ad[N]= {2.71,3.14,9.6,1.12}; //lungo 4
    
    double minimo=ad[0]; //inizializzo il min al primo elemento dell'array
    double massimo=ad[0];
    double somma=0;
   
    for(int i=0;i<N; i++) {
        minimo=min(minimo,ad[i]);
        massimo=max(massimo,ad[i]);
        somma=somma+ad[i];
                     
    }
    double media=somma/N; //calcolo la media
    
    double deviazione=0; //ciclo for per deviazione standard 
    for (int i=0; i<N; i++){

        deviazione=deviazione+pow(ad[i]-media,2); //calcolo la somma dei quadrati delle differenze tra ogni elemento e la media
    }   
    
    cout << minimo << " è il valore del minimo \n";
    cout << massimo << " è il valore del massimo \n";
    cout << media << " è il valore della media \n";
    cout << deviazione << " è il valore della deviazioe standard \n";
    return 0;
}

