#include <stdio.h>
#include <string.h>

#define FLAG "01111110" // Flag used to indicate the start and end of a frame
#define MAX 100         // Maximum input size

void bitStuffing(char input[], char stuffed[]) {
    int i, j = 0, count = 0;

    // Add the FLAG at the start of the stuffed data
    strcpy(stuffed, FLAG);
    j = strlen(FLAG);

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '1') {
            count++;
        } else {
            count = 0; // Reset count if a '0' is found
        }

        // Add the bit to the stuffed data
        stuffed[j++] = input[i];

        // If 5 consecutive '1's are detected, stuff a '0'
        if (count == 5) {
            stuffed[j++] = '0';
            count = 0; // Reset count after stuffing
        }
    }

    // Add the FLAG at the end of the stuffed data
    strcat(stuffed, FLAG);
    stuffed[j + strlen(FLAG)] = '\0'; // Null-terminate the stuffed string
}

void bitDeStuffing(char stuffed[], char deStuffed[]) {
    int i = strlen(FLAG), j = 0, count = 0; // Skip the FLAG at the start

    while (stuffed[i] != '\0' && strncmp(&stuffed[i], FLAG, strlen(FLAG)) != 0) {
        if (stuffed[i] == '1') {
            count++;
        } else {
            count = 0; // Reset count if a '0' is found
        }

        // Add the bit to the de-stuffed data
        deStuffed[j++] = stuffed[i];

        // If 5 consecutive '1's are detected, skip the next bit (stuffed '0')
        if (count == 5 && stuffed[i + 1] == '0') {
            i++;      // Skip the stuffed '0'
            count = 0; // Reset count after de-stuffing
        }
        i++;
    }

    deStuffed[j] = '\0'; // Null-terminate the de-stuffed string
}

int main() {
    char input[MAX], stuffed[MAX * 2], deStuffed[MAX];

    // Input binary data
    printf("Enter binary data (0s and 1s only): ");
    scanf("%s", input);

    // Perform bit stuffing
    bitStuffing(input, stuffed);
    printf("After Bit Stuffing: %s\n", stuffed);

    // Perform bit de-stuffing
    bitDeStuffing(stuffed, deStuffed);
    printf("After Bit De-stuffing: %s\n", deStuffed);

    return 0;
}
