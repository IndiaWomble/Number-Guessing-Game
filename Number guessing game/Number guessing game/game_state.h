//Game State Header

#pragma once
#ifndef __game_state__
#define __game_state__

#include "game.h"

class game_state
{
	enum states
	{
		GAME_OVER,
		RUNNING_CPU,
		RUNNING_PLAYER
	};
	int current_state;
	game obj;
public:
	void game_over();
	void running();
};

#endif