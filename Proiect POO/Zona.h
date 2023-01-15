#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Loc.h"

using namespace std;

class Zona {
    string numeZona;
    vector<Loc*> locuri;
    int nrLocuri;

public:
    Zona();
    Zona(string numeZona);
    Zona(string numeZona, vector<Loc*> locuri);
    ~Zona();
    Zona(const Zona& z);
    Zona& operator=(const Zona& z);

    string getNumeZona() const;
    void setNumeZona(string numeZona);
    vector<Loc*> getLocuri() const;
    void setLocuri(vector<Loc*> locuri);
    int getNrLocuri() const;
    void appendLoc(const Loc& loc);
    void removeLoc(const Loc& loc);

    friend ostream& operator<<(ostream& out, const Zona& z);
    friend istream& operator>>(istream& in, Zona& z);
};