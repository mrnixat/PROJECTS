//********************************************************************
//
// CSCI 241 Assignment 8
//
// Created By: Yousuf Khan, Niko Tsakiridis
// ZID: Z2004989, Z1986104
//
//********************************************************************

#include <iostream>
#include <iomanip>
#include "simplesim.h"
#include "sml.h"

using namespace std;

/**
 * This is the simplesim constructor
 *
 * This sets the data members to 0 and then creates the memory to be all "7777"
 *
 * NO PARAMS
 * 
 */

simplesim::simplesim() 
{
    accumulator = 0;
    instruction_counter = 0;
    instruction_register = 0;
    operation_code = 0;
    operand = 0;

    for ( int i = 0 ; i < 100 ; i++ ) 
    {
        memory[i] = 7777;
    }
}

/**
 * This is the load_program function with the simplesim class.
 *
 * This bascially loads a file into the "fictional computer."
 *
 * NO PARAMS
 *
 */

bool simplesim::load_program() 
{
    int instruction;
    int location = 0;

    while ( cin >> instruction && instruction != -99999 ) 
    {
        if ( instruction < -9999 || instruction > 9999 ) 
        {
            cout << "*** ABEND: pgm load: invalid word ***\n";
            return false;
        }
        if ( location >= 100 ) 
        {
            cout << "*** ABEND: pgm load: pgm too large ***\n";
            return false;
        }
        memory[location++] = instruction;
    }
    return true;
}

/**
 * This is the execute_program function for the class simplesim
 *
 * This function executes the program and the base for this function is basically
 * the switch statement, which tells the program what exactly to do for the lefmost digits
 * and the rightmost digits of the "word."
 *
 * NO PARAMS
 * 
 */

void simplesim::execute_program() 
{
    bool done = false;

    while ( !done ) 
    {
        instruction_register = memory[instruction_counter];
        operation_code = instruction_register / 100;
        operand = instruction_register % 100;


        switch ( operation_code ) 
        {
            case READ: 
            {
                int input_value;
                cin >> input_value;
                if ( input_value < -9999 || input_value > 9999 ) 
                {
                    cout << "*** ABEND: illegal input ***\n";
                    return;
                }
                memory[operand] = input_value;
                cout << "READ: " << showpos << internal << setw(5) << setfill('0') << input_value << '\n';
                break;
            }
            case WRITE: 
            {
                cout << showpos << internal << setw(5) << setfill('0') << memory[operand] << '\n';
                break;
            }
            case LOAD: 
            {
                accumulator = memory[operand];
                break;
            }
            case STORE: 
            {
                accumulator = instruction_register;
                memory[operand] = accumulator;
                break;
            }
            case ADD: 
            {
                int result = accumulator + memory[operand];
                if ( result < -9999 ) 
                {
                    cout << "*** ABEND: underflow ***\n";
                    return;
                } 
                
                else if ( result > 9999 ) 
                {
                    cout << "*** ABEND: overflow ***\n";
                    return;
                } else { accumulator = result; }
                break;
            }
            case SUBTRACT: 
            {
                int result = accumulator - memory[operand];
                if ( result < -9999 ) 
                {
                    cout << "*** ABEND: underflow ***\n";
                    return;
                } 
                
                else if ( result > 9999 ) 
                {
                    cout << "*** ABEND: overflow ***\n";
                    return;
                } else { accumulator = result; }
                break;
            }
            case MULTIPLY: 
            {
                int result = accumulator * memory[operand];
                if ( result < -9999 ) 
                {
                    cout << "*** ABEND: underflow ***\n";
                    return;
                } 
                
                else if ( result > 9999 ) 
                {
                    cout << "*** ABEND: overflow ***\n";
                    return;
                } else { accumulator = result; }
                break;
            }
            case DIVIDE: 
            {
                if ( memory[operand] == 0 ) 
                {
                    cout << "*** ABEND: attempted division by 0 ***\n";
                    return;
                }
                accumulator /= memory[operand];
                break;
            }
            case BRANCH: 
            {
                instruction_counter = operand;
                continue;
            }
            case BRANCHZERO: 
            {
                if ( accumulator == 0 ) 
                {
                    instruction_counter = operand;
                    continue;
                }
                break;
            }
            case BRANCHNEG: 
            {
                if ( accumulator < 0 ) 
                {
                    instruction_counter = operand;
                    continue;
                }
                break;
            }
            case HALT: 
            {
                cout << "*** Simplesim execution terminated ***\n";
                done = true;
                break;
            }
            default: 
            {
                cout << "*** ABEND: invalid opcode ***\n";
                return;
            }
        }

        if ( !done ) 
        {
            instruction_counter++;
            if ( instruction_counter >= 100 ) 
            {
                cout << "*** ABEND: addressability error ***\n";
                return;
            }
        }
    }
}

/**
 * This is a constant dump function for our simplesim class.
 *
 * This simply displays all of the data of the simpesim computer
 * in a very specific format.
 *
 * NO PARAMS
 * 
 */

void simplesim::dump() const 
{
    cout << "\nREGISTERS:\n";
    cout << "accumulator:            " 
         << showpos << internal << setw(5) << setfill('0') << accumulator << '\n';
    cout << "instruction_counter:    " 
         << noshowpos << setw(2) << setfill('0') << instruction_counter << '\n';
    cout << "instruction_register:   " 
         << showpos << internal << setw(5) << setfill('0') << instruction_register << '\n';
    cout << "operation_code:         " 
         << noshowpos << setw(2) << setfill('0') << operation_code << '\n';
    cout << "operand:                " 
         << noshowpos << setw(2) << setfill('0') << operand << '\n';

    cout << "\nMEMORY:\n";
    cout << "       0     1     2     3     4     5     6     7     8     9\n";
    for ( int i = 0 ; i < 100 ; i += 10 ) 
    {
        cout << noshowpos << setfill(' ') << setw(2) << i << " ";
        for ( int j = 0 ; j < 10 ; j++ ) 
        {
            cout << showpos << internal << setw(5) << setfill('0') << memory[i + j] << " ";
        }
        cout << '\n';
    }
}