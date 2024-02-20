#include <stdio.h>
#include "hw1.h"

int main() {
    int* inputt = (int*)malloc(18 * sizeof(int));

    // Initialize the array
    for (int i = 0; i < 18; i++) {
        inputt[i] = (i + 1) * 10;  // Initializing with values 10, 20, 30, ..., 180
    }

    inputt[0] = -1;
    inputt[1] = -2;

    unsigned char *packetss[5];
    packetize_array_sf(inputt,18,packetss,5,16,12346,964321,12,3,16,0,58);
    print_packet_sf(packetss[0]);
    print_packet_sf(packetss[1]);
    print_packet_sf(packetss[2]);
    print_packet_sf(packetss[3]);
    print_packet_sf(packetss[4]);
    return 0;
}
