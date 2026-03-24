# codingan

Ini codingan ESP32 Robot Car 3 roda dengan aplikasi buatan dari MIT APP Inventor yang terintegrasi langsung ke ESP32 melalui WiFi.
ESP32 WiFi Robot Car (RWD)

Proyek ini adalah mobil robot berbasis ESP32 yang dikontrol melalui koneksi WiFi menggunakan aplikasi Android yang dibuat dengan MIT App Inventor. Robot ini mendukung kontrol gerakan (maju, mundur, kiri, kanan) serta pengaturan kecepatan secara real-time.

🚀 Fitur
Kontrol nirkabel melalui WiFi (ESP32 sebagai Access Point).
Pengaturan kecepatan motor (PWM) melalui Slider aplikasi.
Interface aplikasi yang intuitif.
Penanganan masalah tanda seru (!) pada WiFi (Captive Portal handling).

🛠️ Komponen Elektronika
Microcontroller: ESP32 (30 Pin)
Motor Driver: L298N
Motor: 2x Motor DC (Girbox)
Power: 2x Baterai 18650 (7.4V)
Sasis: Kit Robot 3 Roda / 4 Roda

📌 Skema Pengabelan (Pin Mapping)
<img width="974" height="585" alt="image" src="https://github.com/user-attachments/assets/1431247c-1d74-4544-945f-c034a9f4352d" />

📱 Konfigurasi Aplikasi (MIT App Inventor)
IP Address: 192.168.4.1
Slider Speed:
MinValue: 0
MaxValue: 255
Komponen Web: Digunakan untuk mengirim perintah GET ke ESP32.

📖 Cara Penggunaan
Unggah kode esp32_robot_car.ino ke board ESP32 Anda.
Nyalakan robot.
Hubungkan WiFi smartphone Anda ke SSID: "RobotESP32_WiFi".
Buka aplikasi kontrol robot.
Pastikan IP di aplikasi tertulis 192.168.4.1.
Selamat mengontrol robot!

⚠️ Catatan Penting

Jika robot berhenti saat slider digerakkan, pastikan daya ke ESP32 stabil. Sangat disarankan untuk memisahkan sumber daya antara Motor (Baterai) dan ESP32 (Power Bank/Regulator stabil) serta menambahkan kapasitor 1000uF pada pin VIN-GND.
