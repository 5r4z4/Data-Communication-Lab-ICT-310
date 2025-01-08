#include <stdio.h>
#include <string.h>

void main() {
    int i = 0, j = 0;
    char d[50], sd[100], l[] = "DLEETX", ds[100];
    
    printf("Enter Data in UpperCase: ");
    scanf("%s", d);

    // Bit stuffing
    sd[0] = 'D'; sd[1] = 'L'; sd[2] = 'E';
    j = 3; // Start stuffing after initial DLE
    while (d[i] != '\0') {
        if (d[i] == 'D' && d[i+1] == 'L' && d[i+2] == 'E') {
            sd[j++] = 'D'; sd[j++] = 'L'; sd[j++] = 'E';
            sd[j++] = 'D'; sd[j++] = 'L'; sd[j++] = 'E';
            i += 3; // Skip the original DLE
        } else {
            sd[j++] = d[i++];
        }
    }
    sd[j] = '\0'; // End stuffed string
    strcat(sd, l); // Append DLEETX

    printf("After Stuffing: %s", sd);

    // Bit de-stuffing
    i = 0; j = 3; // Start de-stuffing after initial DLE
    while (sd[j] != '\0' && strncmp(&sd[j], "DLEETX", 6) != 0) {
        if (sd[j] == 'D' && sd[j+1] == 'L' && sd[j+2] == 'E' &&
            sd[j+3] == 'D' && sd[j+4] == 'L' && sd[j+5] == 'E') {
            d[i++] = 'D'; d[i++] = 'L'; d[i++] = 'E';
            j += 6; // Skip the stuffed DLEDLE
        } else {
            d[i++] = sd[j++];
        }
    }
    d[i] = '\0'; // End de-stuffed string

    printf("\nAfter De-stuffing: %s", d);
}
