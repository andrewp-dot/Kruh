#include <iostream>
#include "kruh.h"
#include <limits>
#include <time.h>
#include <fstream>

int compFromH(const void * a1,const void *a2);
int compFromL(const void * a1,const void *a2);
int compName(const void * a1,const void *a2);
void generujDoSuboru(int pocetKruhov, std::ofstream  &fout);
void nacitajZoSuboru(int arrLength, std::ifstream &ffin);

//vygenerovat do suboru 250 000 kruhov, precitat ich zo suboru a vlozit do pola a potom triedit toto pole pomocou qsortu aj bubblesortu a porovnat cas

int main() {

    srand(time(NULL));
    /*Kruh & odkazKruh = prvyKruh;
     & neznamena miesto v pamati, ale odkazuje na miesto v pamati obejktu prvyKruh, pri objektoch pouzivat odkazy - je to rychlejsie
    float cislo = Kruh::getFloat();*/

    //std::ofstream ffout;


    try
    {
        std::ofstream fout("zapis.txt"); //deklaracia objektu s otvorenim suboru
        //ffout.open("zapis.txt"); //otvorenie suboru metodou open
        if(!fout.is_open())
        {
            throw Kruh::streamError("Pri praci so suborom sa nieco dojebalo.");
        };
        fout.close();

    }
    catch (const Kruh::streamError &ex)
    {
        ex.getStreamErrorMsg();
        return 1;
    }

    std::ofstream ffout;
    std::ifstream fin;
    generujDoSuboru(1, ffout);

    try
    {
        fin.open("zapis.txt");
        if(!fin.is_open())
        {
            throw Kruh::streamError("Pri praci so suborom sa vyskytla chyba");
        }
        Kruh k;
        while(fin>>k)
        {
            std::cout<<k;
        }
        fin.close();
    }
    catch (const Kruh::streamError &ex)
    {
        ex.getStreamErrorMsg();
        return 1;
    }


    /*for(int i = 0;i<100;++i)
    {
        srand(time(NULL));

    }*/

   /* Kruh a(5,'a');
    Kruh b(10,'b');
    Kruh::vymenKruhy(&a,&b);
    Kruh::vymenKruhy(a,b);

    Kruh c = a+b; //c = a.operator+(b); - preklad kompilatora - pretazenie operatora +

    std::cout << (a<b) << std::endl;
    std::cout << c;



    //Kruh D = c*10; //c.operator*(10)
    ///Kruh E = 10*c: //10.operator*(c)

    int sum=0;

    //for(int i=0; i<3; i++)
    //{
     //   Vysledny=Vysledny.pricitajKruh(Kruhy[i]);
    //}
    for(auto i: Kruhy)
    {
        Vysledny+=i;
    }
    Kruh spoluNew(8, 'l');
    for(auto i:Kruhy)
    {
        spoluNew += i;
    }


    Kruh *pKruh = new Kruh(8,'s');
    int *pole =new int[10]; //to iste ako v cecku (int *)malloc(sizeof(int)*10);
    for(int i=0;i<*pole+10;++i)
    {
        *(pole + i)=i;
        std::cout <<  pole[i] << std::endl;
    };

    for(auto i:Kruhy)
    {
        *pKruh += i;
    }
    pKruh->vypisKruh();*/

    return 0;
}

Kruh::Kruh() {
   polomer = 1;
   nazov = 's';
}

Kruh::Kruh(char mojNazov):nazov(mojNazov) { //inicializacia je ryhclejsia!
    //nazov=mojNazov;
    std::cout << "Zadaj polomer kruhu: ";
    std::cin>>polomer;
}

Kruh::Kruh(float mojPolomer):polomer(mojPolomer) {
    //polomer=mojPolomer;
    std::cout<<"Zadaj nazov kruhu: ";
    std::cin>>nazov;
}

Kruh::Kruh(float mojPolomer, char mojNazov):polomer(mojPolomer),nazov(mojNazov) {
 //   polomer=mojPolomer;
 //   nazov=mojNazov;
}



bool Kruh::operator>(const Kruh & dalsiKruh) const
{
    return polomer > dalsiKruh.polomer;
}

bool Kruh::operator<(const Kruh & dalsiKruh) const
{
    return polomer < dalsiKruh.polomer;
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

Kruh Kruh::getMax(Kruh pole[],int pocet)
{
    Kruh max = pole[0];

    for(int i=1;i<pocet;i++)
    {
        if(pole[i]>max)
        {
            max=pole[i];
        }
    }
    return max;
}

Kruh Kruh::operator+(const Kruh & inyKruh) const
{
    return {polomer+inyKruh.polomer, (polomer>inyKruh.polomer) ? nazov : inyKruh.nazov };
}

void Kruh::vymenKruhy(Kruh *prvy, Kruh *druhy)
{
    Kruh temp = *prvy;
    *prvy = *druhy;
    *druhy = temp;
}

void Kruh::vymenKruhy(Kruh &prvy, Kruh &druhy)
{
    Kruh temp = prvy;
    prvy = druhy;
    druhy = temp;
}

Kruh Kruh::operator/(float cislo) const
{
    return{ polomer/cislo, nazov};
}
Kruh Kruh::operator-(const Kruh & inyKruh) const
{
    return { polomer>=inyKruh.polomer ? polomer - inyKruh.polomer : 1, nazov> inyKruh.nazov ? nazov : inyKruh.nazov};
}

Kruh Kruh::operator*(float cislo) const
{
    return{ polomer*cislo, nazov};
}

const Kruh & Kruh::operator++() //vzdy vratit konstatny odkaz
{
    ++polomer;
    return *this;
}

const Kruh &Kruh::operator--() {
    polomer = (polomer-1 <=0)? 1 : polomer -1;
    return *this;
}

Kruh Kruh::operator++(int nepotrebna)
{
    Kruh Tmp = *this;
    ++polomer;
    return Tmp; //nemozno vratit odkaz na premennu v zasobniku Tmp, lebo premenna pri skonceni funkcie zanika
}

Kruh Kruh::operator--(int nepotrebna)
{
    Kruh Tmp  = *this;
    polomer = (polomer-1 <=0)? 1 : polomer -1;
    return Tmp;
}

const Kruh & Kruh::operator-=(float cislo)
{
    polomer = (polomer -= cislo) <= 0? 1: polomer-cislo;
    return *this;
}

const Kruh & Kruh::operator+=(float cislo)
{
    polomer += cislo;
    return *this;
}

const Kruh & Kruh::operator/=(float cislo)
{
    polomer /= cislo;
    return *this;
}

const Kruh & Kruh::operator*=(float cislo)
{
    polomer *= cislo;
    return *this;
}

Kruh operator*(float cislo, const Kruh & other)
{
    //return {other.polomer*cislo, other.nazov};
    return other*cislo; //funguje iba ak mame pretazeny objekt * cislo
}

Kruh operator+(float cislo, const Kruh & other)
{
    return other + cislo;
}


Kruh Kruh::operator+(float cislo) const
{
    return{polomer+cislo,nazov};
}

std::ostream & operator<<(std::ostream & os, const Kruh & other)
{
    os<< "Kruh "<< other.nazov <<" ma polomer "<<other.polomer<<"." <<std::endl;
    return os;
}

std::istream & operator>>(std::istream & is, Kruh & other)
{
    std::cout << "Zadaj polomer kruhu: " << std::endl;
    is>>other.polomer;
    std::cout << "Zadaj nazov kruhu: " << std::endl;
    is>>other.nazov;

    return is;
}
float Kruh::getFloat(bool noZero, bool noNegative)
{
    float tmp;
    while(true)
    {
        try
        {
            std::cout<< "Zadaj realne cislo: ";
            if(!(std::cin>>tmp))
            {
                throw Kruh::noNumber("Nebolo zadane cislo. ");
            }
            if(noZero == true and tmp == 0)
            {
                throw Kruh::noZero("Cislo je rovne nule. Zadaj dalsie cislo: ");
            }
            if(noNegative ==true and tmp <=0)
            {
                throw Kruh::noNumber("Cislo je zaporne. Zadaj dalsie cislo: ");
            }

        }
        catch (const noNumber &ex)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ex.getMsg();
            continue;
        }
        return tmp;
    }

}


void Kruh::noNumber::getMsg() const
{
    std::cout<<msg<<std::endl;
}

void Kruh::noZero::getMsg1() const
{
    std::cout<<msg1<<std::endl;
}

void Kruh::noNegative::getMsg2() const
{
    std::cout<<msg2<<std::endl;
}

void Kruh::streamError::getStreamErrorMsg() const
{
    std::cout<<streamErrorMsg<<std::endl;
}


Kruh * Kruh::generujKruhy(int arrayLength)
{
    Kruh *newArr = new Kruh[arrayLength];

    srand(time(NULL));
    float randPolomer;
    char randNazov;

    for(int i=0;i<arrayLength; i++)
    {
        randPolomer=rand() % 100;
        randNazov = rand() % 25 + 97;

        *(newArr + i)={  randPolomer,  randNazov};
    }
    return newArr;
}

void Kruh::bubbleSort(Kruh pole[], int pocet, bool desc) {
    Kruh tmp;
    bool zoradene;
    for (int i = 0; i < pocet - 1; ++i) {
        zoradene = true;
        for (int j = 0; j < pocet - 1; ++j) {
            if (pole[j] > pole[j + 1]) {
                tmp = pole[j];
                pole[j] = pole[j + 1];
                pole[j + 1] = tmp;
                zoradene = false;
            }
        }

        if (zoradene) {
            break;
        }
    }
}

int compFromL(const void * a1,const void *a2)
{
    Kruh * p1 = (Kruh *)a1;
    Kruh * p2 = (Kruh *)a2;
    return p1->getPolomer()-p2->getPolomer();
}

int compFromH(const void * a1,const void *a2)
{
    Kruh * p1 = (Kruh *)a1;
    Kruh * p2 = (Kruh *)a2;
    return p2->getPolomer()-p1->getPolomer();
}

int compName(const void * a1,const void *a2)
{
    Kruh * p1 = (Kruh *)a1;
    Kruh * p2 = (Kruh *)a2;
    return p1->getNazov()-p2->getNazov();
}

void Kruh::vypisKruhy(const Kruh arr[], int arrLength)
{
    for(int i=0;i<arrLength;++i)
    {
        std::cout<< *(arr + i)<<std::endl;
    }
}

void generujDoSuboru(int pocetKruhov, std::ofstream &fout)
{
    fout.open("zapis.txt");
    for(int i =0; i<pocetKruhov; ++i)
    {

        char name = rand() % 24 +97;
        fout<< name << " " << rand() % 100 << std::endl;
    }
    fout.close();
}

void nacitajZoSuboru(int arrLength, std::ifstream &ffin)
{
    Kruh *pole = new Kruh[arrLength];
    for(int i = 0; i<arrLength; i++)
    {
        ffin>>*(pole + i);
        std::cout<<*(pole+i);
    }
}





