#include <Arduino.h>
#include "GFXDisplay.h"

const int AnzahlZeilen = 19;
static char scrolltext[AnzahlZeilen][17] ={
                                  { "                "},
                                  { "                "},
                                  { " ---- ACP ----- "},
                                  { " Technologietag "},
                                  { " ---- 2019 ---- "},
                                  { "                "},
                                  { "  Vielen Dank   "},
                                  { "   fuer Ihr     "},
                                  { " Interesse an   "},
                                  { "  einem ACP-    "},
                                  { "   Workshop.    "},
                                  { "                "},
                                  { " Wir freuen uns "},
                                  { " auf Ihre Teil- "},
                                  { " nahme.         "},
                                  { "                "},
                                  { "                "},
                                  { "                "},
                                  { "                "},
                                  }; 

// in http://javl.github.io/image2cpp/ auf vertical stellen und anschließend HexToDez
unsigned char QRBMP[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,96,224,192,0,0,0,240,0,0,240,0,0,0,128,128,128,128,0,0,0,0,0,0,32,224,32,0,0,128,128,128,128,128,0,128,224,176,144,0,0,128,128,128,0,0,0,128,128,128,128,0,0,0,0,0,0,240,128,128,128,128,0,0,144,0,0,0,128,128,128,128,0,0,128,128,128,128,0,0,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,30,7,4,4,7,30,16,0,31,0,0,31,0,0,15,26,18,18,27,2,0,0,0,0,0,16,31,16,0,0,31,1,0,0,31,0,0,31,0,0,0,15,25,16,16,15,6,9,19,18,20,29,12,0,0,0,0,0,31,1,0,0,31,0,0,31,0,0,15,26,18,18,27,2,0,31,1,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,252,252,12,12,204,204,204,204,204,204,204,204,204,204,12,12,252,252,60,60,60,60,12,12,204,204,12,12,252,252,12,12,204,204,204,204,204,204,204,204,204,204,12,12,252,252,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,0,0,255,255,192,192,192,192,192,192,255,255,0,0,255,255,51,51,195,195,252,252,60,60,192,192,255,255,0,0,255,255,192,192,192,192,192,192,255,255,0,0,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,204,204,12,12,12,12,204,204,204,204,252,252,204,204,207,207,204,204,51,51,252,252,207,207,60,60,207,207,252,252,12,12,252,252,204,204,252,252,204,204,60,60,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,192,192,207,207,195,195,255,255,240,240,252,252,204,204,252,252,0,0,195,195,15,15,15,15,192,192,240,240,255,255,63,63,3,3,240,240,51,51,240,240,63,63,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,0,0,252,252,12,12,12,12,12,12,252,252,0,0,255,255,12,12,12,12,51,51,192,192,252,252,192,192,252,252,204,204,51,51,60,60,240,240,192,192,207,207,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,192,192,207,207,204,204,204,204,204,204,207,207,192,192,255,255,192,192,192,192,240,240,240,240,240,240,243,243,255,255,255,255,207,207,243,243,243,243,207,207,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char AZUREBMP[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,192,224,240,56,12,192,240,224,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,224,224,224,224,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,224,248,252,254,255,255,63,15,3,64,248,254,255,255,255,255,255,252,248,224,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,240,252,127,31,3,3,15,127,254,240,192,0,0,0,0,8,28,28,28,28,156,220,252,124,60,28,0,0,0,252,252,248,0,0,0,0,0,0,252,252,248,0,0,0,0,252,252,252,112,56,28,28,28,0,128,224,240,248,28,28,12,12,28,248,248,240,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,224,248,252,255,255,255,255,63,15,3,0,0,0,0,0,0,3,7,15,31,63,127,255,255,255,255,255,252,240,224,128,0,0,0,0,0,0,64,112,124,127,31,7,7,7,7,7,7,7,7,31,127,126,120,64,0,96,112,120,126,127,103,99,97,96,96,96,0,0,0,63,127,127,240,224,224,96,96,56,127,127,127,0,0,0,0,127,127,127,0,0,0,0,0,0,15,63,127,123,243,227,227,227,227,99,99,35,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,8,8,8,8,8,12,12,12,12,12,14,14,14,14,14,15,15,15,15,15,15,15,15,15,15,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


GFXDisplay display;

void setup() {
  display.init();
  display.draw(0,0,128,8,AZUREBMP);
  delay(2000);
}

void loop() {
  display.clear();
  int i;
  int zeile;
  for (zeile=0;zeile+4<AnzahlZeilen;zeile++) {
    for (i=0;i<10;i++) {
      display.clear();
      display.drawText(0,8-i, scrolltext[zeile]);
      display.drawText(0,18-i, scrolltext[zeile+1]);
      display.drawText(0,28-i, scrolltext[zeile+2]);
      display.drawText(0,38-i, scrolltext[zeile+3]);
      display.drawText(0,48-i, scrolltext[zeile+4]);
      display.drawText(0,58-i, scrolltext[zeile+5]);
      display.flush();
      }
    }    
  display.clear();
  display.draw(0,0,128,8,QRBMP);
  delay(5000);
  display.drawText(0,38, " aka.ms/ACPIoT  ");
  display.flush();
  delay(3000);
  }
