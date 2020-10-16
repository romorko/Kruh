#ifndef KRUH_KRUH_H
#define KRUH_KRUH_H

class Kruh
{
private:
    static constexpr float PI {3.14}; //PI=3.14
    float polomer;
    char nazov;
public:
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
    Kruh spocitaj(Kruh other) const;
    Kruh vydel(float cislo) const;
    Kruh pripocitaj(float cislo) const;
};

#endif //KRUH_KRUH_H
