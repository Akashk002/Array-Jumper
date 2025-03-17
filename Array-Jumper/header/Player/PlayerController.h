#pragma once
#include "../../header/Event/EventService.h"
#include "../../header/Level/BlockType.h"
#include "../../header/Level/LevelService.h"

namespace Player
{
	enum class PlayerState;
	class PlayerView;
	class PlayerModel;
	enum MovementDirection;

	class PlayerController
	{
	private:
		PlayerView* player_view;
		PlayerModel* player_model;
		Event::EventService* event_service;
		Level::LevelService* level_service;


		void destroy();
	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();
		void move(MovementDirection direction);
		void readInput();
		void jump(MovementDirection direction);
		void takeDamage();
		void reset();
		void onDeath();

		int GetCurrentLives();

		Level::BlockType getCurrentBoxValue(int currentPosition);

		int getCurrentPosition();
		bool isPositionInBound(int targetPosition);

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState player_state);
	};
}