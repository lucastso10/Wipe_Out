#include "Player.h"
#include <iostream>
Player::Player(std::string file, sf::Vector2f start_pos)
{
	this->setHealth(100);
	this->setArmor(20);
	this->setSpeed(2);

	this->xp = 0;
	this->level = 0;
	this->isWalking = false;
	
	sf::Texture* texture = new sf::Texture;
	sf::Sprite sprite;

	texture->loadFromFile(file);
	sprite.setTexture(*texture);

	this->setTexture(texture);
	this->setSprite(sprite);
	this->setPos(start_pos);
	this->setTextureSpriteRect(sf::IntRect(12, 0, 26, 26));
	this->setScale(sf::Vector2f(1.5f, 1.5f));
	this->animationClock.restart();
	this->adjustOrigin();
	
}

Player::~Player()
{
}

void Player::setWalking(bool walking)
{
	this->isWalking = walking;
}

void Player::animate()
{
	if (this->animationClock.getElapsedTime() >= sf::milliseconds(120)) {
		sf::IntRect newRect;

		if (this->isWalking) {
			newRect = this->getTextureSpriteRect();

			if (newRect.top == 182)
				newRect.top = 0;
			else
				newRect.top += 26;
		}
		else {
			newRect = sf::IntRect(12, 0, 26, 26);
		}

		this->setTextureSpriteRect(newRect);

		this->animationClock.restart();
	}
}

void Player::levelUp()
{	
}

