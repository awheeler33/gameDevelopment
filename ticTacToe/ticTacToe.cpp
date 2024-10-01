#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWin(char *spaces, char player, char computer);
bool checkDraw(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';

    drawBoard(spaces);

    while (true)
    {
        // Player turn
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWin(spaces, player, computer) || checkDraw(spaces))
        {
            break;
        }

        // Computer turn
        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWin(spaces, player, computer) || checkDraw(spaces))
        {
            break;
        }
    }

    return 0;
}
void drawBoard(char *spaces)
{
    std::cout << "\n";
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "\n";
}
void playerMove(char *spaces, char player)
{
    int number;
    while (true)
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> number;
        if (number > 0 && number < 10 && spaces[--number] == ' ')
        {
            spaces[number] = player;
            break;
        }
    }
}

void computerMove(char *spaces, char computer)
{
    int number;
    srand(time(0));
    do
    {
        number = rand() % 9;
    } while (spaces[number] != ' ');
    spaces[number] = computer;
}

/**
 * @brief      Check if a player has won the game.
 *
 * @param      spaces   The board spaces.
 * @param      player   The player's mark.
 * @param      computer The computer's mark.
 *
 * @return     true if a player has won, false otherwise.
 */
bool checkWin(char *spaces, char player, char computer)
{
    static const int lines[][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    for (int i = 0; i < 8; ++i)
    {
        if (spaces[lines[i][0]] != ' ' &&
            spaces[lines[i][0]] == spaces[lines[i][1]] &&
            spaces[lines[i][1]] == spaces[lines[i][2]])
        {
            spaces[lines[i][0]] == player ? std::cout << "You win!" << '\n' : std::cout << "You lose!" << '\n';
            return true;
        }
    }

    return false;
}
bool checkDraw(char *spaces)
{
    for (int i = 0; i < 9; ++i)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    std::cout << "Draw!" << '\n';
    return true;
}