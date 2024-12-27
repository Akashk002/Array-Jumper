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
	};
}
