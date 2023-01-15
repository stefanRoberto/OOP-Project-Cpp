#include <iostream>
#include <string>
#include "Eveniment.h"
#include "Zona.h"
#include "Loc.h"
#include "BiletSpecial.h"
#include "Aplicatie.h"
//#include "Aplicatie.h"

using namespace std;

int main() {
	/*
	Bilet b1;
	cout << b1 << endl;

	Bilet b2(26.59);
	cout << b2 << endl;
	cin >> b2;
	cout << b2 << endl;

	cout << b1.getId() << endl;

	b1 = b2;

	cout << b1;
	Bilet b3;
	b3 = b2;
	cout << b3;

	cout << b2.getId() << endl;
	cout << endl;
	cout << endl;

	cout << b2.getPret() << endl;
	b2.setPret(-25.4);
	cout << b2.getPret() << endl;
	b2.setPret(53.5463);
	cout << b2.getPret() << endl;
	cout << endl;
	cout << endl;


	Bilet b4(60.5, "VIP");
	cout << b4;

	cout << endl;
	cout << endl;


	cout << b1.getCategorie() << endl;
	b1.setCategorie("VIP++Extra");
	cout << b1.getCategorie() << endl;

	cout << b4.aplicareReducereProcent(10);

	cout << endl;
	cout << endl;

	Loc locusor(5,"A2", b4);

	cout << locusor;

	cout << endl;
	cout << endl;

	cout << Bilet::getNrBilete() << endl;*/
	//

	//BiletSpecial bS;
	//bS.setPret(100);

	//bS.aplicareReducereProcent(5);

	//cout << bS.getPret();

	//cin >> bS;

	//cout << endl << bS;

	//Bilet b2(27.5, "VIP+");
	//Bilet b3;
	//Bilet b4(56.2, "Standard");
	//Bilet b5(80, "Medium+");
	//cout << b1 << endl;
	//Bilet* bilet = new Bilet(25.5, "VIP");
	////
	//Loc l1(3, "A12", bilet);
	//
	//cout << l1;

	//cin >> l1;

	//cout << l1;

	//Loc l2;
	//
	//cin >> l2;

	//cout << l2;

	//Bilet b1;
	//cout << b1 << endl;

	//BiletSpecial bS;
	//cout << bS << endl;
	//bS.setPret(100);
	//bS.setCategorie("Special");
	//bS.setCateringInclus(true);
	//bS.setParcareVIP(true);
	//
	//cout << "~~~~~~~~~~~~~~~~" << endl;

	//cout << bS << endl;

	//b1 = bS;

	//cout << b1 << endl;

	//cout << "~~~~~~~~~~~~~~~~" << endl;

	/*Loc l2;

	cin >> l2;

	cout << l2;*/

	//Loc l2(5, "A13", b2);
	//
	//cout << l2;
	//
	//Loc l3(32, "B4A", b3);
	//
	//cout << l3;

	/*Bilet b3(30.5, "VIP++");

	cout << b3.getNrBilete();*/

	//cout << l2.getBilet() << endl;
	//cout << l3.getBilet();

	//cout << endl;

	//const int nrLocuri = 3;
	//vector<Loc> locuri = {
	//	l1,
	//	l2,
	//	l3
	//};
	//Zona zona1("Zona 1", locuri);

	//for (int i = 0; i < nrLocuri; i++)
	//	cout << locuri[i] << endl;
	//cout << endl;

	//cout << zona1;

	//Loc l4(6, "C7", b4);
	//Loc l5(8, "F10", b5);

	//vector<Loc> locuri2 = {
	//	l4,
	//	l5
	//};


	//Eveniment::Eveniment(string numeEveniment, string data, string ora, string locatie, vector<Zona> zone) : numeEveniment(numeEveniment), data(data), ora(ora), locatie(locatie)
	//{
	//	this->zone = zone;
	//	nrZone = zone.size();
	//}
	//Zona zona2("Zona 2", locuri2);

	//cout << zona2;
	//
	//cout << endl << "~~~~~~~~~~TESTARE EVENIMENTE~~~~~~~~~~" << endl << endl;
	//
	//Eveniment eveniment1("Piesa de teatru", "10/06/2020", "19:00", "Teatrul National", { zona1, zona2 });

	/*cout << eveniment1.getNrZone() << endl;
	cout << eveniment1.getZone()[0] << endl;
	cout << string(eveniment1) << endl;*/

	//cout << eveniment1[0] << endl;

	//BiletSpecial bS(70, "Specialmente", 1, 1);
	//
	//cout << bS.getNrBilete() << endl;
	//
	//cout << bS << endl;

	//cout << bS.getCategorie() << endl;

	//BiletSpecial bS2;

	/*cin >> bS2;*/

	//cout << bS2;

	//Bilet b;
	//
	//cin >> b;

	//cout << b; //8 bilete pana acum

	//Eveniment eveniment2;
	//
	//cin >> eveniment2;

	/*Eveniment eveniment;

	cin >> eveniment;

	cout << eveniment;*/

	//Bilet b1;
	//cin >> b1;
	//cout << b1;

	//Loc l1;
	//cin >> l1;
	//cout << endl;
	//cout << l1;

	//Zona z1;
	//cin >> z1;
	//cout << z1;

	/*Eveniment e1;
	cin >> e1;

	cout << "~~~~~~~~~~~~~~~~~~~~";
	cout << e1;*/

	//Loc l1;
	//cin >> l1;
	//cout << l1;

	//Zona z1;
	//cout << z1;
	//cin >> z1;
	////cout << z1;

	/*Bilet* bilet = new Bilet(65.3, "Low cost");
	Loc* l1 = new Loc(5, "A12", bilet);
	vector<Loc*> locuri = { l1 };
	Zona z2("Zona 2", locuri);

	cout << bilet;
	cout << "~~~~~~~~~~~~~~~~~~~~";
	cout << l1;
	cout << "~~~~~~~~~~~~~~~~~~~~\n";
	cout << z2;

	cin >> z2;
	cout << "~~~~~~~~~~~~~~~~~~~~\n";
	cout << z2;*/

	//Eveniment eveniment;
	//cin >> eveniment;
	//cout << "\n\n\n~~~~~~~~~~~~~BILETUL GENERAT ARATA ASA~~~~~~~~~~~~~\n\n\n";
	//cout << eveniment;

	Aplicatie aplicatie;
	aplicatie.ruleaza();

	return 0;
}