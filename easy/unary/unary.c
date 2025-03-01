#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_encoded_message(const char *message) {
    char binary[800] = "";
    char encoded[1600] = "";
    char temp[10];

    for (int i = 0; message[i] != '\0'; i++) {
        for (int j = 6; j >= 0; j--) {
            sprintf(temp, "%d", (message[i] >> j) & 1);
            strcat(binary, temp);
        }
    }

    int len = strlen(binary);
    for (int i = 0; i < len; ) {
        char current = binary[i];
        int count = 0;

        while (i < len && binary[i] == current) {
            count++;
            i++;
        }

        if (current == '1') {
            strcat(encoded, "0 ");
        } else {
            strcat(encoded, "00 ");
        }

        for (int j = 0; j < count; j++) {
            strcat(encoded, "0");
        }

        if (i < len) {
            strcat(encoded, " ");
        }
    }

    printf("%s\n", encoded);
}

int main() {
    char MESSAGE[101];
    scanf("%[^\n]", MESSAGE);

    print_encoded_message(MESSAGE);

    return 0;
}