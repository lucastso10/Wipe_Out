//#pragma once
#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include <SFML/Window.hpp>

#include "Game.h"

class Controller
{
private:

	sf::Event event;

	Game* game;

	std::vector<bool> flags;

public:
	Controller(Game* game);
	~Controller();

	void eventHandler();
	void interpretKey();
};

#endif
