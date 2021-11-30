#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "packetProcessor.h"
#include "protocol.h"
#include "cobsEncoder.h"

/* Packet delimeter and COBS overhead byte will be added to the final packet */
static packetProcessorCallback onPacketReceived = NULL;
static packetProcessorCallback onPacketSend = NULL;

static void packetDecode(uint8_t packetData[], uint8_t decodedPacket[], uint32_t len)
{
    size_t decodedBytes = cobsDecode(packetData, len, decodedPacket);
    // if (decodedBytes != len) {
    //     assert(0);
    // }
}

static void packetEncode(uint8_t *packetData, uint8_t encodedPacket[], uint32_t len)
{
    size_t encodedBytes = cobsEncode(packetData, len, encodedPacket);
    // if (encodedBytes != len) {
    //     assert(0);
    // }
}

void packetProcessorInit(packetProcessorCallback receiveCb, packetProcessorCallback sendCb)
{
    onPacketReceived = receiveCb;
    onPacketSend = sendCb;
}

#define STOP_PACKET_FORMING (len = 0, packetLen = 0, formingPacket = false)
#define START_PACKET_FORMING (len = 0, packetLen = 0, formingPacket = true)
void packetProcessorReceiveByte(uint8_t byte)
{
    static uint8_t data[PACKET_MAX_SIZE];
    static bool formingPacket = false;
    static uint32_t len = 0;
    static uint8_t packetLen = 0;

    if (byte == PACKET_DELIMITER) {
        formingPacket = true;
    }
    
    if (formingPacket) {

        if (len < sizeof(data) / sizeof(data[0])) {
            data[len++] = byte;
        } else {
            len = packetLen = 0;
            formingPacket = false;
        }

        if (len == 4) {
            packetLen = byte;
        }

        if (len == packetLen) {
            uint8_t *decodedPacket = data;
            packetDecode(data, decodedPacket, len);
            if (onPacketReceived) {
                onPacketReceived((Packet *) decodedPacket);
            }
            len = packetLen = 0;
            formingPacket = false;
        }
    }
}

void packetProcessorReceiveMultipleBytes(uint8_t *data, uint32_t len)
{
    // TODO: ****
}

void packetProcessorSendPacket(Packet *packet)
{
    assert(packet->general.len);
    uint8_t *encodedPacket = (uint8_t *) packet;
    packetEncode((uint8_t *) packet, encodedPacket, packet->general.len);
    if (onPacketSend) {
        onPacketSend((Packet *) encodedPacket);
    }
}
