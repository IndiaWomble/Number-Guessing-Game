//Number Guessing Game

#include "pch.h"
#include "common.h"
#include "event_handler.h"
#include "game.h"
#include "game_state.h"
#include <iostream>

using namespace std;

int main()
{
	game_state obj;
	obj.running();
	getchar();
	return 0;
}
