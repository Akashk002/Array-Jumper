#pragma once
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
    };
}