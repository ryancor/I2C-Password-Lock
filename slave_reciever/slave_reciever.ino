// A5 -> A5 (TWI Pin)
// A4 -> A4 (I2C Pin)
// GND -> GND
#include <Wire.h>

#define LED_BUTTON    13
String str_recieved;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8 (SLAVE_ADDR_SET_AT_MASTER)
  Wire.onReceive(receiveEvent); // register event -> master sending to slave
  Wire.onRequest(requestEvent); // register event -> sending back to master
  
  Serial.begin(9600);           // start serial for output
  pinMode(LED_BUTTON, OUTPUT);
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    str_recieved += c;
    Serial.print(c);         // print the character
  }
  Serial.println("");
  
  if(str_recieved.substring(14,18) == "_h4c") {
    digitalWrite(LED_BUTTON, HIGH);
  } else {
    digitalWrite(LED_BUTTON, LOW);
  }
  Serial.println("");
  
  int x = Wire.read();    // receive byte as an integer
  if(x == 88) {
    Serial.println("X IS MY BIRTHDAY");
  }
  Serial.print("Number of tries: ");
  Serial.println(x); // print the integer
}

void requestEvent() {
  if(digitalRead(LED_BUTTON) == HIGH) {
    Wire.write("Got the password!"); 
  } else {
    Wire.write("Nice Try!");
  } 
}
