#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"

namespace Level
{
	using namespace Global;
	using namespace UI::UIElement;
	using namespace Level;

	LevelView::LevelView()
	{
		game_window = nullptr;

		createImages();
	}

	void LevelView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		calculateBoxExtents();
		initializeImages();
	}

	void LevelView::update()
	{
		updateImages();
	}

	void LevelView::render()
	{
		drawLevel();
	}

	BoxDimentions LevelView::getBoxDimentions()
	{
		return box_dimentions;
	}

	void LevelView::createImages()
	{
		background_image = new ImageView();

		box_image = new ImageView();
		target_overlay_image = new ImageView();
		letter_one_overlay_image = new ImageView();
		letter_two_overlay_image = new ImageView();
		letter_three_overlay_image = new ImageView();
		obstacle_one_overlay_image = new ImageView();
		obstacle_two_overlay_image = new ImageView();
	}

	void LevelView::initializeImages()
	{
		background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		background_image->setImageAlpha(background_alpha);

		
		box_image->initialize(Config::box_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
		target_overlay_image->initialize(Config::target_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
		letter_one_overlay_image->initialize(Config::letter_one_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
		letter_two_overlay_image->initialize(Config::letter_two_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
		letter_three_overlay_image->initialize(Config::letter_three_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
		obstacle_one_overlay_image->initialize(Config::obstacle_01_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
		obstacle_two_overlay_image->initialize(Config::obstacle_02_texture_path, box_dimentions.box_width, box_dimentions.box_height, sf::Vector2f(0, 0));
	}

	void LevelView::updateImages()
	{
		background_image->update();

		box_image->update();
		target_overlay_image->update();
		letter_one_overlay_image->update();
		letter_two_overlay_image->update();
		letter_three_overlay_image->update();
		obstacle_one_overlay_image->update();
		obstacle_two_overlay_image->update();
	}
	
	void LevelView::drawLevel()
	{
		background_image->render();

		for (int i = 0; i < LevelData::NUMBER_OF_BOXES; ++i)
		{
			sf::Vector2f position = calculateBoxPosition(i);

			box_image->setPosition(position);
			box_image->render();

			ImageView* image = getBoxOverlayImage(i);
			image->setPosition(position);
			image->render();

		}
	}

	void LevelView::calculateBoxExtents() // Not readable. Add helper functions 
	{
		if (!game_window) return;

		calculateBoxWidthHeight();
		calculateBoxSpacing();

	}


	void LevelView::calculateBoxWidthHeight()
	{
		float screenWidth = static_cast<float>(game_window->getSize().x);
		int numBoxes = LevelData::NUMBER_OF_BOXES;
		
		//Each Box has a Gap on it's left, 1 extra gap for last block's right side
		int numGaps = numBoxes + 1; 

		//Total space consumed by all gaps
		float totalSpaceByGaps = box_dimentions.box_spacing_percentage * static_cast<float>(numGaps); 

		//Total space consumed by boxes and gaps
		float totalSpace = numBoxes + totalSpaceByGaps;
		
		box_dimentions.box_width = screenWidth / (totalSpace);
		box_dimentions.box_height = box_dimentions.box_width;
	}

	void LevelView::calculateBoxSpacing()
	{
		box_dimentions.box_spacing = box_dimentions.box_spacing_percentage * box_dimentions.box_width;
	}

	sf::Vector2f LevelView::calculateBoxPosition(int index)
	{
		float xPosition = box_dimentions.box_spacing + static_cast<float>(index) * (box_dimentions.box_width + box_dimentions.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y) - box_dimentions.box_height - box_dimentions.bottom_offset;
		return sf::Vector2f(xPosition, yPosition);
	}

	ImageView* LevelView::getBoxOverlayImage(int index)
	{
		switch (current_level_data.level_boxes[index])
		{
		case BlockType::OBSTACLE_ONE:
			return obstacle_one_overlay_image;

		case BlockType::OBSTACLE_TWO:
			return obstacle_two_overlay_image;

		case BlockType::ONE:
			return letter_one_overlay_image;

		case BlockType::TWO:
			return letter_two_overlay_image;

		case BlockType::THREE:
			return letter_three_overlay_image;

		case BlockType::TARGET:
			return target_overlay_image;
		}
		return nullptr;
	}


}