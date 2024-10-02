// LIBRARIES
#include <iostream>

//USE NAMESPACE STANDARD
using namespace std;


// FUNCTION PROTOTYPE
void move(int n_disks, int src_peg, int dest_peg, int temp_peg);

// MAIN BODY
int main (int arg, char* num[])
{
    int num1 = atoi(num[1]); // atoi is to convert strings to integers
    move(num1, 1, 2, 3); // using the move function

    return 0; // returns 0

    
} // END OF MAIN


/* "move" FUNCTION
*  Arguments: 
        - int n_disks: # of disks
        - int src_peg: represents the source peg
        - int dest_peg: represents the destination peg
        - int temp_peg: represents the temporary holding peg

    Returns: No returns, for it is a void function.
*/

/**
 * This function uses recursive code for the solution for "Towers of Hanoi"
 *
 * @param n_disks - # of disks.
 * @param src_peg - represents the source peg.
 * @param dest_peg - represents the destination peg.
 * @param temp_peg - represents the temporary holding peg.
 *
 * @warning This algorithm might take a while depending on the amount of disks
 * that the user input.
 * 
 * @return - No return values, for it is a void function.
 * 
 */
void move(int n_disks, int src_peg, int dest_peg, int temp_peg)
{
    if (n_disks == 0) return; // BASE CASE

    move(n_disks - 1, src_peg, temp_peg, dest_peg); /* Performing a recursive call to move 
                                                       n-1 disks from the source peg to the temp_peg 
                                                       while using dest_peg as the temporary holding peg */

    cout << n_disks << " " << src_peg << "->" << dest_peg << endl; /* This is the cout statement that prints the 
                                                                      disk number of the largest disk, the number 
                                                                      of the source peg, and the number of the destination peg */

    move(n_disks - 1, temp_peg, dest_peg, src_peg); /* Last recursive call that moves n-1 disks from temp_peg 
                                                       to dest_peg using the source peg as a temporary holding peg. */



} // END OF "move" FUNCTION