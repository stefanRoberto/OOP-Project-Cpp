#include "BiletSpecial.h"
#include <iomanip>

BiletSpecial::BiletSpecial()
{
	cateringInclus = false;
	parcareVIP = false;
}

BiletSpecial::BiletSpecial(double pret, string categorie, bool cateringInclus, bool parcareVIP)
{
	if (pret > 0)
		this->pret = pret;
	else
		this->pret = 0.0;

	this->categorie = categorie;
	this->cateringInclus = cateringInclus;
	this->parcareVIP = parcareVIP;
}

BiletSpecial::BiletSpecial(const BiletSpecial& b)
{
	if (b.pret > 0.0)
		this->pret = b.pret;
	else
		this->pret = 0.0;

	this->categorie = b.categorie;
	this->cateringInclus = b.cateringInclus;
	this->parcareVIP = b.parcareVIP;
}

BiletSpecial::~BiletSpecial() {}

void BiletSpecial::setPret(double pret)
{
	double pretSpecial = 0.0;
	
	if (pret >= 0.0)
		pretSpecial = pret - (5.0 / 100.0) * pret;
	
	this->setPret(pretSpecial);
}

bool BiletSpecial::getCateringInclus()
const{
	return cateringInclus;
}

void BiletSpecial::setCateringInclus(bool cateringInclus)
{
	this->cateringInclus = cateringInclus;
}

bool BiletSpecial::getParcareVIP()
const{
	return parcareVIP;
}

void BiletSpecial::setParcareVIP(bool parcareVIP)
{
	this->parcareVIP = parcareVIP;
}

ostream& operator<<(ostream& out, const BiletSpecial& b)
{
	out << "ID-ul biletului este: " << b.getId() << endl;
	out << "Pretul biletului este: " << fixed << setprecision(2) << b.getPret();
	if(b.getPret() == 1)
		out << " Leu" << endl;
	else
		out << " Lei" << endl;
	
	out << "Numarul total de bilete este: " << b.getNrBilete() << endl;
	out << "Categoria biletului este: " << b.getCategorie() << endl;
	
	out << "Catering inclus: " << (b.getCateringInclus() ? "Da" : "Nu") << endl;
	out << "Parcare VIP: " << (b.getParcareVIP() ? "Da" : "Nu") << endl;
	
	return out;
}

istream& operator>>(istream& in, BiletSpecial& b)
{
	double pret;
	string categorie;
	
	cout << "Introduceti pretul biletului: ";
	in >> pret;
	b.setPret(pret);
	
	cout << "Introduceti categoria biletului: ";
	in.ignore();
	getline(in, categorie);
	b.setCategorie(categorie);
	
	cout << "Este catering inclus? (0 - Nu, 1 - Da)" << "\n\t> ";
	in >> b.cateringInclus;
	cout << "Este parcare VIP inclusa? (0 - Nu, 1 - Da)" << "\n\t> ";
	in >> b.parcareVIP;
	
	return in;
}