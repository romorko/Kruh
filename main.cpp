#include <iostream>
#include "kruh.h"

int main()
{
    //Kruh Prvy(4,'n');
    Kruh kruhy[3]={{3,'a'},{7,'b'},{12,'l'}};
    Kruh Spolu(0,'s');
    /*for(int i=0;i<3;++i)
    {
        Spolu=Spolu.spocitaj(kruhy[i]);
    }*/
    for(auto i:kruhy)
    {
        Spolu=Spolu.spocitaj(i);
    }
    Spolu.vydel(3).vypisKruh();
    Spolu.pripocitaj(13).vypisKruh();
    return 0;
}

Kruh::Kruh()
{
    std::cout<<"Zadaj polomer:";
    std::cin>>polomer;
    std::cout<<"Zadaj nazov:";
    std::cin>>nazov;
}

Kruh::Kruh(char mojNazov):nazov(mojNazov)
{
    std::cout<<"Zadaj polomer:";
    std::cin>>polomer;
}

Kruh::Kruh(float mojPolomer):polomer(mojPolomer)
{
    std::cout<<"Zadaj nazov:";
    std::cin>>nazov;
}

Kruh::Kruh(float mojPolomer, char mojNazov):polomer(mojPolomer),nazov(mojNazov)
{

}

float Kruh::getPolomer() const
{
    return polomer;
}

char Kruh::getNazov() const
{    return nazov;
}

void Kruh::setPolomer(float mojPolomer)
{
    polomer=mojPolomer;
}
void Kruh::setNazov(char mojNazov)
{
    nazov=mojNazov;
}

float Kruh::getObvod() const
{
    return static_cast<float>(2*PI*polomer);
}

float Kruh::getObsah() const
{
    return static_cast<float>(PI*polomer*polomer);
}

void Kruh::vypisKruh() const
{
    std::cout<<"Kruh "<<nazov<<" ma polomer "<<polomer<<std::endl;
}

bool Kruh::jeVacsi(Kruh otherKruh)const
{
    return (polomer > otherKruh.polomer);
}

Kruh Kruh::spocitaj(Kruh other) const
{
    return {polomer+other.polomer,(polomer>other.polomer)?nazov:other.nazov};
}

Kruh Kruh::vydel(float cislo) const
{
    return {polomer/cislo,nazov};
}

Kruh Kruh::pripocitaj(float cislo) const
{
    //return Kruh(polomer+cislo,nazov);
    return {polomer+cislo,nazov};
}
