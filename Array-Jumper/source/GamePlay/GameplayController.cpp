#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

namespace Gameplay
{
	GameplayController::GameplayController()
	{

	}

	GameplayController::~GameplayController() {}

	void GameplayController::initialize()
	{
		startGame();
	}

	void GameplayController::update()
	{

	}

	void GameplayController::render()
	{

	}

	void GameplayController::startGame()
	{
		Main::GameService::setGameState(Main::GameState::GAMEPLAY);
		return Global::ServiceLocator::getInstance()->getLevelService()->resetLevels();
		return Global::ServiceLocator::getInstance()->getPlayerService()->resetPlayer();

	}

	void GameplayController::processobstacle()
	{
		Global::ServiceLocator::getInstance()->getPlayerService()->takeDamage();
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
	}

	bool GameplayController::isObstacle(Level::BlockType value)
	{
		if (value == Level::BlockType::OBSTACLE_ONE || value == Level::BlockType::OBSTACLE_TWO)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void GameplayController::onPositionChanged(int position)
	{
		Level::BlockType currentBoxValue = Global::ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValueFromController(position);

		if (isObstacle(currentBoxValue))
		{
			processobstacle();
		}
		else if (isEndBlock(currentBoxValue))
		{
			processEndBlock();
		}
	}

	bool GameplayController::isEndBlock(Level::BlockType value)
	{
		if (value == Level::BlockType::TARGET)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void GameplayController::processEndBlock()
	{
		Global::ServiceLocator::getInstance()->getPlayerService()->levelComplete();
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::LEVEL_COMPLETE);

		if (Global::ServiceLocator::getInstance()->getLevelService()->isLastLevel())
		{
			gameWon();
			return;
		}

		Global::ServiceLocator::getInstance()->getLevelService()->loadNextLevel();
	}

	void GameplayController::gameOver()
	{
		Main::GameService::setGameState(Main::GameState::CREDITS);
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
	}

	void GameplayController::onDeath()
	{
		gameOver();
	}

	void GameplayController::gameWon()
	{
		Main::GameService::setGameState(Main::GameState::CREDITS);
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::LEVEL_COMPLETE);
	}
}