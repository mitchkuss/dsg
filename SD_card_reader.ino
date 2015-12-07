#include <SD.h>                      // need to include the SD library
//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>

TMRpcm tmrpcm;   // create an object for use in this sketch


void setup(){
  pinMode(2,INPUT_PULLUP);
  pinMode(9, OUTPUT);
  digitalWrite(9,LOW);
  
  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  //tmrpcm.play("use.wav"); //the sound file "music" will play each time the arduino powers up, or is reset
  Serial.println("Done setting up");
}



void loop(){  
 
    
    if(digitalRead(2) == LOW){ //send the letter p over the serial monitor to start playback
      //Serial.println("Playing music");
      tmrpcm.play("use.raw");
    }
 

}
