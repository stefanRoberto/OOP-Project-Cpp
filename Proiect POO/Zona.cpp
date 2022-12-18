#include "Zona.h"
#include <iostream>
#include <string>
#include "Loc.h"

using namespace std;

Zona::Zona()
{
	numeZona = "N/A";
	locuri = nullptr;
	nrLocuri = 0;
}

Zona::Zona(std::string numeZona, int nrLocuri, Loc* locuri)
{
	this->numeZona = numeZona;
	this->nrLocuri = nrLocuri;

	if (locuri != nullptr && nrLocuri > 0)
	{
		this->locuri = new Loc[nrLocuri];
		for (int i = 0; i < nrLocuri; i++)
			this->locuri[i] = locuri[i];
	}
	else
		this->locuri = nullptr;
}

Zona::~Zona()
{
	if (locuri != nullptr)
	{
		delete[] locuri;
		locuri = nullptr;
	}
}

Zona::Zona(const Zona& z)
{
	this->numeZona = z.numeZona;
	this->nrLocuri = z.nrLocuri;

	if (z.locuri != nullptr && z.nrLocuri > 0)
	{
		this->locuri = new Loc[z.nrLocuri];
		for (int i = 0; i < z.nrLocuri; i++)
			this->locuri[i] = z.locuri[i];
	}
	else
		this->locuri = nullptr;
}

Zona& Zona::operator=(const Zona& z)
{
	this->numeZona = z.numeZona;
	this->nrLocuri = z.nrLocuri;

	if (z.locuri != nullptr && z.nrLocuri > 0)
	{
		if (this->locuri != nullptr)
			delete[] this->locuri;
		this->locuri = new Loc[z.nrLocuri];
		for (int i = 0; i < z.nrLocuri; i++)
			this->locuri[i] = z.locuri[i];
	}
	else
		this->locuri = nullptr;

	return *this;
}

string Zona::getNumeZona()
{
	return numeZona;
}

void Zona::setNumeZona(string numeZona)
{
	this->numeZona = numeZona;
}

const Loc* const& Zona::getLocuri() const
{
	return locuri;
}

int Zona::getNrLocuri()
{
	return nrLocuri;
}

void Zona::setLocuri(Loc* locuri, int nrLocuri)
{
	if (this->locuri != nullptr)
	{
		delete[] this->locuri;
		this->locuri = nullptr;
	}
	this->nrLocuri = nrLocuri;

	if (locuri != nullptr && nrLocuri > 0)
	{
		this->locuri = new Loc[nrLocuri];
		for (int i = 0; i < nrLocuri; i++)
			this->locuri[i] = locuri[i];
	}
	else
		this->locuri = nullptr;
}

ostream& operator<<(ostream& out, Zona& z)
{
	out << "Nume zona: " << z.numeZona << endl;
	out << "Numar locuri: " << z.nrLocuri << endl;
	out << "Locuri: " << endl;
	for (int i = 0; i < z.nrLocuri; i++)
		out << z.locuri[i] << endl;
	return out;
}

istream& operator>>(istream& in, Zona& z)
{
	cout << "Nume zona: ";
	in >> z.numeZona;
	cout << "Numar locuri: ";
	in >> z.nrLocuri;
	if (z.locuri != nullptr)
	{
		delete[] z.locuri;
		z.locuri = nullptr;
	}
	if (z.nrLocuri > 0)
	{
		z.locuri = new Loc[z.nrLocuri];
		for (int i = 0; i < z.nrLocuri; i++)
			in >> z.locuri[i];
	}
	return in;
}