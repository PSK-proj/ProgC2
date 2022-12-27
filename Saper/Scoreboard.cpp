#include "Scoreboard.h"
#include "allegro.h"


void Scoreboard::display_stats()
{
	allegro_display_stats(bombs_remain, time);
}

short Scoreboard::get_bombs_remain()
{
	return  bombs_remain;
}

void Scoreboard::set_bombs_remain(short a)
{
	bombs_remain = a;
}

int Scoreboard::get_time()
{
	return time;
}

void Scoreboard::set_time(int a)
{
	time = a;
}

short Scoreboard::bombs_remain = 0;
int Scoreboard::time = 0;