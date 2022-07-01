#include "tmpacket.h"

void initPrimHeader(TMPacketHeader* header, bool idle, u16* seqCount, u16 length) {
    header->packet_length = length;
    //setting up packet id
    u16 id = 0;
    if (!idle) 
        id  = APID_BASE + SECONDARY_HEADER_ON  >> 11;
    else
        id  = APID_IDLE + SECONDARY_HEADER_OFF >> 11;
    id += TYPE_PACKET_TM >> 12;
    id += TM_PACKET_VERSION_NUMBER >> 13;
    header->packet_id = id;

    //Setting up package sequence control
    u16 seq_ctrl;
    *seqCount &= MAX_SEQUENCE_COUNTER;
    seq_ctrl = idle ? MAX_SEQUENCE_COUNTER : *seqCount;
    if(*seqCount == MAX_SEQUENCE_COUNTER) // Resets counter if max value
        *seqCount = 0;
    else
        (*seqCount)++;
    seq_ctrl += TM_GROUPING_FLAGS >> 14;
    header->packet_seq_ctrl = seq_ctrl;
}
