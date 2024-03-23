import sys

def logic_gate(operation, input1, input2):
    if operation == "AND":
        return "-" if input1 == "-" and input2 == "-" else "_"
    elif operation == "OR":
        return "-" if input1 == "-" or input2 == "-" else "_"
    elif operation == "XOR":
        return "-" if input1 != input2 else "_"
    elif operation == "NAND":
        return "_" if input1 == "-" and input2 == "-" else "-"
    elif operation == "NOR":
        return "_" if input1 == "-" or input2 == "-" else "-"
    elif operation == "NXOR":
        return "_" if input1 != input2 else "-"
    else:
        return None

def main():
    n = int(input())
    m = int(input())

    inputs = {}
    for _ in range(n):
        input_name, input_signal = input().split()
        inputs[input_name] = input_signal

    output_signals = []
    for _ in range(m):
        output_name, gate_type, input_name_1, input_name_2 = input().split()
        input_signal_1 = inputs[input_name_1]
        input_signal_2 = inputs[input_name_2]
        output_signal = "".join(logic_gate(gate_type, input_signal_1[i], input_signal_2[i]) for i in range(len(input_signal_1)))
        inputs[output_name] = output_signal
        output_signals.append((output_name, output_signal))

    for output_name, output_signal in output_signals:
        print(output_name, output_signal)

if __name__ == "__main__":
    main()