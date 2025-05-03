#include "RtcEpr.h"
class __epr epr;

void __epr::yaz8(int adres, uint8_t veri)
{
    EEPROM.update(adres, veri);
}

uint8_t __epr::oku8(int adres)
{
    return EEPROM.read(adres);
}

void __epr::yaz16(int adres, uint16_t veri)
{
    EEPROM.update(adres, veri & 0xFF);   // düşük
    EEPROM.update(adres + 1, veri >> 8); // yüksek
}

uint16_t __epr::oku16(int adres)
{
    uint8_t low = EEPROM.read(adres);
    uint8_t high = EEPROM.read(adres + 1);
    return (uint16_t)(high << 8) | low;
}