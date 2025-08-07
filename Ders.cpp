#include "Ders.h"

Ders::~Ders(){}

void cinHataTemizlemed() {
	cin.clear();
	cin.ignore(1000, '\n');
}

int Ders::GetDersKodu() {
	return dersKodu;
}

void Ders::SetDersKodu(int _dersKodu) {
	dersKodu = _dersKodu;
}

string Ders::GetDersAdi() {
	return dersAdi;
}


void Ders::DersAdiYazdir() {
	cout << dersAdi;
}

void Ders::HarfDuzenleme(string &kelime)
{
	bool kelimeYeniMi = true;

	for (int i = 0; i < (int)kelime.length(); i++)
	{
		if (kelime[i] == ' ') {
			kelimeYeniMi = true;
		}

		else {
			if (kelimeYeniMi) {
				kelime[i] = toupper(kelime[i]);
				kelimeYeniMi = false;
			}
			else {
				kelime[i] = tolower(kelime[i]);
			}
		}
	}

}


void DersYonetim::DersEkleme() {
	int derskodu;
	string dersadi;


	cin.ignore(1000, '\n');
	cout << "Eklenecek dersin adýný giriniz -> ";
	getline(cin, dersadi);

	
	

	cout << "Eklenecek dersin kodunu giriniz -> ";


	while (true) {
		if (!(cin>>derskodu))
		{
			cinHataTemizlemed();
			cout << "Hatalý giriþ yaptýnýz. Tekrar giriniz -> ";
			continue;
		}
		
		
		
		if (derskodu<0)
		{
			cout << "Ders Kodu 0'dan küçük olamaz tekrar giriniz -> ";
			continue;
		}

		bool kodVarMi = false;

		for (list<Ders>::iterator it = dersler.begin(); it != dersler.end(); it++) {
			if (it->GetDersKodu() == derskodu)
			{
				kodVarMi = true;
				break;
			}
		}
		if (kodVarMi)
		{
			cout << "Bu koda ait baþka bir ders var. Lütfen baþka bir kod giriniz -> ";
			continue;
		}

		//EÐER KÝ HÝÇBÝR ÞART SAÐLANMAZ VE KOD DÜZGÜNSE ÇIKAR
		break;
	}
	Ders d;
	d.HarfDuzenleme(dersadi);
	dersler.push_back(Ders(derskodu, dersadi));
	cout << "Ders baþarýyla eklendi -> " << dersadi << " : " << derskodu << endl;

}


void DersYonetim::DersSil(int _derskodu) {
	bool bulundu = false;
	
	for (list <Ders>::iterator it = dersler.begin(); it != dersler.end(); it++)
	{
		if (it->GetDersKodu() == _derskodu)
		{
			cout << "Bulunan dersin adi : " << it->GetDersAdi() << ", silindi.\n";
			dersler.erase(it);
			bulundu = true;
			break;
		}
	}

	if (!bulundu)
	{
		cout << "Ders bulunamadý..\n";
	}
}


void DersYonetim::DersleriListele() {
	cout << left << setw(15) << "Ders Kodu" << "| " << setw(15) << "Ders Adý" << endl;

	cout << string(40, '*') << endl;
	
	for (list <Ders>::iterator it = dersler.begin(); it != dersler.end() ; it++)
	{
		

		cout << left << setw(15) << it->GetDersKodu() << "| " << setw(15) << it->GetDersAdi() << endl;
		
	}
}


list <Ders>& DersYonetim::GetDersListe() {
	return dersler;
}