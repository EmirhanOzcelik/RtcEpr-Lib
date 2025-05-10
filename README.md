🕒 Time and EEPROM Management Library
This library provides functionality for time management and storing time-related data in EEPROM.
It contains two main classes:

__zaman: Handles time tracking and EEPROM-based calendar settings.

__epr: Provides read/write operations for EEPROM.

Includes convenient macros for formatted time string output.

📌 Features
Time management and calendar synchronization with EEPROM

8-bit and 16-bit EEPROM read/write operations

Formatted string output for time elements

Persistent time storage across resets

📦 Classes
🔧 __zaman — Time Manager
Manages time values and provides EEPROM integration for persistent storage.

setup(uint16_t bellek_baslangic = WTQ)
Initializes EEPROM and loads saved time data if available.

cpp
Kopyala
Düzenle
zaman.setup();  // Initializes EEPROM and loads stored values
millis_saat(uint16_t c = g_ms)
Updates time using the millis() function with a customizable interval.

cpp
Kopyala
Düzenle
zaman.millis_saat();  // Updates time with default interval (g_ms = 50ms)
eprden_oku(uint16_t basla = WTQ)
Reads time values from EEPROM starting from the given address.

cpp
Kopyala
Düzenle
zaman.eprden_oku();  // Reads time from EEPROM (default address: WTQ)
eprye_kaydet(uint16_t basla = WTQ)
Writes current time values to EEPROM.

cpp
Kopyala
Düzenle
zaman.eprye_kaydet();  // Saves time to EEPROM (default address: WTQ)
📊 Time Variables
Variable	Description	Range
sn	Second	0–59
dk	Minute	0–59
saat	Hour	0–23
ay	Month	1–12
gun	Day	1–31
hafta_gun	Day of the week (0: Sunday … 6: Sat)	0–6
yil	Year	e.g., 2025

💾 __epr — EEPROM Utility
Handles low-level EEPROM data operations.

yaz8(int adres, uint8_t veri)
Writes an 8-bit value to the given EEPROM address.

cpp
Kopyala
Düzenle
epr.yaz8(0, 123);  // Write 123 to address 0
oku8(int adres)
Reads an 8-bit value from the given EEPROM address.

cpp
Kopyala
Düzenle
uint8_t veri = epr.oku8(0);  // Read value from address 0
yaz16(int adres, uint16_t veri)
Writes a 16-bit value as two bytes to EEPROM.

cpp
Kopyala
Düzenle
epr.yaz16(0, 12345);  // Write 12345 to address 0
oku16(int adres)
Reads a 16-bit value from EEPROM, combining two 8-bit reads.

cpp
Kopyala
Düzenle
uint16_t veri = epr.oku16(0);  // Read 16-bit value from address 0
🧩 Macros
Handy macros to format time variables as strings with consistent length.

Macro	Description	Example Result
format2hane(val)	Converts single-digit number to 2-digit string	"05"
saniye_	Returns second as 2-digit string	"09"
dakika_	Returns minute as 2-digit string	"34"
saat_	Returns hour as 2-digit string	"07"
ay_	Returns month as 2-digit string	"04"
gun_	Returns day as 2-digit string	"02"
yil_	Returns year as string	"2025"

✅ Example Use
cpp
Kopyala
Düzenle
zaman.setup();
zaman.millis_saat();
zaman.eprye_kaydet();

String formattedTime = saat_ + ":" + dakika_ + ":" + saniye_;
Serial.println("Current Time: " + formattedTime);
