#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include "Ogrenci.h"
#include "Ders.h"
#include "DersNotu.h"

//Kendi oluşturduğum sınıfları iki parçaya bölmüştüm buna gerek yok aslında ama denemek için gerçekleştirdim. siz isterseniz tek nesneye çevirip daha basit ve anlaşılabilir bir proje yapabilirsiniz.

using namespace std;

void cinTemizleme() {
	cin.clear();
	cin.ignore(1000, '\n');
}





int main() {
	setlocale(LC_ALL, "Turkish");

	OgrenciMain ogrSistem;
	
	DersYonetim dersSistem;

	DersNotlari dersNotuSistem;

	cout << "Öğrenci Bilgi Yönetim Sistemine Hoşgeldiniz.." << endl;
	int menuSecim, islemSecim, ogrNo,dersKodu;

	do
	{
		cout << "İşlem Seçiniz:\n1: Öğrenci İşlemleri\n2: Ders İşlemleri\n3: Not İşlemleri\n4: Çıkış -> ";
		while (!(cin >> menuSecim) || menuSecim < 1 || menuSecim>4) {
			cinTemizleme();
			cout << "Sadece 1, 2, 3 ve 4 girebilirsiniz -> ";

		}

		cout << endl; //Güzel Görünmesi İçin

		switch (menuSecim)
		{



		case 1: { //menu-1
			cout << "İşlemininiz seçin:\n11: Öğrenci Ekle\n12: Öğrenci Silme\n13: Öğrenci Arama\n14: Öğrencileri Listeleme (-1:Geri) -> ";
			//Hata Ayıklama
			while (!(cin >> islemSecim) || (islemSecim != -1 && (islemSecim < 11 || islemSecim > 14))) {
				cinTemizleme();
				cout << "Sadece 11, 12, 13, 14 ve -1 girebilirsiniz -> ";
			}

		
			switch (islemSecim)
			{

			case -1: {
				break;
			}

			case 11:{
				ogrSistem.OgrenciEkle();
				ogrSistem.KayitMesaji();
				break; }

			case 12: { 
				cout << "Silinecek öğrencinin numarasını giriniz :";
				while (!(cin >> ogrNo)) {
					cinTemizleme();
					cout << "Hatalı giriş yaptınız. Tekrar deneyiniz -> ";
				}
				ogrSistem.OgrenciSil(ogrNo);
				dersNotuSistem.OgrenciNotlariSil(ogrNo);
				break; }

			case 13: { 
				cout << "Aranacak öğrencinin numarasını giriniz :";
				while (!(cin >> ogrNo)) {
					cinTemizleme();
					cout << "Hatalı giriş yaptınız. Tekrar deneyiniz -> ";
				}
				ogrSistem.OgrenciAra(ogrNo);
				break; }

			case 14: {
				ogrSistem.OgrenciListele();
				break;}
			}
			cout << endl; //güzel gözükmesi
			break;
		}

		case 2: { //menu-2
			cout << "İşlemininiz seçin:\n21: Ders Ekleme\n22: Ders Silme\n23: Ders Listesi (-1:Geri) -> ";
			//Hata Ayıklama
			while (!(cin >> islemSecim) ||( islemSecim!=-1 && (islemSecim < 21) || (islemSecim > 23))) {
				cinTemizleme();
				cout << "Sadece 21, 22, 23 ve -1 girebilirsiniz -> ";

			}
			switch (islemSecim)
			{

			case -1: {
				break;
			}

			case 21: { 
				dersSistem.DersEkleme();
				break; }
			case 22: { 
				cout << "Silinecek dersin kodunu giriniz -> ";
				while (!(cin >> dersKodu)) {
					cinTemizleme();
					cout << "Hatalı giriş yaptınız. Tekrar deneyiniz -> ";
				}
				dersSistem.DersSil(dersKodu);
				break; }
			case 23: { 
				dersSistem.DersleriListele();
				break; }

			}
			cout << endl; //güzel gözükmesi
			break;
		}

		case 3: { //menu-3
			cout << "İşlemininiz seçin:\n31: Derse Öğrenci Notu Gir\n32: Öğrencinin Notlarını Görüntüle\n33: Tüm Notları Görüntüle\n34: Ders İstatistiklerini Hesapla (-1:Geri) -> ";
			//Hata Ayıklama
			while (!(cin >> islemSecim) || (islemSecim!=-1 &&(islemSecim < 31) || (islemSecim > 34))) {
				cinTemizleme();
				cout << "Sadece 31, 32, 33 ve -1 girebilirsiniz -> ";

			}
			switch (islemSecim)
			{

			case -1: {
				break;
			}

			case 31: { 
				dersNotuSistem.DersNotuEkle(dersSistem,ogrSistem);
				
				break; }

			case 32: {
				dersNotuSistem.OgrenciNotlariniListele(dersSistem, ogrSistem);
				break; }

			case 33: { 
				dersNotuSistem.TumNotlariniListele(dersSistem, ogrSistem);
				break; }
			case 34: {
				dersNotuSistem.DersIstatistigiHesapla(dersSistem, ogrSistem);
				break;
			}
			}
			cout << endl; //güzel gözükmesi
			break;
		}
		}//ana switch parantezi



	} while (menuSecim != 4);

	cout << "\nProgram sonlandırılıyor..." << endl;

	

	return 0;
}