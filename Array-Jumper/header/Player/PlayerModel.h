#pragma once

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private:
		const int max_lives = 3;
		int current_position;
		int current_lives = max_lives;
		PlayerState player_state;

	public:

		int GetCurrentPosition();
		PlayerState GetPlayerState();
		void SetCurrentPosition(int new_position);
		void SetPlayerState(PlayerState new_player_state);

		void initialize();

		int GetCurrentLives();
		void ResetPlayer();
		void DecrementLife();
		void ResetPosition();
	};
}