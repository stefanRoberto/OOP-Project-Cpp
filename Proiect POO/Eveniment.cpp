#include <iostream>
#include <string>
#include "Eveniment.h"

using namespace std;

Eveniment::Eveniment() : numeEveniment("N/A"), data("N/A"), ora("N/A"), locatie("N/A"), nrZone(0)
{
	zone = {};
}

Eveniment::Eveniment(string numeEveniment, string data, string ora, string locatie, vector<Zona> zone) : numeEveniment(numeEveniment), data(data), ora(ora), locatie(locatie)
{
	this->zone = zone;
	nrZone = zone.size();
}

Eveniment::~Eveniment() {}

Eveniment::Eveniment(const Eveniment& e) : numeEveniment(e.numeEveniment), data(e.data), ora(e.ora), locatie(e.locatie), zone(e.zone), nrZone(e.nrZone) {}

Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (this != &e)
	{
		numeEveniment = e.numeEveniment;
		data = e.data;
		ora = e.ora;
		locatie = e.locatie;
		zone = e.zone;
		nrZone = e.nrZone;
	}
	return *this;
}

string Eveniment::getNumeEveniment()
{
	return numeEveniment;
}

void Eveniment::setNumeEveniment(string numeEveniment)
{
	this->numeEveniment = numeEveniment;
}

string Eveniment::getData()
{
	return data;
}

void Eveniment::setData(string data)
{
	this->data = data;
}

string Eveniment::getOra()
{
	return ora;
}

void Eveniment::setOra(string ora)
{
	this->ora = ora;
}

string Eveniment::getLocatie()
{
	return locatie;
}

void Eveniment::setLocatie(string locatie)
{
	this->locatie = locatie;
}

int Eveniment::getNrZone()
{
	return nrZone;
}

vector<Zona> Eveniment::getZone()
{
	return zone;
}

void Eveniment::setZone(vector<Zona> zone)
{
	this->zone = zone;
	nrZone = zone.size();
}

void Eveniment::addZona(Zona zona)
{
	zone.push_back(zona);
	nrZone++;
}

Eveniment::operator string()
{
	string s = "Nume eveniment: " + numeEveniment + "\nData: " + data + "\nOra: " + ora + "\nLocatie: " + locatie + "\nZone: " + "Z";
	for (int i = 0; i < nrZone; i++)
	{
		s += zone[i].getNumeZona() + "\n";
	}
	return s;
}

Zona& Eveniment::operator[](int index)
{
	return zone[index];
}

ostream& operator<<(ostream& out, Eveniment& e)
{
	out << "Nume eveniment: " << e.numeEveniment << "\nData: " << e.data << "\nOra: " << e.ora << "\nLocatie: " << e.locatie << "\n";
	for (int i = 0; i < e.nrZone; i++)
	{
		out << e.zone[i] << "\n";
	}
	return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Nume eveniment: ";
	in>>ws;
	getline(in, e.numeEveniment);

	cout << "Data: ";
	in >> ws;
	getline(in, e.data);

	cout << "Ora: ";
	in >> ws;
	getline(in, e.ora);

	cout << "Locatie: ";
	in >> ws;
	getline(in, e.locatie);

	cout << "Numar zone: ";
	in >> e.nrZone;
	for (int i = 0; i < e.nrZone; i++)
	{
		Zona z;
		in >> z;
		e.zone.push_back(z);
	}

	return in;
}