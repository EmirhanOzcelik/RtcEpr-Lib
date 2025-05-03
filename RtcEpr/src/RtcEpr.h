#pragma once
#include "ZmNLiBbmkr.h"
#include "EEPROM.h"
#include "EpRLiBb.h"

/**
 * @def WTQ
 * EEPROM başlangıç adresi için sabit tanım.
 */
#define WTQ 0

/**
 * @def __EPR_IMZA
 * EEPROM imza kontrol adresi.
 */
#define __EPR_IMZA 48

/**
 * @def g_ms5
 * 5ms güncelleme aralığı için sabit.
 */
#define g_ms5 5

/**
 * @def g_ms10
 * 10ms güncelleme aralığı için sabit.
 */
#define g_ms10 10

/**
 * @def g_ms25
 * 25ms güncelleme aralığı için sabit.
 */
#define g_ms25 25

/**
 * @def g_ms
 * 50ms güncelleme aralığı için sabit (varsayılan).
 */
#define g_ms 50

/**
 * @def g_ms100
 * 100ms güncelleme aralığı için sabit.
 */
#define g_ms100 100

extern unsigned long gecen_zaman;

/**
 * @class __zaman
 * @brief Zaman yönetimi ve EEPROM tabanlı takvim ayarlarını içeren sınıf.
 */
class __zaman {
   private:
    uint16_t dks = 0;
    uint16_t varsayilan_epr = 0;
    bool haftagun_kontrol = true;
    bool artik_yil_mi(uint16_t y);
    void epr_sifirla(uint16_t basla = WTQ);
    uint8_t ay_gun_sayisi(uint8_t ay, uint16_t y);
    uint8_t hesapla_hafta_gunu();

   public:
    /**
     * @brief EEPROM ayarlarını yapar ve varsa kayıtlı verileri yükler.
     * 
     * @param bellek_baslangic EEPROM başlangıç adresi (varsayılan: WTQ).
     */
    void setup(uint16_t bellek_baslangic = WTQ);

    /**
     * @brief Zamanı millis() tabanlı olarak ilerletir.
     * 
     * @param c Güncelleme aralığı (ms cinsinden). Varsayılan: g_ms (50ms).
     */
    void millis_saat(uint16_t c = g_ms);

    /**
     * @brief EEPROM'dan zaman bilgilerini okur.
     * 
     * @param basla EEPROM adresi (varsayılan: WTQ).
     */
    void eprden_oku(uint16_t basla = WTQ);

    /**
     * @brief EEPROM'a zaman bilgilerini yazar.
     * 
     * @param basla EEPROM adresi (varsayılan: WTQ).
     */
    void eprye_kaydet(uint16_t basla = WTQ);

    /**
     * @brief Saniye değeri (0–59).
     */
    byte sn = 0;

    /**
     * @brief Dakika değeri (0–59).
     */
    byte dk = 0;

    /**
     * @brief Saat değeri (0–23).
     */
    byte saat = 0;

    /**
     * @brief Ay değeri (1–12).
     */
    byte ay = 1;

    /**
     * @brief Gün değeri (1–31).
     */
    byte gun = 1;

    /**
     * @brief Haftanın günü (0: Pazar, 1: Pazartesi, ... 6: Cumartesi).
     */
    byte hafta_gun = 0;

    /**
     * @brief Yıl bilgisi (örnek: 2025).
     */
    uint16_t yil = 2025;
};

/**
 * @brief Zaman sınıfının global örneği.
 */
extern class __zaman zaman;