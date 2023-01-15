#pragma once
#include <iostream>
#include <string>
#include "Zona.h"

using namespace std;

class Eveniment
{
private:
    string numeEveniment;
    string data;
    string ora;
    string locatie;
    vector<Zona> zone;
    int nrZone;

public:
    Eveniment();
    Eveniment(string numeEveniment, string data, string ora, string locatie, vector<Zona> zone);
    ~Eveniment();

    Eveniment(const Eveniment& e);

    Eveniment& operator=(const Eveniment& e);

    string getNumeEveniment();
    void setNumeEveniment(string numeEveniment);

    string getData();
    void setData(string data);

    string getOra();
    void setOra(string ora);

    string getLocatie();
    void setLocatie(string locatie);

    int getNrZone();
    vector<Zona> getZone();
    void setZone(vector<Zona> zone);
    void addZona(Zona zona);
    void removeZona(string numeZona);
    void afisareZone();
	explicit operator string();
	Zona& operator[](int index);
	friend ostream& operator<<(ostream& out, Eveniment& e);
	friend istream& operator>>(istream& in, Eveniment& e);
};
