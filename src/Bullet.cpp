#include "Bullet.h"
#include <math.h>
#include <iostream>

Bullet::Bullet(sf::Texture* texture)
{
	this->animationClock.restart();

	this->setTexture(texture);
	this->enemiesHit = 0;

	this->health = 0.f;

	sf::Sprite sprite;
	sprite.setTexture(*texture);
	this->setSpeed(45.0f);
	this->setSprite(sprite);
	this->setTextureSpriteRect(sf::IntRect(0, 0, 16, 16)); // assume que utiliza uma textura 16x16 do pacote de textura all fire bullet pixels
	this->setScale(sf::Vector2f(2, 2));
	this->adjustOrigin();

	font.loadFromFile("../fonte/kenneypixel.ttf");
	damageNumber.setFont(this->font);
	damageNumber.setFillColor(sf::Color::Magenta);
	damageNumber.setOutlineColor(sf::Color::Black);
	damageNumber.setOutlineThickness(1.f);
	damageNumber.setOrigin(this->sprite.getLocalBounds().getSize() / 2.0f);
}

Bullet::~Bullet()
{
}

void Bullet::setDirection(sf::Vector2f ref_pos)
{
	sf::Vector2f enemyToPlayer = ref_pos - this->getPos();
	float distanceToPlayer = sqrt(enemyToPlayer.x * enemyToPlayer.x + enemyToPlayer.y * enemyToPlayer.y);

	sf::Vector2f movementDirection = enemyToPlayer / distanceToPlayer;
	this->direction = (movementDirection / 25.0f);
}

void Bullet::moveDirection()
{
	sf::IntRect newRect = this->getTextureSpriteRect();

	if (this->animationClock.getElapsedTime() >= sf::milliseconds(150)) {
		if (newRect.left == 48 )
			newRect.left = 0;
		else
			newRect.left += 16;
		this->animationClock.restart();
	}

	this->setTextureSpriteRect(newRect);
	this->move(this->direction);
}

sf::Text Bullet::drawDamage(int damage, bool crit) {	
	if (crit)
		damageNumber.setFillColor(sf::Color::Red);
	else
		damageNumber.setFillColor(sf::Color::Magenta);
	damageNumber.setCharacterSize(damage * 3);
	damageNumber.setPosition(this->getPos());
	damageNumber.setString(std::to_string(damage));
	this->textClock.restart();
	this->drawingText = true;
	return damageNumber;
}

sf::Text Bullet::drawDamage() {	
	if (255 - this->textClock.getElapsedTime().asMilliseconds() <= 100)
		this->drawingText = false;
	return damageNumber;
}


bool Bullet::getDrawingText()
{
	return this->drawingText;
}
