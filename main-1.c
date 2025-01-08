#include<stdio.h>
#include<string.h>
int main() {
    int i = 0, j = 0;
    char d[100], l[] = "DLEETX", sd[100], ds[100];
    printf("Enter Data in UpperCase: ");
    scanf("%s", d);

    // Adding Start Flag (DLESTX)
    sd[0] = 'D', sd[1] = 'L', sd[2] = 'E', sd[3] = 'S', sd[4] = 'T', sd[5] = 'X';
    j = 6;

    // Stuffing
    while (d[i] != '\0') {
        if (d[i] == 'D' && d[i + 1] == 'L' && d[i + 2] == 'E') {
            sd[j] = 'D', sd[j + 1] = 'L', sd[j + 2] = 'E';
            sd[j + 3] = 'D', sd[j + 4] = 'L', sd[j + 5] = 'E';
            j += 6;
            i += 3;
        } else {
            sd[j++] = d[i++];
        }
    }
    sd[j] = '\0';  // End stuffed data

    // Adding End Flag (DLEETX)
    strcpy(ds, sd);
    strcat(ds, l);

    // Print stuffed data with flags
    printf("After Stuffing = ");
    printf("%s", ds);

    // De-stuffing
    i = 0;
    j = 6;  // Start after 'DLESTX'

    while (ds[j] != '\0'){
        // Stop when DLEETX (end flag) is reached
        if (ds[j] == 'D' && ds[j + 1] == 'L' && ds[j + 2] == 'E' &&
            ds[j + 3] == 'E' && ds[j + 4] == 'T' && ds[j + 5] == 'X') {
            break;  // Exit the loop when DLEETX is found
        }

        // Handle stuffed data (DLEDLE -> DLE)
        if (ds[j] == 'D' && ds[j + 1] == 'L' && ds[j + 2] == 'E' &&
            ds[j + 3] == 'D' && ds[j + 4] == 'L' && ds[j + 5] == 'E') {
            d[i] = 'D', d[i + 1] = 'L', d[i + 2] = 'E';
            j += 6;
            i += 3;
        } else {
            d[i++] = ds[j++];
        }
    }
    d[i] = '\0';  // End original data

    // Print de-stuffed data
    printf("\n\nAfter De-stuffing = ");
    printf("%s", d);

    return 0;
}
