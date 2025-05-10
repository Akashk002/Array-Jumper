#pragma once
#include "../../header/Level/BlockType.h"


namespace Gameplay
{
	class GameplayController
	{
	private:
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void processobstacle();
		bool isObstacle(Level::BlockType value);
		bool isEndBlock(Level::BlockType value);
		void onPositionChanged(int position);
		void processEndBlock();
		void gameOver();
		void onDeath();
		void gameWon();
		void startGame();
	};
}