#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "../Level/LevelModel.h"

using namespace Level;

namespace Player
{
	class PlayerController;
	class PlayerView
	{
	private:
		sf::RenderWindow* game_window;
		UI::UIElement::ImageView* player_image;

		float player_height;
		float player_width;

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		void calculatePlayerDimensions();
		void updatePlayerPosition();
			sf::Vector2f calulcatePlayerPosition();
			PlayerController* player_controller;

			BoxDimensions current_box_dimensions;

	public:
		PlayerView(PlayerController* player_controller);

		~PlayerView();

		void initialize();
		void update();
		void render();

		
	};
}