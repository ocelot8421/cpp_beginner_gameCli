#include "GameEngine.hpp"
#include <iostream>
#include <windows.h>



using namespace std;

namespace game{

    using namespace std::chrono_literals;
    constexpr std::chrono::nanoseconds timeStep(50ms);
    #define IS_PRESSED 0x8000

    int GameEngine::run(){
        init();
        gameLoop();
        return finish();
    }

    void GameEngine::init(){
        currentTime = std::chrono::high_resolution_clock::now();
    }

    void GameEngine::gameLoop(){
         std::chrono::nanoseconds lag(0ns);
        while (!quit){
            auto deltaTime = std::chrono::high_resolution_clock::now() - currentTime;
            currentTime = std::chrono::high_resolution_clock::now();
            lag += std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime);

            while(lag >= timeStep){
                lag -= timeStep;
                handleInput();
                update();
                render(); 
            }
        }
    }

    void GameEngine::handleInput(){
        if (GetKeyState('W') & IS_PRESSED)
        {
            --y;
            isStateChanged = true;
        }
        else if (GetKeyState('S') & IS_PRESSED)
        {
            ++y;
            isStateChanged = true;
        }
        else if (GetKeyState('A') & IS_PRESSED)
        {
            --x;
            isStateChanged = true;
        }
        else if (GetKeyState('D') & IS_PRESSED)
        {
            ++x;
            isStateChanged = true;
        }
        else if (currentGameState == GameStateEnum::START &&  GetKeyState(VK_SPACE) & IS_PRESSED)
        {
            currentGameState = GameStateEnum::PLAY;
            isStateChanged = true;
        }


    }
    void GameEngine::update(){

    }
    void GameEngine::render(){
        if(!isStateChanged){
            return;
        }
        if(currentGameState == GameStateEnum::PLAY){
            //Simple drawing
            system("cls");
            for (int height = 0; height < y - 1; ++height){
                cout << endl;
            }
            for (int width = 0; width < x - 1; ++width){
                cout << " ";
            }
            cout << "@";
            cout << endl;
        }
        if(currentGameState == GameStateEnum::START){
            system("cls");
            cout << "Press SPACE to play" << endl;
        }
        isStateChanged = false;
    }

    int GameEngine::finish(){
        return 0;
    }

} // namespace game
