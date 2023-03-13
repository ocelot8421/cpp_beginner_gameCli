#pragma once

namespace game
{
    
struct Position
{
    int x = 0;
    int y = 0;
    Position(int const t_x, int const t_y) : x(t_x), y(t_y){}
    Position() {};
};

} // namespace game
