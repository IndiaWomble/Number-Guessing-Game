//Event Handler Source

#include "pch.h"
#include "event_handler.h"
#include <iostream>

using namespace std;

void Response::in()
{
	int choice;
	cin >> choice;
	if (choice == 0 || choice == 1 || choice == 2)
		obj.choice = choice;
	else
		obj.choice = -1;
}