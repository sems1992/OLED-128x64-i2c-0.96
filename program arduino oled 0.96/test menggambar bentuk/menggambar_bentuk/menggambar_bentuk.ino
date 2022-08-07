/* 
 *  Minggu, 25- juli - 2022
 *  
 * By Aditya Wahyu Ardiansyah - Warna Parabola Ponorogo.
 * Kode untuk menggambar bentuk bentuk, di lcd oled 0.96
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

#define delay_short 400
#define delay_long 2000

void setup() {

 Serial.begin(9600); // addres serial monitornya adalah 9600, ini berfungsi untuk mengecek i2c Address.
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) // Alamat Address nya = 0x3C.
  {
    Serial.println(F("Addres i2c anda Salah !!!"));
    for (;;); // Don't proceed, loop forever
  }  

  // Clear the buffer
  display.clearDisplay();

  display.drawPixel(31, 15, WHITE);
  display.display();
  delay(delay_short);
  display.drawPixel(95, 15, WHITE);
  display.display();
  delay(delay_short);
  display.drawPixel(95, 47, WHITE);
  display.display();
  delay(delay_short);
  display.drawPixel(31, 47, WHITE);
  display.display();
  delay(delay_short);
  display.drawPixel(63, 31, WHITE);
  display.display();
  delay(delay_long);

  display.clearDisplay();
  display.drawLine(0, 0, 127, 63, WHITE);
  display.display();
  delay(delay_short);
  display.drawLine(0, 63, 127, 0, WHITE);
  display.display();
  delay(delay_short);
  display.drawLine(63, 0, 63, 63, WHITE);
  display.display();
  delay(delay_short);
  display.drawLine(0, 31, 127, 31, WHITE);
  display.display();
  delay(delay_long);

  display.clearDisplay();
  display.drawRect(0, 0, 63, 31, WHITE);
  display.display();
  delay(delay_short);
  display.drawRect(31, 15, 63, 31, WHITE);
  display.display();
  delay(delay_short);
  display.drawRect(63, 31, 63, 31, WHITE);
  display.display();
  delay(delay_long);

  display.clearDisplay();
  display.fillRect(0, 0, 42, 21, WHITE);
  display.display();
  delay(delay_short);
  display.fillRect(42, 21, 42, 21, WHITE);
  display.display();
  delay(delay_short);
  display.fillRect(84, 42, 42, 21, WHITE);
  display.display();
  delay(delay_long);

  display.clearDisplay();
  display.drawRoundRect(0, 0, 64, 32, 8, WHITE);
  display.display();
  delay(delay_short);
  display.drawRoundRect(64, 32, 64, 32, 16, WHITE);
  display.display();
  delay(delay_long);

  display.clearDisplay();
  display.fillRoundRect(0, 0, 64, 32, 8, WHITE);
  display.display();
  delay(delay_short);
  display.fillRoundRect(64, 32, 64, 32, 16, WHITE);
  display.display();
  delay(delay_long);

  display.clearDisplay();
  display.drawCircle(31, 15, 10, WHITE);
  display.display();
  delay(delay_short);
  display.drawCircle(95, 47, 10, WHITE);
  display.display();
  delay(delay_short);
  display.drawCircle(95, 15, 10, WHITE);
  display.display();
  delay(delay_short);
  display.drawCircle(31, 47, 10, WHITE);
  display.display();
  delay(delay_short);
  display.drawCircle(64, 32, 10, WHITE);
  display.display();
  delay(delay_long);

  display.clearDisplay();
  display.fillCircle(31, 15, 10, WHITE);
  display.display();
  delay(delay_short);
  display.fillCircle(95, 47, 10, WHITE);
  display.display();
  delay(delay_short);
  display.fillCircle(95, 15, 10, WHITE);
  display.display();
  delay(delay_short);
  display.fillCircle(31, 47, 10, WHITE);
  display.display();
  delay(delay_short);
  display.fillCircle(64, 32, 10, WHITE);
  display.display();
  delay(delay_long);

  display.clearDisplay();
  display.drawTriangle(63, 0, 31, 63, 95, 63, WHITE);
  display.display();
  delay(delay_short);
  display.drawTriangle(0, 0, 0, 63, 31, 0, WHITE);
  display.display();
  delay(delay_short);
  display.drawTriangle(127, 0, 127, 63, 95, 0, WHITE);
  display.display();
  delay(delay_long);

  display.clearDisplay();
  display.fillTriangle(63, 0, 31, 63, 95, 63, WHITE);
  display.display();
  delay(delay_short);
  display.fillTriangle(0, 0, 0, 63, 31, 0, WHITE);
  display.display();
  delay(delay_short);
  display.fillTriangle(127, 0, 127, 63, 95, 0, WHITE);
  display.display();
  delay(delay_long);
}
void loop() {
}
