#include "Application.h"

Application::Application(const std::string& title)
{
	try {
		TextureAtlas::getInstance()->loadTextureFromFile("res/fish.png", "fishTexture");
	}
	catch (std::runtime_error error) {
		std::cerr << error.what() << std::endl;
		TextureAtlas::getInstance()->loadTextureFromFile("res/placeholder.png", "fishTexture");
	}

	try {
		TextureAtlas::getInstance()->loadTextureFromFile("res/duckL.png", "duckLTexture");
	}
	catch (std::runtime_error error) {
		std::cerr << error.what() << std::endl;
		TextureAtlas::getInstance()->loadTextureFromFile("res/placeholder.png", "duckLTexture");
	}

	try {
		TextureAtlas::getInstance()->loadTextureFromFile("res/duckR.png", "duckRTexture");
	}
	catch (std::runtime_error error) {
		std::cerr << error.what() << std::endl;
		TextureAtlas::getInstance()->loadTextureFromFile("res/placeholder.png", "duckRTexture");
	}

	try {
		mScoreUI = new Score();
		mGameOverUI = new GameOver();
	}
	catch (std::runtime_error error)
	{
		std::cerr << error.what() << std::endl;
	}

	mWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), title);

	mObjects.push_back(new Duck(500.0f, sf::Vector2f(75.0f, 75.0f), sf::Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT - 100.0f)));
}

Application::~Application()
{
	for (SFMLObject* object : mObjects)
		delete object;

	delete mScoreUI;

	TextureAtlas::getInstance()->clear();
}

void Application::mainLoop()
{
	sf::Clock deltaClock;

	while (mWindow.isOpen())
	{
		sf::Time deltaTime = deltaClock.restart();

		handleinput();
		update(deltaTime.asSeconds());
		render();
	}
}

void Application::handleinput()
{
	sf::Event windowEvent;
	if (mWindow.pollEvent(windowEvent))
	{
		switch (windowEvent.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::KeyPressed:
			switch (windowEvent.key.code)
			{
			case sf::Keyboard::R:
				resetGame();
				break;
			}
			break;
		}
	}
}

void Application::update(float deltaTime)
{
	if (mScoreUI->getFishMissed() >= 5)
		return;

	fishSpawnTimer += deltaTime;
	if (fishSpawnTimer > 1.0f)
	{
		mObjects.push_back(new Fish(200.0f, mObjects[0], mScoreUI, sf::Vector2f(25, 50), sf::Vector2f((float)(rand() % 740 + 30), -100.0f)));
		fishSpawnTimer = 0.0f;
	}

	for (int i = 0; i < mObjects.size(); ++i)
		mObjects[i]->update(deltaTime);

	mScoreUI->update(deltaTime);

	mObjects.erase(std::remove_if(mObjects.begin(), mObjects.end(), [](SFMLObject* object) { return object->getIsDesignatedForTermination(); }), mObjects.end());
}

void Application::render()
{
	mWindow.clear(sf::Color(255, 192, 128, 255));

	for (SFMLObject* object : mObjects)
		object->draw(mWindow);

	mScoreUI->draw(mWindow);

	if (mScoreUI->getFishMissed() >= 5)
		mGameOverUI->draw(mWindow);

	mWindow.display();
}

void Application::resetGame()
{
	for (SFMLObject* object : mObjects)
		delete object;

	mObjects.clear();

	mObjects.push_back(new Duck(500.0f, sf::Vector2f(75.0f, 75.0f), sf::Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT - 100.0f)));
	mScoreUI->reset();
}
