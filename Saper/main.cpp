#include <iostream>
#include "Board.h"
#include "Field.h"
#include "Scoreboard.h"
#include <Windows.h>

using namespace std;

int main()
{
	Board p;
	p.set_mode(0);
	p.lvl_select();
	p.create_board();
	p.create_clicked();
	p.create_bombs_list();
	p.bombs_draw();
	p.set_field_numbers();

	p.test();

	system("pause");

	return 0;
}
