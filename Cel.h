#include<iostream>
#pragma once

/*
Class Cel		//DEKLARACJA STRUKTURY KOMORKI
{

	int numer;

	char val;

	int x_val;

	int y_val;

	cel * north;

	cel * west;

	cel * east;

	cel * south;

	cel() ;
};
*/

class Cel		//DEKLARACJA STRUKTURY KOMORKI
{
    public:
Cel();// :east(NULL),west(NULL),north(NULL),south(NULL),val('0'),x_val(0),y_val(0),numer(0){	};

	int numer;

	char val;

	int x_val;

	int y_val;

	Cel * north;

	Cel * west;

	Cel * east;

	Cel * south;


};
