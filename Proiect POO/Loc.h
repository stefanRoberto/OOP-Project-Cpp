#pragma once
#include <iostream>
#include <string>
#include "Bilet.h"

using namespace std;

class Loc
{
	friend class Zona;
private:
	int rand;
	string codificareLoc; // codificareLoc este numarul locului, dar unele locuri pot fi notate cu litere (ex: 1A, 2B, 3C etc),
	//de aceea este string
	bool ocupat;
	const Bilet& bilet;
public:
	Loc();
	Loc(int rand, string codificareLoc, const Bilet& bilet);
	Loc(int rand, string codificareLoc, const Bilet& bilet, bool ocupat);
	Loc(const Loc& l);
	Loc& operator=(const Loc& l);
	~Loc();
	int getRand();
	void setRand(int rand);
	string getCodificareLoc();
	void setCodificareLoc(string codificareLoc);
	bool getOcupat();
	void setOcupat(bool ocupat);
	int getIdBilet();
	bool operator!=(const Loc& l);
	const Bilet& getBilet() const;

	friend ostream& operator<<(ostream& out, Loc& l);
	friend istream& operator>>(istream& in, Loc& l);
};

