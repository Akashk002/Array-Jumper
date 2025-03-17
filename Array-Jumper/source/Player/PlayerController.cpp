#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/MovementDirection.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"

namespace Player
{
	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
		level_service = new Level::LevelService();
	}

	PlayerController::~PlayerController()
	{
		destroy();
	}

	void PlayerController::initialize()
	{
		player_model->SetPlayerState(PlayerState::ALIVE);
		player_view->initialize();
		event_service = Global::ServiceLocator::getInstance()->getEventService();
	}

	void PlayerController::update()
	{
		player_view->update();
		readInput();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	void PlayerController::destroy()
	{
		delete(player_model);
		delete(player_view);
	}

	PlayerState PlayerController::GetPlayerState()
	{
		return player_model->GetPlayerState();
	}

	void PlayerController::SetPlayerState(PlayerState player_state)
	{
		player_model->SetPlayerState(player_state);
	}

	int PlayerController::getCurrentPosition()
	{
		return player_model->GetCurrentPosition();
	}

	void PlayerController::jump(MovementDirection direction)
	{
		int steps, targetPosition;
		int currentPosition = player_model->GetCurrentPosition();
		Level::BlockType box_value = Global::ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValueFromController(currentPosition);

		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = box_value;
			break;
		case MovementDirection::BACKWARD:
			steps = box_value;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = player_model->GetCurrentPosition() + steps;

		if (!isPositionInBound(targetPosition))
			return;

		player_model->SetCurrentPosition(targetPosition);
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::JUMP);
		Global::ServiceLocator::getInstance()->getGameplayService()->onPositionChanged(targetPosition);
	}

	void PlayerController::move(MovementDirection direction)
	{
		int steps, targetPosition;

		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = 1;
			break;
		case MovementDirection::BACKWARD:
			steps = -1;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = player_model->GetCurrentPosition() + steps;

		if (!isPositionInBound(targetPosition))
			return;

		player_model->SetCurrentPosition(targetPosition);
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::MOVE);
		Global::ServiceLocator::getInstance()->getGameplayService()->onPositionChanged(targetPosition);
	}

	Level::BlockType PlayerController::getCurrentBoxValue(int currentPosition)
	{
		return level_service->getCurrentBoxValueFromController(currentPosition);
	}

	void PlayerController::readInput()
	{
		if (event_service->pressedDKey() || event_service->pressedRightArrowKey())
		{
			if (event_service->heldSpaceKey())
			{
				jump(MovementDirection::FORWARD);
			}
			else
			{
				move(MovementDirection::FORWARD);
			}
		}
		else if (event_service->pressedAKey() || event_service->pressedLeftArrowKey())
		{
			if (event_service->heldSpaceKey())
			{
				jump(MovementDirection::BACKWARD);
			}
			else
			{
				move(MovementDirection::BACKWARD);
			}
		}
	}

	bool PlayerController::isPositionInBound(int targetPosition)
	{
		if (targetPosition >= 0 && targetPosition < Level::LevelData::number_of_boxes)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void PlayerController::takeDamage()
	{
		player_model->DecrementLife();
		if (player_model->GetCurrentLives() <= 0)
		{
			onDeath();
		}
		else
		{
			player_model->ResetPosition();
		}
	}

	void PlayerController::reset()
	{
		player_model->ResetPlayer();
	}

	int PlayerController::GetCurrentLives()
	{
		return player_model->GetCurrentLives();
	}

	void PlayerController::onDeath()
	{
		Global::ServiceLocator::getInstance()->getGameplayService()->onDeath();
		player_model->ResetPlayer();
	}
}