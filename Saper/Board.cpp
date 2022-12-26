#include "Board.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void Board::test()
{
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Bombs: " << bombs << endl;
	cout << "margin_x: " << margin_x << endl;
	cout << "margin_y: " << margin_y << endl << endl;

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (p[i][j] == -1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x40);
			else if (p[i][j] == 0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00);
			else if (p[i][j] == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
			else if (p[i][j] == 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
			else if (p[i][j] == 3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
			else if (p[i][j] == 4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
			else if (p[i][j] == 5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
			else if (p[i][j] == 6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
			else if (p[i][j] == 7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);

			printf("%2d", p[i][j]);
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		putchar('\n');
	}
}


void Board::set_mode(unsigned short mode)
{
	//this->mode = mode;
	this->mode = 3; //! TYMCZASOWO USTAWIONE NA STA£Ê
}

void Board::lvl_select()
{
	switch (mode)
	{
	case 1:
		x = 9;
		y = 9;
		bombs = 10;
		margin_x = 365;
		margin_y = 265;
		break;
	case 2:
		x = 16;
		y = 16;
		bombs = 40;
		margin_x = 260;
		margin_y = 160;
		break;
	case 3:
		x = 30;
		y = 16;
		bombs = 99;
		margin_x = 50;
		margin_y = 160;
		break;
	default:
		x = 9;
		y = 9;
		bombs = 10;
		margin_x = 365;
		margin_y = 265;
		break;
	}
}

int** Board::allocate_memory(unsigned short x, unsigned short y)
{
	int** p;
	int* temp;

	p = (int**)malloc(
		sizeof(int*) * y +
		sizeof(int) * y * x
	);

	temp = (int*)&p[y];
	for (int i = 0; i < y; i++)
	{
		p[i] = temp;
		temp += x;
	}
	return p;
}

void Board::clear_board(int** tab, unsigned short x, unsigned short y)
{
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			tab[i][j] = 0;
}

void Board::create_board()
{
	p = allocate_memory(x, y);
	clear_board(p, x, y);
}

void Board::create_clicked()
{
	clicked = allocate_memory(x, y);
	clear_board(clicked, x, y);
}

void Board::create_bombs_list()
{
	bombs_list = (unsigned short*)malloc(sizeof(unsigned short) * bombs);
}

void Board::bombs_draw()
{
	unsigned short bombs = this->bombs;
	unsigned short x_b, y_b;
	unsigned short size = x * y;
	unsigned short q = bombs;
	while (bombs)
	{
		y_b = (rand() % size) / x;
		x_b = (rand() % size) % x;
		if (p[y_b][x_b] != -1)
		{
			p[y_b][x_b] = -1;
			bombs_list[q - bombs] = y_b * x + x_b;
			bombs--;
		}
	}
}

void Board::set_field_numbers()
{
	printf("   KOORDYNATY: \n");
	unsigned short bombs = this->bombs;
	int** tab = this->p;
	unsigned char x_b, y_b;
	unsigned short x_b_p, y_b_p;
	short pos_x, pos_y;
	for (int i = 0; i < bombs; i++)
	{
		y_b = bombs_list[i] / x;
		x_b = bombs_list[i] % x;
		printf("\n%3d.bomba: %3hu, y_b: %3hhu, x_b: %3hhu\n", i + 1, bombs_list[i], y_b, x_b);

		for (int j = 0; j < 9; j++)
		{
			y_b_p = j / 3;
			x_b_p = j % 3;
			pos_y = y_b + y_b_p - 1;
			pos_x = x_b + x_b_p - 1;

			if (!(pos_x < 0 || pos_y < 0 || pos_x > x - 1 || pos_y > y - 1 || tab[pos_y][pos_x] == -1))
				tab[pos_y][pos_x] += 1;
		}
	}
}
