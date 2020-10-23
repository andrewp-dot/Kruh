 #ifndef KRUH_KRUH_H
 #define KRUH_KRUH_H

 class Kruh
 {
 private:
     float polomer;
     char nazov;
     static constexpr float PI=3.14; //staticka premenna, constexpr - constant expresion - konstanty retazec; nie je sucast objektu, patri len danej triede
 public:
     static Kruh getMax(Kruh pole[],int pocet);
     Kruh(float mojPolomer, char mojNazov);
     Kruh();
     explicit Kruh(float mojPolomer);
     explicit Kruh(char mojNazov); //explicit, pretoze mame len 1 parameter a nechceme, aby C++ robilo automaticku konverziu
     float getPolomer() const; //ked metoda nemeni objekt, dajme vediet kompilatoru - "const"
     char getNazov() const;
     void setPolomer(float mojPolomer);
     void setNazov(char mojNazov);
     float getObvod() const;
     float getObsah() const;
     void vypisKruh() const;
     bool jeVacsi(Kruh k) const;
     Kruh pricitajKruh(Kruh k) const;
     Kruh vydel(float n) const;
     Kruh pripocitaj(float cislo) const;
 };

 #endif