#pragma once
#include <iostream>
#include <string>

using namespace std;

class Bilet
{
private:
	int id;
	static int nrBilete; // va fi incrementat la fiecare creare a unui obiect de tip Bilet
	double pret;
	string categorie;
public:	
	Bilet();
	Bilet(double pret);
	Bilet(double pret, string categorie);
	Bilet(const Bilet& b);
	Bilet& operator=(const Bilet& b);
	int getId();
	static int getNrBilete();
	double getPret();
	void setPret(double pret);
	string getCategorie();
	void setCategorie(string categorie);
	friend ostream& operator<<(ostream& os, const Bilet& b);
	friend istream& operator>>(istream& is, Bilet& b);
};
