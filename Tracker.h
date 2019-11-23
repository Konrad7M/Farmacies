#include<iostream>
#pragma once
#include"Board.h"


class Tracker		//KLASA GLOWIC
{




int current_x_coordinate;
int current_y_coordinate;
int next_x_coordinate;
int next_y_coordinate;


Board *current_board;


Cel * zero_Cel;

public:

Cel * ptr;
int *x_max;
int *y_max;


//Konstrukctor

	Tracker(Board *b);
   ~Tracker();
//metody

	void change_board(Board *b);

	Cel *kom(int next_x_coordinate,int next_y_coordinate);

	Cel* free_track_go(int k,int n);


	void reload_tr();

};

