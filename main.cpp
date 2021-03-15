#include<bits/stdc++.h>

using namespace std;

class Numar_Complex
{
    double real;
    double imaginar;

public:
    Numar_Complex();
    ~Numar_Complex();

    void afisare();

    double get_real();
    void set_real(double x);

    double get_imaginar();
    void set_imaginar(double x);

    double modul();

    friend class Vector_Complex;
    friend istream& operator>>(istream&, Numar_Complex &);
    friend ostream& operator<<(ostream&, Numar_Complex &);

    Numar_Complex operator+(Numar_Complex C);
};

void Numar_Complex::afisare()
{
    if(imaginar > 0)
        cout<<real<<"+"<<imaginar<<"*i";
    else if(imaginar == 0)
        cout<<real;
    else if(imaginar < 0)
        cout<<real<<imaginar<<"*i";
}

double Numar_Complex::get_real()
{
    return real;
}
void Numar_Complex::set_real(double x)
{
    real = x;
}

double Numar_Complex::get_imaginar()
{
    return imaginar;
}

void Numar_Complex::set_imaginar(double x)
{
    imaginar = x;
}

Numar_Complex::Numar_Complex()
{
    real = 0;
    imaginar = 0;
}

Numar_Complex::~Numar_Complex()
{

}

double Numar_Complex::modul()
{
    double modul = sqrt(real*real + imaginar*imaginar);
    return modul;
}

istream& operator>>(istream& in, Numar_Complex &A)
{
    in>>A.real>>A.imaginar;
    return in;
}

ostream& operator<<(ostream& out, Numar_Complex & A)
{
    if(A.imaginar > 0)
        out<<A.real<<"+"<<A.imaginar<<"*i";
    else if(A.imaginar == 0)
        out<<A.real;
    else if(A.imaginar < 0)
        out<<A.real<<A.imaginar<<"*i";

    return out;
}

Numar_Complex Numar_Complex::operator+(Numar_Complex C)
{

    Numar_Complex rez;
    rez.real = C.real + real;
    rez.imaginar = C.imaginar + imaginar;

    return rez;
}

class Vector_Complex
{
    int n;
    Numar_Complex *v;

public:
    Vector_Complex();
    ~Vector_Complex();
    void afisare();
    void citire();
    void afisareSortModule();
    void sortare();
    void moduleleElementelor();
    Numar_Complex suma();
};

Vector_Complex::Vector_Complex()
{
    v= new Numar_Complex[10];
}

Vector_Complex::~Vector_Complex()
{
    delete[]v;
}

void Vector_Complex::afisare()
{
    cout<<"\nValorile vectorului sunt:\n";

    for(int i = 0; i < n; i++)
        cout<<v[i]<<" ";

    cout<<endl<<endl;
}

void Vector_Complex::citire()
{
    double x,y;
    cout<<"Introduceti numarul de numere n din vector:";
    cin>>n;
    cout<<"\nIntroduceti valorile complexe ale vectorului sub forma - REAL enter IMAGINAR:\n";
    for(int i = 0; i < n; i++)
        cin>>v[i];

}

void Vector_Complex::afisareSortModule()
{
    cout<<"Vectorul sortat dupa module este:\n";
    for(int i = 0; i < n; i++)
    {
        v[i].afisare();
        cout<<" ";
    }
    cout<<endl;
}

void Vector_Complex::sortare()
{
    for(int i = 0 ; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(v[i].modul() > v[i+1].modul())
            {
                swap(v[i], v[i+1]);
            }
}

void Vector_Complex::moduleleElementelor()
{
    cout<<"Modulele elementelor sunt:\n";
    for(int i = 0; i < n; i++)
        cout<<v[i].modul()<<" ";

    cout<<endl<<endl;
}

Numar_Complex Vector_Complex::suma()
{
    Numar_Complex S;
    cout<<"\nSuma elementelor vectorului este:\n";

    for(int i = 0; i < n; i++)
        S = S + v[i];

    return S;
}

int main()
{
    Vector_Complex N;
    N.citire();
    N.afisare();
    N.moduleleElementelor();
    N.sortare();
    N.afisareSortModule();

    Numar_Complex S;
    S = N.suma();
    cout<<S;

    return 0;
}
