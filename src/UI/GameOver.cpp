#include "GameOver.h"

GameOver::GameOver()
{
	if (FILE* file = fopen("res/arial.ttf", "r"))
		fclose(file);
	else
		throw std::runtime_error("Default font - could not be found");

	mFont.loadFromFile("res/arial.ttf");

	mGameOverText.setFont(mFont);
	mGameOverText.setString("       You lost\nPress R to restart");
	mGameOverText.setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f) - sf::Vector2f(mGameOverText.getGlobalBounds().width /2.0f, mGameOverText.getGlobalBounds().height / 2.0f));
}

void GameOver::draw(sf::RenderWindow& window)
{
	window.draw(mGameOverText);
}
