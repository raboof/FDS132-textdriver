/*
Thanks to Rudi Imbrechts (http://arduinows.blogspot.nl/) for the initial example.
*/  
#include "fds132text.h"     
#include <SPI.h>  //for some reason it only works if you include it here

#define n_frames 4
fdsScreen mainScreen[n_frames];

fdsString *changeThisString;

fdsChar mySmiley;
void setup() { 
    //Serial.begin(9600);
    Serial.begin(115200);
  
    for (int f = 0; f < n_frames; f++) {
      mainScreen[f].setPins(0, 1500, 0);
    }
    initialiseLetters();

    mainScreen[0].drawString(0, 0, "hello  world!", WHITE);
    mainScreen[0].drawString(20, 7, "esp32 fds132", LIGHTER);
    mainScreen[0].drawString(40, 14, "-- raboof", DARKER);

    mainScreen[1].drawString(0, 0, "hello  world!", LIGHTER);
    mainScreen[1].drawString(20, 7, "esp32 fds132", DARKER);

    mainScreen[2].drawString(0, 0, "hello  world!", DARKER);
    mainScreen[2].drawString(40, 14, "-- raboof", WHITE);

    mainScreen[3].drawString(20, 7, "esp32 fds132", WHITE);
    mainScreen[3].drawString(40, 14, "-- raboof", LIGHTER);

    //We also want a smiley
    // We already declared mySmiley globally, so it wouldn't cease to exist after the setup is gone
    // We can define it visually, and it helps if your editor lets you highlight 1
    // Note that the character starts at the left, you have to enter the mirror image
    mySmiley.character_map[0]=B00000000;
    mySmiley.character_map[1]=B00100010; 
    mySmiley.character_map[2]=B00000000; 
    mySmiley.character_map[3]=B01001001; 
    mySmiley.character_map[4]=B00100010; 
    mySmiley.character_map[5]=B00011100; 
    mySmiley.character_map[6]=B00000000;
    mySmiley.width=7;

    //mainScreen1.addString(&mySmiley,165); //We have to pass the address of mySmiley, not mySmiley itself

    Serial.print("start");
    //memset(mainScreen[0].output, 0, sizeof(mainScreen[0].output[0][0]) * 35 * 7);
    //memset(mainScreen[0].output_lsb, 0, sizeof(mainScreen[0].output_lsb[0][0]) * 35 * 7);
    //fdsChar* h = charTofdsChar('h');
    //fdsChar* e = charTofdsChar('e');
    //mainScreen[0][0].drawChar(0, 0, h, WHITE);
    //mainScreen[0][0].drawChar(h->width, 0, e, WHITE);
    //mainScreen[0].drawString(0, 0, "hello world!", WHITE);
    //mainScreen[0].drawString(0, 7, "esp32 fds132", LIGHTER);
    //mainScreen[0].drawString(0, 14, "faster grayscale", DARKER);
}  

int t = 0;

int start;

void loop()  
{ 
  
  if (t == 0) {
    start = micros();
  }
  if (t == 1000) {
    int duration = micros() - start;
    Serial.print("t = 1000, elapsed:");
    Serial.print(duration, DEC);
  }

  /*
  // 3 shades of 'grey':
  int f = (t / 3) % n_frames;
  for (int i = 0; i < 3; i++) {
    mainScreen[f].display();
  }
  */
  
  //mainScreen[0].drawPixel((t/20) % 300, 5, WHITE);
  mainScreen[0].display();
  //delayMicroseconds(1000);
  t++;
    
    //int line = t % ((34*8)/3);
    //for (int row=0; row<7; row++) {
    //  for(int i=34/3; i>=0; i--) {
    //    mainScreen[0][0].output[row][i] = (i == (line / 8)) << (line % 8);
    //    mainScreen[0][0].output[row][i+((34)/3)] = (i == (line / 8)) << (line % 8);
    //    mainScreen[0][0].output[row][i+(2*(34)/3)] = (i == (line / 8)) << (line % 8);
    //  }
    //}
    //mainScreen[0][0].display();
    
    //mainScreen.addString("x", (millis()/100) % 250);
    //mainScreen.update();
    
    //mainScreen.zeroDisplay();
    //mainScreen.addString("x", millis() % 250);
    //if (millis()>10000){
    //    changeThisString -> set("More than ever");
    //    mainScreen.update(); // if you don't update no new output buffer is calculated
    //}   
}  
