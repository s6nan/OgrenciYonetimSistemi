#include "DersNotu.h"

DersNotu::DersNotu(int _dersKodu, int _ogrNo, int _dersNotu) : Ders(_dersKodu, "99"), Ogrenci(_ogrNo, "99", "99"), sinavNotu(_dersNotu){

}

void cinHataTemizleme() {	
		cin.clear();
		cin.ignore(1000, '\n');
}

DersNotu::~DersNotu(){}



bool DersNotlari::DersBulunduMu(int _dersKodu, DersYonetim& dersSistem) {
	list<Ders>& dersListesi = dersSistem.GetDersListe();

	for (list <Ders>::iterator it = dersListesi.begin(); it != dersListesi.end(); it++)
	{
		if (_dersKodu == it->GetDersKodu()) {
			return true;
		}
	}
	return false;
}

int DersNotu::GetSinavNotu() {
	return sinavNotu;
}

void DersNotlari::OgrenciNotlariSil(int ogrNo) {
	for (list<DersNotu>::iterator it = dersNotlari.begin(); it != dersNotlari.end(); ) {
		if (it->GetOgrenciNo() == ogrNo) {  
			it = dersNotlari.erase(it);     
		}
		else {
			++it;                           
		}
	}
}

void DersNotlari::DersNotuEkle(DersYonetim& dersSistem, OgrenciMain& ogrSistem) {
	int dersKodu, ogrNo, sinavNotu;
	list<Ders>& dersListesi = dersSistem.GetDersListe();
	list<Ogrenci>& ogrListesi = ogrSistem.GetOgrListe();

	while(true){
		cout << "Ýþlem Yapýlacak Dersin Kodunu Giriniz (-1 : Çýkýþ): ";
		while (!(cin >> dersKodu)) {
			cinHataTemizleme();
			cout << "Hatalý giriþ yaptýnýz. Tekrar giriniz ->";
		}


		if (dersKodu == -1) {
			cout << "Not ekleme iþlemi sonlandýrýlýyor..\n";
			break;
		}

		bool dersVarMi = false;
		for (list<Ders>::iterator it = dersListesi.begin(); it != dersListesi.end(); ++it) {
			if (it->GetDersKodu() == dersKodu) {
				dersVarMi = true;
				break;
			}

		}

		if (!dersVarMi) {
			cout << "Girilen kodda bir ders bulunamadý. Tekrar deneyiniz.\n";
			continue;
		}
		
		while (true)
		{
			
			cout << dersKodu << " kodlu ders için öðrenci numarasýný giriniz (-1:Çýkýþ ) :";
			while (!(cin >> ogrNo)) {
				cinHataTemizleme();
				cout << "Hatalý giriþ yaptýnýz. Tekrar giriniz ->";
			}

			if (ogrNo == -1)
			{
				break;
			}

			bool ogrVarMi = false;
			for (list<Ogrenci>::iterator it = ogrListesi.begin(); it != ogrListesi.end(); it++)
			{
				if (it->GetOgrenciNo() == ogrNo)
				{
					ogrVarMi = true;
					break;
				}
			}

			if (!ogrVarMi) {
				cout << "Bu numaraya ait bir öðrenci bulunmamaktadýr. Tekrar giriniz.\n";
				continue;
			}



			bool ogrNotuVarMi = false;

			for (list<DersNotu>::iterator it = dersNotlari.begin(); it != dersNotlari.end(); ++it)
			{
				if (it->GetDersKodu() == dersKodu && it->GetOgrenciNo() == ogrNo)
				{
					ogrNotuVarMi = true;break;
				}
			}

			if (ogrNotuVarMi) {
				cout << dersKodu << " kodlu ders için " << ogrNo << " nolu öðrencinin ders notu zaten var.\n";
				continue;
			}

			
				cout << ogrNo << " nolu öðrenci için ders notunu giriniz (-1 : Çýkýþ) : ";
				while (!(cin >> sinavNotu) || sinavNotu < 0 || sinavNotu > 100 || sinavNotu == -1) {
					cinHataTemizleme();

					if (sinavNotu == -1)
					{
						break;
					}

					if (sinavNotu < 0 || sinavNotu > 100)
					{
						cout << "Sýnav notu 0-100 arasýnda olmalýdýr. Tekrar giriniz ->";
						continue;
					}
					cout << "Hatalý giriþ yaptýnýz. Tekrar giriniz ->";


				}
				if (sinavNotu == -1) { break; }

				dersNotlari.push_back(DersNotu(dersKodu, ogrNo, sinavNotu));

				cout << "Not baþarýyla eklendi.\n";
		}

	}
}




void DersNotlari::TumNotlariniListele(DersYonetim& dersSistem, OgrenciMain& ogrSistem) {
	int arananDersKodu;
	cout << "Listelenecek Dersin Kodunu Giriniz: ";
	while (!(cin >> arananDersKodu)) {

	}

	list<Ders>& dersListesi = dersSistem.GetDersListe();
	list<Ogrenci>& ogrListesi = ogrSistem.GetOgrListe();
	bool dersvarmi = false;
	for (list<Ders>::iterator dersIt = dersListesi.begin(); dersIt != dersListesi.end(); ++dersIt)
	{
		

		if(dersIt->GetDersKodu() == arananDersKodu ) {
			dersvarmi = true;
		cout << "\n" << left << setw(12) << "Numara" << "| " << setw(15) << "Ýsim" << "| " << setw(15) << "Soyisim" << "| " << setw(15) << "Ders Adý" << "| " << setw(10) << "Not" << "\n";
		cout << string(70, '*') << endl;

		string dersAdi = dersIt->GetDersAdi(); 

		for (list<DersNotu>::iterator it = dersNotlari.begin(); it != dersNotlari.end(); ++it) {
			if (it->GetDersKodu() != arananDersKodu)
				continue;
			string isim = "NULL",soyisim = "NULL"; //EÐER BOÞSA NULL OLARAK KALSIN 

			for (list<Ogrenci>::iterator ogrIt = ogrListesi.begin(); ogrIt != ogrListesi.end(); ++ogrIt) {

				if (ogrIt->GetOgrenciNo() == it->GetOgrenciNo()) {
					isim = ogrIt->GetOgrenciIsim();
					soyisim = ogrIt->GetOgrenciSoyisim();
					break;
				}
			}

			for (list<Ders>::iterator dersIt2 = dersListesi.begin(); dersIt2 != dersListesi.end(); ++dersIt2) {
			
				if (dersIt2->GetDersKodu() == it->GetDersKodu()) {
					dersAdi = dersIt2->GetDersAdi();
					break;
				}
			}

			if (dersAdi == "NULL" ||  isim == "NULL") {
				continue;
			}

			cout << left << setw(12) << it->GetOgrenciNo() << "| "<< setw(15) << isim << "| " << setw(15) << soyisim << "| " << setw(15) << dersAdi << "| " << setw(10) << it->GetSinavNotu() << "\n";
			}
		}
		
	}
	if (!dersvarmi)
	{
		cout << "Bu koda ait bir ders bulunamadý.";
	}


	
}


void DersNotlari::OgrenciNotlariniListele(DersYonetim& dersSistem, OgrenciMain& ogrSistem) {
	int ogrNo;
	string isim, soyisim;
	bool ogrVarMi = false;
	
	cout << "\nNotlarý Listelenecek Öðrencinin Numarasýný Giriniz :";
	while (!(cin >> ogrNo) || ogrNo < 0) {
		cinHataTemizleme();
		cout << "Hatalý giriþ yaptýnýz. Tekrar giriniz ->";
	}

	
	list<Ders>& dersListesi = dersSistem.GetDersListe();
	list<Ogrenci>& ogrListesi = ogrSistem.GetOgrListe();

	for (list <Ogrenci>::iterator it = ogrListesi.begin(); it != ogrListesi.end(); it++)
	{
		if (ogrNo == it->GetOgrenciNo())
		{
			ogrVarMi = true;
			isim = it->GetOgrenciIsim();
			soyisim = it->GetOgrenciSoyisim();

			cout << "\n" << isim << " " << soyisim << " için ders notlari :\n";

			string dersadi = "x";
			for (list <DersNotu>::iterator notlarIT= dersNotlari.begin(); notlarIT != dersNotlari.end(); notlarIT++)
			{
				
				for (list<Ders>::iterator dersIt = dersListesi.begin(); dersIt != dersListesi.end(); ++dersIt) {

					if (dersIt->GetDersKodu() == notlarIT->GetDersKodu()) {
						dersadi = dersIt->GetDersAdi();
						break;
					}
				}

				if (dersadi == "x")
				{
					continue;
				}

				if (notlarIT->GetOgrenciNo() == ogrNo) {
					cout <<"Dersin adý : " << dersadi << " | Ders Kodu : " << notlarIT->GetDersKodu() << " | Notu : " << notlarIT->GetSinavNotu() << endl;
				}
			}
			break;
		}
		
		
	}
	if (!ogrVarMi) {
		cout << "Öðrenci bulunamadý..\n";
	}
}

 list <DersNotu> ListSiralama(list <DersNotu> &x, int dersKodu) {


	list <DersNotu> dersKodluListe;
	
	for (list <DersNotu>::iterator it = x.begin();it!=x.end();it++ )
	{
		if (it->GetDersKodu() ==  dersKodu)
		{
			dersKodluListe.push_back(*it);
		}
	}


	for (list<DersNotu>::iterator it1= dersKodluListe.begin() ; it1 != dersKodluListe.end();it1++)
	{
		for (list<DersNotu>::iterator it2= next(it1); it2 != dersKodluListe.end();it2++)
		{
			if (it2->GetSinavNotu() < it1->GetSinavNotu())
			{
				DersNotu temp = *it1;
				*it1 = *it2;
				*it2 = temp;
			}
			
		}

	}
	return dersKodluListe;
}

void DersNotlari::DersIstatistigiHesapla(DersYonetim& dersSistem, OgrenciMain& ogrSistem) {
	int dersKodu;
	double ortalama;
	//Medyan için yeni list

	list <DersNotu> medyanlist;

	list<Ders>& dersListesi = dersSistem.GetDersListe();
	do
	{
		cout << "Ýstatistiði Hesaplanacak Dersin Kodunu Giriniz (-1: Çýkýþ) -> ";
		while (!(cin >> dersKodu)) {
			cinHataTemizleme();
			cout << "Hatalý giriþ yaptýnýz. Tekrar giriniz -> ";
		}

		if (dersKodu == -1) {
			cout << "Ýstatistik Hesaplama iþlemi sonlandýrýlýyor..\n";
			break;
		}

		bool dersVarMi = false;
		for (list<Ders>::iterator it = dersListesi.begin(); it != dersListesi.end(); ++it) {
			if (it->GetDersKodu() == dersKodu) {
				dersVarMi = true;
				break;
			}

		}

		if (!dersVarMi) {
			cout << "Girilen kodda bir ders bulunamadý. Tekrar deneyiniz.\n";
			continue;
		}

		int sayac60 = 0, toplam = 0, dersKoduSayac = 0;


		for (list <DersNotu>::iterator it = dersNotlari.begin(); it != dersNotlari.end(); it++)
		{
			if (it->GetDersKodu() == dersKodu)
			{
				medyanlist.push_back(DersNotu(it->GetDersKodu(), it->GetOgrenciNo(),it->GetSinavNotu()));
				toplam += it->GetSinavNotu();
				dersKoduSayac += 1;
				if (it->GetSinavNotu() > 60)
				{
					sayac60 += 1;
				}
			}
		}


		list <DersNotu> yeniList = ListSiralama(medyanlist, dersKodu);

		
		double medyan = 0; 
		bool tekMi = (yeniList.size() % 2 != 0);

		int orta = yeniList.size() / 2;
		int sayac = 0;

		for (list<DersNotu>::iterator it = yeniList.begin(); it != yeniList.end(); ++it) {
			if (tekMi) {
				if (sayac == orta) {
					medyan = it->GetSinavNotu(); 
					break;
				}
			}
			else {
				if (sayac == orta - 1) {
					medyan = it->GetSinavNotu(); 
				}
				if (sayac == orta) {
					medyan = (medyan + it->GetSinavNotu()) / 2.0; //BURDA KISACA 2SÝNÝN ORTALAMSINI ALIYORUM
					break;
				}
			}
			sayac++;
		}





		if (dersKoduSayac == 0) {
			cout << "Bu derse ait hiçbir not bulunmamaktadýr..\n";
		}
		
		else{
		ortalama = toplam / (double)dersKoduSayac;
		cout << "Medyan :" << medyan << endl;
		cout << "60 üstü alanlarýn sayisi :" << sayac60 << endl;
		cout << dersKodu << " kodlu dersin sýnýf ortalamasý :" << ortalama << endl;
	}

	} while (dersKodu != -1);
	
}



