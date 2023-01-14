#pragma once
/*****************************************************************//**
 * \file   Board.h
 * \brief  
 * Plik naglowkowy klasy Board
 * \author Piotr Miernik, Oskar Olub
 * \date   Styczen 2023
 *********************************************************************/
#include <allegro5/allegro5.h>
#include "Scoreboard.h"

/// <summary>
/// Klasa Board
/// </summary>
class Board : public Scoreboard
{
	//tablice
	int** p;
	int** clicked;
	unsigned short* bombs_list;
	// zmienne badaj¹ce
	unsigned short clicks_made;
	// zmienne zale¿ne od poziomu trudnoœci
	unsigned short mode;
	unsigned short bombs; // iloœæ bomb w sumie
	unsigned short x; //iloœæ bomb w OX
	unsigned short y; //iloœæ bomb w OY
	unsigned short margin_x;
	unsigned short margin_y;

	/// <summary>
	/// Alokacja pamieci dla dwuwymiarowej tablicy.
	/// 
	/// Ta statyczna metoda alokuje miejsce w pamieci dla dwuwymiarowe tablicy - planszy/macierzy odkrytych pol.
	/// </summary>
	/// <param name="x">Rozmiar planszy w osi X (zalezy od poziomu trudnosci)</param>
	/// <param name="y">Rozmiar planszy w osi Y (zalezy od poziomu trudnosci)</param>
	/// <returns>Wskaznik na zaalokowana pamiec</returns>
	static int** allocate_memory(unsigned short x, unsigned short y);

	/// <summary>
	/// Czyszczenie planszy.
	/// 
	/// Ta statyczna metoda czysci pamiec gry ustawiajac wartosci w tablicy na 0. Jest to przydatne podczas inicjowania rozgrywki, gdyz zapewnia, ze w pamieci nie pozostaly zadne niechciane dane, 
	/// oraz ze operacje wykonywane na tej tablicy dadza przewidywany skutek.
	/// </summary>
	/// <param name="tab">Wskaznik na dwuwymiarowa tablice</param>
	/// <param name="x">Rozmiar planszy w osi X (zalezy od poziomu trudnosci)</param>
	/// <param name="y">Rozmiar planszy w osi Y (zalezy od poziomu trudnosci)</param>
	static void clear_board(int** tab, unsigned short x, unsigned short y);

public:
	/// <summary>
	/// Debugowanie w konsoli.
	/// 
	/// Metoda ta wyswietla w konsoli plansze z oznaczonymi bombami oraz liczbami na polach
	/// </summary>
	void debug_log();

	/// <summary>
	/// Ustawianie trybu gry.
	/// 
	/// Metoda typu setter, ustawia przekazany w argumencie tryb gry.
	/// </summary>
	/// <param name="mode">Tryb gry</param>
	void set_mode(unsigned short mode);

	/// <summary>
	/// Odczytywanie trybu gry.
	/// 
	/// Metoda typu getter, zwraca obecny tryb gry.
	/// </summary>
	/// <returns>Tryb gry</returns>
	unsigned short get_mode();

	/// <summary>
	/// Wybieranie poziomu trudnosci.
	/// 
	/// Metoda ta odpowiada za ustawienie odpowiednich wartosci zmiennych w zaleznosci od wyboru poziomu trudnosci gry. Zmienia sie rozmiar planszy oraz ilosc bomb. 
	/// </summary>
	void lvl_select();

	/// <summary>
	/// Przygotowanie planszy.
	/// 
	/// Metoda ta wywoluje statyczna metode alokujaca pamiec, przypisuje ja do wskaznika oraz wywoluje statyczna metode zerujaca pamiec.
	/// </summary>
	void create_board();

	/// <summary>
	/// Przygotowanie macierzy pol odkrytych.
	/// 
	/// Metoda ta wywoluje statyczna metode alokujaca pamiec, przypisuje ja do wskaznika oraz wywoluje statyczna metode zerujaca pamiec.
	/// </summary>
	void create_clicked();

	/// <summary>
	/// Alokacja pamieci dla list bomb.
	/// 
	/// Metoda ta odpowiada za zaalokowanie pamieci dla tablicy bomb o wybranej dlugosci (zaleznie od ilosci bomb, ktora to zalezy od wybranego poziomu trudnosci).
	/// Tablica ta jest przeznaczona do zakodowania koordynatow bomb na planszy.
	/// </summary>
	void create_bombs_list();

	/// <summary>
	/// Losowanie bomb.
	/// 
	/// Metoda ta odpowiada za wylosowanie pozycji bomby oraz umieszczenie jej na planszy i w tablicy bomb.
	/// Oznaczenie bomby to wartosc "-1" (w tablicy planszy na odpowiednim miejscu pojawia sie wartosc -1).
	/// </summary>
	void bombs_draw();

	/// <summary>
	/// Numeracja pól.
	/// 
	/// Metoda ta odpowiada za nadanie kazdemu polu odpowiedniego numeru. Numerem tym jest ilosc bomb znajduj¹cych sie wokol tego pola, zatem wartosci sa z zakresu 0-8.
	/// Numery zapisywane sa w tablicy planszy.
	/// </summary>
	void set_field_numbers();

	/// <summary>
	/// Zwalnianie pamieci.
	/// 
	/// Metoda ta odpowiada za uwolnienie zaalokowanej pamieci (free()).
	/// </summary>
	void clear_memory();

	/// <summary>
	/// Rysowanie pol.
	/// 
	/// Metoda ta wywoluje funkcje rysujaca pola, przekazujac jej odpowiednie atrybuty obektu.
	/// </summary>
	void draw_fields();

	/// <summary>
	/// Odkrywanie bezpiecznych obszarow.
	/// 
	/// Metoda ta odpowiada za odkrycie calego obszaru, wokol ktorego nie znajduje sie zadna bomba (pola graficznie bez numerkow, w tablicy jako 0). Pola sa odkrywane rekurencyjnie az do
	/// napotkania pola z numerkiem dodatnim. 
	/// </summary>
	/// <param name="clicked_x">Zmienna przechowyjaca koordynat X kliknietego kafelka</param>
	/// <param name="clicked_y">Zmienna przechowyjaca koordynat Y kliknietego kafelka</param>
	void show_safe(int clicked_x, int clicked_y);

	/// <summary>
	/// Obsluga klikniec, informacje o stanie gry.
	/// 
	/// Metoda ta odpowiada za odczytanie pozycji kurosra w oknie gry w momencie wykonywania klikniecia i przeliczenia jej na koordynat kafelka, ktory znajdowal sie w tym momencie pod kursorem.
	/// Pozycja ta zapisywana jest w zmiennych przechowujacych te koordynaty.
	/// Dodatkowo metoda obsluguje sprawdzanie czy dany ruch jest dopuszczalny przez zasady, a takze zwraca informacje o obecnym stanie gry po wykonaniu przez uzytkownika poprawnej interakcji.
	/// </summary>
	/// <param name="mouse_x">Pozycja w osi X kursora w oknie programu</param>
	/// <param name="mouse_y">Pozycja w osi Y kursora w oknie programu</param>
	/// <param name="event">Wskaznik na instancje unii eventow z biblioteki Allegro5</param>
	/// <returns>Informacje o stanie gry. "-1" - przegrana, "1" - wygrana, "0" - gra w toku</returns>
	int handle_field_click(float mouse_x, float mouse_y, ALLEGRO_EVENT* event);

	/// <summary>
	/// Odczytywanie ilosci bomb.
	/// 
	/// Metoda typu getter, zwraca ilosc bomb w wybranym poziomie trudnosci.
	/// </summary>
	/// <returns>Ilosc bomb w wybranym poziomie trudnosci</returns>
	unsigned short get_bombs();

	/// <summary>
	/// Zerowanie licznika odslonietych pol.
	/// 
	/// Metoda ta zeruje zliczona ilosc odslonietych pol.
	/// </summary>
	void clear_clicks_made();
};

