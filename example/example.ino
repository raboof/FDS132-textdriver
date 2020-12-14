/*
Thanks to Rudi Imbrechts (http://arduinows.blogspot.nl/) for the initial example.
*/  
#include "fds132text.h"     
#include <SPI.h>  //for some reason it only works if you include it here

#define n_frames 4
fdsScreen mainScreen[n_frames][3];

fdsString *changeThisString;



fdsChar mySmiley;
void setup() { 
  
    for (int f = 0; f < n_frames; f++) {
    mainScreen[f][0].setPins(150); // Uses the default from Rudi Imbrechts guide on how to set up the pins.
                          // You can set diffent pins, see fds132text.h for the arguments
    mainScreen[f][1].setPins(80); // Uses the default from Rudi Imbrechts guide on how to set up the pins.
                           // You can set diffent pins, see fds132text.h for the arguments
    mainScreen[f][2].setPins(20); // Uses the default from Rudi Imbrechts guide on how to set up the pins.
                           // You can set diffent pins, see fds132text.h for the arguments
    }
    initialiseLetters() ; // I haven't figured out the smart way to set all the letter variables to the value I want yet.

    mainScreen[0][0].addString("hello  world!",0);
    mainScreen[0][1].addString("hello  world!",0);
    mainScreen[0][2].addString("hello  world!",0);
    
    mainScreen[0][1].addString("esp32 fds132",100);
    mainScreen[0][2].addString("esp32 fds132",100);
    
    mainScreen[0][2].addString("-- raboof",225);

//--------------
    mainScreen[1][1].addString("hello  world!",0);
    mainScreen[1][2].addString("hello  world!",0);
    
    mainScreen[1][2].addString("esp32 fds132",100);
//--------------
    mainScreen[2][2].addString("hello  world!",0);
    
    mainScreen[2][0].addString("-- raboof",225);
    mainScreen[2][1].addString("-- raboof",225);
    mainScreen[2][2].addString("-- raboof",225);
//--------------

    mainScreen[3][0].addString("esp32 fds132",100);
    mainScreen[3][1].addString("esp32 fds132",100);
    mainScreen[3][2].addString("esp32 fds132",100);

    mainScreen[3][1].addString("-- raboof",225);
    mainScreen[3][2].addString("-- raboof",225);

    
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

    for (int f = 0; f < n_frames; f++) {
    mainScreen[f][0].update();
    mainScreen[f][1].update();
    mainScreen[f][2].update();
    }
}  

int t = 0;

void loop()  
{ 
  int f = (t / 20) % n_frames;
  for (int i = 0; i < 3; i++) {
    mainScreen[f][i].display();
  }
  t++;
  
    
    //int line = t % ((34*8)/3);
    //for (int row=0; row<7; row++) {
    //  for(int i=34/3; i>=0; i--) {
    //    mainScreen.output[row][i] = (i == (line / 8)) << (line % 8);
    //    mainScreen.output[row][i+((34)/3)] = (i == (line / 8)) << (line % 8);
    //    mainScreen.output[row][i+(2*(34)/3)] = (i == (line / 8)) << (line % 8);
    //  }
    //}
    //mainScreen.addString("x", (millis()/100) % 250);
    //mainScreen.update();
    
    //mainScreen.zeroDisplay();
    //mainScreen.addString("x", millis() % 250);
    //if (millis()>10000){
    //    changeThisString -> set("More than ever");
    //    mainScreen.update(); // if you don't update no new output buffer is calculated
    //}   
}  
