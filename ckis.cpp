#include "ckis.h"

using namespace std;

void playGame()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "CKIS");
    char map[640][360];
    initFillMap(map);
    player_t MyPlayer;

    std::vector<std::string> textureList;
    textureList.push_back("player.png");

    std::vector<sf::Texture> textures;
    loadTexures(textureList, textures);

    // // its in the name
    // initFillMap(map);
    // main player function and input function
    engine(map, MyPlayer, window, textureList, textures);
}

//Load the textures
void loadTexures(std::vector<std::string>& texturesToLoad, std::vector<sf::Texture>& loadedTextures)
{
    for(auto it = texturesToLoad.begin(); it < texturesToLoad.end(); ++it)
    {
        sf::Texture texture;
        if(!texture.loadFromFile(*it)) std::cout << "FAILED TO LOAD TEXTURE VERY BAD" << std::endl;
        loadedTextures.push_back(texture);
    }
}

void initFillMap(char (&map)[640][360])
{
    for (int i = 0; i < 640; i++)
    {
        for (int j = 0; j < 360; j++)
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

void render(char (&map)[640][360], player_t &MyPlayer, sf::RenderWindow &window, std::vector<std::string> textureList, std::vector<sf::Texture> textures)
{
    const int cellSize = 8;
    // Calculate the pixel coordinates for the sprite based on the player's position in the map
    sf::Vector2f spritePosition(MyPlayer.x * cellSize, MyPlayer.y * cellSize);

    // Player inserted into map
    // Player inserted into map
    sf::Sprite sprite;
    sprite.setTexture(textures[0]);
    sprite.setScale(3.0f, 3.0f);
    sprite.setPosition(spritePosition);
    window.draw(sprite);
    map[MyPlayer.y][MyPlayer.x] = 'P';

    // // Render UI
    // string message = "+" + MyPlayer.message;
    // string hp = "+HP:" + to_string(MyPlayer.hp);
    // int uiCount = 2;
    // for (int i = 0; i < 640; i++)
    // {
    //     for (int j = 0; j < 360; j++)
    //     {
    //         if (i == 11 && j <= hp.size())
    //         {
    //             map[i][j] = hp[j];
    //         }
    //         else if (i == 13 && j <= message.size())
    //         {
    //             map[i][j] = message[j];
    //         }
    //     }
    //     cout << endl;
    // }
    // Draw map to screen
    for (int i = 0; i < 640; i++)
    {
        for (int j = 0; j < 360; j++)
        {
            cout << " ";
            cout << map[i][j];
        }
        cout << endl;
    }
}

void engine(char (&map)[640][360], player_t &MyPlayer, sf::RenderWindow &window, std::vector<std::string> textureList, std::vector<sf::Texture> textures)
{
    sf::Color backgroundColor(0x1d2021ff);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                    case sf::Keyboard::Up:
                        MyPlayer.y -= 1;
                        break;
                    case sf::Keyboard::Down:
                        MyPlayer.y += 1;
                        break;
                    case sf::Keyboard::Left:
                        MyPlayer.x -= 1;
                        break;
                    case sf::Keyboard::Right:
                        MyPlayer.x += 1;
                        break;
                    // case sf::Keyboard::Space:
                    //     MyPlayer.attack();
                    //     break;
                }
            }
        }
        
        window.clear(backgroundColor);
        std::cout << "\033[2J\033[H";
        
        // draw everything here...
        // window.draw(...);
        render(map, MyPlayer, window, textureList, textures);
        // end the current frame

        window.display();
    }
}

// My attempt at a c++ game
int main()
{
    playGame();
    return 0;
}
