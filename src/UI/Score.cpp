#include "Score.h"

Score::Score()
{
	if (FILE* file = fopen("res/arial.ttf", "r"))
		fclose(file);
	else
		throw std::runtime_error("Default font - could not be found");

	mFont.loadFromFile("res/arial.ttf");

	mFishCoughtText.setFont(mFont);
	mFishCoughtText.setPosition(sf::Vector2f(10.0f, 10.0f));

	mFishMissedText.setFont(mFont);
	mFishMissedText.setPosition(sf::Vector2f(WINDOW_WIDTH - 220.0f, 10.0f));
}

void Score::increaseScore(FishEndState fishEndState)
{
	if (fishEndState == FishEndState::FishCought)
		mFishCought += 1;
	else
		mFishMissed += 1;
}

void Score::update(float deltaTime)
{
	std::stringstream leftScoreText;
	leftScoreText << "Fish cought: " << mFishCought;

	std::stringstream rightScoreText;
	rightScoreText << "Fish missed: " << mFishMissed;

	mFishCoughtText.setString(leftScoreText.str());
	mFishMissedText.setString(rightScoreText.str());
}

void Score::draw(sf::RenderWindow& window)
{
	window.draw(mFishCoughtText);
	window.draw(mFishMissedText);
}

void Score::reset()
{
	mFishCought = 0;
	mFishMissed = 0;
}
