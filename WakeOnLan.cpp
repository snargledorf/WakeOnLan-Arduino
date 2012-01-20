/*
	WakeOnLan by Ryan Esteves
	
	Send WOL magic packets
	
	To Use:
	(Arduino 1.0+)
		1. Initialize WakeOnLan with your EthernetUDP object.
		2. Send magic packet using the method 'send(byte* mac, byte port);'
		3. Repeat step 3 for as many packets as you would like to send.
	(Arduino 0023-)
		1. Initiate Udp
		2. Send magic packet using the static method 'send(byte* mac, byte port);'
		3. Repeat step 3 for as many packets as you would like to send.
*/

#include "WakeOnLan.h"

byte _magic_packet[102] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
byte _ip[4] = {255,255,255,255};

#if defined(ARDUINO) && ARDUINO >= 100
WakeOnLan::WakeOnLan(EthernetUDP Udp){
	_udp = Udp;
}
#endif

#if defined(ARDUINO) && ARDUINO >= 100
void WakeOnLan::send(byte* mac, byte port) {
	for (byte ix=6; ix<102; ix++)
	{
		_magic_packet[ix] = mac[ix%6];
	}
	_udp.beginPacket(_ip, port);
	_udp.write(_magic_packet, 102);
	_udp.endPacket();
}
#else
static void WakeOnLan::send(byte* mac, byte port) {
	for (byte ix=6; ix<102; ix++)
	{
		_magic_packet[ix] = mac[ix%6];
	}
	Udp.sendPacket(magic_packet, 102, _ip, port);
}
#endif