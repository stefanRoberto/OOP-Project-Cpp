#include <iostream>
#include <string>
#include "Client.h"

using namespace std;

Client::Client()
{
	this->nume = "N/A";
	this->email = nullptr;
}

Client::Client(string nume, const char* email, Bilet* bilete)
{
	this->nume = nume;

	if (email != nullptr)
	{
		this->email = new char[strlen(email) + 1];
		strcpy_s(this->email, strlen(email) + 1, email);
	}
	else
		this->email = nullptr;
	
	if (bilete != nullptr && bilete->getNrBilete() > 0)
	{
		this->bilete = new Bilet[bilete->getNrBilete()];
		for (int i = 0; i < bilete->getNrBilete(); i++)
			this->bilete[i] = bilete[i];
	}
	else
		this->bilete = nullptr;
}


Client::Client(const Client& c)
{
	this->nume = c.nume;
	if (c.email != nullptr)
	{
		this->email = new char[strlen(c.email) + 1];
		strcpy_s(this->email, strlen(c.email) + 1, c.email);
	}
	else
		this->email = nullptr;

	if (c.bilete != nullptr && c.bilete->getNrBilete() > 0)
	{
		this->bilete = new Bilet[c.bilete->getNrBilete()];
		for (int i = 0; i < c.bilete->getNrBilete(); i++)
			this->bilete[i] = c.bilete[i];
	}
	else
		this->bilete = nullptr;
}

Client::~Client()
{
	if (this->email != nullptr)
	{
		delete[] this->email;
		this->email = nullptr;
	}
	if (this->bilete != nullptr)
	{
		delete[] this->bilete;
		this->bilete = nullptr;
	}
}

Client& Client::operator=(const Client& c)
{
	this->nume = c.nume;
	if (c.email != nullptr)
	{
		if (this->email != nullptr)
			delete[] this->email;
		this->email = new char[strlen(c.email) + 1];
		strcpy_s(this->email, strlen(c.email) + 1, c.email);
	}
	else
		this->email = nullptr;

	if (c.bilete != nullptr && c.bilete->getNrBilete() > 0)
	{
		if (this->bilete != nullptr)
			delete[] this->bilete;
		this->bilete = new Bilet[c.bilete->getNrBilete()];
		for (int i = 0; i < c.bilete->getNrBilete(); i++)
			this->bilete[i] = c.bilete[i];
	}
	else
		this->bilete = nullptr;
	return *this;
}

string Client::getNume()
{
	return nume;
}

void Client::setNume(string nume)
{
	this->nume = nume;
}

char* Client::getEmail()
{
	if (this->email != nullptr)
	{
		char* copie = new char[strlen(this->email) + 1];
		strcpy_s(copie, strlen(this->email) + 1, this->email);
		return copie;
	}
	else
		return nullptr;
}

void Client::setEmail(char* email)
{
	if (this->email != nullptr)
		delete[] this->email;
	if (email != nullptr)
	{
		this->email = new char[strlen(email) + 1];
		strcpy_s(this->email, strlen(email) + 1, email);
	}
	else
		this->email = nullptr;
}

void Client::adaugaBilet(Bilet b)
{
	if (this->bilete != nullptr)
	{
		Bilet* copie = new Bilet[this->bilete->getNrBilete() + 1];
		for (int i = 0; i < this->bilete->getNrBilete(); i++)
			copie[i] = this->bilete[i];
		copie[this->bilete->getNrBilete()] = b;
		delete[] this->bilete;
		this->bilete = copie;
	}
	else
	{
		this->bilete = new Bilet[1];
		this->bilete[0] = b;
	}
}

void Client::afiseazaBilete()
{
	if (this->bilete != nullptr)
	{
		for (int i = 0; i < this->bilete->getNrBilete(); i++)
			cout << this->bilete[i];
	}
}


ostream& operator<<(ostream& out, const Client& c)
{
	out << "Nume: " << c.nume << endl;
	out << "Email: " << c.email << endl;
	if (c.bilete != nullptr)
	{
		for (int i = 0; i < c.bilete->getNrBilete(); i++)
			out << c.bilete[i];
	}
	return out;
}

istream& operator>>(istream& in, Client& c)
{
	cout << "Nume: ";
	in >> c.nume;
	cout << "Email: ";
	char buffer[50];
	in >> buffer;
	if (c.email != nullptr)
		delete[] c.email;
	c.email = new char[strlen(buffer) + 1];
	strcpy_s(c.email, strlen(buffer) + 1, buffer);
	return in;
}