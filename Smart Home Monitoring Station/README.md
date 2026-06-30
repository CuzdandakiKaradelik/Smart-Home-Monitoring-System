# 🏠 ESP32 Smart Home Monitoring Station / Akıllı Ev İzleme İstasyonu

<p align="center">
  <a href="#-english">English</a> •
  <a href="#-türkçe">Türkçe</a>
</p>

---

## 🇺🇸 English

This project is an IoT (Internet of Things) based Smart Home Monitoring Station developed using the **ESP32** development board and the **Blynk** platform. It allows users to monitor room temperature, humidity, and ambient light levels in real-time while providing automated and manual controls.

### 🚀 Features
* **Real-time Environment Monitoring:** Measures room temperature and humidity using the DHT11 sensor.
* **Smart Night Light Automation:** Automatically turns on the onboard ESP32 LED when ambient light drops below 30% (via LDR).
* **Mobile Integration & Dashboard:** Visualize live data on the Blynk app using Gauges and control the built-in LED remotely using a virtual button.

### 🛠️ Hardware Requirements
* ESP32 Development Board
* DHT11 Temperature & Humidity Sensor
* LDR (Light Dependent Resistor)
* 10K Ohm Resistor (for LDR)
* Jumper Wires & Breadboard

### 💻 Installation and Usage
1. Install **Arduino IDE** and set up the ESP32 board manager.
2. Install the required libraries: `Blynk` and `DHT sensor library`.
3. Open the code inside the `firmware` folder.
4. Replace the placeholders with your actual Blynk tokens and Wi-Fi credentials:
   ```cpp
   char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
   char ssid[] = "YOUR_WIFI_SSID";
   char pass[] = "YOUR_WIFI_PASSWORD";

Upload the code to your ESP32.

Configure your Blynk Dashboard with the following Virtual Pins:

V1: Temperature (Gauge)

V2: Humidity (Gauge)

V3: Light Level (Value Display)

V4: LED Control (Button Switch)

## 📺 Project Introduction and Demo Video

To see how the project works and the installation steps in detail, you can access my YouTube video by clicking on the image below:

[![ESP32 Smart Home Monitoring System](https://youtu.be/t0Vx_-WZN8s?si=PN4jharj8U-KaOwb)](https://youtube.com/shorts/6QIa9vA82sE?si=jJtiBHzMaCT7FKiF)


// For Turks Persons

Bu proje, ESP32 geliştirme kartı ve Blynk platformu kullanılarak geliştirilmiş IoT (Nesnelerin İnterneti) tabanlı bir Akıllı Ev İzleme İstasyonudur. Kullanıcıların oda sıcaklığını, nemini ve ortam ışığı seviyesini anlık olarak takip etmesini sağlarken, hem otomatik hem de manuel kontrol imkanı sunar.

🚀 Özellikler
Anlık Ortam Takibi: DHT11 sensörü ile oda sıcaklığı ve nem oranını anlık olarak ölçer.

Akıllı Gece Lambası Otomasyonu: LDR sensörü sayesinde ortam ışığı %30'un altına düştüğünde ESP32 üzerindeki dahili LED otomatik olarak yanar.

Mobil Entegrasyon ve Panel: Blynk uygulaması üzerinden tüm verileri grafiksel (Gauge) olarak izleme ve sanal bir butonla LED'i uzaktan kontrol etme imkanı sunar.

🛠️ Donanım Malzemeleri
ESP32 Geliştirme Kartı

DHT11 Sıcaklık ve Nem Sensörü

LDR (Işık Sensörü)

10K Ohm Direnç (LDR için)

Jumper Kablolar ve Breadboard

Kurulum ve Kullanım
Bilgisayarınıza Arduino IDE kurun ve ESP32 kart kütüphanelerini yükleyin.

Gerekli kütüphaneleri ekleyin: Blynk ve DHT sensor library.

firmware klasöründeki kod dosyasını açın.

Kodun en üstünde yer alan ilgili alanlara kendi Blynk token ve Wi-Fi bilgilerinizi yazın:
char auth[] = "BLYNK_TOKENINIZ";
char ssid[] = "WIFI_ADINIZ";
char pass[] = "WIFI_SIFRENIZ";

Kodu ESP32 kartınıza yükleyin.

Blynk uygulamanızda şu Sanal Pinleri (Virtual Pins) tanımlayarak arayüzünüzü oluşturun:

V1: Sıcaklık (Gauge)

V2: Nem (Gauge)

V3: Işık Seviyesi (Value Display)

V4: LED Kontrolü (Button Switch)

## 📺 Proje Tanıtım ve Demo Videosu

Projenin nasıl çalıştığını ve kurulum adımlarını detaylı izlemek için aşağıdaki görsele tıklayarak YouTube videoma ulaşabilirsiniz:

[![ESP32 Akıllı Ev İzleme İstasyonu](https://youtu.be/t0Vx_-WZN8s?si=PN4jharj8U-KaOwb)](https://youtube.com/shorts/6QIa9vA82sE?si=jJtiBHzMaCT7FKiF)