#include "entity.h"

Entity_t::Entity_t(const std::string &filename, int x, int y) : spriteManager(filename), x(x), y(y){}

void Entity_t::debug()
{
    std::cout << "called Dubg" << std::endl;
}
