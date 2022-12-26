#pragma once
class Board
{
	// tablice
	int** p;
	int** clicked;
	unsigned short* bombs_list;
	// zmienne badaj¹ce
	unsigned short clicks_made;
	// zmienne zale¿ne od poziomu trudnoœci
	unsigned short mode;
	unsigned short bombs; // iloœæ bomb w sumie
	unsigned short x; //iloœæ bomb w OX
	unsigned short y;
	unsigned short margin_x;
	unsigned short margin_y;

	static int** allocate_memory(unsigned short, unsigned short);
	static void clear_board(int**, unsigned short, unsigned short);

public:
	void test();
	void set_mode(unsigned short);
	void lvl_select();
	void create_board();
	void create_clicked();
	void create_bombs_list();
	void bombs_draw();
	void set_field_numbers();

};

