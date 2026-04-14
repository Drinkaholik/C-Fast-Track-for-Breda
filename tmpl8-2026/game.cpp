#include "game.h"
#include "surface.h"

#include <cstdio> //printf
#include <iostream>
#include <string>

namespace Tmpl8
{
    // Screen dimensions
    int screenWidth = 512;
    int screenHeight = 800;

    // Sprites
    Sprite tankSprite(new Surface("assets/ctankbase.tga"), 16);
    Sprite ballSprite(new Surface("assets/ball.png"), 1);
    Sprite* sprite = &ballSprite;
    
    int spritePos[2];
    int spriteSize[2];


    // -----------------------------------------------------------
    // Initialize the application
    // -----------------------------------------------------------
    void Game::Init()
    {
        
        spritePos[]{
            sprite->GetWidth();
            
        }
        



    }


    // -----------------------------------------------------------
    // Close down application
    // -----------------------------------------------------------
    void Game::Shutdown()
    {
    }


    int frame;
    int count;

    // -----------------------------------------------------------
    // Main application tick function
    // -----------------------------------------------------------
    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);

        screen->Line(0, 0, screenHeight, screenWidth, 0xFFFFFF);
        

        sprite->Draw(screen, 0, 0);

        ShowFPS(400, 400, deltaTime);

    }

    void Game::ShowFPS(int xPos, int yPos, float deltaTime)
    {
        float FPS = (1 / deltaTime) * 1000; // Why mult by 1000 specifically? Idk, but that gives the number that most closely matches whats im shown by the sprite rotation
        screen->Print(std::to_string(FPS).c_str(), xPos, yPos, 0xFFFFFF);
        std::cout << "hh";
    }



};