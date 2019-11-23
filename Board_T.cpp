#include <iostream>


using namespace std;


template <class cell>
class Board_T			//KLASA SZACHOWNICY
{


	friend  class Tracker;

	public:
cell *zero_cell;	// NW cell

cell *north_east;

cell* south_west;

cell* south_east;

int MAX_X;

int MAX_Y;

int notfirst;

cell * ptr;

cell * ptr_temp;

public:

Board_T(int MAX_X,int MAX_Y)	:MAX_X(0),MAX_Y(0)			//KONSTRUKTOR
{
zero_cell=new cell;

ptr=zero_cell;

notfirst=0;
int i;

for(i=1;i<MAX_X;i++)
	add_kolumn();

	for(i=1;i<MAX_Y;i++)
	add_row();




}


~Board_T()												//Destruktor
{
	int i,x;
x=MAX_Y;

	for(i=0;i<=x;i++)
		{

			delete_row();


		}



			delete zero_cell;

			if(zero_cell==NULL)
			cout<<"sukces";

			zero_cell=NULL;




}

void print_chessboard()			//WYSWIETL
{
	cell *wsk_4;
	cell *wsk_5;

	wsk_5=wsk_4=zero_cell;

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

void print()			//WYSWIETL
{
	cell *wsk_4;
	cell *wsk_5;

	wsk_5=wsk_4=zero_cell;

while(wsk_5)
{

while(wsk_4)
	{
	cout<<wsk_4->val<<"  ";
	wsk_4=wsk_4->east;
	}
	cout<<"\n";
	wsk_5=wsk_5->south;
	wsk_4=wsk_5;
}


}


void add_kolumn()	//DODAWANIE KOLUMN
{




	cell * wsk_4;
	cell *wsk_5;

wsk_4=wsk_5=zero_cell;

while(wsk_4->east)
{
wsk_4=wsk_4->east;
}



north_east=wsk_4->east=new cell;

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
			wsk_4->south=new cell;

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



void add_row()		//DODAWANIE SZEREGOW
{




	cell * wsk_4;

	cell *wsk_5;

	wsk_4=wsk_5=zero_cell;


while(wsk_4->south)
{
wsk_4=wsk_4->south;
}

wsk_4->south=new cell;

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
			wsk_4->east=new cell;

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



void delete_row()					//USUWANIE SZEREGOW
{

cell *wsk_4;
	cell *wsk_5;

	wsk_4=wsk_5=zero_cell;

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

if(zero_cell==wsk_4)
	{
		notfirst=0;

		zero_cell=new cell;

		zero_cell->east=zero_cell->west=zero_cell->north=zero_cell->south=NULL;

		zero_cell->x_val=0;

		zero_cell->y_val=0;
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



void delete_kolumn()						//USUWANIE KOLUMN
{
	cell *wsk_4;
	cell *wsk_5;

	wsk_4=wsk_5=zero_cell;

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

		if(zero_cell==wsk_4)
	{
		notfirst=0;

		zero_cell=new cell;

		zero_cell->east=zero_cell->west=zero_cell->north=zero_cell->south=NULL;

		zero_cell->x_val=0;

		zero_cell->y_val=0;
	}

		south_east=wsk_5->west;

		wsk_5=wsk_4->south;



		wsk_4->east=wsk_4->west=wsk_4->north=wsk_4->south=NULL;
	 	delete wsk_4;
	 	wsk_4=NULL;
		wsk_4=wsk_5;
	}

if(zero_cell==wsk_4)
	{
		notfirst=0;

		zero_cell=new cell;

		zero_cell->east=zero_cell->west=zero_cell->north=zero_cell->south=NULL;

		zero_cell->x_val=0;

		zero_cell->y_val=0;
	}


	MAX_X--;

}





};
