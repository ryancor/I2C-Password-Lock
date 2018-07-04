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
