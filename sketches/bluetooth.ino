#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(11, 10); // RX, TX
int led = 13;
String command;
 
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT); 
  mySerial.begin(9600);
  Serial.println("Ready.");
}

void ledOn(int pin=13) {
   digitalWrite(pin, HIGH);
   Serial.println("Turning LED On");
}

void ledOff(int pin=13) {
   digitalWrite(pin, LOW);
   Serial.println("Turning LED Off");
}

String readBluetooth() {
  String data = String("");
  while (mySerial.available() > 0) {
    data += String((char) mySerial.read());
  }
  
  data.trim();
  
  return data; 
}
 
void loop() // run over and over
{
  command = readBluetooth();

  if (command.length() > 0) {    
    Serial.print("Command: ");
    Serial.println(command);
    
    if (command == "LED;On") {
      ledOn();
    }
    if (command.compareTo("LED;Off") == 0) {
      ledOff();      
    }
  }  
}
