#pragma once
#include <iostream>
#include <string>
#include "Bilet.h"

using namespace std;

class Loc {
	friend class Zona;
private:
	int rand;
	string codificareLoc;
	bool ocupat;
	Bilet* bilet;
public:
	Loc();
	Loc(int rand, string codificareLoc,	Bilet* bilet);
	Loc(int rand, string codificareLoc, bool ocupat, Bilet* bilet);
	Loc(const Loc& l);
	~Loc();
	Loc& operator=(const Loc& l);
	bool operator==(const Loc& l) const;
	
	int getRand();
	void setRand(int rand);
	string getCodificareLoc();
	void setCodificareLoc(string codificareLoc);
	bool getOcupat();
	void setOcupat(bool ocupat);
	Bilet* getBilet();
	void setBilet(Bilet* bilet);

	friend istream& operator>>(istream& in, Loc& l);
	friend ostream& operator<<(ostream& out, const Loc& l);
};

