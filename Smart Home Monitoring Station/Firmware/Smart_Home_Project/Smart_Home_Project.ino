#define BLYNK_TEMPLATE_ID "XXXXXXXXXXXXX"
#define BLYNK_TEMPLATE_NAME "Akıllı ev"
#define BLYNK_AUTH_TOKEN "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// --- KİMLİK BİLGİLERİ ---
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Your Wİ-Fİ NAME";     // Wi-Fi adın
char pass[] = "YOUR Wİ-Fİ PASSWOORD";   // Wi-Fi şifren

// --- PİN TANIMLAMALARI ---
#define DHTPIN 14      // DHT11 Data Pini (Mor kablo)
#define DHTTYPE DHT11
#define LDRPIN 34       // LDR Analog Pini (Mutlaka ADC1 grubundan olmalı)
#define LED_PIN 2       // ESP32 Dahili Mavi LED

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

// --- SENSÖR VERİLERİ VE OTOMASYON ---
void sendSensorData() {
  // 1. DHT11 Okuma
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // 2. LDR Okuma ve Oranlama (0-4095 arasını 0-100'e çeker)
  int rawLDR = analogRead(LDRPIN);
  int ldrYuzde = map(rawLDR, 0, 4095, 0, 100); // Ters orantı: Işık artınca yüzde artsın

  // 3. Hata Kontrolü ve Seri Port Yazdırma
  if (isnan(h) || isnan(t)) {
    Serial.println("DHT Sensörü okunamıyor, bağlantıyı kontrol et!");
  } else {
    Serial.print("Sıcaklık: "); Serial.print(t);
    Serial.print("°C | Nem: %"); Serial.print(h);
    Serial.print(" | Işık Seviyesi: %"); Serial.println(ldrYuzde);

    // 4. Blynk Uygulamasına Gönder
    Blynk.virtualWrite(V1, t);        // Sıcaklık (Gauge)
    Blynk.virtualWrite(V2, h);        // Nem (Gauge)
    Blynk.virtualWrite(V3, ldrYuzde); // Işık Yüzdesi (Value Display)
  }

  // 5. Işık Otomasyonu (Gece Lambası Mantığı)
  // Eğer ışık %30'un altına düşerse LED'i yak
  if (ldrYuzde < 30) {
    digitalWrite(LED_PIN, HIGH);
    Blynk.virtualWrite(V4, 1); // Uygulamadaki butonu "AÇIK" yap
  } else {
    digitalWrite(LED_PIN, LOW);
    Blynk.virtualWrite(V4, 0); // Uygulamadaki butonu "KAPALI" yap
  }
}

// --- MANUEL LED KONTROLÜ (Blynk Butonundan) ---
BLYNK_WRITE(V4) {
  int pinValue = param.asInt();
  digitalWrite(LED_PIN, pinValue);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  
  dht.begin();
  Blynk.begin(auth, ssid, pass);

  // Her 2 saniyede bir sensörleri oku ve gönder
  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}
