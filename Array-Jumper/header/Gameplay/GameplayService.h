#pragma once
#include "GameplayController.h"
namespace Gameplay
{

    class GameplayService {
    public:
        GameplayService();  // Default constructor
        ~GameplayService(); // Destructor

        void initialize(); // To be called when the object is created
        void update();     // To be called on every frame
        void render();     // To be called on every frame
        void onDeath();

        GameplayController* gameplay_controller;
    };
}