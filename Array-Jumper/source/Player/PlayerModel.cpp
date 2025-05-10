#include "../../header/Player/PlayerModel.h"

namespace Player
{
	int PlayerModel::GetCurrentPosition()
	{
		return current_position;
	}

	void PlayerModel::SetCurrentPosition(int new_position)
	{
		current_position = new_position;
	}

	PlayerState PlayerModel::GetPlayerState()
	{
		return player_state;
	}

	void PlayerModel::SetPlayerState(PlayerState new_player_state)
	{
		player_state = new_player_state;
	}

	int PlayerModel::GetCurrentLives()
	{
		return current_lives;
	}

	void PlayerModel::ResetPlayer()
	{
		current_position = 0;
		player_state = PlayerState::ALIVE;
		current_lives = max_lives;
	}

	void PlayerModel::DecrementLife()
	{
		current_lives--;
	}

	void PlayerModel::ResetPosition()
	{
		current_position = 0;
	}
}