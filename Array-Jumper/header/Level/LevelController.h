#pragma once

namespace Level
{
	class LevelModel;
	class LevelView;
	enum  BlockType;
	struct BoxDimensions;

	class LevelController
	{
	private:
		LevelModel* level_model;
		LevelView* level_view;

	public:
		LevelController();
		~LevelController();

		BlockType getCurrentBoxValue(int currentPosition);

		BoxDimensions getBoxDimensionsFromView();

		void initialize();
		void update();
		void render();

		bool isLastLevel();
		void loadNextLevel();
		int getCurrentLevelNumber();
		void resetLevels();
	};
}