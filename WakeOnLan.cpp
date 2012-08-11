/*
	WakeOnLan by Ryan Esteves
	
	Send WOL magic packets
	
	To Use:
	(Arduino 1.0+)
		1. Initialize WakeOnLan with your EthernetUDP object.
		2. Send magic packet using the method 'send(byte* mac, byte port);'
		3. Repeat step 2 for as many packets as you would like to send.
	(Arduino 0023-)
		1. Initiate Udp
		2. Send magic packet using the static method 'send(byte* mac, byte port);'
		3. Repeat step 3 for as many packets as you would like to send.
*/

#include "WakeOnLan.h"

byte WakeOnLan::_ip[4] = {255,255,255,255};

#if defined(ARDUINO) && ARDUINO >= 100

void WakeOnLan::send(byte* mac, byte port, EthernetUDP udp) {

    byte preamble[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	
    byte i;

    udp.beginPacket(_ip, port);
	
    udp.write(preamble, sizeof preamble);
    
    for (i = 0; i < 16; i++)
	
      udp.write(mac, sizeof mac);
      
    udp.endPacket();

#else // ARDUINO not defined or ARDUINO < 100

void WakeOnLan::send(byte* mac, byte port) {

	byte magic_packet[102] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
	
	for (byte i = 6; i < 102; i++)
	{
		magic_packet[i] = mac[i%6];		
	}
	
	Udp.sendPacket(magic_packet, 102, _ip, port);	

#endif // #if defined(ARDUINO) && ARDUINO >= 100

}