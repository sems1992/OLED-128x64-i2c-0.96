/*
 * Minggu, 25- juli - 2022
 * Contoh Program untuk mengetes Lcd Display Oled.
 * 
 * By Aditya Wahyu Ardiansyah - Warna Parabola Ponorogo.
 * Upload kode di bawah ini ke papan Arduino Anda.
 * Koding ini akan mengisi semua piksel / Dot OLED Anda baris demi baris.
 * Jikalau ada piksel yang rusak di LCD Oled, Anda dapat Mengidentifikasinya / Mengetauhinya.
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
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay(); // hapus buffer
  CekDisplay(); // jalankan perintah cek diplay
}

void loop()
{
  
}

//perintah cek diplay
void CekDisplay(void) 
{
  display.clearDisplay();
  for (int j = 0; j < 63; j++) 
  {
    for (int i = 0; i < 127; i++) 
    {
      display.drawPixel(i, j, WHITE); // on kan dot pikselnya, non inverse.
    }
    display.display();
    delay(2);
  }
}
