#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Ogrenci.h"
using namespace std;


class Ders:public OgrenciMain
{
public:
	Ders(int _dersKodu, const string& _dersAdi) : dersKodu(_dersKodu), dersAdi(_dersAdi) {}
	Ders() : dersKodu(0), dersAdi("") {};
	~Ders();
	void SetDersKodu(int dersKodu);
	void DersAdiYazdir(); //DERSNOTLARÝ ÝÇÝN

	int GetDersKodu();
	string GetDersAdi();
	void HarfDuzenleme(string &kelime);

private:
	int dersKodu;
	string dersAdi;
};



class DersYonetim
{
public:
	void DersEkleme();
	void DersSil(int _derskodu);
	void DersleriListele();

	list<Ders>& GetDersListe();
private:
	list <Ders> dersler;
};
