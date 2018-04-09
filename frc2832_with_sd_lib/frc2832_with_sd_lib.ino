
#include <Adafruit_NeoPixel.h>
#include <SD.h>
#include <SPI.h>

//Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(39, 9, 6,

File configfile;
int pass = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(39 * 9, 6, NEO_GRB + NEO_KHZ800);


void setup()
{
  strip.begin();
  Serial.begin(9600);
  Serial.begin(9600);
  const int chipSelect = BUILTIN_SDCARD;
  SD.begin(chipSelect);

}

void display_image(String fname)
{
  int count = 0;
  char buf[fname.length() + 1];
  fname.toCharArray(buf, fname.length() + 1);
  File img = SD.open(buf);
  while (img.available()) {

    int r = img.read();
    int g = img.read();
    int b = img.read();
    Serial.print(count);
    Serial.print(r);
    Serial.print(g);
    Serial.println(b);
    if (count < 39) {
      strip.setPixelColor(38 - count, r, g, b);
    }
    else if (count < 39 * 2)
    {
      strip.setPixelColor(count, r, g, b);
    }
    else if (count < 39 * 3)
    {
      strip.setPixelColor((abs(count - 39 * 3)) + 39 * 2 - 1 , r, g, b);
    }
    else if (count < 39 * 4)
    {
      strip.setPixelColor(count, r, g, b);
    }
    else if (count < 39 * 5)
    {
      strip.setPixelColor((abs(count - 39 * 5)) + 39 * 4 - 1 , r, g, b);
    }
    else if (count < 39 * 6)
    {
      strip.setPixelColor(count, r, g, b);
    }
    else if (count < 39 * 7)
    {
      strip.setPixelColor((abs(count - 39 * 7)) + 39 * 6 - 1 , r, g, b);
    }
    else if (count < 39 * 8)
    {
      strip.setPixelColor(count, r, g, b);
    }
    else if (count < 39 * 9)
    {
      strip.setPixelColor((abs(count - 39 * 9)) + 39 * 8 - 1 , r, g, b);
    }
    //strip.setPixelColor(count,r,g,b);
    count = count + 1;
  }
  strip.show();
}



void loop()
{
  while (true) {
    configfile = SD.open("main.csv");
    if (configfile) {
      // read from the file until there's nothing else in it:
      while (configfile.available()) {
        String fname = configfile.readStringUntil(',');
        int fdelay = configfile.readStringUntil('\n').toInt();
        display_image(fname);

        delay(fdelay);
        //char* a = Text;
        Serial.println(fname + " " + fdelay);
      }
      // close the file:
      configfile.close();
    }


  }
}

