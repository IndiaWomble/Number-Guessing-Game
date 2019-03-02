//Game source

#include "pch.h"
#include "game.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void game::init()
{
	obj.first = 0;
	obj.last = 1000;
	obj.correct = -1;
	obj.tries = 0;
	obj.choice = -1;
	for (int i = 1; i <= 1000; i++)
		obj.a[i] = i;
}

void game::update()
{
	cout << "Press 1 for yes, 2 if my answer is correct and 0 for no\n";
	while ((obj.first < obj.last || obj.tries < 10) && obj.correct == -1)
	{
		int mid_temp = mid_finder();
		cout << "Is your number greater than or equal to " << mid_temp << "?" << endl;
		r.in();
		switch (r.obj.choice)
		{
		case -1:
		{
			cout << "Invalid input!" << endl;
			break;
		}
		case 0:
		{
			obj.last = mid_temp;
			obj.tries++;
			break;
		}
		case 1:
		{
			obj.first = mid_temp;
			obj.tries++;
			break;
		}
		case 2:
		{
			obj.correct = mid_temp;
			cout << "Your number was - " << obj.correct << endl;
			obj.tries = 0;
			break;
		}
		}
	}
}

int game::mid_finder()
{
	obj.mid = (obj.first + obj.last) / 2;
	return obj.mid;
}

void game::random_generator()
{
	srand(time(0));
	obj.random = ((rand() % 1000) + 1);
}

void game::check()
{
	cout << "You have only 10 tries to guess my number\n";
	cout << "You can ask me 10 questions in the format - '</>/=_number_'\n";
	cout << obj.random << endl;
	string question, num;
	char oprtr;
	int temp;
	bool flag = false;
	while (flag != true && obj.tries < 10)
	{
		cin >> question;
		oprtr = question[0];
		num = question.substr(1);
		temp = stoi(num);
		if (oprtr == '<')
		{
			if (obj.random < temp)
				cout << "True\n";
			else
				cout << "False\n";
			obj.tries++;
		}
		else if (oprtr == '>')
		{
			if (obj.random > temp)
				cout << "True\n";
			else
				cout << "False\n";
			obj.tries++;
		}
		else if (oprtr == '=')
		{
			if (temp == obj.random)
			{
				flag = true;
				cout << "Correct! You got it!" << endl;
			}
			else
				cout << "Wrong! Try again...." << endl;
			obj.tries++;
		}
	}
	obj.tries = 0;
}