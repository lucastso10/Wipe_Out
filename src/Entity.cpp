#include "Entity.h"
#include <iostream>

Entity::~Entity() 
{
	delete texture;
	this->texture = nullptr;
}

bool Entity::isOnScreen(const sf::RenderWindow* screen)
{
	if (screen->mapPixelToCoords(sf::Vector2i(screen->getSize())).x <= sprite.getGlobalBounds().left || screen->mapPixelToCoords(sf::Vector2i(0,0)).x >= sprite.getGlobalBounds().left + sprite.getTextureRect().width)
		return false;

	if (screen->mapPixelToCoords(sf::Vector2i(screen->getSize())).y <= sprite.getGlobalBounds().top || screen->mapPixelToCoords(sf::Vector2i(0,0)).y >= sprite.getGlobalBounds().top + sprite.getTextureRect().height)
		return false;
		
	return true;
}

void Entity::setPos(sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

sf::Vector2f Entity::getPos()
{
	return sprite.getPosition();
}

void Entity::setSprite(sf::Sprite sprite)
{
	this->sprite = sprite;
}

sf::Sprite Entity::getSprite()
{
	return this->sprite;
}

void Entity::setTexture(sf::Texture* texture)
{
	this->texture = texture;
}

void Entity::setTextureSpriteRect(sf::IntRect rect)
{
	this->sprite.setTextureRect(rect);
}

sf::IntRect Entity::getTextureSpriteRect()
{
	return this->sprite.getTextureRect();
}

void Entity::adjustOrigin()
{
	this->sprite.setOrigin((this->sprite.getLocalBounds().getSize() / 2.0f));
}

void Entity::move(sf::Vector2f direction)
{
	this->sprite.move(direction * this->speed);
}

bool Entity::isDead()
{
	return this->health <= 0;
}

float Entity::getHealth() {
	return this->health;
}

float Entity::getSpeed() {
	return this->speed;
}

void Entity::setHealth(float health) 
{
	this->health = health;
}

void Entity::setSpeed(float speed) 
{
	this->speed = speed;
}

void Entity::setScale(sf::Vector2f scale)
{
	this->sprite.setScale(scale);
}

void Entity::flip()
{
	this->sprite.setScale(this->sprite.getScale().x * -1, this->sprite.getScale().y);
}
