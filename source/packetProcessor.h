#pragma once
#include <stdint.h>
#include "protocol.h"

typedef void (* packetProcessorCallback)(Packet *packet);

void packetProcessorInit(packetProcessorCallback receiveCb, packetProcessorCallback sendCb);

void packetProcessorReceiveByte(uint8_t byte);

void packetProcessorReceiveMultipleBytes(uint8_t *data, uint32_t len);

void packetProcessorSendPacket(Packet *packet);