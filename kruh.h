#ifndef KRUH_KRUH_H
#define KRUH_KRUH_H

class Kruh
{
private:
    float polomer;
    char nazov;
    static constexpr float PI {3.14}; //PI=3.14
public:
    static Kruh getMax(Kruh pole[],int pocet);
    Kruh(float mojPolomer,char mojNazov);
    Kruh();
    explicit Kruh(float mojPolomer);
    explicit Kruh(char mojNazov);
    float getPolomer() const;
    char getNazov() const;
    void setPolomer(float mojPolomer);
    void setNazov(char mojNazov);
    float getObvod() const;
    float getObsah() const;
    void vypisKruh() const;
    bool jeVacsi(Kruh otherKruh) const;
    bool jeVacsi(const Kruh * otherKruh) const;
    Kruh spocitaj(Kruh other) const;
    Kruh spocitaj(const Kruh *otherKruh) const;
    Kruh vydel(float cislo) const;
    Kruh pripocitaj(float cislo) const;
};

#endif //KRUH_KRUH_H
