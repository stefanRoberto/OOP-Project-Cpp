#pragma once
#include <iostream>
#include <string>
#include "Bilet.h"

using namespace std;

class Client
{
private:
	string nume;
	char* email;
	Bilet* bilete;
	
public:
	Client();
	Client(string nume, const char* email, Bilet* bilete);
	Client(const Client& c);
	~Client();
	Client& operator=(const Client& c);
	string getNume();
	void setNume(string nume);
	char* getEmail();
	void setEmail(char* email);
	void adaugaBilet(Bilet b);
	void afiseazaBilete();
	friend istream& operator>>(istream& is, Client& c);
	friend ostream& operator<<(ostream& os, const Client& c);
};


