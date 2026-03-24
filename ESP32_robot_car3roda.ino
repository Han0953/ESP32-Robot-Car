#include <WiFi.h>
#include <WebServer.h>

// --- PENGATURAN JARINGAN WIFI ---
const char* ap_ssid = "RobotESP32_WiFi";

// Inisialisasi server
WebServer server(80);

// --- PENGATURAN PIN MOTOR (Sesuai dengan koneksi Anda) ---
// Motor Kanan
#define ENA 14
#define IN1 27
#define IN2 26
// Motor Kiri
#define ENB 32
#define IN3 25
#define IN4 33

// Variabel global
int motorSpeed = 128;

// --- FUNGSI KONTROL GERAKAN (LOGIKA DIPERBAIKI) ---

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Perintah: Berhenti");
}

void moveForward() {
  // Terapkan kecepatan saat bergerak
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  // Atur arah
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Perintah: Maju");
}

void moveBackward() {
  // Terapkan kecepatan saat bergerak
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  // Atur arah
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Perintah: Mundur");
}

void turnRight() {
  // Terapkan kecepatan saat bergerak
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  // Atur arah
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Perintah: Belok Kanan");
}

void turnLeft() {
  // Terapkan kecepatan saat bergerak
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  // Atur arah
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Perintah: Belok Kiri");
}


// --- FUNGSI WEB SERVER ---

void handleControl() {
  String command = "";
  if (server.hasArg("cmd")) {
    command = server.arg("cmd");
    char cmdChar = command.charAt(0);
    switch (cmdChar) {
      case 'F': moveForward(); break;
      case 'B': moveBackward(); break;
      case 'L': turnLeft(); break;
      case 'R': turnRight(); break;
      case 'S':
      case 'H':
        stopMotors();
        break;
    }
  }
  server.send(200, "text/plain", "OK: " + command);
}

void handleSpeed() {
  if (server.hasArg("val")) {
    String speedValue = server.arg("val");
    // HANYA perbarui variabel, tidak langsung memanggil analogWrite
    motorSpeed = speedValue.toInt();
    Serial.print("Variabel kecepatan diatur ke: ");
    Serial.println(motorSpeed);
    server.send(200, "text/plain", "Speed set to " + speedValue);
  }
}

void handleNotFound() {
  String receivedUri = server.uri();
  Serial.print("URL TIDAK DIKENAL DITERIMA: ");
  Serial.println(receivedUri);
  server.send(404, "text/plain", "Not found");
}

// --- FUNGSI UTAMA ---

void setup() {
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  stopMotors();

  Serial.print("Membuat Access Point: ");
  Serial.println(ap_ssid);
  WiFi.softAP(ap_ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Alamat IP AP: ");
  Serial.println(myIP);

  // Definisi endpoint URL yang akan diterima server
  server.on("/control", HTTP_GET, handleControl);
  server.on("/speed", HTTP_GET, handleSpeed);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server dimulai. Siap menerima perintah.");
}

void loop() {
  server.handleClient();
}