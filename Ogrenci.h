#pragma once
#include <iostream>
#include <list>
#include <string>
#include <iomanip>


using namespace std;

class Ogrenci
{
public:
	Ogrenci(int _ogrNo,const string &isim, const string& soyisim);
	Ogrenci() : ogrNo(0), isim(""), soyisim("") {};
	~Ogrenci();

	
	int OgrenciSil(int _ogrNo);

	int GetOgrenciNo();
	string GetOgrenciIsim();
	string GetOgrenciSoyisim();

	
	
private:
	int ogrNo;
	string isim, soyisim;
};


class OgrenciMain
{
public:

	list<Ogrenci>& GetOgrListe();

	void HarfDuzenleme(string &kelime);

	void OgrenciEkle();
	void KayitMesaji();

	void OgrenciListele();

	void OgrenciAra(int _ogrNo);

	void OgrenciSil(int _ogrNo);

private:
	list <Ogrenci> ogrenciler;
};
