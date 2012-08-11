/*
	WakeOnLan by Ryan Esteves
	
	Send WOL magic packets
*/

#ifndef wakeonloan_h
#define wakeonloan_h

#if defined(ARDUINO) && ARDUINO >= 100 // Arduino 1.0+ compatibility

#include "Arduino.h"
#include "EthernetUdp.h"

#else // ARDUINO not defined or ARDUINO < 100

#include "WProgram.h"
#include "Udp.h"

#endif // ARDUINO >= 100

class WakeOnLan {

	public:		
		// Send a magic packet to the provided mac address on the specified port
#if defined(ARDUINO) && ARDUINO >= 100 // Arduino 1.0+ compatibility
		static void send(byte* mac, byte port, EthernetUDP udp);
#else
		static void send(byte* mac, byte port);
#endif
		
	private:
		
		static byte _ip[4];
		
};

#endif // #ifndef wakeonloan_h