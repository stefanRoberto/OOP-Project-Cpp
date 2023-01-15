#include "Loc.h"
#include <iostream>
#include <string>

using namespace std;

Loc::Loc() : bilet({})
{
	rand = 0;
	codificareLoc = "N/A";
	ocupat = false;
}

Loc::Loc(int rand, string codificareLoc, const Bilet& bilet) : bilet(bilet)
{
	this->rand = rand;
	this->codificareLoc = codificareLoc;
	ocupat = false;
}

Loc::Loc(int rand, string codificareLoc, const Bilet& bilet, bool ocupat) : bilet(bilet)
{
	this->rand = rand;
	this->codificareLoc = codificareLoc;
	this->ocupat = ocupat;
}

Loc::Loc(const Loc& l) : bilet(l.bilet)
{
	this->rand = l.rand;
	this->codificareLoc = l.codificareLoc;
	this->ocupat = l.ocupat;
}

Loc& Loc::operator=(const Loc& l)
{
	this->rand = l.rand;
	this->codificareLoc = l.codificareLoc;
	this->ocupat = l.ocupat;
	
	return *this;
}

bool Loc::operator==(const Loc& l)
{
	return this->rand == l.rand && this->codificareLoc == l.codificareLoc;
}

Loc::~Loc() {}

int Loc::getRand()
{
	return rand;
}

void Loc::setRand(int rand)
{
	this->rand = rand;
}

string Loc::getCodificareLoc()
{
	return codificareLoc;
}

void Loc::setCodificareLoc(string codificareLoc)
{
	this->codificareLoc = codificareLoc;
}

bool Loc::getOcupat()
{
	return ocupat;
}

void Loc::setOcupat(bool ocupat)
{
	this->ocupat = ocupat;
}

int Loc::getIdBilet()
{
	return bilet.getId();
}

bool Loc::operator!=(const Loc& l)
{
	if (this->bilet.getId() != l.bilet.getId())
		return false;
}

const Bilet& Loc::getBilet() const
{
	return bilet;
}

ostream& operator<<(ostream& out, Loc& l)
{
	out << "Rand: " << l.getRand() << endl;
	out << "Codificare loc: " << l.getCodificareLoc() << endl;
	
	if (l.getOcupat() == true)
		out << "Loc ocupat" << endl;
	else
		out << "Loc liber" << endl;
	
	out << l.getBilet() << endl;
	
	return out;
}

istream& operator>>(istream& in, Loc& l)
{
	cout << "Introduceti numarul randului: " << endl;
	in >> l.rand;
	
	cout << "Introduceti codificarea locului: " << endl;
	in >> ws;
	getline(in, l.codificareLoc);
	
	cout << "Specificati daca locul este ocupat (0 - nu, 1 - da): " << endl;
	in >> l.ocupat;
	
	return in;
}

