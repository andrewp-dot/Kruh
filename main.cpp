#include <iostream>
#include "kruh.h"

int main() {

    /*Kruh Prvy(2, 'e');
    Kruh Dalsi(77,'x');
    Kruh Druhy(8, 'm');*/

    Kruh Vysledny(0, 's');
    Kruh Kruhy[3] = {{5, 'm'}, {7 , 'n'} , {10 , 'o'}};

    //int sum=0;

    //for(int i=0; i<3; i++)
    //{
     //   Vysledny=Vysledny.pricitajKruh(Kruhy[i]);
    //}
    for(auto i: Kruhy)
    {
        Vysledny=Vysledny.pricitajKruh(i);
    }
    Vysledny.vypisKruh();
    Vysledny.vydel(3).vypisKruh();
    Vysledny.pripocitaj(13).vypisKruh();
    Kruh::getMax(Kruhy , 3).vypisKruh();

    return 0;
}

Kruh::Kruh() {
    std::cout << "Zadaj polomer: ";
    std::cin>>polomer;
    std::cout<<"Zadaj nazov: ";
    std::cin>>nazov;
}

Kruh::Kruh(char mojNazov):nazov(mojNazov) { //inicializacia je ryhclejsia!
    //nazov=mojNazov;
    std::cout << "Zadaj polomer: ";
    std::cin>>polomer;
}

Kruh::Kruh(float mojPolomer):polomer(mojPolomer) {
    //polomer=mojPolomer;
    std::cout<<"Zadaj nazov: ";
    std::cin>>nazov;
}

Kruh::Kruh(float mojPolomer, char mojNazov):polomer(mojPolomer),nazov(mojNazov) {
 //   polomer=mojPolomer;
 //   nazov=mojNazov;
}

bool Kruh::jeVacsi(Kruh k) const {
    return polomer > k.polomer;
}

float Kruh::getPolomer() const {
    return polomer;
}

char Kruh::getNazov() const {
    return nazov;
}

void Kruh::setPolomer(float mojPolomer) {
    polomer = mojPolomer;
    //alebo this->polomer = mojPolomer;
}

void Kruh::setNazov(char mojNazov) {
    nazov = mojNazov;
}

float Kruh::getObvod() const {
    return 2*PI*polomer;
}

float Kruh::getObsah() const {
    return PI*polomer*polomer;
}

void Kruh::vypisKruh() const {
    std::cout<< "Kruh " << nazov << " ma polomer " << polomer << std::endl;
}

Kruh Kruh::pricitajKruh(Kruh k) const {
    return Kruh(polomer+k.polomer, this->jeVacsi(k) ? nazov : k.nazov);
}

Kruh Kruh::vydel(float n) const {
    return Kruh(polomer/n, nazov);
}

Kruh Kruh::pripocitaj(float cislo) const
{
    return {polomer+cislo,nazov};
}

Kruh Kruh::getMax(Kruh pole[],int pocet)
{
    Kruh max = pole[0];

    for(int i=1;i<pocet;i++)
    {
        if(pole[i].jeVacsi(max))
        {
            max=pole[i];
        }
    }
    return max;
}

