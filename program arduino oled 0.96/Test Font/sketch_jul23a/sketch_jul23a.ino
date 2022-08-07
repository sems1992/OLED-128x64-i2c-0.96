/*
 * Sabtu, 23 - juli - 2022
 * Contoh Program Test Display Oled 0,96 Inch I2C
 * By Aditya Wahyu Ardiansyah - Warna Parabola Ponorogo.
 * 
 * Konfigurasi Pin :
 * VCC ⟶ PIN 5V atau 3.3V arduino
 * GND ➝ PIN GND Arduino
 * SDA ➝ PIN A4 (Jika MemakaiArduino Uno dan Nano) D20 (Jika Memakai Arduino Mega)
 * SCL ➝ PIN A5 (Jika MemakaiArduino Uno dan Nano) D21 (Jika Memakai Arduino Mega)
 * 
 * Sumber :
 * https://ahonerd.com/esp32-oled-display
 * https://lastminuteengineers.com/oled-display-arduino-tutorial/
 * 
 * JIKA ANDA BINGUNG, PORT - PORT PADA ARDUINO ANDA... CEK LINK INI !!!
 * ARDUINO UNO ---> https://images.prismic.io/circuito/8e3a980f0f964cc539b4cbbba2654bb660db6f52_arduino-uno-pinout-diagram.png?auto=compress,format
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeSerifBold9pt7b.h>
#include <Fonts/FreeSerifBoldItalic9pt7b.h>   
#include <Fonts/FreeSerifItalic9pt7b.h>  
#include <Fonts/FreeMonoOblique9pt7b.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSansOblique9pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
}

void loop() {
// test teks berjalan
display.clearDisplay();
display.setCursor(0,0);
display.setTextSize(1);
display.println("Warna Parabola Ponorogo");
display.println("Coba test..");
display.println("Teks Berjalan :)");
display.display();
display.startscrollright(0x00, 0x00);
delay(6000);

// test screen full berjalan.
display.clearDisplay();
display.setCursor(0,0);
display.setTextSize(1);
display.println("Warna Parabola");
display.println("Screen");
display.println("Berjalan !");
display.display();
display.startscrollright(0x00, 0x07);
delay(2000);
display.stopscroll();
delay(1000);
display.startscrollleft(0x00, 0x07);
delay(2000);
display.stopscroll();
delay(1000);    
display.startscrolldiagright(0x00, 0x07);
delay(2000);
display.startscrolldiagleft(0x00, 0x07);
delay(2000);
display.stopscroll();

  // test font
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 1); // kiri kanan, atas bawah
  display.println("Oled 0.96 i2c Font.");
  display.setFont(&FreeSerif9pt7b);
  display.setCursor(0, 25);
  display.println("Warna Parabola.");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setFont(&FreeSerifBold9pt7b);
  display.setCursor(0, 25);
  display.println("Warna Parabola.");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setFont(&FreeSerifBoldItalic9pt7b);
  display.setCursor(0, 25);
  display.println("Warna Parabola.");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setFont(&FreeSerifItalic9pt7b);
  display.setCursor(0, 25);
  display.println("Warna Parabola.");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setFont(&FreeMonoOblique9pt7b);
  display.setCursor(0, 25);
  display.println("Warna Parabola.");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setFont(&FreeMono9pt7b);
  display.setCursor(0, 25);
  display.println("Warna Parabola.");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setFont(&FreeSansOblique9pt7b);
  display.setCursor(0, 25);
  display.println("Warna Parabola.");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setFont(&FreeSans9pt7b);
  display.setCursor(0, 25);
  display.println("Warna Parabola.");
  display.display();
  display.clearDisplay();

  // test teks`
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(15, 1);
  display.println("Warna Parabola");
  display.setCursor(20, 10);
  display.println("Grow Up Your");
  display.setCursor(10, 20);
  display.println("Programming Skill!!");
  display.display();
  delay(3000);
}
