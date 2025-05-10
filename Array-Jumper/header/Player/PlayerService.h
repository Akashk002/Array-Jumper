#pragma once

namespace Player
{
	class PlayerController;

	class PlayerService
	{
	private:
		PlayerController* player_controller;

		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void takeDamage();

		void initialize();
		void update();
		void render();

		int GetCurrentLives();
		void resetPlayer();

		void levelComplete();
	};
}