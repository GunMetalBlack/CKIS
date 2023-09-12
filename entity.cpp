#include "entity.h"

Entity_t::Entity_t(std::string &filename, int x, int y) : spriteManager(filename), x(x), y(y)
{

    SpriteManager spriteManager; // Assuming you made this gonna work
    int x;
    int y;
}

void Entity_t::debug()
{
    std::cout << "called Dubg" << std::endl;
}
