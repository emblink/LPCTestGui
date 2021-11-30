#pragma once
#include <stdint.h>

#define PACKET_MAX_SIZE 100
#define PACKET_DELIMITER 0x00

typedef enum {
	PACKET_ID_LOG_MESSAGE = 1U,
	PACKET_ID_START,
	PACKET_ID_STOP,
	PACKET_ID_PROPERTY,
	PACKET_ID_PING,
	PACKET_ID_COUNT,
} PacketId;

typedef enum {
	PROPERTY_TRIGGER = 1U,
	PROPERTY_DEBUG_LOG,
} Property;

#pragma pack(push, 1)
typedef struct {
	uint8_t delimeter;
	uint8_t cobsOverhead;
	uint8_t id;
	uint8_t len;
	uint8_t number;
} Header;

typedef struct {
	uint16_t crc;
} Trailer;

typedef struct {
	uint8_t general[sizeof(Header)];
	uint16_t periodMin;
	uint16_t periodMax;
	uint32_t count;
	bool randomEnable;
	uint8_t trailer[sizeof(Trailer)];
} PacketStart;

typedef struct {
	uint8_t general[sizeof(Header)];
	uint8_t property;
	bool enable;
	uint8_t trailer[sizeof(Trailer)];
} PacketProperty;

typedef union {
	uint8_t data[PACKET_MAX_SIZE];
	Header general;
	PacketStart setup;
	PacketProperty property;
} Packet;
#pragma pack(pop)