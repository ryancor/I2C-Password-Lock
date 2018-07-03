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
  Wire.beginTransmission(8); // transmit to device #8 (SLAVE_ADDRESS)
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  x++;
  delay(5000);

  Wire.beginTransmission(8);
  Wire.write("secret_message_h4ck3r");
  Wire.endTransmission();

  delay(5000);
  
  Wire.requestFrom(8, 17); // device, how_many_bytes
  while(1 < Wire.available()) {
    char val = Wire.read();
    Serial.print(val);
  }
  Serial.println("");
}
