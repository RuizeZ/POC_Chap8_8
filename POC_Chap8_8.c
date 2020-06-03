/*
ruizeZ
6/2/2020
The Eight Queens Problem
*/
#include <stdio.h>

int checkqueen(int (*board)[8]);
int main(void)
{
    int chessboard[8][8] = {0};
    checkqueen(chessboard);
    
}

int checkqueen(int (*board)[8])
{
    static int row = -1;
    static int finish = 0;
    static int count = 0;
    row++;


    if (row > 7)
    {
        count++;
        printf("#%d: \n", count);
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d", board[i][j]);
            }
            printf("\n");
            
        }

        printf("\n");
        finish = 1;
        row--;
        
        return 1;
    }
    for (int R = row, C = 0; C < 8; C++)
    {
        int pass = 1;
        board[R][C] = 1;

        //to the east
        for ( int j = C + 1 ; j < 8; j++)
        {
            if (board[R][j] == 0)
            {
                continue;
            }
            else
            {
                pass = 0;
                board[R][C] = 0;
                goto quit;
            }
        }

        //to the west
        for (int j = C - 1; j > -1; j--)
        {
            if (board[R][j] == 0)
            {
                continue;
            }
            else
            {
                pass = 0;
                board[R][C] = 0;
                goto quit;
            }
        }
        //to the north
        for (int i = R-1; i > -1; i--)
        {
            if (board[i][C] == 0)
            {
                continue;
            }
            else
            {
                pass = 0;
                board[R][C] = 0;
                goto quit;
            }
        }
        //to the south
        for (int i = R+1; i < 8; i++)
        {
            if (board[i][C] == 0)
            {
                continue;
            }
            else
            {
                pass = 0;
                board[R][C] = 0;
                goto quit;
            }
        }
        //to the northeast
        for (int i = R+1, j = C-1; i < 8 && j > -1; i++, j--)
        {
            if (board[i][j] == 0)
            {
                continue;
            }
            else
            {
                pass = 0;
                board[R][C] = 0;
                goto quit;
            }
        }
        
        //to the southeast
        for (int i = R+1, j = C+1; i < 8 && j < 8; i++, j++)
        {
            if (board[i][j] == 0)
            {
                continue;
            }
            else
            {
                pass = 0;
                board[R][C] = 0;
                goto quit;
            }
        }
        //to the southwest
        for (int i = R-1, j = C+1; i > -1 && j < 8; i--, j++)
        {
            if (board[i][j] == 0)
            {
                continue;
            }
            else
            {
                pass = 0;
                board[R][C] = 0;
                goto quit;
            }
        }
        //to the northwest
        for (int i = R-1, j = C-1; i >-1 && j > -1; i--, j--)
        {
            if (board[i][j] == 0)
            {
                continue;
            }
            else
            {
                pass = 0;
                board[R][C] = 0;
                goto quit;
            }
        }
        quit: ;
        if (pass == 1)
        {
            checkqueen(board);

            if(row < 0)
            {
                printf("begin return");
                return 1;
            }
            board[R][C] = 0;
            if (finish == 1)
            {
                finish = 0;
                continue;
            }
            
        }
    }
    //printf("return\n");
    row--;
    return 1;
}