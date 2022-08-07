#include <SPI.h> //spi.
#include <Wire.h> // pendukung library spi.
#include <Adafruit_GFX.h> // pendukung library drivernya.
#include <Adafruit_SSD1306.h> // lib driver olednya.
//#include <Fonts/FreeSerif9pt7b.h> // lib fontnya.

#define SCREEN_WIDTH 128 // lebar piksel
#define SCREEN_HEIGHT 32 // tinggi piksel

// Deklarasi pin SCL dan SDA nya.
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin) --> ini tidak perlu di perhatikan.
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example
#define LOGO_HEIGHT   16 // abaikan saja.
#define LOGO_WIDTH    16 // // abaikan saja.

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) // --- set Address i2cnya. JANGAN DI GANTI !!!
  { 
    // Address 0x3C for 128x32
    Serial.println(F("Addres i2cnya Salah!"));
    for (;;); // Don't proceed, loop forever
  }
  /*
   * contoh program tampil text dan test font di next layer.
   * layer 1 = menampilkan text
   * layer 2 = menampilkan text dan test font
   */
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(10, 1);
  display.println("> Warna Parabola. <");
  display.setCursor(20, 10);
  display.println("Oled 0,96 Inci.");
  display.setCursor(10, 20);
  display.println(" >> YELLOW BLUE << ");
  /*
  delay(4000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(10, 1);
  display.println("> Warna Parabola. <");
  display.setFont(&FreeSerif9pt7b);
  display.setTextSize(1);
  display.setCursor(20, 10);
  display.println("Oled 0.96 Inch."); //15char
  display.display();
  */
}

void loop() 
{
  
}
