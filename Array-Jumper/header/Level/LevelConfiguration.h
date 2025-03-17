#pragma once
#include "../../header/Level/LevelData.h"

namespace Level
{
	enum BlockType;

	class LevelConfiguration
	{
	private:
		BlockType level_1[LevelData::number_of_boxes] =
		{
			ONE, TWO, OBSTACLE_ONE, TWO, THREE, ONE, OBSTACLE_TWO, TWO, ONE, TARGET
		};

		BlockType level_2[LevelData::number_of_boxes] =
		{
			ONE, TWO, OBSTACLE_ONE, TWO, THREE, OBSTACLE_ONE, OBSTACLE_TWO, TWO, ONE, TARGET
		};

		BlockType level_3[LevelData::number_of_boxes] =
		{
			ONE, TWO, OBSTACLE_TWO, TWO, TWO, TWO, OBSTACLE_TWO, THREE, ONE, TARGET
		};
	public:

		static const int NUMBER_OF_LEVELS = 3;
		LevelData levels[NUMBER_OF_LEVELS];

		LevelConfiguration()
		{
			for (int i = 0; i < LevelData::number_of_boxes; i++)
			{
				levels[0].level_boxes[i] = level_1[i];
			}

			for (int i = 0; i < LevelData::number_of_boxes; i++)
			{
				levels[1].level_boxes[i] = level_2[i];
			}

			for (int i = 0; i < LevelData::number_of_boxes; i++)
			{
				levels[2].level_boxes[i] = level_3[i];
			}
		}
	};
}