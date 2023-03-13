#pragma once
#include "Position.hpp"

namespace game  
{
    
struct Map
{
    int width = 30;
    int height = 10;
    Position end{5,5};
};

} // namespace game 
