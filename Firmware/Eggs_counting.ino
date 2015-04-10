#include <SerialCommand.h>


SerialCommand sCmd;


int ledArray[] = {5,6,9};


void setup(){
  
    Serial.begin(9600);
    for (int i=0;i<3;i++){
      pinMode(ledArray[i],OUTPUT);
    }
    sCmd.addCommand("Led", led_controller); // Takes three arguments, 
     Serial.println("Ready!");                                       // 0 or 1 for each led, i.e "Led 0 1 0" (switch on the topleftLed)
}

void led_controller(){
  for (int i=0;i<3;i++){
    char *arg;
    arg = sCmd.next();
    if (arg != NULL && atoi(arg) == 1){
        digitalWrite(ledArray[i], HIGH);
        Serial.print(i);
        Serial.print(",ON,");
    }else{
        digitalWrite(ledArray[i], LOW);
        Serial.print(i);
        Serial.print(",OFF,");
    }
  }
}

void loop(){
  sCmd.readSerial();
}
