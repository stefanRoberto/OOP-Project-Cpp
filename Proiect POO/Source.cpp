#include <iostream>
#include <string>
#include "Client.h"
//#include "Aplicatie.h"

using namespace std;

int main() {
	cout << "Hello World! --> Proiect POO" << endl;
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

	cout << b1.getCategorie() << endl;
	b1.setCategorie("VIP++Extra");
	cout << b1.getCategorie() << endl;

	return 0;
}