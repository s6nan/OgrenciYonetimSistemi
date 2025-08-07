# Öğrenci Bilgi Yönetim Sistemi

C++ kullanarak geliştirdiğim bu konsol tabanlı, kullanıcı dostu yönetim sistemi, öğrencilerin bilgilerini, derslerini ve notlarını etkili bir şekilde yönetmek amacıyla tasarlanmıştır. Projede nesne yönelimli programlama (OOP) prensipleri kullanılarak sağlam bir temel oluşturulmuştur.

**Tasarım Notu:** Öğrenci bilgilerini ve ders bilgilerini ayırmak amacıyla 'Ders' ve 'Dersler' gibi benzer işlevlere sahip sınıfları farklı başlık dosyalarında kullandım. Bu yaklaşım, daha modüler bir yapı oluşturma denemesiydi. Alternatif olarak, ilgili işlevler tek bir sınıf altında birleştirilerek proje daha basit bir hale getirilebilir.

**Geliştirici Notu:** Bu projeyi, hazır kütüphane fonksiyonlarından kaçınarak ve temel algoritmaları kendim yazarak geliştirdim. Amacım, C++ dilinde kendimi daha iyi ifade edebilmek ve problem çözme yeteneklerimi geliştirmekti. Proje sürecinde yapay zeka araçlarını yalnızca hata ayıklama ve fikir alma amaçlı kullandım. Projemin illaki eksikleri olacaktır; fikirlerinizi ve yapıcı eleştirilerinizi benimle paylaşırsanız sevinirim.

## Menüler

Proje, kullanıcı dostu bir menü sistemi aracılığıyla yönetilir.

### Öğrenci Menüsü

- **Öğrenci Ekle:** Ad, soyad ve numara gibi bilgileri kullanıcıdan alarak yeni bir öğrenci kaydı oluşturur.
- **Öğrenci Sil:** Girilen öğrenci numarasına sahip öğrenciyi arar ve sistemden siler.
- **Öğrenci Ara:** Girilen öğrenci numarasını öğrenciler içinde arar ve detaylı bilgilerini görüntüler.
- **Öğrencileri Listele:** Eklenen tüm öğrencileri düzenli bir tablo halinde listeler.

### Ders Menüsü

- **Ders Ekle:** Ders adı ve ders kodu gibi bilgileri kullanıcıdan alarak yeni bir ders ekler.
- **Ders Sil:** Girilen ders kodunu arar ve ilgili dersi sistemden siler.
- **Dersleri Listele:** Eklenmiş tüm dersleri düzenli bir şekilde listeler.

### Not Menüsü

- **Ders Notu Ekle:** Girilen ders kodu ve öğrenci numarasına göre öğrencinin notunu sisteme ekler. Hatalı girişler ve sistemde olmayan öğrenci/ders kodları için gerekli kontrolleri yapar.
- **Öğrenci Notlarını Listele:** Girilen öğrenci numarasına göre, öğrencinin almış olduğu tüm notları düzenli bir şekilde listeler.
- **Tüm Notları Listele:** Girilen ders koduna göre, o dersten notu olan tüm öğrencileri listeler.
- **Ders İstatistiği Hesapla:** Girilen ders kodu için medyan, ortalama gibi istatistikleri ve notu 60'ın üstünde olan öğrenci sayısını hesaplayıp gösterir. (Not: Bu fonksiyon, öğrenci silme işlemlerine karşı duyarlıdır.)

## Kullanılan Teknolojiler

- **C++:** Projenin temel programlama dilidir.
- **STL (Standard Template Library):** Veri yapıları için `std::list` kullanılmıştır. Özellikle dinamik eleman ekleme ve silme işlemlerinin hızlı olması için tercih edilmiştir.

### by s6nan or slexod
