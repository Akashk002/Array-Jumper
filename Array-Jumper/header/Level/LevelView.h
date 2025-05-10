#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Level/LevelModel.h"

namespace Level
{
	class LevelController;

	class LevelView
	{
	private:
		sf::RenderWindow* game_window;
		LevelController* level_controller;
		BoxDimensions box_dimensions;

		UI::UIElement::ImageView* target_overlay_image;
		UI::UIElement::ImageView* letter_one_overlay_image;
		UI::UIElement::ImageView* letter_two_overlay_image;
		UI::UIElement::ImageView* letter_three_overlay_image;
		UI::UIElement::ImageView* obstacle_one_overlay_image;
		UI::UIElement::ImageView* obstacle_two_overlay_image;
		UI::UIElement::ImageView* background_image;
		UI::UIElement::ImageView* box_image;
		const float background_alpha = 110.f;

		void createImages();
		void initializeImages();
		void updateImages();
		void drawLevel();
		void deleteImages();


	public:
		LevelView(LevelController* controller);
		~LevelView();

		void initialize();
		void update();
		void render();

		void drawBox(sf::Vector2f position);
		void drawBoxValue(sf::Vector2f position, BlockType box_value);

		UI::UIElement::ImageView* getBoxOverlayImage(BlockType block_type);
		void calculateBoxDimensions();
		void calculateBoxWidthHeight();
		void calculateBoxSpacing();

		BoxDimensions getBoxDimensions();
		sf::Vector2f calculateBoxPosition(int index);
	};
}