#include "../../header/Player/PlayerView.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

using namespace UI::UIElement;
using namespace Global;

namespace Player
{
	PlayerView::PlayerView()
	{
		game_window = nullptr;
		player_image = new ImageView();
	}

	PlayerView::PlayerView(PlayerController* controller)
	{
		player_controller = controller;
		game_window = nullptr;
	}

	PlayerView::~PlayerView() {}

	void PlayerView::initialize()
	{
		//Yet to Implement
	}

	void PlayerView::update()
	{
		//Yet to implement
	}

	void PlayerView::render()
	{
		switch (player_controller->getPlayerState())
		{
		case PlayerState::ALIVE:
			drawPlayer();
			break;
		}
	}
	void PlayerView::CalculatePlayerDimensions()
	{
		current_box_dimensions = ServiceLocator::getInstance()->getLevelService()->getBoxDimensions();
		player_height = current_box_dimensions.box_height;
		player_width = current_box_dimensions.box_width;
	}
	void PlayerView::initializePlayerImage()
	{
		player_image->initialize(Config::character_texture_path,
			player_width,
			player_height,
			sf::Vector2f(0, 0));
	}
	void PlayerView::loadPlayer()
	{
		calculatePlayerDimensions();
		initializePlayerImage();
	}
	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		loadPlayer();
	}
	sf::Vector2f PlayerView::calulcatePlayerPosition()
	{
		float xPosition = current_box_dimensions.box_spacing + static_cast<float>(player_controller->getCurrentPosition()) * (current_box_dimensions.box_width + current_box_dimensions.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y) - current_box_dimensions.box_height - current_box_dimensions.bottom_offset - player_height;
		return sf::Vector2f(xPosition, yPosition);
	}
	void PlayerView::updatePlayerPosition()
	{
		player_image->setPosition(calulcatePlayerPosition());
	}
	void PlayerView::drawPlayer()
	{
		player_image->render();
	}
}