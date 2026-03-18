#include <fstream>
#include <iostream>
#include <string>



int main(int argc, const char *argv[])
{
    if (argc < 2) {
        std::cout << "errore: specificare ilparametro\n";
        return 1;
    }
    std::ifstream ifs(argv[1]); //apre il file di testo in modalità lettura per estrapolare le temperature e la città
    if (ifs.is_open()) {
        std::string città;
        double temp1,temp2,temp3,temp4; //variabile per la temperature  

        while (ifs >> città >> temp1 >> temp2 >> temp3 >> temp4) { //legge sia la città che la temperatura 
            double media = (temp1 + temp2 + temp3 + temp4) / 4; //calcola la media delle 4 temperature
            std::cout << città <<" "<< media << "\n"; //stampa la temperatura media
        }

        ifs.close(); //chiude il file dopo averlo letto, non è importante farlo ma è buona prassi 

    } else {
        std::cerr << "Errore nell'apertura del file!\n";
        return 1;
    }
    
return 0;
}
 //in terminale mi da che c'è un errore di compilazione sicuramente c'è un problema con il ciclo while
