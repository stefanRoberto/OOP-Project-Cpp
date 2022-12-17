#include <iostream>
#include <string>
#include <iomanip>
#include "Bilet.h"

using namespace std;

int Bilet::nrBilete;

Bilet::Bilet()
{
	id = ++nrBilete;
	pret = 0.0;
	categorie = "N/A";
}

Bilet::Bilet(double pret)
{
	id = ++nrBilete;
	
	if (pret > 0)
		this->pret = pret;
	else
		this->pret = 0.0;
	
	categorie = "N/A";
}

Bilet::Bilet(double pret, string categorie)
{
	id = ++nrBilete;

	if (pret > 0)
		this->pret = pret;
	else
		this->pret = 0.0;

	this->categorie = categorie;
}

Bilet::Bilet(const Bilet& b)
{
	if (b.pret > 0)
		this->pret = b.pret;
	else
		this->pret = 0.0;
}

Bilet& Bilet::operator=(const Bilet& b)
{
	this->pret = b.pret;
	return *this;
}

int Bilet::getNrBilete()
{
	return nrBilete;
}

int Bilet::getId()
{
	return id;
}

double Bilet::getPret()
{
	return pret;
}

void Bilet::setPret(double pret)
{
	if (pret >= 0)
		this->pret = pret;
}

string Bilet::getCategorie() {
	return categorie;
}

void Bilet::setCategorie(string categorie)
{
	this->categorie = categorie;
}

ostream& operator<<(ostream& out, const Bilet& b)
{
	string pretLei = (b.pret == 1) ? " Leu" : " Lei";

	out << "Pretul biletului este: " << fixed << setprecision(2) << b.pret << pretLei << endl;
	out << "Categoria biletului este: " << b.categorie << endl;

	out << "Numarul total de bilete este: " << b.getNrBilete() << endl;
	out << "ID-ul biletului este: " << b.id << endl;

	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "Introduceti pretul biletului: ";
	in >> b.pret;
	if (b.pret < 0)
		b.pret = 0.0;

	return in;
}


