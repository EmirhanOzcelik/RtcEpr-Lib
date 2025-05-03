# Zaman Yönetimi Kütüphanesi (zaman)

Bu kütüphane, Arduino platformunda zaman yönetimini sağlamak ve EEPROM tabanlı takvim ayarlarını yapmak için kullanılır. Kullanıcılar, zaman bilgisini takip edebilir, EEPROM'a kaydedebilir ve düzenleyebilir. Kütüphane, kullanıcı dostu bir API ile zaman hesaplamalarını ve EEPROM işlemlerini basitleştirir.

## Özellikler

- Saat, dakika, saniye, ay, gün, hafta ve yıl bilgilerini tutma.
- EEPROM'a zaman verilerini kaydetme ve okuma.
- Zaman bilgisinin güncellenmesi ve yönetilmesi için `millis()` fonksiyonu kullanılır.
- Artık yıl ve hafta günü hesaplamaları.
- EEEPROM için uint8_t ve uint16_t veri saklama ve okuma fonksiyonları

## Kullanım

### Kütüphaneyi Projeye Dahil Etme

Kütüphaneyi projene dahil etmek için aşağıdaki gibi yazabilirsin:

```cpp
#include "RtcEpr.h"
