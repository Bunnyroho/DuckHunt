#pragma once

#include <SFML/Graphics.hpp>

class IDrawable
{
public:
	virtual void draw(sf::RenderWindow& window) {}
};