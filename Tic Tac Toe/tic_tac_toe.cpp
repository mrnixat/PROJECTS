#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkDraw (char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard ( spaces );

    while(running)
    {
        //PLAYER MOVES
        playerMove(spaces, player);
        drawBoard(spaces);

        if(checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }

        else if (checkDraw(spaces))
        {
            running = false;
            break;
        }

        //COMPUTER RANDOMLY MOVES
        computerMove(spaces, computer);
        drawBoard(spaces);

        if(checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if (checkDraw(spaces))
        {
            running = false;
            break;
        }

    }

    cout << "Thanks for playing my game!" << endl << endl;

    return 0;
}


void drawBoard(char *spaces)
{
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;

}
void playerMove(char *spaces, char player)
{
    int num;
    do
    {
        cout << "Enter a spot to place a marker (1-9)";
        cin >> num;
        num--;
        if (spaces[num] == ' ')
        {
            spaces[num] = player;         
            break;  
        }
        
    } while (!num > 0 || !num < 8);

}
void computerMove(char *spaces, char computer)
{
    int num;
    srand(time(0));

    while(true)
    {
        num = rand() % 9;
        if (spaces[num] == ' ')
        {
            spaces[num] = computer;
            break;
        }
    }

}
bool checkWinner(char *spaces, char player, char computer)
{
    // CHECK TOP ROW
    if ( spaces[0] != ' ' && 
         spaces[0] == spaces[1] && 
         spaces[1] == spaces[2])
    {
        spaces[0] == player ? cout << "You have won the game!" << endl : cout << "You have lost the game!" << endl;
    }

    // CHECK MIDDLE ROW
    else if ( spaces[3] != ' ' && 
              spaces[3] == spaces[4] && 
              spaces[4] == spaces[5] )
    {
        spaces[3] == player ? cout << "You have won the game!" << endl : cout << "You have lost the game!" << endl;
    }

    // CHECK BOTTOM ROW
    else if ( spaces[6] != ' ' && 
              spaces[6] == spaces[7] && 
              spaces[7] == spaces[8] )
    {
        spaces[6] == player ? cout << "You have won the game!" << endl << endl : cout << "You have lost the game!" << endl << endl;
    }

    // CHECK LEFT COLUMN
    else if ( spaces[0] != ' ' && 
              spaces[0] == spaces[3] && 
              spaces[3] == spaces[6] )
    {
        spaces[0] == player ? cout << "You have won the game!" << endl << endl : cout << "You have lost the game!" << endl << endl;
    }

    // CHECK MIDDLE COLUMN
    else if ( spaces[1] != ' ' && 
              spaces[1] == spaces[4] && 
              spaces[4] == spaces[7] )
    {
        spaces[1] == player ? cout << "You have won the game!" << endl << endl : cout << "You have lost the game!" << endl << endl ;
    }

    //CHECK RIGHT COLUMN
    else if ( spaces[2] != ' ' && 
              spaces[2] == spaces[5] && 
              spaces[5] == spaces[8] )
    {
        spaces[2] == player ? cout << "You have won the game!" << endl << endl : cout << "You have lost the game!" << endl << endl ;
    }

    //CHECK DIAGONAL 1
    else if ( spaces[0] != ' ' && 
              spaces[0] == spaces[4] && 
              spaces[4] == spaces[8] )
    {
        spaces[0] == player ? cout << "You have won the game!" << endl << endl : cout << "You have lost the game!" << endl << endl ;
    }

    //CHECK DIAGONAL 2
    else if ( spaces[2] != ' ' && 
              spaces[2] == spaces[4] && 
              spaces[4] == spaces[6] )
    {
        spaces[2] == player ? cout << "You have won the game!" << endl << endl  : cout << "You have lost the game!" << endl << endl ;
    }

    else
    {
        return false;
    }

    return true;
}
bool checkDraw (char *spaces)
{
    for( int i = 0; i < 9; i++)
    {
        if(spaces[i] == ' ')
        {
           return false; 
        }

    }
    cout << "Its a draw!" << endl << endl;

    return true;
}
