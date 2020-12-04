#ifndef KRUH_KRUH_H
#define KRUH_KRUH_H

class Kruh
{
private:
    float polomer;
    char nazov;
    static constexpr float PI {3.14}; //PI=3.14
public:
    class noNumber
    {
    private:
        const char * msg;
    public:
        noNumber(const char * sprava):msg(sprava){};
        void getMsg() const;
    };

    class noZero
    {
    private:
        const char * msg;
    public:
        noZero(const char * sprava):msg(sprava){};
        void getMsg() const;
    };

    class noNegative
    {
    private:
        const char * msg;
    public:
        noNegative(const char * sprava):msg(sprava){};
        void getMsg() const;
    };
    static Kruh getMax(Kruh pole[],int pocet);
    static void vymenKruhy(Kruh *prvy, Kruh *druhy);
    static void vymenKruhy(Kruh &prvy, Kruh &druhy);
    static float getfloat(bool noZero= false,bool noNegative= false);
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
    bool operator>(const Kruh& inyKruh) const;
    bool operator<(const Kruh& inyKruh) const;
    Kruh operator+(const Kruh & inyKruh) const;
    Kruh operator-(const Kruh & inyKruh) const;
    Kruh operator/(float cislo) const;
    Kruh operator*(float cislo) const;
    Kruh operator+(float cislo) const;
    friend Kruh operator+(float cislo, const Kruh & other);
    friend Kruh operator*(float cislo,const Kruh & other);
    friend std::ostream & operator<<(std::ostream & os,const Kruh & other);
    friend std::istream & operator>>(std::istream & is,Kruh & other);
    const Kruh & operator++();
    Kruh operator++(int nepotrebna);
    const Kruh & operator--();
    Kruh operator--(int nepotrebny);
    const Kruh & operator+=(float cislo);
    const Kruh & operator-=(float cislo);
    const Kruh & operator*=(float cislo);
    const Kruh & operator/=(float cislo);
};



#endif //KRUH_KRUH_H
