#include<iostream>
#include"Cel.h"
#pragma once




class Board			//KLASA SZACHOWNICY
{


	friend  class Tracker;

	public:
Cel *zero_Cel;	// NW Cel

Cel *north_east;

Cel* south_west;

Cel* south_east;

int MAX_X;

int MAX_Y;

int notfirst;

Cel * ptr;

Cel * ptr_temp;

public:

Board(int MAX_X,int MAX_Y)	;		//KONSTRUKTOR


~Board();

void print_chessboard();

void print();

void add_kolumn();


void add_row();


void delete_row();


void delete_kolumn();




};
