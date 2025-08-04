#include <iostream>
#include <ctime>
using namespace std;

void setUp(char *spaces);
void playerTurn(char *spaces, char player);
void compTurn(char *spaces, char comp);
bool checkWinner(char *spaces, char player, char comp);
bool checkTie(char *spaces);
int main()
{
    char player = 'O';
    char comp = 'X';
    char playAgain;
    cout <<"      TIC-TAC-TOE GAME      \n";
    cout <<"You are assigned with 'O' on the board\n";
    do{
        char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        setUp(spaces);
        bool running = true;
        while (running)
    {
        playerTurn(spaces, player);
        setUp(spaces);
        if (checkWinner(spaces, player, comp))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }

        compTurn(spaces, comp);
        setUp(spaces);
        if (checkWinner(spaces, player, comp))
        {
            running = false;
            break;
        }
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }
    }
    cout << "Do you want to play again? (Y/N): ";
    cin >> playAgain;
}while(playAgain == 'y' || playAgain == 'Y');
    cout << "Game Over!!";
    return 0;
}
void setUp(char *spaces)
{
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
}
void playerTurn(char *spaces, char player)
{
    int num;
    do
    {
        cout << "Enter the space to make a move (1-9) ";
        cin >> num;
        num--;
        if (spaces[num] == ' ')
        {
            spaces[num] = player;
            break;
        }
    } while (!num > 0 || !num < 8);
}
void compTurn(char *spaces, char comp)
{
    int num;
    srand(time(NULL));

    while (true)
    {
        num = rand() % 9;
        if (spaces[num] == ' ')
        {
            spaces[num] = comp;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char comp)
{
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
    {
        spaces[3] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
    {
        spaces[6] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
    {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
    {
        spaces[1] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
    {
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
    {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
    {
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    else
    {
        return false;
    }
    return true;
}
bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << "It's a tie!\n";
    return true;
}
