#pragma once
#include <iostream>
#include "deps/SFML-2.6.0-linux-gcc-64-bit/SFML-2.6.0/include/SFML/Graphics.hpp"
class Entity_t
{
public:
    // Player inserted into map
    char mapChar;

    Entity_t(char mapChar);
    void debug();
};