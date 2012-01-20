/*
	WakeOnLan by Ryan Esteves
	
	Send WOL magic packets
	
	To Use:
		1. Initiate Udp using 'Udp.begin(<port>);'
		2. Send magic packet using the static method 'send(byte* mac, byte port);'
		3. Repeat step 3 for as many packets as you would like to send.
*/
#ifndef wakeonloan_h
#define wakeonloan_h

#if defined(ARDUINO) && ARDUINO >= 100
# include "EthernetUdp.h"
# include "Arduino.h"
#else
# include "Udp.h"
# include "WProgram.h"
#endif

class WakeOnLan {
	public:
#if defined(ARDUINO) && ARDUINO >= 100
		WakeOnLan(EthernetUDP Upd);
		// Send a magic packet to the provided mac address on the specified port
		void send(byte* mac, byte port);
#else
		WakeOnLan();	
		// Send a magic packet to the provided mac address on the specified port
		static void send(byte* mac, byte port);
#endif

		
	private:
#if defined(ARDUINO) && ARDUINO >= 100
		EthernetUDP _udp;
#endif
		byte _ip[4];
		byte _magic_packet[102];
		
};

#endif