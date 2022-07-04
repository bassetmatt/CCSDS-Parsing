#ifndef TMPACKET_H
#define TMPACKET_H

#include "int.h"
/**
 * Definitions for TM Packets
 * See documentation for more information
 */

/**
 * Primary header constants
 */

// Fixed value, useless
#define TM_PACKET_VERSION_NUMBER 0b000
// 0 for TM, 1 for TC
#define TYPE_PACKET_TM 0
// 1 means secondary header is use 
#define SECONDARY_HEADER_OFF 0
#define SECONDARY_HEADER_ON  1
// Defines the source of the packet, 11 bits, 0x0 (time)
// and Ob11111111111 (idle) forbidden for base
//TODO define
#define APID_BASE 0xABC // Random for now
#define APID_IDLE 0x7FF

// Max counter value
#define MAX_SEQUENCE_COUNTER 0x3FFF

//Grouping flags
#define TM_GROUPING_FLAGS 0b11

#define PACKET_MAX_LENGTH 65542U

/**
 * Secondary Header constants
 */
//PUS Version
#define PUS_VERSION_NUMBER 0b001

//Service Type
#define SERVICE_TYPE     3U
#define SERVICE_SUBTYPE 25U

// Time p-field
#define P_FIELD_TIMER 0x1E

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

} TMPacketPrimaryHeader;

/**
 * @brief Structure that represents the secondary header of a TM packet.
 * In the cases where it is defined.
 */
typedef struct TMPacketSecondaryHeader
{
    /* PUS version*/
    u8 versionPUS;
    /* Service type*/
    u8 serviceType;
    /* Service subtype*/
    u8 serviceSubType;
    /* Packet sub counter*/
    u8 subCounter;
    /* ID of the ddestination*/
    u8 destinationID;
    /* Time (CUC 7 bytes format) */
    CUCTime time;
} TMPacketSecondaryHeader;

/**
 * @brief Structure to represent the time with CUC format 
 */
typedef struct CUCTime
{
    /* Informations about the format, must be 0x1E */
    u8  pField;
    /* Number of seconds since 1958/1/1 */
    u32 coarseTime;
    /* Subseconds counter */
    u16 fineTime;
} CUCTime;

typedef struct TMPacket {
    TMPacketPrimaryHeader   pHeader;
    TMPacketSecondaryHeader sHeader;
    u8*                     data;
    u16                     crc;
} TMPacket;
/**
 * @brief Initialises the TM Primary Header with correct values
 * 
 * @param header    The adress of the header
 * @param idle      Is the packet idle or not
 * @param seqCount  The counter of sequences
 * @param length    The length of the packet to transmit
 */
void initPrimHeader(TMPacketPrimaryHeader* header, bool idle, u16* seqCount, u16 length);

/**
 * @brief Initialises the TM Secondary Header with correct values
 * 
 * @param header The adress of the header
 * @param time   The adress of the time handler
 */
void initSecondHeader(TMPacketSecondaryHeader* header, CUCTime* time);

/**
 * @brief Initialises the time counter with a given value
 * 
 * @param time   The adress of the timer
 * @param coarse The coarse time value
 * @param fine   The fine time value
 */
void initTime(CUCTime* time, u32 coarse, u16 fine);

/**
 * @brief Create a Packet from all the fields it must contain
 * 
 * @param packet The actual packet adress
 * @param pHead  The primary header
 * @param sHead  The secondary header, NULL if idle packet
 * @param data   The data containin the packet, its size must be the one
 *               defined in the primary header
 * @param crc    The crc checksum of the data
 */
void createPacket(TMPacket* packet,
                  TMPacketPrimaryHeader pHead, 
                  TMPacketSecondaryHeader sHead,
                  u8* data,
                  u16 crc);
#endif