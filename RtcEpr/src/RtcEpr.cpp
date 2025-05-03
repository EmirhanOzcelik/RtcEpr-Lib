#include "RtcEpr.h"

class __zaman zaman;

bool __zaman::artik_yil_mi(uint16_t y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

uint8_t __zaman::ay_gun_sayisi(uint8_t ay, uint16_t y)
{
    switch (ay)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return artik_yil_mi(y) ? 29 : 28;
    default:
        return 30; // güvenlik için
    }
}

void __zaman::millis_saat(uint16_t c)
{
    dks++;
    if (c * dks >= 1000)
    {
        sn++;
        dks = 0;

        if (sn >= 60)
        {
            sn = 0;
            dk++;
            if (haftagun_kontrol)
                hafta_gun = hesapla_hafta_gunu();
            if (dk >= 60)
            {
                dk = 0;
                saat++;
                if (saat >= 24)
                {
                    saat = 0;
                    gun++;
                    haftagun_kontrol = true;
                    uint8_t max_gun = ay_gun_sayisi(ay, yil);
                    if (gun > max_gun)
                    {
                        gun = 1;
                        ay++;
                        if (ay > 12)
                        {
                            ay = 1;
                            yil++;
                        }
                    }
                }
            }
        }
    }
}

uint8_t __zaman::hesapla_hafta_gunu()
{
    uint16_t y = yil;
    uint8_t m = ay;
    if (m < 3)
    {
        m += 12;
        y -= 1;
    }
    uint8_t q = gun;
    uint16_t K = y % 100;
    uint16_t J = y / 100;
    uint8_t h = (q + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    haftagun_kontrol = false;
    // Zeller: 0 = Cumartesi, 1 = Pazar, ..., 6 = Cuma
    // Biz:    0 = Pazar,     ..., 6 = Cumartesi
    return (h + 6) % 7;
}