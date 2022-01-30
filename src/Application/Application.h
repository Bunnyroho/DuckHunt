#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

#include <Utils/EnumFishEndState.h>
#include <Utils/TextureAtlas.h>
#include <Object/SFMLObject.h>
#include <Object/Duck.h>
#include <Object/Fish.h>
#include <UI/Score.h>
#include <UI/GameOver.h>

class Application
{
private:
	sf::RenderWindow mWindow;

	std::vector<SFMLObject*> mObjects;
	Score* mScoreUI;
	GameOver* mGameOverUI;

	float fishSpawnTimer = 0.0f;

public:
	Application(const std::string& title);
	~Application();

	void mainLoop();

	void handleinput();
	void update(float deltaTime);
	void render();

	void resetGame();
};