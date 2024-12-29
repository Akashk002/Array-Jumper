#pragma once
#include "../Level/BlockType.h"
#include "../Player/PlayerController.h"

namespace Gameplay
{
    class GameplayController {
    public:
        GameplayController();  // Default constructor
        ~GameplayController(); // Destructor

        void initialize(); // To be called when the object is created
        void update();     // To be called on every frame
        void render();     // To be called on every frame
        void processObstacle();
        bool isObstacle(BlockType value);
        void onPositionChanged(int position);
        bool isEndBlock(BlockType value);
        void processEndBlock();
        bool isLastLevel();
        void gameOver();
        void onDeath();
        void gameWon();
        void loadNextLevel();
    };
}