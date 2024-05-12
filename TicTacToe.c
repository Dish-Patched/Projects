#include<stdio.h>

void printBoard(char board[3][3])  //for printing the board
{

        for(int r = 0; r < 3; r++) //for looping through the rows
        {
                printf("\n|");
                for(int c = 0; c < 3; c++) // for looping through the columns
                {
                        printf("  %c  |", board[r][c]);
                }
                printf("\n-------------------");
        }
        printf("\n");
}



int playerInput(char board[3][3], int r, int c, char sign) //for taking player input and putting their token on the board
{
        //this is done so that the player input matches the index number
        r--;
    c--;

    board[r][c] = sign;
    printf("Token placed!");

}


int didWin(char board[3][3], char sign) //to check whether a player won the game
{
        for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
             if (board[0][0] == sign && board[0][1] == sign && board[0][2] == sign ||  //across
                 board[1][0] == sign && board[1][1] == sign && board[1][2] == sign ||
                 board[2][0] == sign && board[2][1] == sign && board[2][2] == sign)
                                return 1;

                        else if (board[0][0] == sign && board[1][0] == sign && board[2][0] == sign ||  //horizontal
                board[0][1] == sign && board[1][1] == sign && board[2][1] == sign ||
                board[0][2] == sign && board[1][2] == sign && board[2][2] == sign)
                                return 1;

                        else if (board[0][0] == sign && board[1][1] == sign && board[2][2] == sign ||  //diagonal
                board[0][2] == sign && board[1][1] == sign && board[2][0] == sign)
                                return 1;
        }
    }
        return 0;

}




int fullBoard(char board[3][3]) //to check if the board is full
{
        for(int r = 0; r < 3; r++)
        {
                for(int c = 0; c < 3; c++)
                {
                        if(board[r][c] == '.') //if any space is empty, the board is not full
                                return 0;
                }
        }

        return 1;

}


int main()
{
        int a, b, c, d;
        char board[3][3];

         for(int r = 0; r < 3; r++) //for putting in a period in each open space on the board
    {
        for(int c = 0; c < 3; c++)
        {
            board[r][c] = '.';
        }
    }

        printBoard(board);
        printf("\n");

                printf("-----------Welcome to Tic-tac-Toe------------");
                printf("Player 1 is X and Player 2 is O\n");

        while(fullBoard(board) == 0) //takes input as long as the board has at least one empty space
    {
                while(1) //infinite loop for catching invalid input
                {
                        printf("Player 1.... Please Enter a row: "); //for 1st player
                scanf("%d", &a);
                printf("Player 1... Please Enter a column: ");
                scanf("%d", &b);

                        if(board[a-1][b-1] != '.')
                        {
                                printf("Invalid space, already taken.\n");
                        }
                        else
                        {
                                playerInput(board, a, b, 'X');
                                break;
                        }

                }

                printBoard(board);
                if(didWin(board, 'X') == 1)
                {
                        printf("Congratulations Player 1... You Won!\n");
                        return 0;
                }

                while(1)
        {
            printf("Player 2.... Please Enter a row: "); //for second player
            scanf("%d", &a);
            printf("Player 2... Please Enter a column: ");
            scanf("%d", &b);

            if(board[a-1][b-1] != '.')
            {
                printf("Invalid space, already taken.\n");
            }
            else
            {
                playerInput(board, a, b, 'O');
                break;
            }

        }

        printBoard(board);
        if(didWin(board, 'O')) {
                        printf("Congratulations Player 2... You won!\n");
                        return 0;
                }

        }



}
