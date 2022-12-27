#pragma once
#include <allegro5/allegro5.h>
#include "Scoreboard.h"
class Board : public Scoreboard
{
	// tablice
	int** p;
	int** clicked;
	unsigned short* bombs_list;
	// zmienne badaj�ce
	unsigned short clicks_made;
	// zmienne zale�ne od poziomu trudno�ci
	unsigned short mode;
	unsigned short bombs; // ilo�� bomb w sumie
	unsigned short x; //ilo�� bomb w OX
	unsigned short y;
	unsigned short margin_x;
	unsigned short margin_y;

	static int** allocate_memory(unsigned short, unsigned short);
	static void clear_board(int**, unsigned short, unsigned short);

public:
	void test();
	void set_mode(unsigned short);
	unsigned short get_mode();
	void lvl_select();
	void create_board();
	void create_clicked();
	void create_bombs_list();
	void bombs_draw();
	void set_field_numbers();
	void clear_memory();
	void draw_fields();
	void show_safe(int, int);
	int handle_field_click(float, float, ALLEGRO_EVENT*);
	unsigned short get_bombs();
};

