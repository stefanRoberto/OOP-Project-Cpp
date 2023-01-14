#include "Zona.h"
#include <iostream>
#include <string>
#include "Loc.h"

using namespace std;

Zona::Zona()
{
	numeZona = "N/A";
	nrLocuri = 0;
}

Zona::Zona(string numeZona) : numeZona(numeZona), nrLocuri(0) {}

Zona::Zona(string numeZona, vector<Loc> locuri) : numeZona(numeZona), locuri(locuri), nrLocuri(locuri.size()) {}

string Zona::getNumeZona() const
{
	return numeZona;
}

void Zona::setNumeZona(string numeZona)
{
	this->numeZona = numeZona;
}

vector<Loc> Zona::getLocuri() const
{
	return locuri;
}

void Zona::setLocuri(vector<Loc> locuri)
{
	this->locuri = locuri;
	this->nrLocuri = locuri.size();
}

int Zona::getNrLocuri() const
{
	return nrLocuri;
}

void Zona::appendLoc(const Loc& loc)
{
	locuri.push_back(loc);
	nrLocuri++;
}

void Zona::removeLoc(const Loc& loc)
{
	auto it = find(locuri.begin(), locuri.end(), loc);
	if (it != locuri.end())
	{
		locuri.erase(it);
		nrLocuri--;
	}
}

ostream& operator<<(ostream& out, const Zona& z)
{
	out << "Nume zona: " << z.numeZona << endl;
	out << "Numar locuri: " << z.nrLocuri << endl;
	out << "Locuri: " << endl;
	for (auto loc : z.locuri)
		out << loc << endl;
	return out;
}

istream& operator>>(istream& in, Zona& z)
{
	cout << "Nume zona: ";
	in >> z.numeZona;
	cout << "Numar locuri: ";
	in >> z.nrLocuri;
	cout << "Locuri: " << endl;
	for (int i = 0; i < z.nrLocuri; i++)
	{
		Loc loc;
		in >> loc;
		z.locuri.push_back(loc);
	}
	return in;
}