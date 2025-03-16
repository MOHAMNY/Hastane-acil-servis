# 🛑 Acil Servis Hasta Yönetim Sistemi

## 📌 Proje Açıklaması

Bu proje, bir hastanenin acil servisinde hasta yönetimini sağlayan C diliyle geliştirilmiş bir sistemdir. Sistem, hastaları öncelik sırasına göre yönetir, reçete numarası oluşturur ve hastaların sırasını dinamik olarak düzenler.

## 🚀 Özellikler

✅ Bağlı liste (Linked List) kullanımı ile hastaların sıralı saklanması  
✅ Öncelik sırasına göre hasta kabulü (1: Kritik, 2: Orta, 3: Hafif)  
✅ Reçete numarası üretme ve her hasta için benzersiz ID oluşturma  
✅ Hasta listesi görüntüleme ve anlık güncelleme  
✅ Hastayı işleme alma ve listeden çıkarma  
✅ Kullanıcı dostu menü ile hasta yönetimi  

## 🔧 Kullanılan Teknolojiler

C Programlama Dili  
Bağlı Liste (Linked List) Veri Yapısı  
Dinamik Bellek Yönetimi (malloc, free)  

## 📥 Kurulum & Çalıştırma
### 1️⃣ Projeyi Klonlayın:
```
https://github.com/MOHAMNY/Hastane-acil-servis/blob/main/odev.c
```
### 2️⃣ C kodunu derleyin ve çalıştırın:
```
gcc odev.c -o app1 ./app1
```
## 📌 Kullanım
### 📌 Hasta Ekleme:
Kullanıcıdan ad, yaş, tanı ve öncelik bilgisi alınır.  
Hasta, öncelik sırasına göre listeye eklenir.  
Reçete numarası otomatik oluşturulur.  
### 📌 Hasta Listesini Görüntüleme:
Bekleyen tüm hastalar öncelik sırasına göre listelenir.  
### 📌 Hastayı İşleme Alma:
En öncelikli hasta işleme alınır ve sistemden silinir.  
## 📸 Örnek Kullanım
```
--- Acil Servis Sistemi ---
1. Yeni Hasta Ekle
2. Hasta Listesini Görüntüle
3. Hastayı İşleme Al
4. Çıkış
Seçiminizi yapın: 1

Hasta adı: Mehmet Yılmaz
Yaş: 60
Tanı: Kalp krizi
Öncelik (1: Kritik, 2: Orta, 3: Hafif): 1
Hasta eklendi: Mehmet Yılmaz (ID: 1, Öncelik: 1, Reçete No: 1000)

Seçiminizi yapın: 2
--- Acil Servis Bekleyen Hastalar ---
ID: 1, Ad: Mehmet Yılmaz, Yaş: 60, Tanı: Kalp krizi, Öncelik: 1, Reçete No: 1000

Seçiminizi yapın: 3
Hasta işleme alındı: Mehmet Yılmaz (ID: 1, Reçete No: 1000)
