String voice;
#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); //TX, RX respetively
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
}

// the loop function runs over and over again forever
void loop() 
{
  while (BT.available())
 { //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable
    char c = BT.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0){
    if ((voice == "*alphabet A")||(voice == "*alphabet a")){
      led_off();
      digitalWrite(9,HIGH);
      }
    else if ((voice == "*alphabet B")||(voice == "*alphabet b")){
      led_off();
      digitalWrite(9,HIGH);
      digitalWrite(8,HIGH);
      }  
    else if ((voice == "*alphabet C")||(voice == "*alphabet c")){
      led_off();
      digitalWrite(9,HIGH);
      digitalWrite(4,HIGH);
      }  
    else if ((voice == "*alphabet D")||(voice == "*alphabet d")){
      led_off();
      digitalWrite(9,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      }
    else if ((voice == "*alphabet E")||(voice == "*alphabet e")){
      led_off();
      digitalWrite(9,HIGH);
      digitalWrite(5,HIGH);
      }
  voice=""; //Reset the variable after initiating
  }
}
void led_off()
{
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
delay(1000);
}