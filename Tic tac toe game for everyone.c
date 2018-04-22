// this is a tic tac toe game created for the enjoyment of whom ever finds it. 
#include <stdio.h>
#include <stdlib.h>
//gloabal declarations
int winner = 0;

int choice = 0;

int row = 0;

int column = 0;

int line = 0;

int i;

#define ROWS 3

#define COLS 3
//sturcture access
typedef char Board[ROWS][COLS];

void printBoard(Board board)
{

    printf("\n\n");

    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);

    printf("---|---|---\n");

    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);

    printf("---|---|---\n");

    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

}

int hasWinner(Board board )
{

    if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||

       (board[0][2]==board[1][1] && board[0][2]==board[2][0]))
    {
        return 1;
    }

    for( int line = 0; line <=2; line++)
    {

        if((board[line][0]==board[line][1] && board[line][0]==board[line][2])||

           (board[0][line]==board[1][line] && board[0][line]==board[2][line]))
        {

            return 1;

        }

    }

    return 0;
}
void architecture()
{
    printf("Hello this is a game of tic-tac-toe, between two players.\n Rules are simple, input the desired box via numerical 1-9\n connect three and winner!");
    Board board =
    {
        {'1','2','3'},

        {'4','5','6'},

        {'7','8','9'}

    };
    for (i = 0; i<9 && !winner; i++)
    {

        int player = i%2 + 1;

        printBoard(board);
        do
        {

            printf("\nPlayer %d, please enter the number of the square "

                   "where you want to place your %c: ",

                   player,(player==1)?'X':'O');

            scanf("%d", &choice);

            row = --choice/3;

            column = choice%3;

        }
        while(choice<0 || choice>9 || board [row][column]>'9');

        board[row][column] = (player == 1) ? 'X' : 'O';

        if (hasWinner(board))
        {
            winner = player;

        }
        else
        {
            printf("invalid input");
        }
    }
    printBoard(board);

    if(!winner)
    {

        printf("The game is a draw\n");

    }
    else
    {

        printf("Player %d has won\n", winner);

    }

}
int main()
{
    architecture();
    return 0;

}


