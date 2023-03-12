#pragma once
#include <chrono>
#include "GameStateEnum.hpp"

namespace game {
    class GameEngine{
    public:
        int run();
    private:
        void init();

        void gameLoop();
        void handleInput();
        void update();
        void render();

        int finish();
    private:
        int x = 3;
        int y = 3;
        bool quit = false;
        bool isStateChanged = true;
        std::chrono::time_point<std::chrono::system_clock> currentTime;
        GameStateEnum currentGameState = GameStateEnum::START;
    };

} //namespace game