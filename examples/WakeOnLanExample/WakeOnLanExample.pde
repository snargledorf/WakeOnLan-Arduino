#include "WakeOnLan.h"
#include "SPI.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "EthernetUdp.h"
EthernetUDP Udp;
#else
#include "Udp.h"
#endif


void setup()
{
	Serial.begin(9600);

	Udp.begin(7);
}

void loop()
{
	Serial.println("Sending WOL Packet...");
	delay(1000);
	
	byte mac[6] = { 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6 };

#if defined(ARDUINO) && ARDUINO >= 100
	WakeOnLan::send(mac, 6, Udp);
#else
	WakeOnLan::send(mac, 6);
#endif
}
