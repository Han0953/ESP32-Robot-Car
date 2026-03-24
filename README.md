# 🚗 ESP32 WiFi Robot Car

Selamat datang di repositori **ESP32 WiFi Robot Car**! 

Proyek ini adalah panduan lengkap dan kode sumber untuk membuat mobil robot pintar berbasis microcontroller **ESP32**. Robot ini beroperasi sebagai *Access Point* (WiFi Hotspot) mandiri dan dapat dikendalikan sepenuhnya melalui *smartphone* Android menggunakan aplikasi buatan sendiri (via MIT App Inventor).

---

## ✨ Fitur Utama
- **Koneksi Independen (AP Mode):** Robot memancarkan sinyal WiFi sendiri, tidak memerlukan router eksternal atau koneksi internet.
- **Kontrol Gerak Penuh:** Maju, Mundur, Belok Kanan, Belok Kiri, dan Berhenti.
- **Kontrol Kecepatan Halus (PWM):** Mengatur kecepatan motor secara *real-time* menggunakan antarmuka *slider* pada aplikasi.
- **Anti-Captive Portal:** Dilengkapi dengan penanganan otomatis agar *smartphone* tidak memunculkan tanda seru (!) saat terhubung ke WiFi tanpa internet.

---

## 🛠️ Perangkat Keras (Hardware) yang Dibutuhkan
Untuk merakit robot ini, Anda membutuhkan komponen berikut:
1. **Microcontroller:** 1x Board ESP32 (Versi 30 Pin)
2. **Motor Driver:** 1x Modul Driver Motor L298N
3. **Aktuator:** 2x Motor DC dengan Girbox (DC Gear Motor)
4. **Sasis:** 1x Kit Sasis Robot (2 Roda / 4 Roda) + Roda Bebas (Caster Wheel)
5. **Sumber Daya:** - 2x Baterai 18650 (Menghasilkan 7.4V)
   - 1x Tempat Baterai (Battery Holder) 18650
   - *Opsional tapi sangat disarankan:* Powerbank kecil/Step-down khusus untuk suplai daya ESP32.
6. Kabel Jumper secukupnya (Male-to-Female & Male-to-Male)

---

## 📌 Skema Pengabelan (Pin Mapping)

Pastikan Anda menyambungkan kabel dari ESP32 ke modul L298N sesuai dengan tabel berikut agar arah gerak robot sesuai dengan tombol di aplikasi:

| ESP32 Pin | Sambungan ke L298N | Deskripsi Fungsi |
| :---: | :---: | :--- |
| **VIN** | `+5V` / External 5V | Input daya untuk menyalakan ESP32 |
| **GND** | `GND` | Jalur Ground (Wajib disatukan dengan L298N) |
| **D14** | `ENA` | Kontrol Kecepatan (PWM) Motor Kanan |
| **D27** | `IN1` | Kontrol Arah Motor Kanan |
| **D26** | `IN2` | Kontrol Arah Motor Kanan |
| **D25** | `IN3` | Kontrol Arah Motor Kiri |
| **D33** | `IN4` | Kontrol Arah Motor Kiri |
| **D32** | `ENB` | Kontrol Kecepatan (PWM) Motor Kiri |

---

## 💻 Instalasi dan Penggunaan

### 1. Persiapan Kode (Arduino IDE)
1. Pastikan Anda sudah menginstal **Arduino IDE** dan **ESP32 Board Package**.
2. *Clone* atau unduh repositori ini.
3. Buka file `esp32_robot_car.ino` di Arduino IDE.
4. Sambungkan ESP32 ke komputer, pilih *Board* dan *Port* yang sesuai.
5. Klik **Upload**.

### 2. Persiapan Aplikasi (MIT App Inventor)
1. Instal aplikasi `.apk` yang tersedia di repositori ini ke HP Android Anda.
2. Saat aplikasi terbuka, pastikan kolom IP Address berisi `192.168.4.1`.
3. Pastikan *Slider* kecepatan memiliki nilai pengaturan `MinValue: 0` dan `MaxValue: 255`.

### 3. Cara Menjalankan
1. Nyalakan sumber daya robot (baterai/power bank).
2. Buka pengaturan WiFi di HP Android Anda.
3. Cari dan hubungkan ke WiFi bernama **`RobotESP32_WiFi`**.
4. Buka aplikasi kontrol, atur kecepatan pada slider, dan tekan tombol arah untuk menggerakkan robot!

---

## ⚠️ Pemecahan Masalah (Troubleshooting)

**Masalah: Robot tiba-tiba berhenti, tidak responsif, atau koneksi WiFi terputus saat digerakkan/mengubah kecepatan.**
- **Penyebab:** Ini adalah masalah *Brownout*. Regulator 5V pada driver L298N tidak sanggup memberikan arus listrik yang stabil saat motor tiba-tiba menarik daya besar, sehingga ESP32 kekurangan daya dan me-*restart* dirinya sendiri.
- **Solusi Terbaik:** Pisahkan sumber daya. Gunakan baterai 18650 *hanya* untuk memberi daya pada L298N (pin +12V), dan gunakan sumber daya 5V terpisah (seperti Power Bank via USB) untuk menyalakan ESP32. Pastikan pin `GND` pada ESP32 dan L298N tetap terhubung.
