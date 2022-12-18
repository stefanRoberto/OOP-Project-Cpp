#include <iostream>
#include <string>
#include <iomanip>
#include "Bilet.h"

using namespace std;

int Bilet::nrBilete=0;

Bilet::Bilet() : id(nrBilete++)
{
	pret = 0.0;
	categorie = "N/A";
}

Bilet::Bilet(double pret) : id(nrBilete++)
{
	if (pret > 0)
		this->pret = pret;
	else
		this->pret = 0.0;
	
	categorie = "N/A";
}

Bilet::Bilet(double pret, string categorie) : id(nrBilete++)
{
	if (pret > 0)
		this->pret = pret;
	else
		this->pret = 0.0;

	this->categorie = categorie;
}

Bilet::Bilet(const Bilet& b) : id(nrBilete++)
{
	if (b.pret > 0)
		this->pret = b.pret;
	else
		this->pret = 0.0;

	this->categorie = b.categorie;
}

Bilet& Bilet::operator=(const Bilet& b)
{
	this->pret = b.pret;
	this->categorie = b.categorie;
	return *this;
}

Bilet::~Bilet() {}

int Bilet::getNrBilete()
{
	return nrBilete;
}

int Bilet::reducereNrBilete(int nr)
{
	nrBilete -= nr;
	return nrBilete;
}

int Bilet::getId()
const{
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

double Bilet::operator+(Bilet b)
{
	return this->pret + b.pret;
}

bool Bilet::operator==(Bilet b)
{
	return this->id == b.id;
}

bool Bilet::operator!=(Bilet b)
{
	return this->id != b.id;
}

Bilet Bilet::aplicareReducereProcent(int procent)
{
	if (procent > 0 && procent < 100)
	{
		double reducere = (double)procent / 100;
		this->pret = this->pret - (this->pret * reducere);
	}
	return *this;
}

Bilet Bilet::aplicareReducereLei(double lei)
{
	if (lei > 0 && lei < this->pret)
	{
		this->pret = this->pret - lei;
	}
	return *this;
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

	cout << "Introduceti categoria biletului: ";
	in >> b.categorie;

	return in;
}


