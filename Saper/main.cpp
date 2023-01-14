/*****************************************************************//**
 * \file   main.cpp
 * \brief  
 * Gra Saper
 * \author Piotr Miernik, Oskar Olub
 * \date   Styczen 2023
 *********************************************************************/

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "Board.h"
#include "Scoreboard.h"
#include "allegro.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
/// <summary>
/// Glowna funkcja programu.
/// </summary>
int main()
{
	srand(time(NULL));

	unsigned char running = 1;
	int game_state = 0; // 0 - w trakcie, 1 - wygrana, -1 - przegrana
	float mouse_x = 0, mouse_y = 0;

	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_TIMER* timer;
	ALLEGRO_TIMER* game_timer;
	ALLEGRO_BITMAP* baner;

	allegro_init();

	display = al_create_display(1000, 650);
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	game_timer = al_create_timer(1.0);
	baner = al_load_bitmap("img\\baner.bmp");

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_timer_event_source(game_timer));
	al_register_event_source(queue, al_get_mouse_event_source());

	al_set_window_title(display, "Gra Saper");
	al_start_timer(timer);

	allegro_display_menu();

	Board p;
	p.set_mode(0);

	while (running == 1)
	{

		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) running = 0;
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			mouse_x = event.mouse.x;
			mouse_y = event.mouse.y;
		}

		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (p.get_mode() == 0)
			{
				if (mouse_x >= 370 && mouse_x <= 630 && mouse_y >= 200 && mouse_y <= 280) p.set_mode(1);
				else if (mouse_x >= 370 && mouse_x <= 630 && mouse_y >= 300 && mouse_y <= 380) p.set_mode(2);
				else if (mouse_x >= 370 && mouse_x <= 630 && mouse_y >= 400 && mouse_y <= 480) p.set_mode(3);

				if (p.get_mode() != 0)
				{

					p.lvl_select();
					p.create_board();
					p.create_clicked();
					p.create_bombs_list();
					p.bombs_draw();
					p.set_field_numbers();
					p.clear_clicks_made();
					Scoreboard::bombs_remain = p.get_bombs();

					p.debug_log();

					al_start_timer(game_timer);
					al_clear_to_color(al_map_rgb(0, 0, 0));
				}
			}
			else if (p.get_mode() == 1 || p.get_mode() == 2 || p.get_mode() == 3)
				game_state = p.handle_field_click(mouse_x, mouse_y, &event);
		}


		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			if (p.get_mode() != 0)
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_bitmap(baner, 0, 0, 0);

				p.draw_fields();

				if (event.timer.source == game_timer && p.get_mode() != 10)
					Scoreboard::set_time(event.timer.count);
				Scoreboard::display_stats();

				if (game_state == 1)
				{
					p.set_mode(10);
					allegro_display_win();
				}
				else if (game_state == -1)
					p.set_mode(10);

				al_flip_display();
			}
		}
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_timer(game_timer);
	al_destroy_bitmap(baner);

	p.clear_memory();

	return 0;
}
