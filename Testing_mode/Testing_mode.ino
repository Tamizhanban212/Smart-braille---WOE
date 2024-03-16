String voice;
#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); //TX, RX respetively
const String le[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
}

// the loop function runs over and over again forever
void loop() 
{
  A();
  B();
  C();
  D();
}

void A()
{
  voice="";
  while (BT.available())
 { //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = BT.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }
  digitalWrite(9,HIGH);
  if (voice.length() > 0){
    if ((voice == "*alphabet A")||(voice == "*alphabet a")){
      digitalWrite(10,HIGH);
      delay(1000);
      led_off();
      delay(1000);
    }
    else {
      digitalWrite(10,HIGH);
      delay(250);
      digitalWrite(10,LOW);
      delay(250);
      digitalWrite(10,HIGH);
      delay(250);
      digitalWrite(10,LOW);
      delay(250);     
      voice="";
      A();
    }
  }
  else {
    voice="";
    A();
  }  
}

void B()
{
  voice="";
  while (BT.available())
 { //Check if there is an available byte to read
     delay(100); //Delay added to make thing stable 
    char c = BT.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  if (voice.length() > 0){
    if ((voice == "*alphabet B")||(voice == "*alphabet b")){
      digitalWrite(10,HIGH);
      delay(1000);
      led_off();
      delay(1000);
    }
    else {
      digitalWrite(10,HIGH);
      delay(250);
      digitalWrite(10,LOW);
      delay(250);
      digitalWrite(10,HIGH);
      delay(250);
      digitalWrite(10,LOW);
      delay(250);  
      voice="";
      B();
    }
  }
  else {
    voice="";
    B();
  }  
}

void C()
{
  voice="";
  while (BT.available())
 { //Check if there is an available byte to read
     delay(100); //Delay added to make thing stable 
    char c = BT.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }
  digitalWrite(9,HIGH);
  digitalWrite(4,HIGH);
  delay(1000);
  if (voice.length() > 0){
    if ((voice == "*alphabet C")||(voice == "*alphabet c")){
      digitalWrite(10,HIGH);
      delay(1000);
      led_off();
      delay(1000);
    }
    else {
      digitalWrite(10,HIGH);
      delay(250);
      digitalWrite(10,LOW);
      delay(250);
      digitalWrite(10,HIGH);
      delay(250);
      digitalWrite(10,LOW);
      delay(250);      
      voice="";
      C();
    }
  }
  else {
    voice="";
    C();
  }  
}

void D()
{
  voice="";
  while (BT.available())
 { //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = BT.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }
  digitalWrite(9,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  if (voice.length() > 0){
    if ((voice == "*alphabet D")||(voice == "*alphabet d")){
      digitalWrite(10,HIGH);
      delay(1000);
      led_off();
      delay(1000);
    }
    else {
      digitalWrite(10,HIGH);
      delay(250);
      digitalWrite(10,LOW);
      delay(250);
      digitalWrite(10,HIGH);
      delay(250);
      digitalWrite(10,LOW);
      delay(250);  
      voice="";
      D();
    }

  }
  else {
    voice="";
    D();
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
digitalWrite(10,LOW);
delay(1000);
}