# Labirent Çözen Robot

Bu proje; ön, sağ ve sol olmak üzere üç adet lazer mesafe sensörü kullanarak engelleri tespit eden ve labirent içerisinde otonom yol bulabilen bir robot projesidir. Proje, motor sürücü kontrolü ve I2C üzerinden çoklu sensör yönetimi üzerine odaklanmıştır.

---

## ✨ Özellikler

* **📏 Lazer Hassasiyeti:** 3 adet VL53L0X ToF (Time-of-Flight) sensörü ile milimetrik mesafe ölçümü.
* **🧠 Akıllı Adresleme:** Aynı I2C hattı üzerindeki sensörlerin XSHUT pinleri kullanılarak çalışma anında dinamik olarak adreslenmesi.
* **🛤️ Duvar Takibi:** Sağ veya sol duvarı referans alarak koridor boyunca stabil sürüş sağlayan regülasyon mantığı.
* **🕹️ Diferansiyel Sürüş:** İki tekerlek hız farkı ile keskin dönüş ve manevra kabiliyeti.

---

## 🛠️ Kullanılan Bileşenler

* **Arduino Uno / Nano**
* **3x VL53L0X Lazer Mesafe Sensörü**
* **L298N veya L293D Motor Sürücü**
* **2x DC Motor ve Tekerlek Takımı**
* **Sarhoş Tekerlek** (Denge için)
* **Li-po Pil / Güç Kaynağı**

---

## 🔌 Pin Bağlantıları

### Motor Sürücü (L298N Örneği)
| Fonksiyon | Pin | Tanım |
| :--- | :--- | :--- |
| **RFmotorPin** | 9 | Sağ Motor İleri (PWM) |
| **RBmotorPin** | 10 | Sağ Motor Geri (PWM) |
| **LFmotorPin** | 11 | Sol Motor İleri (PWM) |
| **LBmotorPin** | 6 | Sol Motor Geri (PWM) |

### Lazer Sensör Kontrol (XSHUT)
| Sensör | XSHUT Pini | I2C Adresi (Atanan) |
| :--- | :--- | :--- |
| **Ön (Front)** | Pin 2 | 0x30 |
| **Sol (Left)** | Pin 3 | 0x31 |
| **Sağ (Right)** | Pin 4 | 0x32 |

---

## 🚀 Çalışma Mantığı

1.  **Sensör Başlatma:** Arduino her sensörü sırayla aktif eder (`XSHUT HIGH`) ve her birine benzersiz bir I2C adresi atar. Bu, çakışmaları önler.
2.  **Mesafe Okuma:** Sürekli (Continuous) modda ön, sağ ve sol mesafeler milimetrik olarak okunur.
3.  **Karar Mekanizması:** * Eğer ön mesafe `wallThreshold` değerinden büyükse: **İleri Git**.
    * Eğer ön kapalıysa: Sağ ve sol mesafeleri kıyasla ve **Boş Olan Yöne Dön**.
    * Dar koridorda sağ/sol farkına göre motor hızlarını anlık güncelleyerek merkeze odaklan.

---

## ⚙️ Kurulum ve Kalibrasyon

1.  **Kütüphane:** Arduino IDE'ye **VL53L0X** kütüphanesini ekleyin.
2.  **Hız Ayarı:** `RbaseSpeed` ve `LbaseSpeed` değişkenlerini motorlarınızın gücüne ve pil voltajınıza göre 0-255 arasında optimize edin.
3.  **Mesafe Eşiği:** `wallThreshold = 200;` değeri robotun duvara ne kadar yaklaştığında duracağını belirler. 

---

## 📸 Proje Görselleri
<img width="1200" height="1600" alt="image" src="https://github.com/user-attachments/assets/99f6cffb-91d2-460a-a170-1420853e823e" />

<img width="1200" height="1600" alt="image" src="https://github.com/user-attachments/assets/50e4ea7a-ddc7-410d-93fd-07431e03bbaf" />
