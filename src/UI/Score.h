#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>

#include <Utils/EnumFishEndState.h>
#include <Utils/Config.h>
#include <Interface/IDrawable.h>
#include <Interface/IUpdatable.h>

class Score : public IDrawable, public IUpdatable
{
private:
	int mFishMissed = 0, mFishCought = 0;

	sf::Font mFont;
	sf::Text mFishMissedText, mFishCoughtText;

public:
	Score();

	void increaseScore(FishEndState fishEndState);

	virtual void update(float deltaTime);
	virtual void draw(sf::RenderWindow& window);

	int getFishCought() { return mFishCought; }
	int getFishMissed() { return mFishMissed; }

	void reset();
};