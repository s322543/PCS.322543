//passo1: copiare il programma 
#include <iostream>
#include <cmath>

using namespace std; 
int main()
{
    double ad[4]= {0.0,1.1,2.2,3.3};  
    float af[8]={0.0,1.1, 2.2,3.3,4.4,5.5,6.6,7.7};    
    int ai[3]={0,1,2};  //lungo 4 

    int x=1;
    float y=1.1;

    (&y)[1]=0;  //l'obbiettivo è per capire se x e y hanno una posizone relativa tale che ciò che succede qui abbia un effetto a riga 18

    
    std:: cout << &x << "\n";  //stampa indirizzo variabile x
    std:: cout << &y << "\n";  //stampa indirizzo variabile y

    std:: cout << x << "\n"; //secondo punto del primo passo deve stampare 1 mi stampa 0, questo è dovuto al fatto che x e y sono a distanza di 4 bit l'uno dall'altro, quindi sono di seguito essendo x un intero ed essendo lungo 4 bit, quindi quando faccio (&y)[1]=0; sto andando a modificare il valore di x, ecco perché mi stampa 0 invece di 1

    //0x7fffe823f510= 140737088058640  indirizzo di x e 0x7fffe823f50c=140737088058636 indirizzo di y, x e y sono a distanza 4 bit l'uno dall'altro, quindi sono di seguito, prima y e poi x, essendo x un intero e y un float
    
    std:: cout << &ad[2] << "\n"; // stampa indirizzo del terzo elemento dell'array  

    std:: cout << &ad[0] << " " << &ad[3] << "  stampare primo e ultimo elemento di ad" << "\n"; //voglio stampare primo e ultimo elemento di ad
    std:: cout << &af[0] <<" " << &af[7] <<"  stampare primo e ultimo elemento di af" << "\n"; //voglio stampare primo e ultimo elemento di af 
    std:: cout << &ai[0] <<" " << &ai[2] << "  stampare primo e ultimo elemento di ai" << "\n";//voglio stampare primo e ultimo elemento di ai 

   //0x7fffe823f540 0x7fffe823f558  stampare primo e ultimo elemento di ad  140737088058688-140737088058712=24 ogni elemento quindi è lungo 8 bit
   //0x7fffe823f520 0x7fffe823f53c  stampare primo e ultimo elemento di af  140737088058656-140737088058684= 28 ogmi elemento è lungo 4 bit 
   //0x7fffe823f514 0x7fffe823f51c  stampare primo e ultimo elemento di ai  140737088058644-140737088058652= 8 quindi ogni elemento è lungo 4 bit
   return 0;
} 

//nel disegno prima viene rappresentata la y, poi la x, poi ai,poi af e infine ad

 