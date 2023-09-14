#include "ckis.h"
#include "globals.h"
using namespace std;
std::vector<std::string> textureList;
std::vector<sf::Texture> textures;
std::vector<Entity_t> entitys_list;
void playGame()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "CKIS");
    char map[640][360];
    player_t MyPlayer;

    // TODO: For the love of god I hate to do this to yah jim but here we go
    // Im going to preload the textures and store them in a vector of strings which i will use in the SpriteManager class as an easy lookup using the string
    // Unfortunately i dont know of a better way of doing this in c++ well and Im lazy so i will just do this for now
    textureList.push_back("player.png");
    textureList.push_back("wall.png");

    loadTexures(textureList, textures);

    // // its in the name
    // initFillMap(map);
    initFillMap(map);
    // main player function and input function
    engine(map, MyPlayer, window, textureList, textures);
}

// Load the textures
void loadTexures(std::vector<std::string> &texturesToLoad, std::vector<sf::Texture> &loadedTextures)
{
    for (auto it = texturesToLoad.begin(); it < texturesToLoad.end(); ++it)
    {
        sf::Texture texture;
        if (!texture.loadFromFile(*it))
            std::cout << "FAILED TO LOAD TEXTURE VERY BAD" << std::endl;
        loadedTextures.push_back(texture);
    }
    for (const std::string &str : textureList)
    {
        std::cout << str << " TEXTURE" << std::endl;
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
                map[i][j] = '.';
            }
            else
            {
                map[i][j] = 'w';
            }
        }
    }
    // Alright this is going to be dumb but here we go this is the entity init loop
    for (int i = 0; i < 640; i++)
    {
        for (int j = 0; j < 360; j++)
        {
            //*If the map is of type 'w' which is wall then we create a WALL entity with the x , y pos in the map
            std::string textureID;
            if (map[i][j] == 'w')
            {
                textureID = "wall.png";
            }
            else if (map[i][j] == '.')
            {
                textureID = "empty";
            }
            // Now we do checks to push said unique entity into the entitys_list vector
            if (textureID == "empty")
            {
                continue;
            }
            else if (textureID != "")
            {
                entitys_list.push_back(Entity_t(textureID, i, j));
            }
            else
            {
                cout << "Entity Init Failed in InitFillMap!!!" << endl;
            }
        }
    }
}

void render(char (&map)[640][360], player_t &MyPlayer, sf::RenderWindow &window, std::vector<std::string> &textureList, std::vector<sf::Texture> &textures)
{
    const int cellSize = 8;
    const int RenderDistanceX = 50;
    const int RenderDistanceY = 20;
    // Calculate the pixel coordinates for the sprite based on the player's position in the map

    // RKIS Map Render Please Don't Touch this trash
    // Player inserted into map
    sf::Sprite sprite;
    sprite.setTexture(textures[0]);
    sprite.setScale(3.0f, 3.0f);
    for (int i = -RenderDistanceX; i <= RenderDistanceX; i++)
    {
        for (int j = -RenderDistanceY; j <= RenderDistanceY; j++)
        {
            int screen_space_x = i + RenderDistanceX;
            int screen_space_y = j + RenderDistanceY;
            int world_space_x = i + MyPlayer.x;
            int world_space_y = j + MyPlayer.y;
            int screen_space_offset;
            screen_space_offset = (100 - RenderDistanceX) / 2;

            // Lookup Char from World
            char char_from_map = map[world_space_x][world_space_y];
            if (i == 0 && j == 0)
            {
                sf::Vector2f spritePosition((screen_space_x + screen_space_offset) * cellSize, screen_space_y * cellSize);
                sprite.setPosition(spritePosition);
            }
        }
    }

    // window.draw(entitys_list[0].spriteManager.getSprite());
    window.draw(sprite);

    // Draw Debug Info to the Console
    cout << "Player X:" << MyPlayer.x << endl;
    cout << "Player Y:" << MyPlayer.y << endl;
}

void engine(char (&map)[640][360], player_t &MyPlayer, sf::RenderWindow &window, std::vector<std::string> &textureList, std::vector<sf::Texture> &textures)
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
                // TODO: DO NOT LEAVE THIS IN PRODUCTION YOU FOOL
                std::ofstream debugMapStream("debugMap");
                for (int i = 0; i < 640; i++)
                {
                    for (int j = 0; j < 360; j++)
                    {
                        debugMapStream << " ";
                        debugMapStream << map[i][j];
                    }
                    debugMapStream << endl;
                }
                // REMOVE THIS
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Up:
                    if (MyPlayer.y >= 1)
                    {
                        MyPlayer.y -= 1;
                    }
                    break;
                case sf::Keyboard::Down:
                    if (MyPlayer.y < 360)
                    {
                        MyPlayer.y += 1;
                    }
                    break;
                case sf::Keyboard::Left:
                    if (MyPlayer.x > 0)
                    {
                        MyPlayer.x -= 1;
                    }
                    break;
                case sf::Keyboard::Right:
                    if (MyPlayer.x >= 0)
                    {
                        MyPlayer.x += 1;
                    }
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
