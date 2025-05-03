#include "RtcEpr.h"

/**
 * @brief millis yapısında kullanılabilecek tutucu değişken eğer değer sınıra ulaşırsa kendini resetleyebilir.
 *
 * Bu değişken millis süresini saklamak içindir. Örn: gecen_zaman = millis(); ve if(millis() - gecen_zaman >= g_ms)
 */
unsigned long gecen_zaman = 0;

void __zaman::setup(uint16_t bellek_baslangic)
{
  uint16_t u = bellek_baslangic;
  if (epr.oku8(u + 8) != __EPR_IMZA)
  {
    epr_sifirla(u);
    setup(u);
  }
  eprden_oku();
  millis();
}

void __zaman::epr_sifirla(uint16_t basla)
{
  epr.yaz8(basla, 0);         // sn
  epr.yaz8(basla + 1, 0);     // dk
  epr.yaz8(basla + 2, 0);     // saat
  epr.yaz8(basla + 3, 1);     // gun
  epr.yaz8(basla + 4, 1);     // ay
  epr.yaz16(basla + 5, 2025); // yil
  epr.yaz8(basla + 7, 0);     // hafta_gun
  epr.yaz8(basla + 8, __EPR_IMZA);
}

void __zaman::eprden_oku(uint16_t basla)
{
  if (epr.oku8(basla + 8) != __EPR_IMZA)
  {
    epr_sifirla(basla);
  }
  sn = epr.oku8(basla);            // sn
  dk = epr.oku8(basla + 1);        // dk
  saat = epr.oku8(basla + 2);      // saat
  gun = epr.oku8(basla + 3);       // gun
  ay = epr.oku8(basla + 4);        // ay
  yil = epr.oku16(basla + 5);      // yil
  hafta_gun = epr.oku8(basla + 7); // haftagn
}

void __zaman::eprye_kaydet(uint16_t basla)
{
  epr.yaz8(basla, sn);            // sn
  epr.yaz8(basla + 1, dk);        // dk
  epr.yaz8(basla + 2, saat);      // saat
  epr.yaz8(basla + 3, gun);       // gun
  epr.yaz8(basla + 4, ay);        // ay
  epr.yaz16(basla + 5, yil);      // yil
  epr.yaz8(basla + 7, hafta_gun); // haftagn
  epr.yaz8(basla + 8, __EPR_IMZA);
}