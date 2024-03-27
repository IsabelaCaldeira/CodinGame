#include <stdio.h>
#include <string.h>

#define MAX_INPUTS 100
#define MAX_NAME_LEN 50
#define MAX_SIGNAL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char signal[MAX_SIGNAL_LEN];
} Input;

typedef struct {
    char name[MAX_NAME_LEN];
    char signal[MAX_SIGNAL_LEN];
    char gate_type[MAX_NAME_LEN];
    char input_name_1[MAX_NAME_LEN];
    char input_name_2[MAX_NAME_LEN];
} Output;

char logic_gate(char* operation, char input1, char input2) {
    if (strcmp(operation, "AND") == 0)
        return (input1 == '-' && input2 == '-') ? '-' : '_';
    else if (strcmp(operation, "OR") == 0)
        return (input1 == '-' || input2 == '-') ? '-' : '_';
    else if (strcmp(operation, "XOR") == 0)
        return (input1 != input2) ? '-' : '_';
    else if (strcmp(operation, "NAND") == 0)
        return (input1 == '-' && input2 == '-') ? '_' : '-';
    else if (strcmp(operation, "NOR") == 0)
        return (input1 == '-' || input2 == '-') ? '_' : '-';
    else if (strcmp(operation, "NXOR") == 0)
        return (input1 != input2) ? '_' : '-';
    else
        return '0';
}

char* find_signal(Input* inputs, int n, char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(inputs[i].name, name) == 0) {
            return inputs[i].signal;
        }
    }
    return NULL;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    Input inputs[MAX_INPUTS];
    for (int i = 0; i < n; i++) {
        scanf("%s %s", inputs[i].name, inputs[i].signal);
    }

    Output outputs[MAX_INPUTS];
    for (int i = 0; i < m; i++) {
        scanf("%s %s %s %s", outputs[i].name, outputs[i].gate_type, outputs[i].input_name_1, outputs[i].input_name_2);
        char* input_signal_1 = find_signal(inputs, n, outputs[i].input_name_1);
        char* input_signal_2 = find_signal(inputs, n, outputs[i].input_name_2);
        for (int j = 0; j < strlen(input_signal_1); j++) {
            outputs[i].signal[j] = logic_gate(outputs[i].gate_type, input_signal_1[j], input_signal_2[j]);
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%s %s\n", outputs[i].name, outputs[i].signal);
    }

    return 0;
}