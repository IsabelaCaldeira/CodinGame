#include <stdio.h>
#include <string.h>

#define MAX_SIGNAL_LENGTH 100
#define MAX_SIGNALS 16

char logic_gate(char operation, char input1, char input2) {
    switch(operation) {
        case 'A':
            return (input1 == '-' && input2 == '-') ? '-' : '_';
        case 'O':
            return (input1 == '-' || input2 == '-') ? '-' : '_';
        case 'X':
            return (input1 != input2) ? '-' : '_';
        case 'N':
            return (input1 == '-' && input2 == '-') ? '_' : '-';
        default:
            return (input1 == input2) ? '_' : '-';
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    getchar(); // consume newline character

    char inputs[MAX_SIGNALS][MAX_SIGNAL_LENGTH + 1];
    for (int i = 0; i < n; i++) {
        scanf("%s", inputs[i]);
    }

    for (int i = 0; i < m; i++) {
        char output_name[MAX_SIGNAL_LENGTH + 1], gate_type, input_name_1[MAX_SIGNAL_LENGTH + 1], input_name_2[MAX_SIGNAL_LENGTH + 1];
        char input_signal_1[MAX_SIGNAL_LENGTH + 1], input_signal_2[MAX_SIGNAL_LENGTH + 1], output_signal[MAX_SIGNAL_LENGTH + 1];

        scanf("%s %c %s %s", output_name, &gate_type, input_name_1, input_name_2);

        int index1, index2;
        for (int j = 0; j < n; j++) {
            if (strcmp(input_name_1, inputs[j]) == 0) index1 = j;
            if (strcmp(input_name_2, inputs[j]) == 0) index2 = j;
        }

        strcpy(input_signal_1, inputs[index1]);
        strcpy(input_signal_2, inputs[index2]);

        for (int j = 0; input_signal_1[j] != '\0'; j++) {
            output_signal[j] = logic_gate(gate_type, input_signal_1[j], input_signal_2[j]);
        }
        output_signal[strlen(input_signal_1)] = '\0';
        
        strcpy(inputs[i + n], output_signal);

        printf("%s %s\n", output_name, output_signal);
    }

    return 0;
}