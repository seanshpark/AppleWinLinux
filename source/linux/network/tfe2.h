#pragma once

bool tfeReceiveOnePacket(const uint8_t * mac, BYTE * buffer, int & len);
void tfeTransmitOnePacket(BYTE * buffer, const int len);
uint16_t readNetworkWord(const uint8_t * address);
