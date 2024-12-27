#pragma once
#include "../Level/BlockType.h"
#include "MovementDirection.h"
#include "../Event/EventService.h"
#include "../../header/Level/BlockType.h"

using namespace Event;
using namespace Level;

namespace Player
{
	class BlockType;
	class PlayerView;
	class PlayerModel;
	enum class PlayerState;
	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;

		void destroy();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		EventService* event_service;

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		void move(MovementDirection direction);
		bool isPositionInBound(int targetPosition);

		void readInput();
		//BlockType getCurrentBoxValue(int currentPosition);
		Level::BlockType getCurrentBoxValue(int currentPosition);
		void jump(MovementDirection direction);
		void takeDamage();
		int getCurrentPosition();
	};
}