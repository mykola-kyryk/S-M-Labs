#define trigPin 12

int distanceSensors[4];
int numberOfDistanceSensors;

void setup() {
  Serial.begin (9600);
  
  numberOfDistanceSensors = 4;
  distanceSensors[0] = 11;
  distanceSensors[1] = 10;
  distanceSensors[2] = 9;
  distanceSensors[3] = -1;  
  
  pinMode(trigPin, OUTPUT);
  
  for (int i = 0; i < numberOfDistanceSensors; i++) {
    if (distanceSensors[i] != -1) {
      pinMode(distanceSensors[i], INPUT);
    }
  }
  
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(200); // Added this line
}

void hc_sr04_trigger(int triggerPin, int delay=10) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(delay);
  digitalWrite(triggerPin, LOW);  
}

long hc_sr04_read(int echoPin) {
  return ( (pulseIn(echoPin, HIGH)/2) / 29.1 );
}

void loop() {
 
  for (int i = 0; i < numberOfDistanceSensors; i++) {
    if (distanceSensors[i] != -1) {
      hc_sr04_trigger(trigPin);
      Serial.print("#");
      Serial.print(i+1);
      Serial.print(": ");
      Serial.println(hc_sr04_read(distanceSensors[i]));
    }
  }
  
  delay(500);
}
