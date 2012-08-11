## WakeOnLan-Arduino ##

A simple class for sending Wake On Lan packets using the Arduino.
	
To Use:

	(Arduino 1.0+)
		1. Create an EthernetUDP object.
		2. Start Udp using the EthernetUDP objects begin method.

	(Arduino 0023-)
		1. Initiate Udp using 'Udp.begin'.

	(Both)
		1. Send magic packet using the static 'send' method;
			1a. Arduino 1.0+ 'send(byte* mac, byte port, EthernetUDP udp)'
			1b. Arduino 0023- 'send(byte* mac, byte port)'
		2. Repeat step 1 for as many packets as you would like to send.