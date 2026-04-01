#include <iostream>
#include <stdexcept>
#include "rational.hpp" //serve per includere la definizione della classe

//programma che stampa la frazione 3/6 come 1/2
int main()
{
    rational<int> r1(3,6);
    rational<int> r2(1,2); //serve a verificare che mi stampi correttamente 1/2
    
    std::cout << r1 << "\n";
    std::cout << r2 << "\n";

    //ora voglio verificare che funzionino le operazioni di somma, sottrazione e moltiplicazione 
    rational<int> r3 = r1 + r2; // deve darmi 1/1
    std::cout << "r1 +r2 = "<< r3 << "\n";

    rational<int> r4= r1 - r2; //deve restituirmi 0/1; 
    std::cout << "r1-r2 = " << r4 << "\n";

    rational<int> r5 =r1 * r2; // deve risultare 1/4;
    std::cout << "r1*r2 = " << r5 << "\n";

    //casi di inf e nan  da implementare in rational.hpp
    rational<int> inf(1,0); 
    rational<int> r6(2,1); //deve stampare inf
    std::cout << "inf + r6 = " << inf + r6 << "\n";

    rational<int> nan = inf - inf; //deve stamapre nan
    std::cout << "inf - inf = " << nan << "\n";


    return 0;
}