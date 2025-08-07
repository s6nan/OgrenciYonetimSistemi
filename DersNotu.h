#pragma once
#include <iostream>
#include "Ders.h"
#include "Ogrenci.h"
#include <list>
using namespace std;

class DersNotu:public Ders,public Ogrenci
{
public:
	DersNotu(int _dersKodu,int _ogrNo,int _dersNotu);
	~DersNotu();

	int GetSinavNotu();

private:
	int sinavNotu;
};



class DersNotlari
{
public:
	
	void OgrenciNotlariSil(int ogrNo);

	void DersNotuEkle(DersYonetim& dersSistem, OgrenciMain& ogrSistem);

	bool DersBulunduMu(int _dersKodu, DersYonetim& dersSistem);

	void TumNotlariniListele(DersYonetim& dersSistem, OgrenciMain& ogrSistem);

	void OgrenciNotlariniListele(DersYonetim& dersSistem, OgrenciMain& ogrSistem);
	
	void DersIstatistigiHesapla(DersYonetim& dersSistem, OgrenciMain& ogrSistem);
private:
	list <DersNotu> dersNotlari;
};




