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
     static void vymenKruhy(Kruh *prvy, Kruh *druhy);
     static void vymenKruhy(Kruh &prvy, Kruh &druhy);
     Kruh(float mojPolomer, char mojNazov);
     Kruh();
     static float getFloat(bool noZero = false, bool noNegative = false);
     explicit Kruh(float mojPolomer);
     explicit Kruh(char mojNazov); //explicit, pretoze mame len 1 parameter a nechceme, aby C++ robilo automaticku konverziu
     float getPolomer() const; //ked metoda nemeni objekt, dajme vediet kompilatoru - "const"
     char getNazov() const;
     void setPolomer(float mojPolomer);
     void setNazov(char mojNazov);
     float getObvod() const;
     float getObsah() const;
     bool operator>(const Kruh & dalsiKruh) const;
     bool operator<(const Kruh & dalsiKruh) const;
     Kruh operator+(const Kruh & inyKruh) const;
     Kruh operator+(float cislo) const;
     Kruh operator-(const Kruh & inyKruh) const;
     Kruh operator/(float cislo) const;
     Kruh operator*(float cislo) const;
     void bubbleSort(Kruh pole[], int pocet, bool desc);
     static void vypisKruhy(const Kruh arr[], int arrLength);
     friend Kruh operator+(float cislo, const Kruh & other);
     friend Kruh operator*(float cislo, const Kruh & other); //priatelska metoda - nie je prvkom triedy, ale ma pristup k parametrom triedy
     friend std::ostream & operator<<(std::ostream & os, const Kruh & other);
     friend std::istream & operator>>(std::istream & is, Kruh & other);
     const Kruh & operator++(); //prefixovy operator
     Kruh operator++(int nepotrebna); //postfixovy operato; nepotrebna - symbol, ktory odlisuje prefixovy operator od postfixu
     //vracat iba klasicky kruh pri postfixe
     const Kruh & operator--();
     Kruh operator--(int nepotrebna);
     const Kruh & operator+=(float cislo);
     //friend Kruh operator+=(Kruh other, Kruh other2);
     const Kruh & operator-=(float cislo);
     const Kruh & operator/=(float cislo);
     const Kruh & operator*=(float cislo);
     static Kruh * generujKruhy( int arrayLength);

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
         const char * msg1;
     public:
         noZero(const char * sprava1):msg1(sprava1){};
         void getMsg1() const;
     };

     class noNegative
     {
     private:
         const char * msg2;
     public:
         noNegative(const char * sprava2):msg2(sprava2){};
         void getMsg2() const;

     };

     class streamError
     {
     private:
         const char * streamErrorMsg;
     public:
         streamError(const char * streamErrorSprava):streamErrorMsg(streamErrorSprava){};
         void getStreamErrorMsg() const;
     };


 };



 #endif