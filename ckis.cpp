#include <iostream>
using namespace std;

struct player_t
{
    int x = 5;
    int y = 5;
    int hp = 100;
    int attack = 1;
    string message = "Player";
};

// Function prototypes
void mainMenu();
void playGame();
void initFillMap(char (&map)[20][20]);
void render(char (&map)[20][20], player_t &MyPlayer);
void engine(char (&map)[20][20], player_t &MyPlayer);

// Main menu function
void mainMenu()
{
    cout << "Welcome to the C++ Game!" << endl;
    cout << "1. Play" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        playGame();
    }
    else if (choice == 2)
    {
        cout << "NO YOU RAT YOU WILL PLAY" << endl;
        exit(0);
    }
    else
    {
        cout << "Invalid choice" << endl;
        mainMenu();
    }
}

void playGame()
{
    char map[20][20];
    initFillMap(map);
    player_t MyPlayer;
    while (true)
    {
        // its in the name
        initFillMap(map);
        // main player function and input function
        engine(map, MyPlayer);
    }
}

void initFillMap(char (&map)[20][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (i >= 10)
            {
                map[i][j] = '+';
            }
            else
            {
                map[i][j] = '.';
            }
        }
    }
}

void render(char (&map)[20][20], player_t &MyPlayer)
{
    // Player inserted into map
    map[MyPlayer.y][MyPlayer.x] = 'P';

    // Render UI
    string message = "+" + MyPlayer.message;
    string hp = "+HP:" + to_string(MyPlayer.hp);
    int uiCount = 2;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (i == 11 && j <= hp.size())
            {
                map[i][j] = hp[j];
            }
            else if (i == 13 && j <= message.size())
            {
                map[i][j] = message[j];
            }
        }
        cout << endl;
    }
    // Draw map to screen
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << " ";
            cout << map[i][j];
        }
        cout << endl;
    }
}

void engine(char (&map)[20][20], player_t &MyPlayer)
{
    // stuff
    render(map, MyPlayer);
    string input;
    cout << "What do you want to do?";
    cin >> input;
    if (input[0] == '/')
    {
        // Other Commands
    }
    else
    {
        for (int i = 0; i < input.length(); i++)
        {
            if ((input[i] == 'w') && MyPlayer.y > 0)
            {
                MyPlayer.message = "moved north";
                MyPlayer.y = MyPlayer.y - 1;
            }
            else if (input[i] == 's' && MyPlayer.y < 9)
            {
                MyPlayer.message = "moved south";
                MyPlayer.y = MyPlayer.y + 1;
            }
            else if (input[0] == 'a' && MyPlayer.x > 0)
            {
                MyPlayer.message = "moved west";
                MyPlayer.x = MyPlayer.x - 1;
            }
            else if (input[0] == 'd' && MyPlayer.x < 19)
            {
                MyPlayer.message = "moved east";
                MyPlayer.x = MyPlayer.x + 1;
            }
            else
            {
                MyPlayer.message = "invalid input";
            }
        }
    }

    system("clear");
}

// My attempt at a c++ game
int main()
{
    mainMenu();
    return 0;
}
