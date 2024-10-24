#ifndef SIMPLESIM_H
#define SIMPLESIM_H

class simplesim
{
    // Simplesim memory.
    int memory[100];

    // Simplesim registers.
    int accumulator;
    int instruction_counter;
    int instruction_register;
    int operation_code;
    int operand;

public:

    simplesim();
    bool load_program();
    void execute_program();
    void dump() const;
};

#endif
