#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelView.h"
#include "../../header/Level/BlockType.h"

namespace Level
{
	LevelController::LevelController()
	{
		level_model = new LevelModel();
		level_view = new LevelView(this);
	}

	LevelController::~LevelController() {}

	void LevelController::initialize()
	{
		level_view->initialize();
	}

	void LevelController::update()
	{
		level_view->update();
	}

	void LevelController::render()
	{
		level_view->render();
	}

	BlockType LevelController::getCurrentBoxValue(int currentPosition)
	{
		return level_model->getBoxValue(currentPosition);
	}

	BoxDimensions LevelController::getBoxDimensionsFromView()
	{
		return level_view->getBoxDimensions();
	}

	bool LevelController::isLastLevel()
	{
		return level_model->isLastLevel();
	}

	void LevelController::loadNextLevel()
	{
		return level_model->loadNextLevel();
	}

	int LevelController::getCurrentLevelNumber()
	{
		return level_model->getCurrentLevelNumber();
	}

	void LevelController::resetLevels()
	{
		level_model->reset();
	}
}