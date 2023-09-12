#pragma once
#include <iostream>
#include <vector>
#include "deps/SFML-2.6.0-linux-gcc-64-bit/SFML-2.6.0/include/SFML/Graphics.hpp"
#include "entity.h"
struct player_t
{
    int x = 5;
    int y = 5;
    int hp = 100;
    int attack = 1;
    std::string message = "Player";
};

// Function prototypes
void playGame();
void loadTexures(std::vector<std::string>& texturesToLoad, std::vector<sf::Texture>& loadedTextures);
void initFillMap(char (&map)[640][360]);
void render(char (&map)[640][360], player_t &MyPlayer, sf::RenderWindow& window, std::vector<std::string>& textureList, std::vector<sf::Texture>& textures);
void engine(char (&map)[640][360], player_t &MyPlayer, sf::RenderWindow &window, std::vector<std::string>& textureList, std::vector<sf::Texture>& textures);
