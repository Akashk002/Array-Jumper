#pragma once
#include "LevelModel.h"

namespace Level
{
	class LevelController;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelController* loadNextLevel;

		void destroy();
	public:
		LevelService();
		~LevelService();

		void intialize();
		void update();
		void render();
		BoxDimensions getBoxDimensions();
		BlockType getCurrentBoxValue(int currentPosition);

		bool isLastLevel();
		void loadNextLevel();
		int getCurrentLevelNumber();

		void resetLevels();
	};
}