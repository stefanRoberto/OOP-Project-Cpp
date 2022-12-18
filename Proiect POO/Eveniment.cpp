#include <iostream>
#include <string>
#include "Eveniment.h"

using namespace std;

Eveniment::Eveniment()
{
	numeEveniment = "N/A";
	data = "N/A";
	ora = "N/A";
	locatie = "N/A";
	zone = nullptr;
	nrZone = 0;
}

Eveniment::Eveniment(string numeEveniment, string data, string ora, string locatie, Zona* zone, int nrZone)
{
	this->numeEveniment = numeEveniment;
	this->data = data;
	this->ora = ora;
	this->locatie = locatie;
	
	if (zone != nullptr && nrZone > 0)
	{
		this->zone = new Zona[nrZone];
		for (int i = 0; i < nrZone; i++)
			this->zone[i] = zone[i];
	}
	else
		this->zone = nullptr;
}

Eveniment::Eveniment(const Eveniment& e)
{
	this->numeEveniment = e.numeEveniment;
	this->data = e.data;
	this->ora = e.ora;
	this->locatie = e.locatie;

	if (e.zone != nullptr && e.nrZone > 0)
	{
		this->zone = new Zona[e.nrZone];
		for (int i = 0; i < e.nrZone; i++)
			this->zone[i] = e.zone[i];
	}
	else
		this->zone = nullptr;
}

Eveniment::~Eveniment()
{
	if (zone != nullptr)
	{
		delete[] zone;
		zone = nullptr;
	}
}

Eveniment& Eveniment::operator=(const Eveniment& e)
{
	this->numeEveniment = e.numeEveniment;
	this->data = e.data;
	this->ora = e.ora;
	this->locatie = e.locatie;

	if (e.zone != nullptr && e.nrZone > 0)
	{
		this->zone = new Zona[e.nrZone];
		for (int i = 0; i < e.nrZone; i++)
			this->zone[i] = e.zone[i];
	}
	else
		this->zone = nullptr;

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

const Zona* const& Eveniment::getZone() const
{
	return zone;
}

void Eveniment::setZone(Zona* zone)
{
	if (this->zone != nullptr)
	{
		delete[] this->zone;
		this->zone = nullptr;
	}

	if (zone != nullptr && nrZone > 0)
	{
		this->zone = new Zona[nrZone];
		for (int i = 0; i < nrZone; i++)
			this->zone[i] = zone[i];
	}
	else
		this->zone = nullptr;
}

int Eveniment::getNrZone()
{
	return nrZone;
}

void Eveniment::setNrZone(int nrZone)
{
	this->nrZone = nrZone;
}

Eveniment::operator string()
{
	return numeEveniment;
}

Zona& Eveniment::operator[](int index)
{
	if (index >= 0 && index < nrZone)
		return zone[index];
	else
		throw new exception("Index invalid!");
}

ostream& operator<<(ostream& out, Eveniment& e)
{
	out << "Nume eveniment: " << e.numeEveniment << endl;
	out << "Data: " << e.data << endl;
	out << "Ora: " << e.ora << endl;
	out << "Locatie: " << e.locatie << endl;
	out << "Numar zone: " << e.nrZone << endl;
	out << "Zona: " << e.zone << endl;

	return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Nume eveniment: ";
	in >> e.numeEveniment;
	cout << "Data: ";
	in >> e.data;
	cout << "Ora: ";
	in >> e.ora;
	cout << "Locatie: ";
	in >> e.locatie;
	cout << "Numar zone: ";
	in >> e.nrZone;

	if (e.zone != nullptr)
	{
		delete[] e.zone;
		e.zone = nullptr;
	}

	if (e.nrZone > 0)
	{
		e.zone = new Zona[e.nrZone];
		for (int i = 0; i < e.nrZone; i++)
			in >> e.zone[i];
	}

	return in;
}
