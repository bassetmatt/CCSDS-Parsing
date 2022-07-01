#include "int.h"
/**
 * Definitions for TM Packets
 * See documentation for more information
 */

/**
 * Primary header constants
 */

// Fixed value, useless
#define VERSION_NUMBER 0b000
// 0 for TM, 1 for TC
#define TYPE_PACKET_TM 0
// 1 means secondary header is use 
#define SECONDARY_HEADER_UFF 0
#define SECONDARY_HEADER_ON  1
// Defines the source of the packet, 11 bits, 0x0 (time)
// and Ob11111111111 (idle) forbidden for base
//TODO define
#define APID_BASE 0xABC // Random for now
#define APID_IDLE 0x7FF

#define PACKET_MAX_LENGTH 65542U

/**
 * Secondary Header constants
 */
//PUS Version
#define PUS_VERSION_NUMBER 0b001

//Service Type
#define SERVICE_TYPE     3U
#define SERVICE_SUBTYPE 25U

// Time, CUC format
#define TIME 0x0000000 //TODO implement
/**
 * @brief Structure that represents the primary header of
 * a TM  packet with the 6 bytes of information it shall contain
 */
typedef struct TMPacketPrimaryHeader
{
    /* Contains id flags*/
    u16 packet_id;
    /* Contins the sequence counter*/
    u16 packet_seq_ctrl;
    /* Indicates the lenth (in bytes) of the following packet minus 1*/
    u16 packet_length;

} TMPacketHeader;

/**
 * @brief Initializes the header with correct values
 * 
 * @param header The adress of the header
 * @param idle Is the packet idle or not
 * @param length The length of the packet to transmit
 */
void initPrimHeader(TMPacketHeader* header, bool idle, u16 length);
