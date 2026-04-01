#pragma once 
#include <iostream>
#include <numeric>
#include <concepts>
template<typename I> requires std::integral<I>
class rational
{ 
    I num_;
    I den_;
    
    void semplifica() {
        if (den_==0) return; //non semplifico se il demominatore è zero 
        
        I mcd = std:: gcd(num_,den_);
        num_ /= mcd;
        den_ /= mcd;
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        } //cambia il segno se il denominatore è negativo
    }

public:
   /*costruttore di default*/
    rational()
     : num_(0), den_(1)
     {}
/*costrutture user-defined*/
    rational(I num, I den)
        : num_(num), den_(den)
    {
            if (den_==0){
                if (num_==0) { 
                    //deve ritornare Nan (viene stampato da es3.cpp al terminale)
                    num_=0; 
                    den_=0;
                } else {
                    //caso num/0 deve ritornare inf 
                    if (num_>0) {
                        num_=1;
                        den_=0;
                    } else {
                        num_=-1; // deve dare -inf 
                        den_=0;
                    }
                }
            } else {
                semplifica();
            }
    }
    I num() const {return num_;}
    I den() const {return den_;}

    //somma
    rational& operator+=(const rational& other) {
        //devo distinguere i casi operazione valida e se uno è Nan
        if ((den_==0 && num_==0) || (other.den_==0 && other.num_==0)) {
            num_=0;
            den_=0; //se uno dei due è nan, il risultato è nan
            return *this;
        }
        //se uno dei due è inf, il risultato è inf
        if (den_==0 || other.den_==0) {
            if (den_==0 && other.den==0) {
                if (num_!=other.num_) {
                    num_=0;
                    den_=0; //inf -inf da nan
                }
            } else if (den_!=0){
                num_= other.num_;
                den_=0; //non ho capito bene perchè 

            }
          return *this; 
        }
        //num_ e den_ finiti e diversi da zero 
        num_= num_*other.den_ + other.num_*den_; //operazione di somma tra razionali 
        den_= den_*other.den_; //mcd tra i denominatori 
        semplifica(); //mi restituisce il risultato semplificato 

        return *this;
    }

    //sottrazione il contrario della somma in pratica
    rational& operator-=(const rational& other) {
        rational neg_other(-other.num(), other.den());
        *this += neg_other; //sottrazione come somma con il razionale opposto
        return *this; 
    }

    // prodotto 
    rational& operator*=(const rational& other) {
        //se uno dei due è Nan, il risultato è nan
        if ((den_==0 && num_==0) || (other.den_==0 && other.num_==0)) {
            num_=0;
            den_=0; //se uno dei due è nan, il risultato è nan
            return *this;
        }
    //caso inf*0 o 0*inf da nan
        if ((num_==0 && other.den_==0) || (den_==0 && other.num_==0)) {
            num_=0;
            den_=0; //inf*0 da nan
            return *this;
        }

        //caso inf*inf o -inf*-inf da inf, inf*-inf da -inf 
        if (den_==0 || other.den_==0) {
            if ((num_>0 && other.num_>0) || (num_<0 && other.num_<0)) {
                num_=1;
            } else {
                num_=-1;
            }
            den_=0; //inf*inf da inf, inf*-inf da -inf 
            return *this;
        }

        //caso normale con numeri finiti e diversi da zero 
        num_= num_*other.num_;
        den_= den_*other.den_;
        semplifica();
        return *this;
    }
    //divisione 
    rational& operator/=(const rational& other){
        rational reciproco(other.num(), other.den());
        *this *= reciproco; //divisione come moltiplicazione per il reciproco
        return *this;
    }
    
    //operatori binari 
    rational operator+(const rational& other) const {  //somma
        rational result= *this;
        result += other;
        return result;
    }
    rational operator-(const rational& other) const {  //sottrazione 
        rational result=*this;
        result -= other;
        return result;
    }
    rational operator*(const rational& other) const{  //prodotto 
        rational result=*this;  
        result *= other;
        return result;
    }
    rational operator/(const rational& other) const { //divisione 
        rational result=*this;
        result /= other;
        return result;
    }
};

template <typename I> //devo specificare che tipo di dati voglio stampare 
std::ostream& 
operator << (std::ostream& os, const rational<I>& r){
    if (r.den()==0 ){
        if (r.num()==0) os << "Nan";//os è l'oggetto di output 
        else {
            if (r.num()>0) os << "inf";
            else 
            os << "-inf"; 
        }
    } else {
        os <<r.num()<<"/"<< r.den(); //stampare num/den 
    }
return os;
}



