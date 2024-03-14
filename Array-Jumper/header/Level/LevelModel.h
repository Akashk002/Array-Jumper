#pragma once
#include "LevelData.h"

namespace Level
{

    struct BoxDimentions
    {
        float box_width;
        float box_height;
        float box_spacing;

        float box_spacing_percentage = 0.3f;
        float bottom_offset = 200.f;
    };


	class LevelModel
	{
	private:
		LevelData current_level_data;
		
	public:
		LevelData getCurrentLevelData();
		int getCurrentBoxValue(int currentPosition);
	};
}
