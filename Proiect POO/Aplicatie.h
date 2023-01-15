#pragma once
#include "Eveniment.h"
#include "Bilet.h"

class Aplicatie
{
private:
//class has two attributes, a vector of Bilet and a vector of Eveniment, it will be a singleton class
	vector<Eveniment> evenimente;
	vector<Bilet> bilete;
	static Aplicatie* instanta;
public:
	Aplicatie(const Aplicatie& a);
	Aplicatie& operator=(const Aplicatie& a);
	static Aplicatie* getInstanta();
	Aplicatie();
	~Aplicatie();
	void afiseazaMeniu();
	void adaugaBilet();
	void adaugaEveniment();
	void stergeBilet();
	void stergeEveniment();
	void afisareBilete();
	void afisareEvenimente();
	void cautaEveniment();
	void valideazaBilet();
	void ruleaza();
};

