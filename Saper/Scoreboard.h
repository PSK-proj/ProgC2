#pragma once
/*****************************************************************//**
 * \file   Scoreboard.h
 * \brief  
 * Plik naglowkowy klasy Scoreboard
 * \author Piotr Miernik, Oskar Olub
 * \date   Styczen 2023
 *********************************************************************/

/// <summary>
/// Klasa Scoreboard
/// </summary>
class Scoreboard
{
	static int time;

public:
	/// <summary>
	/// Atrybut przechowujacy ilosc pozostalych bomb.
	/// </summary>
	static short bombs_remain;
	/// <summary>
	/// Wyswietlnie statystyk.
	/// 
	/// Metoda ta wywoluje funkcje wyswietlajaca aktualne statystyki, przekazujac jej odpowiednie atrybuty obektu.
	/// </summary>
	static void display_stats();

	/// <summary>
	/// Odczytywanie pozostalej ilosci bomb.
	/// 
	/// Metoda typu getter, zwraca aktualna ilosc pozostalych bomb.
	/// </summary>
	/// <returns>Ilosc pozostalych bomb</returns>
	static short get_bombs_remain();

	/// <summary>
	/// Ustawianie pozostalej ilosci bomb.
	/// 
	/// Metoda typu setter, ustawia aktualna ilosc pozostalych bomb.
	/// </summary>
	/// <param name="a">Ilosc pozostalych bomb</param>
	static void set_bombs_remain(short a);

	/// <summary>
	/// Odczytywanie aktualnego czasu.
	/// 
	/// Metoda typu getter, zwraca aktualny czas.
	/// </summary>
	/// <returns>Czas w sekundach</returns>
	static int get_time();

	/// <summary>
	/// Ustawianie aktualnego czasu.
	/// 
	/// Metoda typu setter, ustawia aktualny.
	/// </summary>
	/// <param name="a">Czas w sekundach</param>
	static void set_time(int a);
};

