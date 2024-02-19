#include "hw1.h"

unsigned int source_addr = 0;
unsigned int destination_addr = 0;
unsigned int source_port = 0;
unsigned int destination_port = 0;
unsigned int fragment_offset = 0;
unsigned int packet_len = 0;
unsigned int max_hop_count = 0;
unsigned int checksum = 0;
unsigned int compress_scheme = 0;
unsigned int traff_class = 0;
int payload[100];
int payload_count = 0;  
void get_src_addr(unsigned char packet[]){
    //source address
    source_addr = packet[0] << 20;
    source_addr |= packet[1] << 12;
    source_addr |= packet[2] << 4;
    source_addr |= packet[3] >>4;
}
void get_dest_addr(unsigned char packet[]){
    //destination address
    destination_addr = (packet[3] & 0xF) << 24;
    destination_addr |= packet[4] << 16;
    destination_addr |= packet[5] << 8;
    destination_addr |= packet[6];
}

void get_source_port(unsigned char packet[]){
    //source port
    source_port = 0;
    source_port |= packet[7] >>4;
}

void get_dest_port(unsigned char packet[]){
    //destination port
    destination_port = 0;
    destination_port |= (packet[7] & 0xF);
}

void get_frag_offset(unsigned char packet[]){
    //fragment offset
    fragment_offset = 0;
    fragment_offset |= packet[8] << 6;
    fragment_offset |= packet[9] >> 2;
}

void get_packet_len(unsigned char packet[]){
    //packet length
    packet_len = 0;
    packet_len |= (packet[9] & 0x3) << 12;
    packet_len |= packet[10] << 4;
    packet_len |= packet[11] >> 4;
}

void get_max_hop_count(unsigned char packet[]){
    //maximum hop count
    max_hop_count = 0;
    max_hop_count |= (packet[11] & 0xF) << 1;
    max_hop_count |= packet[12] >> 7;
}

void get_checksum(unsigned char packet[]){
    //checksum
    checksum = 0;
    checksum |= (packet[12] & 0x7F) << 16; 
    checksum |= packet[13] <<8;
    checksum |= packet[14];
}

void get_compression_scheme(unsigned char packet[]){
    //compression scheme;
    compress_scheme = 0; 
    compress_scheme |= packet[15] >> 6;
}

void get_traffic_class(unsigned char packet[]){
    //traffic class
    traff_class = 0;
    traff_class |= (packet[15] & 0x3F);
}
void get_payload(unsigned char packet[]){
    payload_count = 0;
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
    printf("Source Address: %d\n", source_addr);
    printf("Destination Address: %d\n", destination_addr);
    printf("Source Port: %d\n", source_port);
    printf("Destination Port: %d\n", destination_port);
    printf("Fragment Offset: %d\n", fragment_offset);
    printf("Packet Length: %d\n", packet_len);
    printf("Maximum Hop Count: %d\n", max_hop_count);
    printf("Checksum: %d\n", checksum);
    printf("Compression Scheme: %d\n", compress_scheme);
    printf("Traffic Class: %d\n", traff_class);
    printf("Payload:");
    for(int x =0; x <= payload_count-1; x++){
        printf(" %d", payload[x]);
    }
    printf("\n");
}

unsigned int compute_checksum_sf(unsigned char packet[])
{   
    unsigned int result = 0;
    unsigned int payload_total = 0;
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
    result = (source_addr + destination_addr + source_port + destination_port + fragment_offset + packet_len + max_hop_count + compress_scheme + traff_class + payload_total)% (8388607);
    return result; 

}

unsigned int reconstruct_array_sf(unsigned char *packets[], unsigned int packets_len, int *array, unsigned int array_len) {
    unsigned int insert_count = 0; 
    for(size_t x = 0; x <= packets_len-1; x++){
        get_frag_offset(packets[x]); //get the fragment offset 
        unsigned int start_index = (fragment_offset / (int) 4); //the starting index at the array to be put in 
        get_checksum(packets[x]); //get the original checksum of the current packet 
        unsigned int calculated_checksum = compute_checksum_sf(packets[x]);
        if((checksum == calculated_checksum) && (start_index <= array_len-1)){// start putting in stuff into the array 
            get_payload(packets[x]);
            for(size_t y = start_index, z = 0; y <= array_len-1; y++, z++){
                array[y] = payload[z];
                insert_count++; 
            }
        }
    }
    return insert_count;
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
