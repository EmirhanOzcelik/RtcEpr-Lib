cat << 'EOF' > README.md
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

## 📦 Classes

### 🔧 \_\_zaman — Time Manager

Manages time values and provides EEPROM integration for persistent storage.

#### `setup(uint16_t bellek_baslangic = WTQ)`
Initializes EEPROM and loads saved time data if available.

```cpp
zaman.setup();  // Initializes EEPROM and loads stored values
