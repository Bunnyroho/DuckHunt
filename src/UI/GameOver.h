#pragma once

#include <SFML/Graphics.hpp>

#include <Interface/IDrawable.h>
#include <Utils/Config.h>

class GameOver : public IDrawable
{
private:
	sf::Font mFont;
	sf::Text mGameOverText;

public:
	GameOver();

	virtual void draw(sf::RenderWindow& window);
};