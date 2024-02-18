#include "hw1.h"

unsigned int src_addr = 0;
unsigned int dest_addr = 0;
unsigned int source_port = 0;
unsigned int dest_port = 0;
unsigned int frag_offset = 0;
unsigned int packet_len = 0;
unsigned int max_hop_count = 0;
unsigned int checksum = 0;
unsigned int compression_scheme = 0;
unsigned int traffic_class = 0;
int payload[10];
int payload_count = 0;  
void get_src_addr(unsigned char packet[]){
    //source address
    src_addr = packet[0] << 20;
    src_addr |= packet[1] << 12;
    src_addr |= packet[2] << 4;
    src_addr |= packet[3] >>4;
}
void get_dest_addr(unsigned char packet[]){
    //destination address
    dest_addr = (packet[3] & 0xF) << 24;
    dest_addr |= packet[4] << 16;
    dest_addr |= packet[5] << 8;
    dest_addr |= packet[6];
}

void get_source_port(unsigned char packet[]){
    //source port
    source_port |= packet[7] >>4;
}

void get_dest_port(unsigned char packet[]){
    //destination port
    dest_port |= (packet[7] & 0xF);
}

void get_frag_offset(unsigned char packet[]){
    //fragment offset
    frag_offset |= packet[8] << 6;
    frag_offset |= packet[9] >> 2;
}

void get_packet_len(unsigned char packet[]){
    //packet length
    packet_len |= (packet[9] & 0x3) << 12;
    packet_len |= packet[10] << 4;
    packet_len |= packet[11] >> 4;
}

void get_max_hop_count(unsigned char packet[]){
    //maximum hop count
    max_hop_count |= (packet[11] & 0xF) << 1;
    max_hop_count |= packet[12] >> 7;
}

void get_checksum(unsigned char packet[]){
    //checksum
    checksum |= (packet[12] & 0x7F) << 16; 
    checksum |= packet[13] <<8;
    checksum |= packet[14];
}

void get_compression_scheme(unsigned char packet[]){
    //compression scheme;
    compression_scheme |= packet[15] >> 6;
}

void get_traffic_class(unsigned char packet[]){
    //traffic class
    unsigned int traffic_class = 0;
    traffic_class |= (packet[15] & 0x3F);
}
void get_payload(unsigned char packet[]){
    //payload 
    for(unsigned int x = 16, y = 0; x <= packet_len-1; x+= 4, y++){
        payload[y] = packet[x] << 24;
        payload[y] |= packet[x+1] << 16;
        payload[y] |= packet[x+2] << 8;
        payload[y] |= packet[x+3]; 
        payload_count++;
    }
}
    
void print_packet_sf(unsigned char packet[]){
    get_src_addr(packet);
    get_dest_addr(packet);
    get_source_port( packet);
    get_dest_port( packet);
    get_frag_offset( packet);
    get_packet_len( packet);
    get_max_hop_count( packet);
    get_checksum( packet);
    get_compression_scheme( packet);
    get_traffic_class(packet);
    get_payload(packet);
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
    int result = 0;
    int payload_total;
    get_src_addr(packet);
    get_dest_addr(packet);
    get_source_port( packet);
    get_dest_port( packet);
    get_frag_offset( packet);
    get_packet_len( packet);
    get_max_hop_count( packet);
    get_compression_scheme( packet);
    get_traffic_class(packet);
    get_payload(packet);
    for(int x =0; x <= payload_count-1; x++){
        payload_total = payload_total + (abs(payload[x]));
    }
    result = src_addr + dest_addr + source_port + dest_port + frag_offset + packet_len + max_hop_count + compression_scheme + traffic_class + payload_total;
    return result; 

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
