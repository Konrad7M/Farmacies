#include <iostream>
#include"Board.h"
using namespace std;








Board::Board(int MAX_X,int MAX_Y)	:MAX_X(0),MAX_Y(0)			//KONSTRUKTOR
{
zero_Cel=new Cel;

ptr=zero_Cel;

notfirst=0;
int i;

for(i=1;i<MAX_X;i++)
	add_kolumn();

	for(i=1;i<MAX_Y;i++)
	add_row();




}


Board::~Board()												//Destruktor
{
	int i,x;
x=MAX_Y;

	for(i=0;i<=x;i++)
		{

			delete_row();


		}



			delete zero_Cel;

			if(zero_Cel==NULL)
			cout<<"sukces";

			zero_Cel=NULL;




}

void Board::print_chessboard()			//WYSWIETL
{
	Cel *wsk_4;
	Cel *wsk_5;

	wsk_5=wsk_4=zero_Cel;

while(wsk_5)
{

while(wsk_4)
	{
	cout<<"["<<wsk_4->x_val<<" "<<wsk_4->y_val<<"]";
	wsk_4=wsk_4->east;
	}
	cout<<"\n";
	wsk_5=wsk_5->south;
	wsk_4=wsk_5;
}


}

void Board::print()			//WYSWIETL
{
	Cel *wsk_4;
	Cel *wsk_5;

	wsk_5=wsk_4=zero_Cel;

while(wsk_5)
{

while(wsk_4)
	{
	cout<<wsk_4->numer<<"  ";
	wsk_4=wsk_4->east;
	}
	cout<<"\n";
	wsk_5=wsk_5->south;
	wsk_4=wsk_5;
}


}


void Board::add_kolumn()	//DODAWANIE KOLUMN
{




	Cel * wsk_4;
	Cel *wsk_5;

wsk_4=wsk_5=zero_Cel;

while(wsk_4->east)
{
wsk_4=wsk_4->east;
}



north_east=wsk_4->east=new Cel;

wsk_5=wsk_4;

wsk_4=wsk_4->east;

wsk_4->west=wsk_5;

wsk_4->x_val=wsk_4->west->x_val+1;
wsk_4->y_val=0;

wsk_5=wsk_5->south;

	if(notfirst==1)
	while(wsk_5)

		{
			ptr_temp=wsk_4;
			wsk_4->south=new Cel;

			wsk_4=wsk_4->south;


			wsk_4->west=wsk_5;
			wsk_4->north=ptr_temp;
			wsk_5->east=wsk_4;

			wsk_4->x_val=wsk_4->west->x_val+1;
			wsk_4->y_val=wsk_4->north->y_val+1;

			wsk_5=wsk_5->south;
			south_east=wsk_4;
		}
		else
		south_east=north_east;


	if(notfirst==0){notfirst=1;	}



MAX_X++;

}



void Board::add_row()		//DODAWANIE SZEREGOW
{




	Cel * wsk_4;

	Cel *wsk_5;

	wsk_4=wsk_5=zero_Cel;


while(wsk_4->south)
{
wsk_4=wsk_4->south;
}

wsk_4->south=new Cel;

wsk_5=wsk_4;

south_west=wsk_4=wsk_4->south;

wsk_4->north=wsk_5;

wsk_4->y_val=wsk_4->north->y_val+1;
wsk_4->x_val=0;

wsk_5=wsk_5->east;

	if(notfirst==1)
	while(wsk_5)

		{
			ptr_temp=wsk_4;
			wsk_4->east=new Cel;

			wsk_4=wsk_4->east;


			wsk_4->north=wsk_5;
			wsk_4->west=ptr_temp;
			wsk_5->south=wsk_4;

			wsk_4->x_val=wsk_4->west->x_val+1;
			wsk_4->y_val=wsk_4->north->y_val+1;

			south_east=wsk_4;

			wsk_5=wsk_5->east;

		}


if(notfirst==0){notfirst=1;south_east=south_west;	}


MAX_Y++;


}



void Board::delete_row()					//USUWANIE SZEREGOW
{

Cel *wsk_4;
	Cel *wsk_5;

	wsk_4=wsk_5=zero_Cel;

	while(wsk_4->south)
	{
		wsk_4=wsk_4->south;
	}

	wsk_5=wsk_4;

	south_west=wsk_4->north;



	while(wsk_4)
	{

	if(wsk_4->north!=NULL)
		wsk_4->north->south=NULL;

if(zero_Cel==wsk_4)
	{
		notfirst=0;

		zero_Cel=new Cel;

		zero_Cel->east=zero_Cel->west=zero_Cel->north=zero_Cel->south=NULL;

		zero_Cel->x_val=0;

		zero_Cel->y_val=0;
	}

		south_east=wsk_5;
		wsk_5=wsk_4->east;

		wsk_4->east=wsk_4->west=wsk_4->north=wsk_4->south=NULL;

	 	delete wsk_4;
	 	wsk_4=NULL;
		wsk_4=wsk_5;
	}


MAX_Y--;

}



void Board::delete_kolumn()						//USUWANIE KOLUMN
{
	Cel *wsk_4;
	Cel *wsk_5;

	wsk_4=wsk_5=zero_Cel;

	while(wsk_4->east)
{
wsk_4=wsk_4->east;
}

north_east=wsk_4;

	wsk_5=wsk_4;


	while(wsk_4)
	{
	if(wsk_4->west!=NULL)
		wsk_4->west->east=NULL;

		if(zero_Cel==wsk_4)
	{
		notfirst=0;

		zero_Cel=new Cel;

		zero_Cel->east=zero_Cel->west=zero_Cel->north=zero_Cel->south=NULL;

		zero_Cel->x_val=0;

		zero_Cel->y_val=0;
	}

		south_east=wsk_5->west;

		wsk_5=wsk_4->south;



		wsk_4->east=wsk_4->west=wsk_4->north=wsk_4->south=NULL;
	 	delete wsk_4;
	 	wsk_4=NULL;
		wsk_4=wsk_5;
	}

if(zero_Cel==wsk_4)
	{
		notfirst=0;

		zero_Cel=new Cel;

		zero_Cel->east=zero_Cel->west=zero_Cel->north=zero_Cel->south=NULL;

		zero_Cel->x_val=0;

		zero_Cel->y_val=0;
	}


	MAX_X--;

}







