#pragma once
#include <iostream>
#include <string>
#include "Loc.h"

using namespace std;

class Zona
{
    friend class Eveniment;
private:
    string numeZona;
    Loc* locuri;
    int nrLocuri;

public:
    Zona();
    Zona(string numeZona, int nrLocuri, Loc* locuri);
    Zona(const Zona& z);
    ~Zona();
    Zona& operator=(const Zona& z);
    string getNumeZona();
    void setNumeZona(string numeZona);
    const Loc* const& getLocuri() const;
    int getNrLocuri();
    void setNrLocuri(int n);
    void setLocuri(Loc* locuri, int nrLocuri);

    friend ostream& operator<<(ostream& out, Zona& z);
    friend istream& operator>>(istream& in, Zona& z);
};