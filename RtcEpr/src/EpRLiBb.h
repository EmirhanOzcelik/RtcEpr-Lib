#pragma once
#include <Arduino.h>
#include <EEPROM.h>

/**
 * @brief EEPROM erişim işlemleri için yardımcı sınıf.
 */
class __epr {
public:
    /**
     * @brief EEPROM'a 8-bit (0-255) veri yazar.
     * 
     * @param adres EEPROM adresi
     * @param veri Yazılacak 8-bit değer
     */
    static void yaz8(int adres, uint8_t veri);

    /**
     * @brief EEPROM'dan 8-bit (0-255) veri okur.
     * 
     * @param adres EEPROM adresi
     * @return Okunan 8-bit değer
     */
    static uint8_t oku8(int adres);

    /**
     * @brief EEPROM'a 16-bit (0-66000) veri yazar.
     * 
     * @param adres EEPROM başlangıç adresi
     * @param veri Yazılacak 16-bit değer
     */
    static void yaz16(int adres, uint16_t veri);

    /**
     * @brief EEPROM'dan 16-bit (0-66000) veri okur.
     * 
     * @param adres EEPROM başlangıç adresi
     * @return Okunan 16-bit değer
     */
    static uint16_t oku16(int adres);
};
extern class __epr epr;