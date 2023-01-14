#pragma once
/*****************************************************************//**
 * \file   allegro.h
 * \brief  
 * Plik naglowkowy funkcji obslugujacych Allegro5
 * \author Piotr Miernik, Oskar Olub
 * \date   Styczen 2023
 *********************************************************************/

/// <summary>
/// Funkcja inicjalizuj¹ca komponenty biblioteki Allegro5.
/// </summary>
void allegro_init();

/// <summary>
/// Wyswietlanie menu.
/// 
/// Ta funkcja odpowiada za wyswietlenie menu pokazujacego dostepne tryby gry.
/// </summary>
void allegro_display_menu();

/// <summary>
/// Wyswietlanie wygranej.
/// 
/// Ta funkcja odpowiada za wyswietlenie bitmapy informujacej uzytkownika o wyrganej.
/// </summary>
void allegro_display_win();

/// <summary>
/// Rysowanie pol na planszy gry.
/// 
/// Ta funkcja odpowiada za wyrysowanie na ekranie kafelkow planszy ulozonych w siatke zgodna z rozmiarami odpowiednimi do poziomu trudnosci gry.
/// Funkcja wie, w ktorym miejscu wyrysowac opowiednia bitmape dzieki tablicy kliknietych pol.
/// </summary>
/// <param name="tab">Wskaznik na dwuwymiarowa tablice - plansze</param>
/// <param name="clicked">Wskaznik na dwuwymiarowa tablice - macierz kliknietych pol</param>
/// <param name="x">Rozmiar planszy w osi X (zalezy od poziomu trudnosci)</param>
/// <param name="y">Rozmiar planszy w osi Y (zalezy od poziomu trudnosci)</param>
/// <param name="margin_x">Zmienna przechowujaca margines planszy od krawedzi okna w osi X</param>
/// <param name="margin_y">Zmienna przechowujaca margines planszy od krawedzi okna w osi Y</param>
void allegro_draw_fields(int** tab, int** clicked, unsigned short x, unsigned short y, unsigned short margin_x, unsigned short margin_y);

/// <summary>
/// Wyswietlanie statystyk.
/// 
/// Ta funkcja odpowiada za wyswietlenie podczas gry statystyk: ilosci nieoznaczonych bomb oraz czasu, ktory uplynal od rozpoczecia rozgrywki.
/// </summary>
/// <param name="bombs_remain">Zmienna przechowujaca ilosc bomb pozostalych do oznaczenia</param>
/// <param name="time">Zmienna przechowujaca ilosc czasu, ktory uplynal w grze</param>
void allegro_display_stats(short bombs_remain, int time);
