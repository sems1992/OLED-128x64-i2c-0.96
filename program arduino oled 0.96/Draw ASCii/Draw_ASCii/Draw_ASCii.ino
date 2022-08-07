/* 
 *  Minggu, 25- juli - 2022
 *  
 * By Aditya Wahyu Ardiansyah - Warna Parabola Ponorogo.
 * Kode untuk menggambar ASCII Characters
 * 
 * >> Konfigurasi Pin :
 * VCC ⟶ PIN 5V atau 3.3V arduino
 * GND ➝ PIN GND Arduino
 * SDA ➝ PIN A4 (Jika MemakaiArduino Uno dan Nano) D20 (Jika Memakai Arduino Mega)
 * SCL ➝ PIN A5 (Jika MemakaiArduino Uno dan Nano) D21 (Jika Memakai Arduino Mega)
 * 
 * >> Langkah Pertama Harus pasang library berikut ke software Arduino IDE anda. saya di sini memakai Arduino IDE 1.8.3 
 * 1. Library Adafruit_SSD1306 dan Library Adafruit_GFX
 * 2. setelah librarynya selesai di install, maka klik compile dan klik upload program ke arduino anda.
 * 
 * >> JIKA ANDA BINGUNG, PORT - PORT PADA ARDUINO ANDA... CEK LINK INI !!!
 * ARDUINO UNO ---> https://images.prismic.io/circuito/8e3a980f0f964cc539b4cbbba2654bb660db6f52_arduino-uno-pinout-diagram.png?auto=compress,format
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {

 Serial.begin(9600); // addres serial monitornya adalah 9600, ini berfungsi untuk mengecek i2c Address.
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) // Alamat Address nya = 0x3C.
  {
    Serial.println(F("Addres i2c anda Salah !!!"));
    for (;;); // Don't proceed, loop forever
  }  

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.write(2);
  display.setCursor(20, 0);
  display.write(3);
  display.setCursor(40, 0);
  display.write(14);
  display.setCursor(60, 0);
  display.write(38);
  display.setCursor(80, 0);
  display.write(42);
  display.display();
}
void loop() {
}
