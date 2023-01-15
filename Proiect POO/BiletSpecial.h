#pragma once
#include <iostream>
#include <string>
#include "Bilet.h"

class BiletSpecial : public Bilet
{
private:
	bool cateringInclus;
	bool parcareVIP;

public:
	BiletSpecial();
	BiletSpecial(double pret, string categorie, bool cateringInclus, bool parcareVIP);
	BiletSpecial(const BiletSpecial& b);
	~BiletSpecial();
	
	BiletSpecial aplicareReducereProcent(double procent);
	void afisareInfoExtra();
	
	bool getCateringInclus() const;
	void setCateringInclus(bool cateringInclus);

	bool getParcareVIP() const;
	void setParcareVIP(bool parcareVIP);

	friend ostream& operator<<(ostream& out, const BiletSpecial& b);
	friend istream& operator>>(istream& in, BiletSpecial& b);
};

