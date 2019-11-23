#include <iostream>
#include"Tracker.h"
using namespace std;





	
	


//Konstrukctor

	Tracker::Tracker(Board *b)
	{
		
	current_board=b;
	ptr=zero_Cel=b->zero_Cel;
	x_max=&b->MAX_X;
	y_max=&b->MAX_Y;
	current_x_coordinate=0;//zero->x_val;
	current_y_coordinate=0;//zero->y_val;
		
	}

	Tracker::~Tracker()
	{
	}
	
//metody

void Tracker::change_board(Board *b)
{
	current_board=b;
	ptr=zero_Cel=b->zero_Cel;
	x_max=&b->MAX_X;
	y_max=&b->MAX_Y;
	current_x_coordinate=0;//zero->x_val;
	current_y_coordinate=0;//zero->y_val;
	
	
}


	Cel * Tracker::kom(int next_x_coordinate,int next_y_coordinate)	
	{
	int k,n,i;
	
	if((0>next_x_coordinate)||(next_x_coordinate>*x_max)||(next_y_coordinate>*y_max)||(0>next_y_coordinate))
	{
		cout<<"Blad nieprawidlowe wspolrzedne tracker nie poruzy sie \n";
		return ptr;
	}
	else

//	if((next_x_coordinate!=current_x_coordinate)||(next_y_coordinate!=current_y_coordinate))
	{
		
		
		k=next_x_coordinate-current_x_coordinate;
		n=next_y_coordinate-current_y_coordinate;
		
		if(k>0)
		{
			for(i=0;i<k;i++)
			{
				ptr=ptr->east;
			}
		}
		else
		{
			k=k*(-1);
			
			for(i=0;i<k;i++)
			{
				ptr=ptr->west;
			}
		}
		
		if(n>0)
		{
			for(i=0;i<n;i++)
			{
				ptr=ptr->south;
			}
		}
		else
		{
			n=n*(-1);
			
			for(i=0;i<n;i++)
			{
				ptr=ptr->north;
			}
		}
		
		
/*	
	//else
	//{
//	cout<<"Blad Tracker znajduje sie juz w tej komorce \n";
//	return ptr;
//	}
	*/
	current_x_coordinate=next_x_coordinate;
	current_y_coordinate=next_y_coordinate;
	
	}
	
	if(ptr==NULL)
	{
	cout<<"WARNING - out of bounds - ERROR \n";
	}
	
	return ptr;
}

	
	Cel* Tracker::free_track_go(int k,int n)
	{
		
		int i;
		
		
		
		
	if(k>0)
		{
			for(i=0;i<k;i++)
			{
				ptr=ptr->east;
		
		if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0;reload_tr(); return ptr;}
			}
		}
		else
		{
			k=k*(-1);
			
			for(i=0;i<k;i++)
			{
				ptr=ptr->west;
			
			if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
			}
		}
		
		if(n>0)
		{
			for(i=0;i<n;i++)
			{
				ptr=ptr->south;
				
				if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
			}
		}
		else
		{
			n=n*(-1);
			
			for(i=0;i<n;i++)
			{
				ptr=ptr->north;
				
				if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
			}
		}	
		
		current_x_coordinate=ptr->x_val;
		current_y_coordinate=ptr->y_val;
		
		if(ptr==NULL){	cout<<"WARNING - out of bounds - ERROR \n";	k=0;n=0; reload_tr();return ptr;}
		
		
			return ptr;
	}
	

	
	void Tracker::reload_tr()
	{
		ptr=zero_Cel;
		current_x_coordinate=0;//zero->x_val;
		current_y_coordinate=0;//zero->y_val;
	}
	

