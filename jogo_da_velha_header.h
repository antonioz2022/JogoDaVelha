#ifndef JOGO_DA_VELHA_HEADER_H_INCLUDED
#define JOGO_DA_VELHA_HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define PLAYER 'X'
#define COMPUTER 'O'
void play();

char board[3][3];
int win = 0;

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
};

void printBoard()
{
    printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");

    printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");

    printf(" %c | %c | %c", board[2][0], board[2][1], board[2][2]);
    printf("\n---|---|---\n");

    printf("\n");
};

int checkFreeSpaces()
{
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
};

void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
        {
            printf("Invalid move!");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }

    } while (board[x][y] != ' ');
};

char printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("YOU WON");
    }
    else if (winner == COMPUTER)
    {
        printf("YOU LOSED");
    }
    else
    {
        printf("IT'S A TIE");
    }
};

void computerMove()
{
    // creates a seed based on current time
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}

void printMenu()
{
    printf("  JOGO DA VELHA ");
    printf("\n");
    printf(" JOGAR - Digite 1 ");
    printf("\n");
    printf(" Sair -  Digite 2 ");
    printf("\n");
    printf(" Rank -  Digite 3 ");
    printf("\n");
    return;
}

char checkWinner()
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        };
    }

    // checkColumns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        };
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    };
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    };

    return ' ';
};

void Game()
{
    char winner = ' ';
    resetBoard();

    while (winner == ' ' && checkFreeSpaces() != 0)
    {
        printBoard();
        playerMove();
        winner = checkWinner();

        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            win++;
            break;
        }

        computerMove();
        winner = checkWinner();

        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
    }

    printBoard();
    printWinner(winner);

    printf("\n");
    printf("\n");

    play();
    return;
}

void play()
{
    int OPTION;
    printMenu();
    scanf("%d", &OPTION);
    switch (OPTION)
    {
    case 1:
        Game();
        break;
    case 2:
        exit(0);
        break;
    case 3:
        printf("\n");
        printf("Vitorias: %d", win);
        printf("\n");
        printf("\n");
        play();
        break;
    }
    return;
}

#endif // JOGO_DA_VELHA_HEADER_H_INCLUDED
