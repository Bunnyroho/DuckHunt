#include "Fish.h"

Fish::Fish(float speed, SFMLObject* playerPtr, Score* scoreUIPtr, sf::Vector2f size, sf::Vector2f position)
{
	create(TextureAtlas::getInstance()->getTexture("fishTexture"), size, position);

	mSpeed = speed;
	mPlayerPtr = playerPtr;
	mScorePtr = scoreUIPtr;
}

void Fish::update(float deltaTime)
{
	mPosition.y += (mSpeed + (int)(mScorePtr->getFishCought() / 10.0f) * 50.0f) * deltaTime;

	if (mPosition.y > WINDOW_HEIGHT + mSize.y)
	{
		isDesignatedForTermination = true;

		mScorePtr->increaseScore(FishEndState::FishMissed);
	}

	if (mPosition.y + mSize.y / 2.0f > mPlayerPtr->getPosition().y - mPlayerPtr->getSize().y / 2.0f)
		if (abs(mPosition.x - mPlayerPtr->getPosition().x) < mSize.x / 2.0f + mPlayerPtr->getSize().x / 2.0f)
		{
			isDesignatedForTermination = true;

			mScorePtr->increaseScore(FishEndState::FishCought);
		}

	mSprite.setPosition(mPosition);
}