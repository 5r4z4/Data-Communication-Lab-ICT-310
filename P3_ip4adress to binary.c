#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimal) {
    // Convert decimal to binary and print as 8 bits
    for (int i = 7; i >= 0; i--) {
        printf("%d", (decimal >> i) & 1);
    }
}

int main() {
    char ipv4[16];  // Input IPv4 address
    int octet1, octet2, octet3, octet4;

    // Get the IPv4 address from the user
    printf("Enter an IPv4 address (e.g., 192.168.1.1): ");
    scanf("%15s", ipv4);

    // Extract the four octets using sscanf
    if (sscanf(ipv4, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4) != 4) {
        printf("Invalid IPv4 address format.\n");
        return 1;
    }

    // Validate each octet (0-255)
    if (octet1 < 0 || octet1 > 255 || octet2 < 0 || octet2 > 255 ||
        octet3 < 0 || octet3 > 255 || octet4 < 0 || octet4 > 255) {
        printf("Invalid IPv4 address: Each octet must be in the range 0-255.\n");
        return 1;
    }

    // Print binary representation of each octet
    printf("Binary representation of %s:\n", ipv4);
    decimalToBinary(octet1);
    printf(".");
    decimalToBinary(octet2);
    printf(".");
    decimalToBinary(octet3);
    printf(".");
    decimalToBinary(octet4);
    printf("\n");

    return 0;
}
