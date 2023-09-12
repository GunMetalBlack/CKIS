#pragma once
#include <iostream>
#include "deps/SFML-2.6.0-linux-gcc-64-bit/SFML-2.6.0/include/SFML/Graphics.hpp"


class SpriteManager
{
public:
    // Constructor to load the texture and initialize the sprite
    SpriteManager(std::string &filename);

    // Getter for the sprite
    sf::Sprite &getSprite();

private:
    sf::Sprite sprite;
};
