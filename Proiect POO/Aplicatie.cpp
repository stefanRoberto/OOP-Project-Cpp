#include "Aplicatie.h"

Aplicatie* Aplicatie::instanta = nullptr;

Aplicatie* Aplicatie::getInstanta()
{
	if (instanta == nullptr)
	{
		instanta = new Aplicatie();
	}
	return instanta;
}

Aplicatie::Aplicatie() {}

Aplicatie::Aplicatie(const Aplicatie& a)
{
	evenimente = a.evenimente;
	bilete = a.bilete;
}

Aplicatie& Aplicatie::operator=(const Aplicatie& a)
{
	if (this != &a)
	{
		evenimente = a.evenimente;
		bilete = a.bilete;
	}
	return *this;
}

Aplicatie::~Aplicatie()
{
	evenimente.clear();
	bilete.clear();
}

void Aplicatie::ruleaza()
{
	cout << "DISCLAIMER: Nu merg toate optiunile, se recomanda a alege optiunea 1 pentru testare, inainte de toate celelalte.\n\n> Multumesc pentru intelegere :)\n" << endl;
	afiseazaMeniu();
}

void Aplicatie::afiseazaMeniu()
{
	int optiune;
	do
	{
		cout << "1. Adauga eveniment" << endl;
		cout << "2. Adauga bilet" << endl;
		cout << "3. Sterge eveniment" << endl;
		cout << "4. Sterge bilet" << endl;
		cout << "5. Afiseaza evenimente" << endl;
		cout << "6. Afiseaza bilete" << endl;
		cout << "7. Cauta eveniment" << endl;
		cout << "8. Valideaza bilet" << endl;
		cout << "9. Iesire" << endl;
		cout << "\nOptiune: ";
		cin >> optiune;
		cout << "\n\n";
		switch (optiune)
		{
		case 1:
			adaugaEveniment();
			break;
		case 2:
			adaugaBilet();
			break;
		case 3:
			stergeEveniment();
			break;
		case 4:
			stergeBilet();
			break;
		case 5:
			afisareEvenimente();
			break;
		case 6:
			afisareBilete();
			break;
		case 7:
			cautaEveniment();
			break;
		case 8:
			valideazaBilet();
			break;
		case 9:
			cout << "La revedere!" << endl;
			break;
		default:
			cout << "Optiune invalida!" << endl;
			break;
		}
	} while (optiune != 9);
}

void Aplicatie::adaugaBilet()
{
	Bilet b;
	cin >> b;
	cout << "\n~~~AFISARE~~~\n";
	cout << b;
	bilete.push_back(b);
}

void Aplicatie::adaugaEveniment()
{
	Eveniment e;
	cin >> e;
	cout << "\n~~~AFISARE~~~\n";
	cout << e;
	evenimente.push_back(e);
}

void Aplicatie::stergeBilet()
{
	int id;
	cout << "\nIntroduceti id-ul biletului pe care doriti sa il stergeti: ";
	cin >> id;
	
	for (int i = 0; i < bilete.size(); i++)
	{
		if (bilete[i].getId() == id)
		{
			bilete.erase(bilete.begin() + i);
			cout << "\nBiletul a fost sters cu succes!\n" << endl;
			return;
		}
	}
	cout << "\nNu exista niciun bilet cu acest id!\n" << endl;
}

void Aplicatie::stergeEveniment()
{
	string numeEveniment;
	cout << "\nIntroduceti numele evenimentului pe care doriti sa il stergeti: ";
	cin.ignore();
	getline(cin, numeEveniment);
	
	for (int i = 0; i < evenimente.size(); i++)
	{
		if (evenimente[i].getNumeEveniment() == numeEveniment)
		{
			evenimente.erase(evenimente.begin() + i);
			cout << "\nEvenimentul " << numeEveniment << " a fost sters cu succes!\n" << endl;
			return;
		}
	}
	cout << "Nu exista niciun eveniment cu acest nume!\n" << endl;
}

void Aplicatie::afisareBilete()
{
	for (int i = 0; i < bilete.size(); i++)
	{
		cout << bilete[i] << endl;
	}
}

void Aplicatie::afisareEvenimente()
{
	for (int i = 0; i < evenimente.size(); i++)
	{
		cout << evenimente[i] << endl;
	}
}

void Aplicatie::cautaEveniment() 
{
	string numeEveniment;
	cout << "Introduceti numele evenimentului pe care doriti sa il cautati: ";
	cin.ignore();
	getline(cin, numeEveniment);

	for (int i = 0; i < evenimente.size(); i++)
	{
		if (evenimente[i].getNumeEveniment() == numeEveniment)
		{
			cout << "Evenimentul " << numeEveniment << " a fost gasit!\n" << endl;
			return;
		}
	}
	cout << "Nu exista niciun eveniment cu acest nume!\n" << endl;
}

void Aplicatie::valideazaBilet() 
{
	int id;
	cout << "\nIntroduceti id-ul biletului pe care doriti sa il validati: ";
	cin >> id;
	
	for (int i = 0; i < bilete.size(); i++)
	{
		if (bilete[i].getId() == id)
		{
			cout << "\nBiletul cu id-ul " << id << " este valid!\n" << endl;
			return;
		}
	}
	cout << "\nNu exista niciun bilet cu acest id!\n" << endl;
}