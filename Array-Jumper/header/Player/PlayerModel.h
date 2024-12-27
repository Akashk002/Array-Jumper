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

		PlayerState player_state;
		int current_position;

	public:
		const int max_lives = 3;
		int current_lives;

		PlayerModel();
		~PlayerModel();

		void initialize();
		void update();
		void render();
		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);
		void resetPlayer();

		int getCurrentPosition();
		void setCurrentPosition(int new_position);
		int getCurrentLives();
		void resetPlayer();
		void decrementLife();
		void resetPosition();

	};
}
