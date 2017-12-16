// MagicDraw
// by Richard E. Barber
// 16 DEC 2017

#include <stdint.h>
#include <TouchScreen.h>   // see http://wiki.seeedstudio.com/wiki/File:TFT_Touch_Shield_libraries.zip
#include <TFT.h>

#ifdef SEEEDUINO
#define YP A2   // must be an analog pin, use "An" notation!
#define XM A1   // must be an analog pin, use "An" notation!
#define YM 14   // can be a digital pin, this is A0
#define XP 17   // can be a digital pin, this is A3 
#endif

#ifdef MEGA
#define YP A2   // must be an analog pin, use "An" notation!
#define XM A1   // must be an analog pin, use "An" notation!
#define YM 54   // can be a digital pin, this is A0
#define XP 57   // can be a digital pin, this is A3 
#endif 

int x,y,z;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup()
{

  Tft.init();  //init TFT library
  Tft.setDisplayDirect(UP2DOWN);
  Tft.drawString("MAGICDRAW BY RICHARD E BARBER",12,12,1,CYAN);
  randomSeed(analogRead(A0));
}

void loop()
{
  x= random(240);
  y= random(340);
  z= random(65535);
  Tft.setPixel(x,y,z);

  Point p = ts.getPoint();
  p.x = map(p.x, 130, 900, 240, 0);
  p.y = map(p.y, 93, 927, 320, 0);

  if (p.z > ts.pressureThreshhold) {
    Tft.drawCircle(p.x,p.y,12,p.z*500);
  }
}
