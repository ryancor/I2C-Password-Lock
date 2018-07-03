// A5 -> A5 (TWI Pin)
// A4 -> A4 (I2C Pin)
// GND -> GND
#include <Wire.h>

void setup() {
  Serial.begin(9600);
  // join i2c bus (address optional for master)
  Wire.begin(); //sda_pin A4 ,scl_pin A5
  Serial.println("Beginning Bus Transfer");
}

byte x = 0;

void loop() {
  send_msg_to_slave((byte)x);

  x++;
  delay(5000);

  send_msg_to_slave("secret_message_h4ck3r");

  delay(5000);

  // This is where we request from slave if we got password right  
  Wire.requestFrom(8, 17); // device, how_many_bytes
  while(1 < Wire.available()) {
    char val = Wire.read();
    Serial.print(val);
  }
  Serial.println("");
}

void send_msg_to_slave(char *wordz) {
  Wire.beginTransmission(8); // transmit to device #8 (SLAVE_ADDRESS)
  Wire.write(wordz); // sends one byte
  Wire.endTransmission(); // stop transmitting
}

