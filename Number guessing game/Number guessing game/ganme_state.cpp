//Gmae State Source

#include "pch.h"
#include "game_state.h"
#include <iostream>

using namespace std;

void game_state::game_over()
{
	cout << "Wanna Play again?\n";
	cout << "press 1 for yes and 0 for no\n";
	int c;
	cin >> c;
	switch (c)
	{
	case 0:
	{
		current_state = GAME_OVER;
		exit(0);
	}
	case 1:
	{
		running();
	}
	}
}

void game_state::running()
{
	cout << "\t\t\t\t\t\tNUMBER GUESSING GAME" << endl;
	cout << "Do you want to guess the number or do you want me to guess yours? \n";
	cout << "Enter 1 if you want to guess the number and 0 if you want me to guess\n";
	int c;
	cin >> c;
	switch (c)
	{
	case 0:
	{
		current_state = RUNNING_CPU;
		break;
	}
	case 1:
	{
		current_state = RUNNING_PLAYER;
		break;
	}
	}
	switch (current_state)
	{
	case RUNNING_CPU:
	{
		obj.init();
		obj.update();
		break;
	}
	case RUNNING_PLAYER:
	{
		obj.random_generator();
		obj.check();
		break;
	}
	}
	current_state = GAME_OVER;
	game_over();
}