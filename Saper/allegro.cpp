#include <stdio.h>
#include <cstdlib>
#include "allegro.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

void allegro_init()
{
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
}

void allegro_display_menu()
{
	ALLEGRO_BITMAP* baner;
	ALLEGRO_BITMAP* mode1;
	ALLEGRO_BITMAP* mode2;
	ALLEGRO_BITMAP* mode3;

	baner = al_load_bitmap("img\\baner.bmp");
	mode1 = al_load_bitmap("img\\mode1.bmp");
	mode2 = al_load_bitmap("img\\mode2.bmp");
	mode3 = al_load_bitmap("img\\mode3.bmp");

	al_draw_bitmap(baner, 0, 0, 0);
	al_draw_bitmap(mode1, 370, 200, 0);
	al_draw_bitmap(mode2, 370, 300, 0);
	al_draw_bitmap(mode3, 370, 400, 0);

	al_flip_display();

	al_destroy_bitmap(baner);
	al_destroy_bitmap(mode1);
	al_destroy_bitmap(mode2);
	al_destroy_bitmap(mode3);
}

void allegro_display_win()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	ALLEGRO_BITMAP* baner;
	ALLEGRO_BITMAP* win;
	baner = al_load_bitmap("img\\baner.bmp");
	win = al_load_bitmap("img\\win.bmp");
	al_draw_bitmap(baner, 0, 0, 0);
	al_draw_bitmap(win, 0, 80, 0);
	al_flip_display();
	al_destroy_bitmap(baner);
	al_destroy_bitmap(win);
}

void allegro_draw_fields(int** tab, int** clicked, unsigned short x, unsigned short y, unsigned short margin_x, unsigned short margin_y)
{
	ALLEGRO_BITMAP* hidden;
	ALLEGRO_BITMAP* flag;
	ALLEGRO_BITMAP* bomb;
	ALLEGRO_BITMAP* empty;
	ALLEGRO_BITMAP* one;
	ALLEGRO_BITMAP* two;
	ALLEGRO_BITMAP* three;
	ALLEGRO_BITMAP* four;
	ALLEGRO_BITMAP* five;
	ALLEGRO_BITMAP* six;
	ALLEGRO_BITMAP* seven;
	ALLEGRO_BITMAP* eight;

	hidden = al_load_bitmap("img\\hidden.bmp");
	flag = al_load_bitmap("img\\flag.bmp");
	bomb = al_load_bitmap("img\\bomb.bmp");
	empty = al_load_bitmap("img\\empty.bmp");
	one = al_load_bitmap("img\\1.bmp");
	two = al_load_bitmap("img\\2.bmp");
	three = al_load_bitmap("img\\3.bmp");
	four = al_load_bitmap("img\\4.bmp");
	five = al_load_bitmap("img\\5.bmp");
	six = al_load_bitmap("img\\6.bmp");
	seven = al_load_bitmap("img\\7.bmp");
	eight = al_load_bitmap("img\\8.bmp");

	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
		{
			if (clicked[i][j] == 0)
				al_draw_bitmap(hidden, margin_x + j * 30, margin_y + i * 30, 0);
			else if (clicked[i][j] == -2)
				al_draw_bitmap(flag, margin_x + j * 30, margin_y + i * 30, 0);
			else if (clicked[i][j] == 10)
			{
				switch (tab[i][j])
				{
				case -1: al_draw_bitmap(bomb, margin_x + j * 30, margin_y + i * 30, 0); break;
				case 0: al_draw_bitmap(empty, margin_x + j * 30, margin_y + i * 30, 0); break;
				case 1: al_draw_bitmap(one, margin_x + j * 30, margin_y + i * 30, 0); break;
				case 2: al_draw_bitmap(two, margin_x + j * 30, margin_y + i * 30, 0); break;
				case 3: al_draw_bitmap(three, margin_x + j * 30, margin_y + i * 30, 0); break;
				case 4: al_draw_bitmap(four, margin_x + j * 30, margin_y + i * 30, 0); break;
				case 5: al_draw_bitmap(five, margin_x + j * 30, margin_y + i * 30, 0); break;
				case 6: al_draw_bitmap(six, margin_x + j * 30, margin_y + i * 30, 0); break;
				case 7: al_draw_bitmap(seven, margin_x + j * 30, margin_y + i * 30, 0); break;
				case 8: al_draw_bitmap(eight, margin_x + j * 30, margin_y + i * 30, 0); break;
				}
			}
		}


	al_destroy_bitmap(hidden);
	al_destroy_bitmap(flag);
	al_destroy_bitmap(bomb);
	al_destroy_bitmap(empty);
	al_destroy_bitmap(one);
	al_destroy_bitmap(two);
	al_destroy_bitmap(three);
	al_destroy_bitmap(four);
	al_destroy_bitmap(five);
	al_destroy_bitmap(six);
	al_destroy_bitmap(seven);
	al_destroy_bitmap(eight);
}

void allegro_display_stats(short bombs_remain, int time)
{
	char* bombs_string = (char*)malloc(4);
	snprintf(bombs_string, 4, "%hi", bombs_remain);

	char* time_string = (char*)malloc(6);
	snprintf(time_string, 6, "%d", time);

	ALLEGRO_FONT* roboto_regular;
	ALLEGRO_FONT* roboto_bold_italic;
	roboto_regular = al_load_font("fonts\\Roboto-Regular.ttf", 20, 0);
	roboto_bold_italic = al_load_font("fonts\\Roboto-BoldItalic.ttf", 20, 0);

	al_draw_text(roboto_regular, al_map_rgb(255, 73, 0), 200, 110, ALLEGRO_ALIGN_LEFT, "Bomby: ");
	al_draw_text(roboto_bold_italic, al_map_rgb(255, 122, 0), 270, 110, ALLEGRO_ALIGN_LEFT, bombs_string);

	al_draw_text(roboto_regular, al_map_rgb(255, 73, 0), 700, 110, ALLEGRO_ALIGN_LEFT, "Czas: ");
	al_draw_text(roboto_bold_italic, al_map_rgb(255, 122, 0), 770, 110, ALLEGRO_ALIGN_LEFT, time_string);

	al_destroy_font(roboto_regular);
	al_destroy_font(roboto_bold_italic);
}