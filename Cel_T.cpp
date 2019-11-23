#include <iostream>


using namespace std;

template <class a_type>
class Cel_T		//DEKLARACJA STRUKTURY KOMORKI
{
    public:


	//int numer;

	//char val;

	int x_val;

	int y_val;

	Cel_T * north;

	Cel_T * west;

	Cel_T * east;

	Cel_T * south;

	a_type att;

Cel_T() :east(NULL),west(NULL),north(NULL),south(NULL),x_val(0),y_val(0){	};

};






