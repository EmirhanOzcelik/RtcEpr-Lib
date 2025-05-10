# 🕒 Time and EEPROM Management Library

This library provides easy-to-use time management features and persistent storage using EEPROM. It contains two main classes:

- **\_\_zaman** — Handles time tracking and EEPROM-based calendar settings  
- **\_\_epr** — Provides low-level EEPROM read/write operations

Includes convenient macros for consistent and formatted time string output.

---

## 📌 Features

- Time tracking and calendar synchronization using EEPROM  
- 8-bit and 16-bit EEPROM read/write functions  
- Formatted time string generation  
- Persistent time storage across device resets  

---

## zaman CLASS FUNCTIONS
------------------------

void setup(uint16_t bellek_baslangic = WTQ)
→ Initializes EEPROM and loads saved time data if available.
→ Takes an optional starting address (default: WTQ).

void millis_saat(uint16_t c = g_ms)
→ Updates time using the millis() function.
→ The optional parameter 'c' sets the update interval (default: g_ms = 50ms).

void eprden_oku(uint16_t basla = WTQ)
→ Reads time values from EEPROM starting at the given address.

void eprye_kaydet(uint16_t basla = WTQ)
→ Writes current time values to EEPROM for persistence after reset.

## TIME VARIABLES
---------------
sn         → Seconds (0–59)  
dk         → Minutes (0–59)  
saat       → Hours (0–23)  
gun        → Day of the month (1–31)  
ay         → Month (1–12)  
hafta_gun  → Day of the week (0 = Sunday, 6 = Saturday)  
yil        → Year (e.g., 2025)


## epr CLASS FUNCTIONS
----------------------

void yaz8(int adres, uint8_t veri)
→ Writes an 8-bit (1 byte) value to the specified EEPROM address.

uint8_t oku8(int adres)
→ Reads an 8-bit (1 byte) value from the specified EEPROM address.

void yaz16(int adres, uint16_t veri)
→ Writes a 16-bit (2 byte) value to EEPROM using two consecutive addresses.

uint16_t oku16(int adres)
→ Reads a 16-bit value from EEPROM by combining two 8-bit reads.


## MACROS
-------

format2hane(val)
→ Converts single-digit numbers to two-digit strings.
→ Example: format2hane(5) → "05"

saniye_
→ Returns the second value as a 2-digit string.  
→ Example: "08"

dakika_
→ Returns the minute value as a 2-digit string.  
→ Example: "45"

saat_
→ Returns the hour value as a 2-digit string.  
→ Example: "07"

gun_
→ Returns the day of the month as a 2-digit string.  
→ Example: "02"

ay_
→ Returns the month as a 2-digit string.  
→ Example: "11"

yil_
→ Returns the full year as a string.  
→ Example: "2025"

saat_format
→ Returns the full time as a formatted string: "hh:mm:ss"  
→ Example: "14:07:30"

tarih_format
→ Returns the full date as a formatted string: "YYYY/MM/DD"  
→ Example: "2025/05/10"
