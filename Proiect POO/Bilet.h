#pragma once
#include <iostream>
#include <string>

using namespace std;

class Bilet
{
	friend class Loc;
	friend class BiletSpecial;
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
	~Bilet();
	
	int getId() const;
	static int getNrBilete();
	static int reducereNrBilete(int nr);
	double getPret() const;
	virtual void setPret(double pret);
	string getCategorie() const;
	void setCategorie(string categorie);
	double operator+(Bilet b);
	bool operator==(Bilet b);
	bool operator!=(Bilet b);
	Bilet aplicareReducereProcent(int procent);
	Bilet aplicareReducereLei(double);
	
	friend ostream& operator<<(ostream& out, const Bilet& b);
	friend istream& operator>>(istream& in, Bilet& b);
};
