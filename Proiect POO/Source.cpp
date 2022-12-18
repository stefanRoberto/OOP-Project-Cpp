#include <iostream>
#include <string>
#include "Client.h"
#include "Eveniment.h"
#include "Zona.h"
#include "Loc.h"
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
	Bilet b1(25.5, "VIP");
	Bilet b2(27.5, "VIP+");
	Bilet b3;
	//
	Loc l1(3, "A12", b1);
	//
	//cout << l1;

	Loc l2(5, "A13", b2);
	//
	//cout << l2;
	//
	Loc l3(32, "B4A", b3);
	//
	//cout << l3;

	/*Bilet b3(30.5, "VIP++");
	
	cout << b3.getNrBilete();*/

	cout << l2.getBilet() << endl;
	cout << l3.getBilet();

	cout << endl;

	const int nrLocuri = 3;
	Loc locuri[nrLocuri] = {
		l1,
		l2,
		l3
	};
	//Zona zona1("Zona 1", nrLocuri, locuri);

	for (int i = 0; i < nrLocuri; i++)
		cout << locuri[i] << endl;
	cout << endl;

	//cout << zona1;

	//Zona zona2;

	//cout << zona2;

	return 0;
}