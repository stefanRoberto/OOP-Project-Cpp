#include "Loc.h"
#include <iostream>
#include <string>
#include "BiletSpecial.h"

using namespace std;

Loc::Loc() : rand(0), codificareLoc("N/A"), ocupat(false) {}

Loc::Loc(int rand, string codificareLoc, Bilet* bilet) : rand(rand), codificareLoc(codificareLoc), ocupat(0), bilet(bilet) {}

Loc::Loc(int rand, string codificareLoc, bool ocupat, Bilet* bilet) : rand(rand), codificareLoc(codificareLoc), ocupat(ocupat), bilet(bilet) {}

Loc::Loc(const Loc& l) : rand(l.rand), codificareLoc(l.codificareLoc), ocupat(l.ocupat), bilet(l.bilet) {}

Loc& Loc::operator=(const Loc& l) {
	if (this != &l) {
		this->rand = l.rand;
		this->codificareLoc = l.codificareLoc;
		this->ocupat = l.ocupat;
		this->bilet = l.bilet;
	}
	return *this;
}

bool Loc::operator==(const Loc& l) const {
	return this->rand == l.rand && this->codificareLoc == l.codificareLoc;
}

Loc::~Loc()
{
	if (bilet != nullptr)
		delete bilet;
}

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

Bilet* Loc::getBilet()
{
	return bilet;
}

void Loc::setBilet(Bilet* bilet)
{
	this->bilet = bilet;
}

ostream& operator<<(ostream& out, const Loc& l)
{
	out << "Locul se afla pe randul: " << l.rand << endl;
	out << "Codificarea locului este: " << l.codificareLoc << endl;

	if (l.ocupat == true)
		out << "Locul este ocupat" << endl;
	else
		out << "Loc este liber" << endl;

	if (l.bilet != nullptr) {
		out << "Bilet: " << endl << *(l.bilet) << endl;
	}
	else {
		out << "Bilet: " << "Locul nu are un bilet atasat" << endl;
	}

	return out;
}

istream& operator>>(istream& in, Loc& l)
{
	cout << "Introduceti randul: ";
	in >> l.rand;

	cout << "Introduceti codificarea locului: ";
	in >> l.codificareLoc;

	cout << "Este ocupat? (0 - Nu, 1 - Da): ";
	in >> ws;
	in >> l.ocupat;

	cout << "\nBiletul: \n";
	
	int input;
	cout << "\nAlegeti tipul biletului:";
	cout << "\n1. Bilet normal\n";
	cout << "2. Bilet special\n\n> ";
	in >> input;
	
	if (input == 1) {
		if (l.bilet != nullptr)
			in >> *l.bilet;
		else
		{
			Bilet* bilet = new Bilet;
			in >> *bilet;
			l.bilet = bilet;
		}
	}
	else if (input == 2) {
		BiletSpecial* biletSpecial = new BiletSpecial;
		in >> *biletSpecial;
		l.bilet = biletSpecial;
	}

	return in;
}


