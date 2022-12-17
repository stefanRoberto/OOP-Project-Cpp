#pragma once
#include <iostream>
#include <string>
#include "Bilet.h"

using namespace std;

class Eveniment
{
private:
	string numeEveniment;
	int nrMaxLocuri;
	string data;
	string ora;
	string locatie;
	Bilet* bilete; // maximul de bilete disponibile va fi egal cu nrMaxLocuri
};

//fa o functie care sa ceara nr de randuri si locuri si sa repartizeze biletele in functie de randuri si locuri

