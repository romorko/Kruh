#include <iostream>
#include <limits>
#include <time.h>
#include "kruh.h"

int compA(const void * a1, const void *a2);
int compD(const void * a1,const void *a2);
int compNazov(const void * a1,const void *a2);

int main()
{
    srand(time(NULL));
    //Kruh Kruhy[10];
    //Kruh::generuj(Kruhy,10);
    //Kruh::vypisKruhy(Kruhy,10);
    Kruh * KruhyNew=Kruh::generuj(10);
    Kruh::vypisKruhy(KruhyNew,10);
    int (* pComp)(const void * a1, const void *a2);
    pComp=compA;
    qsort(KruhyNew,10,sizeof(Kruh),pComp);
    Kruh::vypisKruhy(KruhyNew,10);
    pComp=compD;
    qsort(KruhyNew,10,sizeof(Kruh),pComp);
    Kruh::vypisKruhy(KruhyNew,10);
    pComp=compNazov;
    qsort(KruhyNew,10,sizeof(Kruh),pComp);
    Kruh::vypisKruhy(KruhyNew,10);
    int (* pCompArray [])(const void * a1, const void *a2)={compA,compD,compNazov};
    for(int i=0;i<3;++i)
    {
        qsort(KruhyNew,10,sizeof(Kruh),pCompArray[i]);
        Kruh::vypisKruhy(KruhyNew,10);
    }
    delete [] KruhyNew;
    //float cislo = Kruh::getfloat(true, true);
    //std::cout<<cislo;
    //Kruh Prvy(4,'n');
    //Kruh kruhy[3]={{3,'a'},{7,'b'},{12,'l'}};
    //Kruh Spolu(0,'s');
    //Kruh prvyKruh(3,'a');
    //Kruh & odkazKruh = prvyKruh;
    //Kruh A(3,'a');
    //Kruh B(6,'b');
    //Kruh::vymenKruhy(&A,&B);
    //Kruh::vymenKruhy(A,B);
    //Kruh C = A+B;  //C = A.operator+(B);
    /*C.vypisKruh();
    (++C).vypisKruh();
    (C++).vypisKruh();
    (--C).vypisKruh();
    (C--).vypisKruh();*/
    //std::cout<<A<<B;
    //std::cout<<C;
    //std::cin>>C;
    //std::cout<<C<<A<<B;
    //Kruh D = C*10;
    //Kruh E = 10*C;

    /*for(auto i:kruhy)
    {
        Spolu=Spolu.spocitaj(i);
    }
    Spolu.vypisKruh();

    Kruh spoluNew(0,'l');
    for(auto i:kruhy)
    {
        spoluNew=spoluNew.spocitaj(&i);
    }
    spoluNew.vypisKruh();

    //Kruh *pKruh = (Kruh *)malloc(sizeof(Kruh));
    Kruh *pKruh = new Kruh(0,'p');
    //int *pole = new int[10];
    //delete []pole;
    for(auto i:kruhy)
    {
        *pKruh=pKruh->spocitaj(&i);
    }
    pKruh->vypisKruh();

    delete pKruh;
    //Spolu.vydel(3).vypisKruh();
    //Spolu.pripocitaj(13).vypisKruh();
    //Kruh::getMax(kruhy,3).vypisKruh();*/
    return 0;
}

Kruh::Kruh()
{
    /*std::cout<<"Zadaj polomer:";
    std::cin>>polomer;
    std::cout<<"Zadaj nazov:";
    std::cin>>nazov;*/
    polomer=1;
    nazov='k';
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

Kruh Kruh::getMax(Kruh pole[], int pocet)
{
    Kruh max=pole[0];
    for(int i=1;i<pocet;++i)
    {
        if(pole[i]>(max))
        {
            max=pole[i];
        }
    }
    return max;
}


void Kruh::vymenKruhy(Kruh *prvy, Kruh *druhy)
{
    Kruh temp;
    temp= *prvy;
    *prvy=*druhy;
    *druhy=temp;
}

void Kruh::vymenKruhy(Kruh &prvy, Kruh &druhy)
{
    Kruh temp;
    temp=prvy;
    prvy=druhy;
    druhy=temp;
}

Kruh Kruh::operator+(const Kruh &inyKruh) const
{
    return {polomer+inyKruh.polomer,(polomer>inyKruh.polomer)?nazov:inyKruh.nazov};
}

bool Kruh::operator>(const Kruh &inyKruh) const
{
    return polomer>inyKruh.polomer;
}

bool Kruh::operator<(const Kruh &inyKruh) const
{
    return polomer<inyKruh.polomer;
}

Kruh Kruh::operator/(float cislo) const
{
    return {polomer/cislo,nazov};
}

Kruh Kruh::operator-(const Kruh &inyKruh) const
{
    return {polomer<=inyKruh.polomer?1:polomer-inyKruh.polomer,'k'};
}

Kruh Kruh::operator*(float cislo) const
{
    return {polomer*cislo,nazov};
}

const Kruh &Kruh::operator++()
{
    ++polomer;
    return *this;
}

Kruh Kruh::operator++(int nepotrebna)
{
    Kruh Tmp = *this;
    ++polomer;
    return Tmp;
}

const Kruh &Kruh::operator--()
{
    polomer = (polomer-1<=0)?1:polomer-1;
    return *this;
}

Kruh Kruh::operator--(int nepotrebny)
{
    Kruh Tmp = *this;
    polomer = (polomer-1<=0)?1:polomer-1;
    return Tmp;
}

const Kruh &Kruh::operator+=(float cislo)
{
    polomer+=cislo;
    return *this;
}

const Kruh &Kruh::operator-=(float cislo)
{
    polomer = (polomer-cislo<=0)?1:polomer-cislo;
    return *this;
}

const Kruh &Kruh::operator*=(float cislo)
{
    polomer*=cislo;
    return *this;
}

const Kruh &Kruh::operator/=(float cislo)
{
    polomer/=cislo;
    return *this;
}

Kruh operator*(float cislo, const Kruh & other)
{
    return other*cislo;
}

Kruh Kruh::operator+(float cislo) const
{
    return {polomer+cislo,nazov};
}

Kruh operator+(float cislo, const Kruh &other)
{
    return other+cislo;
}

std::ostream &operator<<(std::ostream &os, const Kruh &other)
{
    os<<"Kruh ma polomer "<<other.polomer<<" a nazov "<<other.nazov<<std::endl;
    return os;
}

std::istream &operator>>(std::istream &is,Kruh & other)
{
    std::cout<<"Zadaj polomer";
    is>>other.polomer;
    std::cout<<"Zadaj nazov";
    is>>other.nazov;
    return is;
}

float Kruh::getfloat(bool noZero, bool noNegative)
{
    float tmp;
    while(true)
    {
        try
        {
            std::cout<<"Zadaj realne cislo:";
            if(!(std::cin>>tmp))
            {
                throw Kruh::noNumber("Nebolo zadane cislo, skus este raz!");
            }
            if(noZero== true && tmp==0)
            {
                throw Kruh::noZero("Cislo nemoze byt nula!");
            }
            if(noNegative==true and tmp <0)
            {
                throw Kruh::noNegative("Cislo nesmie byt zaporne!");
            }
        }
        catch (const Kruh::noNumber & ex)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            ex.getMsg();
            continue;
        }
        catch (const Kruh::noZero & ex)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            ex.getMsg();
            continue;
        }
        catch (const Kruh::noNegative & ex)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            ex.getMsg();
            continue;
        }
        return tmp;
    }
}

void Kruh::generuj(Kruh *pole, int pocet)
{
    for(int i=0;i<pocet;++i)
    {
        (*(pole+i)).polomer=rand()%100; //pole[i].polomer =
        (*(pole+i)).nazov=rand()%('z'-'a')+'a';     //97 az 122
    }
}

Kruh *Kruh::generuj(int pocet)
{
    Kruh * newKruhy = new Kruh[pocet];
    for(int i=0;i<pocet;++i)
    {
        (*(newKruhy+i)).polomer=rand()%100;
        (*(newKruhy+i)).nazov=rand()%('z'-'a')+'a';     //97 az 122
    }
    return newKruhy;
}

void Kruh::vypisKruhy(const Kruh *pole, int pocet)
{
    std::cout<<"Vypisujem pole kruhov:"<<std::endl;
    for(int i=0;i<pocet;++i)
    {
        std::cout<<*(pole+i);
    }
}

void Kruh::noNumber::getMsg() const
{
    std::cout<<msg<<std::endl;
}

void Kruh::noZero::getMsg() const
{
    std::cout<<msg<<std::endl;
}

void Kruh::noNegative::getMsg() const
{
    std::cout<<msg<<std::endl;
}

int compA(const void * a1, const void *a2)
{
    Kruh * k1 = (Kruh *)a1;
    Kruh * k2 = (Kruh *)a2;
    return k1->getPolomer()-k2->getPolomer();
}

int compD(const void * a1,const void *a2)
{
    Kruh * k1 = (Kruh *)a1;
    Kruh * k2 = (Kruh *)a2;
    return k2->getPolomer()-k1->getPolomer();
}
int compNazov(const void * a1,const void *a2)
{
    Kruh * k1 = (Kruh *)a1;
    Kruh * k2 = (Kruh *)a2;
    return k1->getNazov()-k2->getNazov();
}