#pragma once
#include "../../header/Level/LevelConfiguration.h"

namespace Level
{
	struct BoxDimensions
	{
		float box_width = 5.f;
		float box_height = 5.f;
		float box_spacing = 5.f;

		float box_spacing_percentage = 0.3f;
		float bottom_offset = 200.f;
	};

	class LevelModel
	{
	private:
		LevelConfiguration level_configuration;
		int current_level_index;

	public:
		LevelModel();
		~LevelModel();

		BlockType getBoxValue(int currentPosition);
		void loadNextLevel();
		int getCurrentLevelNumber();
		bool isLastLevel();

		void reset();
	};
}