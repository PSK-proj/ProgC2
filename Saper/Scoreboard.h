#pragma once
class Scoreboard
{
	static int time;

public:
	static short bombs_remain;
	static void display_stats();
	static short get_bombs_remain();
	static void set_bombs_remain(short);
	static int get_time();
	static void set_time(int);
};

