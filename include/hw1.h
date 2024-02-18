/*
ANY CHANGES MADE TO THIS FILE WILL BE DISCARDED DURING GRADING!
*/

#ifndef HW1_H
#define HW1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void get_src_addr(unsigned char packet[]);
void get_dest_addr(unsigned char packet[]);
void get_source_port(unsigned char packet[]);
void get_dest_port(unsigned char packet[]);
void get_frag_offset(unsigned char packet[]);
void get_packet_len(unsigned char packet[]);
void get_max_hop_count(unsigned char packet[]);
void get_checksum(unsigned char packet[]);
void get_compression_scheme(unsigned char packet[]);
void get_traffic_class(unsigned char packet[]);
void get_payload(unsigned char packet[]);
void print_packet_sf(unsigned char packet[]);
unsigned int compute_checksum_sf(unsigned char packet[]);
unsigned int reconstruct_array_sf(unsigned char *packets[], unsigned int packets_len, int *array, unsigned int array_len);
unsigned int packetize_array_sf(int *array, unsigned int array_len, unsigned char *packets[], unsigned int packets_len,
                          unsigned int max_payload, unsigned int src_addr, unsigned int dest_addr, 
                          unsigned int src_port, unsigned int dest_port, unsigned int maximum_hop_count,
                          unsigned int compression_scheme, unsigned int traffic_class);

#endif // HW1_H
