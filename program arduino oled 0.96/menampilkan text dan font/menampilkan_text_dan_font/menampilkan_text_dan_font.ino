/*
 * Minggu, 24- juli - 2022
 * Contoh Program Menampikan Teks di Display Oled 0,96 Inch I2C
 * By Aditya Wahyu Ardiansyah - Warna Parabola Ponorogo.
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

#include <SPI.h> // library SPI
#include <Wire.h> // Pendukung Library SPI
#include <Adafruit_GFX.h> // // library pendukung Adafruit_SSD1306.h
#include <Adafruit_SSD1306.h> // library driver lcdnya
#include <Fonts/FreeSerif9pt7b.h> // library fontnya
#define SCREEN_WIDTH 128 // ukuran lebar piksel lcd
#define SCREEN_HEIGHT 32 // ukuran lebar piksel lcd

// Deklarasi Pin pinnya. (JANGAN DIRUBAH !!!)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define NUMFLAKES     10 // Number of snowflakes in the animation example

void setup() {
  Serial.begin(9600); // addres serial monitornya adalah 9600, ini berfungsi untuk mengecek i2c Address.
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
   if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) // Alamat Address nya = 0x3C.
  {
    Serial.println(F("Addres i2c anda Salah !!!"));
    for (;;); // Don't proceed, loop forever
  }  

  // Display Text
  display.clearDisplay(); // hapus semua tulisan pada display / hapus buffer.
  display.setTextSize(1); // size.
  display.setTextColor(WHITE); // opsi inversnya
  display.setCursor(5, 0); // kiri kanan, atas bawah
  display.println("Oled 0.96 inch i2c.");
  display.display();
  delay(1000);
  display.clearDisplay();

  // Display Inverted Text
  display.setTextColor(BLACK, WHITE);
  display.setCursor(5, 0);
  display.println("Oled 0.96 inch i2c.");
  display.display();
  delay(1000);
  display.clearDisplay();
  
  display.setTextColor(WHITE);
  display.setCursor(5, 0);
  display.println("Oled 0.96 inch i2c.");
  display.display();
  delay(1000);
  
  // test font
  display.setTextColor(WHITE);
  display.setFont(&FreeSerif9pt7b); // set fontnya.
  display.setCursor(5, 25);
  display.println("Warna Parabola");
  display.display();
  delay(1000);
  
  // menampilkan kotak pada tulisan "Warna Parabola"
  display.drawRect(3, 8, 120, 24, WHITE); // -- > drawRect(x, y, width, height) --> (Samping kiri, bawah, lebar, tinggi)
  display.display();
  delay(3000);
  display.clearDisplay();
}

void loop()
{
  
}
