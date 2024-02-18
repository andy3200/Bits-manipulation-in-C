#include "hw1.h"

void print_packet_sf(unsigned char packet[])
{   
    //source address
    unsigned int src_addr = 0;
    src_addr = packet[0] << 20;
    src_addr |= packet[1] << 12;
    src_addr |= packet[2] << 4;
    src_addr |= packet[3] >>4;

    //destination address
    unsigned int dest_addr = 0;
    dest_addr = (packet[3] & 0xF) << 24;
    dest_addr |= packet[4] << 16;
    dest_addr |= packet[5] << 8;
    dest_addr |= packet[6];
    
    //source port
    unsigned int source_port = 0;
    source_port |= packet[7] >>4;

    //destination port
    unsigned int dest_port = 0;
    dest_port |= (packet[7] & 0xF);

    //fragment offset
    unsigned int frag_offset = 0;
    frag_offset |= packet[8] << 6;
    frag_offset |= packet[9] >> 2;

    //packet length
    unsigned int packet_len = 0;
    packet_len |= (packet[9] & 0x3) << 12;
    packet_len |= packet[10] << 4;
    packet_len |= packet[11] >> 4;

    //maximum hop count
    unsigned int max_hop_count = 0;
    max_hop_count |= (packet[11] & 0xF) << 1;
    max_hop_count |= packet[12] >> 7;

    //checksum
    unsigned int checksum = 0;
    checksum |= (packet[12] & 0x7F) << 16; 
    checksum |= packet[13] <<8;
    checksum |= packet[14];

    //compression scheme;
    unsigned int compression_scheme = 0;
    compression_scheme |= packet[15] >> 6;

    //traffic class
    unsigned int traffic_class = 0;
    traffic_class |= (packet[15] & 0x3F);

    //payload
    int payload[10];
    int payload_count = 0; 
    for(unsigned int x = 16, y = 0; x <= packet_len-1; x+= 4, y++){
        payload[y] = packet[x] << 24;
        payload[y] |= packet[x+1] << 16;
        payload[y] |= packet[x+2] << 8;
        payload[y] |= packet[x+3]; 
        payload_count++;
    }

    //printing

    printf("Source Address: %d\n", src_addr);
    printf("Destination Address: %d\n", dest_addr);
    printf("Source Port: %d\n", source_port);
    printf("Destination Port: %d\n", dest_port);
    printf("Fragment Offset: %d\n", frag_offset);
    printf("Packet Length: %d\n", packet_len);
    printf("Maximum Hop Count: %d\n", max_hop_count);
    printf("Checksum: %d\n", checksum);
    printf("Compression Scheme: %d\n", compression_scheme);
    printf("Traffic Class: %d\n", traffic_class);
    printf("Payload:");
    for(int x =0; x <= payload_count-1; x++){
        printf(" %d", payload[x]);
    }
    printf("\n");
}

unsigned int compute_checksum_sf(unsigned char packet[])
{
    (void)packet;
    return -1;
}

unsigned int reconstruct_array_sf(unsigned char *packets[], unsigned int packets_len, int *array, unsigned int array_len) {
    (void)packets;
    (void)packets_len;
    (void)array;
    (void)array_len;
    return -1;
}

unsigned int packetize_array_sf(int *array, unsigned int array_len, unsigned char *packets[], unsigned int packets_len,
                          unsigned int max_payload, unsigned int src_addr, unsigned int dest_addr,
                          unsigned int src_port, unsigned int dest_port, unsigned int maximum_hop_count,
                          unsigned int compression_scheme, unsigned int traffic_class)
{
    (void)array;
    (void)array_len;
    (void)packets;
    (void)packets_len;
    (void)max_payload;
    (void)src_addr;
    (void)dest_addr;
    (void)src_port;
    (void)dest_port;
    (void)maximum_hop_count;
    (void)compression_scheme;
    (void)traffic_class;
    return -1;
}
