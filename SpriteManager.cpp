#include "SpriteManager.h"
// Constructor to load the texture and initialize the sprite
SpriteManager::SpriteManager(const std::string &filename)
{
    int index = -1;
    for (int i = 0; i < textureList.size(); i++)
    {
        if (textureList[i] == filename)
        {
            index = i; // Found the target string, update the index
            break;     // Exit the loop since we found the string
        }
    }
    // if we found something in the texture list do the shit
    if (index != -1)
    {
        std::cout << "String '" << filename << "' found at index " << index << std::endl;
        sprite.setTexture(textures[index]);
        sprite.setScale(3.0f, 3.0f);
        std::cout << "Texture loaded" << std::endl;
    }
    else
    {
        std::cout << "String '" << filename << "' not found in the list." << std::endl;
    }
}

// Getter for the sprite
sf::Sprite &SpriteManager::getSprite()
{
    return sprite;
}
