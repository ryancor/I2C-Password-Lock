# I2C-Password-Lock
1. For this we are going to need:
	- Two Arduino Uno's
	- Three male2male jumper wires
2. This is how we are going to hook the I2C
	- Upload the master code to one MCU
	- Upload the reciever code to the second MCU
3. Example
	- ![alt text](https://www.arduino.cc/en/uploads/Tutorial/Master_Sender_bb.png)
4. On master, open up serial console =>
	- Baud Rate: 9600
	- Line: New Line
	- Example
	```
	Input Password: 
	Recieved Password => secret_message_h4ck3r
	Got the password
	```

## How to reverse and debug I2C
1. Using BusPirate
	- Attach Pins:
		-  BP's MOSI   ->    AVR's SDA
		-  BP's CLK    ->    AVR's SCL
		-  BP's GND    ->    AVR's GND
		-  BP's 5V     ->    AVR's 5V
	- Open up ZTerm on your MAC:
		- Set connection settings to 115200 BaudRate
		- Press 'enter' key on terminal
		- You should see a 'HiZ>' terminal
		- Press '4' for I2C
		- Press '3' for 100Mhz
		- Then press 'W' to power the clutch
		- Then hit '(2)' to sniff out values coming from either Master Arduino or Slave Arduino
		- You should start seeing hex values `[0x10] [0x41] [0x48]`
2. Using Adafruits USB to TTL Serial Cable - Debug / Console Cable
	- Instructions coming soon!
