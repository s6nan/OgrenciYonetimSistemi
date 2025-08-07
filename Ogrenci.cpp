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
	cout << "��rencinin Numaras�n� giriniz -> ";
	while (!(cin >> no) || no < 0) {	
		cinHataTemizlemeo();
		cout << "Hatal� giri� yapt�n�z. Tekrar giriniz ->";
	}

	//AYNI NUMARA OLMAMASI ���N SORGU / ATAMA ��LEMLER�
	for (list<Ogrenci>::iterator it = ogrenciler.begin(); it != ogrenciler.end(); it++) { 
		if (it->GetOgrenciNo() == no)
		{
			cout << "Bu numaraya sahip ��renci bulunmaktad�r. Yeni bir numara giriniz -> ";
			while (!(cin >> no) || no < 0 || (it->GetOgrenciNo() == no)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Hatal� giri� yapt�n�z. Tekrar giriniz ->";
			}
		}
	}
	cinHataTemizlemeo();

	cout << "��rencinin ismini giriniz -> ";
	getline(cin, isim);


	cout << "��rencinin soyad�n� giriniz -> ";
	getline(cin, soyisim);
	
	HarfDuzenleme(isim);
	HarfDuzenleme(soyisim);

	ogrenciler.push_back(Ogrenci(no, isim, soyisim));
}

void OgrenciMain::KayitMesaji() {
	cout << ogrenciler.back().GetOgrenciIsim() + " " + ogrenciler.back().GetOgrenciSoyisim() << " i�in ba�ar�yla kay�t olu�turulmu�tur.\n";
}

//��RENC�LER� D�ZENL� B�R �EK�LDE L�STELER 
void OgrenciMain::OgrenciListele() {
	cout << "\n";
	cout << left << setw(12) << "Numara" << "| " << setw(15) << "�sim" << "| " << setw(15) << "Soyisim" << endl;

	cout << string(50, '*') << endl;

	for (list<Ogrenci>::iterator it = ogrenciler.begin(); it != ogrenciler.end(); it++) {
		
		cout << left << setw(12) << it->GetOgrenciNo() << "| " << setw(15) << it->GetOgrenciIsim() << "| " << setw(15) << it->GetOgrenciSoyisim() << endl;
	
	}
}

void OgrenciMain::OgrenciSil(int _ogrNo) {
	bool bulunduMu = false;

	for (list<Ogrenci>::iterator it = ogrenciler.begin(); it != ogrenciler.end(); it++) {
		if (it->GetOgrenciNo() == _ogrNo) {
			cout << _ogrNo << " numaral� ��renci bulundu. Ad�: " << it->GetOgrenciIsim() << " Soyad�: " << it->GetOgrenciSoyisim() << ". ��renci silindi.." << endl;
			ogrenciler.erase(it);
			bulunduMu = true;
			break;
		}
	}
	if(!(bulunduMu))
	cout << "��renci bulunamad�\n";
}


void OgrenciMain::OgrenciAra(int _ogrNo) {
	for (list<Ogrenci>::iterator it = ogrenciler.begin(); it != ogrenciler.end(); it++) {
		if (it->GetOgrenciNo() == _ogrNo)
		{
			cout << _ogrNo << " numaral� ��renci bulundu. Ad�: " << it->GetOgrenciIsim() << " Soyad�: " << it->GetOgrenciSoyisim() << endl;
			return;
		}
	}
	cout << "Bulunamad�.." << endl;
}

list <Ogrenci>& OgrenciMain::GetOgrListe() {
	return ogrenciler;
}

