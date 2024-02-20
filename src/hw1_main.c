#include <stdio.h>
#include "hw1.h"

int main() {
    int* inputt = (int*)malloc(27 * sizeof(int));
    int elements[] = {17, 89, 42, 631, 52, 77, 89, 100, 125, -6, 823, 
                      800, 1024, 1025, 9, 1888, 0, -17, 19, 9999999, -888888, 
                      723, 1000, 1111, -99, -95, 55};
    // Initialize the array
    for (int i = 0; i < 27; i++) {
         inputt[i] = elements[i];
    }
    


    unsigned char *packetss[4];
    packetize_array_sf(inputt,27,packetss,4,20,93737,10973,11,6,25,3,14);
    print_packet_sf(packetss[0]);
    print_packet_sf(packetss[1]);
    print_packet_sf(packetss[2]);
    print_packet_sf(packetss[3]);
    
    return 0;
}
