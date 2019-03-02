//Game header

#pragma once
#ifndef __game__
#define __game__

#include "event_handler.h"
#include "Common.h"

class game
{
private:
	common obj;
	Response r;
public:
	void init();
	void update();
	int mid_finder();
	void random_generator();
	void check();
};

#endif