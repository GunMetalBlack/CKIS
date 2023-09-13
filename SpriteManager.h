#pragma once
#include <iostream>
#include "deps/SFML-2.6.0-linux-gcc-64-bit/SFML-2.6.0/include/SFML/Graphics.hpp"
#include "globals.h"

class SpriteManager
{
public:
    // Constructor to load the texture and initialize the sprite
    SpriteManager(const std::string &filename);

    // Getter for the sprite
sf::Sprite &getSprite();

private:
    sf::Sprite sprite;
};
