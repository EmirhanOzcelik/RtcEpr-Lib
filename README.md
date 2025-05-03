
# Zaman ve EEPROM Yönetimi Kütüphanesi

Bu kütüphane, zaman yönetimi ve EEPROM üzerinde veri saklamak için işlevsellik sunar. `__zaman` sınıfı, zaman bilgisini saklar ve EEPROM'dan zaman bilgilerini okur ve yazar. `__epr` sınıfı ise EEPROM'a veri yazma ve okuma işlemlerini içerir. Ayrıca, bazı makrolar ile zaman bilgisini formatlı şekilde döndürme işlemleri yapılabilir.

## Kütüphane Özellikleri

- Zaman yönetimi ve EEPROM tabanlı takvim ayarları.
- 8 bit ve 16 bit EEPROM veri işlemleri.
- Zaman bilgilerini formatlı şekilde döndürme.
- EEPROM üzerinde kalıcı veri saklama.

---

## `__zaman` Sınıfı

Bu sınıf, zaman yönetimi ve EEPROM tabanlı takvim ayarlarını içerir.

### `setup(uint16_t bellek_baslangic = WTQ)`

Bu fonksiyon, EEPROM ayarlarını yapar ve varsa kayıtlı verileri yükler. Varsayılan EEPROM başlangıç adresi `WTQ`'dir.

#### Parametreler:
- `bellek_baslangic`: EEPROM başlangıç adresi. (Varsayılan: `WTQ`)

#### Örnek Kullanım:
```cpp
zaman.setup();  // EEPROM ayarlarını yapar ve verileri yükler.
```

---

### `millis_saat(uint16_t c = g_ms)`

Zamanı `millis()` tabanlı olarak ilerletir. `c` parametresi ile güncelleme aralığı belirlenebilir (ms cinsinden). Varsayılan değer `g_ms`'dir (50ms).

#### Parametreler:
- `c`: Güncelleme aralığı (ms cinsinden). (Varsayılan: `g_ms`)

#### Örnek Kullanım:
```cpp
zaman.millis_saat();  // Varsayılan güncelleme aralığı ile zamanı günceller.
```

---

### `eprden_oku(uint16_t basla = WTQ)`

Bu fonksiyon, EEPROM'dan zaman bilgilerini okur. Varsayılan olarak `WTQ` adresinden başlar.

#### Parametreler:
- `basla`: EEPROM adresi. (Varsayılan: `WTQ`)

#### Örnek Kullanım:
```cpp
zaman.eprden_oku();  // EEPROM'dan zaman bilgisini okur.
```

---

### `eprye_kaydet(uint16_t basla = WTQ)`

Zaman bilgilerini EEPROM'a yazar. Varsayılan olarak `WTQ` adresine kaydeder.

#### Parametreler:
- `basla`: EEPROM adresi. (Varsayılan: `WTQ`)

#### Örnek Kullanım:
```cpp
zaman.eprye_kaydet();  // Zaman bilgisini EEPROM'a kaydeder.
```

---

### Değişkenler

- **sn**: Saniye değeri (0–59)
- **dk**: Dakika değeri (0–59)
- **saat**: Saat değeri (0–23)
- **ay**: Ay değeri (1–12)
- **gun**: Gün değeri (1–31)
- **hafta_gun**: Haftanın günü (0: Pazar, 1: Pazartesi, ... 6: Cumartesi)
- **yil**: Yıl bilgisi (örnek: 2025)

---

## `__epr` Sınıfı

Bu sınıf, EEPROM'a 8 bit ve 16 bit veri yazma ve okuma işlemleri için fonksiyonlar içerir.

### `yaz8(int adres, uint8_t veri)`

Verilen adresi ve veriyi 8 bit olarak EEPROM'a yazar.

#### Parametreler:
- `adres`: Verinin yazılacağı EEPROM adresi.
- `veri`: Yazılacak 8 bitlik veri.

#### Örnek Kullanım:
```cpp
epr.yaz8(0, 123);  // Adres 0'a 123 değerini yazar.
```

---

### `oku8(int adres)`

Verilen adresteki 8 bitlik veriyi okur ve geri döndürür.

#### Parametreler:
- `adres`: Okunacak EEPROM adresi.

#### Örnek Kullanım:
```cpp
uint8_t veri = epr.oku8(0);  // Adres 0'daki veriyi okur.
```

---

### `yaz16(int adres, uint16_t veri)`

Verilen adresi ve veriyi 16 bit olarak EEPROM'a yazar. 16 bitlik veri, iki 8 bitlik byte olarak EEPROM'a kaydedilir.

#### Parametreler:
- `adres`: Verinin yazılacağı EEPROM adresi.
- `veri`: Yazılacak 16 bitlik veri.

#### Örnek Kullanım:
```cpp
epr.yaz16(0, 12345);  // Adres 0'a 12345 değerini yazar.
```

---

### `oku16(int adres)`

Verilen adresteki 16 bitlik veriyi okur ve geri döndürür. Verinin iki byte'ı (düşük ve yüksek byte) okunarak birleştirilir.

#### Parametreler:
- `adres`: Okunacak EEPROM adresi.

#### Örnek Kullanım:
```cpp
uint16_t veri = epr.oku16(0);  // Adres 0'daki 16 bitlik veriyi okur.
```

---

## Makrolar

### `format2hane(deger)`

Bu makro, 0–9 arasındaki değerleri iki haneli `String` formatına çevirir. Tek haneli sayılar için başına "0" ekler. 

#### Örnek:
```cpp
String zaman_format = format2hane(5);  // "05"
```

---

### `saniye_`

Saniye bilgisini 2 haneli `String` formatında döndürür.

#### Örnek:
```cpp
String saniye = saniye_;  // "05"
```

---

### `dakika_`

Dakika bilgisini 2 haneli `String` formatında döndürür.

#### Örnek:
```cpp
String dakika = dakika_;  // "09"
```

---

### `saat_`

Saat bilgisini 2 haneli `String` formatında döndürür.

#### Örnek:
```cpp
String saat = saat_;  // "07"
```

---

### `ay_`

Ay bilgisini 2 haneli `String` formatında döndürür.

#### Örnek:
```cpp
String ay = ay_;  // "04"
```

---

### `gun_`

Gün bilgisini 2 haneli `String` formatında döndürür.

#### Örnek:
```cpp
String gun = gun_;  // "02"
```

---

### `haftaGun_`

Hafta günü bilgisini `String` formatında döndürür.

#### Örnek:
```cpp
String haftaGun = haftaGun_;  // "Pazartesi"
```

---

### `yil_`

Yıl bilgisini `String` formatında döndürür.

#### Örnek:
```cpp
String yil = yil_;  // "2025"
```
