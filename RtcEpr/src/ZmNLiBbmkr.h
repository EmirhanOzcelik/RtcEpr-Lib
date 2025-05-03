#pragma once
#include "Arduino.h"

/**
 * @brief 0–9 arasındaki değerleri 2 haneli String'e çeviren yardımcı makro.
 * 
 * Bu makro, tek haneli sayılar için başına "0" ekler. Örn: 3 -> "03"
 */
#define format2hane(deger) (deger < 10 ? "0" + String(deger) : String(deger))

/**
 * @brief Saniye bilgisini 2 haneli String formatında döndüren makro.
 * 
 * Örn: zaman.sn = 5 ise, sonuç "05" olur.
 */
#define saniye_ format2hane(zaman.sn)

/**
 * @brief Dakika bilgisini 2 haneli String formatında döndüren makro.
 * 
 * Örn: zaman.dk = 9 ise, sonuç "09" olur.
 */
#define dakika_ format2hane(zaman.dk)

/**
 * @brief Saat bilgisini 2 haneli String formatında döndüren makro.
 * 
 * Örn: zaman.saat = 7 ise, sonuç "07" olur.
 */
#define saat_ format2hane(zaman.saat)

/**
 * @brief Ay bilgisini 2 haneli String formatında döndüren makro.
 * 
 * Örn: zaman.ay = 4 ise, sonuç "04" olur.
 */
#define ay_ format2hane(zaman.ay)

/**
 * @brief Gün bilgisini 2 haneli String formatında döndüren makro.
 * 
 * Örn: zaman.gun = 2 ise, sonuç "02" olur.
 */
#define gun_ format2hane(zaman.gun)

/**
 * @brief Hafta günü bilgisini String formatında döndüren makro.
 * 
 * Bu makro, `zaman.hafta_gun` (örneğin "Pazartesi") değerini String formatında döndürür.
 */
#define haftaGun_ String(zaman.hafta_gun)

/**
 * @brief Yıl bilgisini String formatında döndüren makro.
 * 
 * Örn: zaman.yil = 2025 ise, sonuç "2025" olur.
 */
#define yil_ String(zaman.yil)

/**
 * @brief Saat formatında (hh:mm:ss) çıktı döndüren makro.
 * 
 * Bu makro, `zaman.saat`, `zaman.dk` ve `zaman.sn` değerlerini 
 * 2 haneli formatta birleştirerek "hh:mm:ss" formatında döndürür.
 */
#define saatFormat_ (format2hane(zaman.saat) + ":" + format2hane(zaman.dk) + ":" + format2hane(zaman.sn))

/**
 * @brief Tarih formatında (dd.mm.yyyy) çıktı döndüren makro.
 * 
 * Bu makro, `zaman.gun`, `zaman.ay` ve `zaman.yil` değerlerini 
 * 2 haneli gün ve ay ile birleştirerek "dd.mm.yyyy" formatında döndürür.
 */
#define tarihFormat_ (format2hane(zaman.gun) + "/" + format2hane(zaman.ay) + "/" + String(zaman.yil))