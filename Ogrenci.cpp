#include "Ogrenci.h"
#include <cctype>


Ogrenci::Ogrenci(int _ogrNo=0, const string& _isim="isim", const string& _soyisim="soyisim") {
	ogrNo = _ogrNo;
	isim = _isim;
	soyisim = _soyisim;

}

Ogrenci::~Ogrenci() {}

void cinHataTemizlemeo() {
	cin.clear();
	cin.ignore(1000, '\n');
}

int Ogrenci::GetOgrenciNo() {
	return ogrNo;
}

string Ogrenci::GetOgrenciIsim() {
	return isim;
}

string Ogrenci::GetOgrenciSoyisim() {
	return soyisim;
}



void OgrenciMain::HarfDuzenleme(string& kelime) {
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




void OgrenciMain::OgrenciEkle() {
	int no;
	string isim, soyisim;
	cout << "Öðrencinin Numarasýný giriniz -> ";
	while (!(cin >> no) || no < 0) {	
		cinHataTemizlemeo();
		cout << "Hatalý giriþ yaptýnýz. Tekrar giriniz ->";
	}

	//AYNI NUMARA OLMAMASI ÝÇÝN SORGU / ATAMA ÝÞLEMLERÝ
	for (list<Ogrenci>::iterator it = ogrenciler.begin(); it != ogrenciler.end(); it++) { 
		if (it->GetOgrenciNo() == no)
		{
			cout << "Bu numaraya sahip öðrenci bulunmaktadýr. Yeni bir numara giriniz -> ";
			while (!(cin >> no) || no < 0 || (it->GetOgrenciNo() == no)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Hatalý giriþ yaptýnýz. Tekrar giriniz ->";
			}
		}
	}
	cinHataTemizlemeo();

	cout << "Öðrencinin ismini giriniz -> ";
	getline(cin, isim);


	cout << "Öðrencinin soyadýný giriniz -> ";
	getline(cin, soyisim);
	
	HarfDuzenleme(isim);
	HarfDuzenleme(soyisim);

	ogrenciler.push_back(Ogrenci(no, isim, soyisim));
}

void OgrenciMain::KayitMesaji() {
	cout << ogrenciler.back().GetOgrenciIsim() + " " + ogrenciler.back().GetOgrenciSoyisim() << " için baþarýyla kayýt oluþturulmuþtur.\n";
}

//ÖÐRENCÝLERÝ DÜZENLÝ BÝR ÞEKÝLDE LÝSTELER 
void OgrenciMain::OgrenciListele() {
	cout << "\n";
	cout << left << setw(12) << "Numara" << "| " << setw(15) << "Ýsim" << "| " << setw(15) << "Soyisim" << endl;

	cout << string(50, '*') << endl;

	for (list<Ogrenci>::iterator it = ogrenciler.begin(); it != ogrenciler.end(); it++) {
		
		cout << left << setw(12) << it->GetOgrenciNo() << "| " << setw(15) << it->GetOgrenciIsim() << "| " << setw(15) << it->GetOgrenciSoyisim() << endl;
	
	}
}

void OgrenciMain::OgrenciSil(int _ogrNo) {
	bool bulunduMu = false;

	for (list<Ogrenci>::iterator it = ogrenciler.begin(); it != ogrenciler.end(); it++) {
		if (it->GetOgrenciNo() == _ogrNo) {
			cout << _ogrNo << " numaralý öðrenci bulundu. Adý: " << it->GetOgrenciIsim() << " Soyadý: " << it->GetOgrenciSoyisim() << ". Öðrenci silindi.." << endl;
			ogrenciler.erase(it);
			bulunduMu = true;
			break;
		}
	}
	if(!(bulunduMu))
	cout << "Öðrenci bulunamadý\n";
}


void OgrenciMain::OgrenciAra(int _ogrNo) {
	for (list<Ogrenci>::iterator it = ogrenciler.begin(); it != ogrenciler.end(); it++) {
		if (it->GetOgrenciNo() == _ogrNo)
		{
			cout << _ogrNo << " numaralý öðrenci bulundu. Adý: " << it->GetOgrenciIsim() << " Soyadý: " << it->GetOgrenciSoyisim() << endl;
			return;
		}
	}
	cout << "Bulunamadý.." << endl;
}

list <Ogrenci>& OgrenciMain::GetOgrListe() {
	return ogrenciler;
}

