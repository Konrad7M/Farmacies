#include<iostream>
#include<string>
#include<fstream>


#include"Cel.h"

#include"Board.h"

#include"Tracker.h"


#include"Cel_T.cpp"

#include"Board_T.cpp"

#include"Tracker_T.cpp"


#include"Apteka.h"

#include"Lek.h"




#define nullptr 0

using namespace std;

typedef Cel_T<Apteka> A_cell;

typedef Cel_T<Lek> L_cell;

typedef Board_T<A_cell> A_board;

typedef Board_T<L_cell> L_board;

typedef Tracker_T<A_board,A_cell> A_track;

typedef Tracker_T<L_board,L_cell> L_track;

//-------------------------------------------------------------DEKLAROWANIE ZMIENNYCH GLOBALNYCH--------------------------------------------------------

Board mag(0,0);

A_board apt_list(0,0);

L_board lek_list(0,0);

int i,j,x,y,input_variable,menu,board_x_size,board_y_size,w,apteki=0,leki=0;

char watever;

//-----------------------------------------------------------DEKLARACJE FUNKCJI-------------------------------------------------------


int get_apt_int(string nazwa){

int i;
A_track T1(&apt_list);

for(i=1;i<=apteki;i++)
    if(T1.kom(i,0)->att.nazwa==nazwa)
      {
 return i;
        }
}

void add_apt(){



A_track T1(&apt_list);

apteki++;

mag.add_kolumn();

apt_list.add_kolumn();

(T1.kom(apteki,0)->att).edit_data();



}

void del_apt(string nazwa){

int v,i,tm;

Apteka tmp;

A_track T1(&apt_list);

Tracker T3(&mag);

v=get_apt_int(nazwa);

if(v!=apteki)
{




    tmp=T1.kom(v,0)->att;
    T1.kom(v,0)->att=T1.kom(apteki,0)->att;
    T1.kom(apteki,0)->att=tmp;


    for(i=0;i<leki;i++)
    {
        tm=T3.kom(v,i)->numer;
        T3.kom(v,i)->numer=T3.kom(leki,i)->numer;
        T3.kom(leki,i)->numer=tm;
    }

}

apt_list.delete_kolumn();

mag.delete_kolumn();

--apteki;

}

void edit_apt(string nazwa){
int v;

A_track T1(&apt_list);

v=get_apt_int(nazwa);

T1.kom(v,0)->att.edit_data();


}

void apt_disp_list(){

A_track T1(&apt_list);

int i;

for(i=1;i<=apteki;i++)
{


cout<<"\n";
T1.kom(i,0)->att.display();
cout<<"\n";
}
}



int get_lek_int(string nazwa){

int i;
L_track T1(&lek_list);

for(i=1;i<=leki;i++)
    if(T1.kom(i,0)->att.nazwa==nazwa)
        return i;

}

void add_lek(){

    leki++;

L_track T1(&lek_list);

mag.add_row();

lek_list.add_kolumn();

(T1.kom(leki,0)->att).edit();

}

void del_lek(string nazwa){

int v,i,tm;

L_track T1(&lek_list);

Tracker T3(&mag);

v=get_lek_int(nazwa);

if(v!=leki)
{
    Lek tmp;



    tmp=T1.kom(v,0)->att;
    T1.kom(v,0)->att=T1.kom(leki,0)->att;
    T1.kom(leki,0)->att=tmp;


    for(i=0;i<=apteki;i++)
    {
        tm=T3.kom(i,v)->numer;
        T3.kom(i,v)->numer=T3.kom(i,leki)->numer;
        T3.kom(i,leki)->numer=tm;
    }

}

lek_list.delete_kolumn();

mag.delete_row();

leki--;

}

void edit_lek(string nazwa){
int v;

L_track T1(&lek_list);

v=get_lek_int(nazwa);

T1.kom(v,0)->att.edit();


}

void lek_disp_list(){

L_track T1(&lek_list);

int i;

for(i=1;i<=leki;i++)
(T1.kom(i,0)->att).display();


}

void zamow_leki()
{
    Tracker TT(&mag);

    string naz_1;
    string naz_2;
    int j,k,f;

    cout<<"zamow lek \n";
    cin>>naz_1;

    cout<<"do \n";
    cin>>naz_2;

    j=get_apt_int(naz_2);

    k=get_lek_int(naz_1);

    cout<<"w ilosci \n";

    cin>>f;

    TT.kom(j,k)->numer=TT.kom(j,k)->numer+f;



}


void stan_mag(string nazwa){


    int v;

v=get_apt_int(nazwa);

L_track T1(&lek_list);

A_track T2(&apt_list);

Tracker T3(&mag);

int i;
(T1.kom(i,0)->att).display();
for(i=1;i<=leki;i++)
{



cout<<"------------------------\n";

(T1.kom(i,0)->att).display();
cout<<T3.kom(v,i)->numer<<"\n";
if(T3.kom(v,i)->numer <= 4)
    cout<<"wykryto braki\n";


cout<<"------------------------\n";
}


}


void sprzedaj(){


Tracker TT(&mag);

    Board   Paragon(0,1);

L_track T1(&lek_list);

A_track T2(&apt_list);

Tracker T3(&mag);

Tracker T4(&Paragon);

int suma=0;
int recep;
    string naz_1;
    string naz_2;
    int j,k,f,sajz=0;
    char Q='Y';

    cout<<"w APTECE \n";
    cin>>naz_2;

    j=get_apt_int(naz_2);


    //while(Q=='Y')
//{
    Paragon.add_kolumn();
    sajz++;

    cout<<"sprzedaj LEK \n";
    cin>>naz_1;



    k=get_lek_int(naz_1);

    if((T1.kom(k,0)->att).recepta==1){

        cout<<"poprosze nr recepty: ";
        cin>>recep;

        if(recep==-1)
        {  cout<<"PROSZE ZOSTAC NA PLACOWCE ODPOWIEDNIE SLUZBY SA W DRODZE LILALILALILALILA \n";
            return ;
        }


    }


    cout<<"w ilosci \n";

    cin>>f;

    T4.kom(sajz,0)->numer=k;
    T4.kom(sajz,1)->numer=f;

    TT.kom(j,k)->numer=TT.kom(j,k)->numer-f;

    //cout<<"continue: Y/N?\n";
    //cin>>Q;

//}


//---------Paragon----------------------------------

    cout<<"____________________________________PARAGON_________________________________________\n\n\n\n\n\n";

    cout<<"APTEKA: \n";
    T2.kom(j,0)->att.display();
    cout<<"\n";
    cout<<"numer recepty: "<<recep<<"\n";

  //  for(i=1;i<=sajz;i++)
    //{
i=1;

        cout<<"--------------------------------------------------------------------\n";
            cout<<"lek: \n";
            T1.kom(T4.kom(i,0)->numer,0)->att.display();
            cout<<"\n";
            cout<<"\nilosc:"<<T4.kom(i,1)->numer<<"\n";
        cout<<"--------------------------------------------------------------------\n";

        suma=((T1.kom(T4.kom(i,0)->numer,0)->att.cena)*(T4.kom(i,1)->numer))+suma;

    //}
int VAT;

VAT=1.2*suma;

cout<<"NETTO: "<<suma<<"BRUTTO: "<<VAT<<"\n";
cout<<"____________________________________Zapraszamy ponownie!___________________________________________________________________________________________________________________________Pani da 3 \n\n\n\n\n\n";

}





//-------------------------------------------------menusy-----------------------------------------------------------




void manage_farmacy(){

cout<<" 1.dodaj apt \n";
cout<<" 2.usun apt \n";
cout<<" 3.edyt apt \n";
cout<<" 4.wyswietl wszyst \n";
cout<<" 5.zamow lek do apt \n";
cout<<" 6.stan magazynowy danej apt \n";

int local_menu;

    cin>>local_menu;

    string nazwa;

    switch(local_menu)
    {
    case 1://dodaj apteke
        {
            add_apt();

            break;
        }

    case 2://zlikwiduj apteke
        {
cout<<"PODAJ NAZWE APTEKI:";
        cin>>nazwa;

           del_apt(nazwa);

            break;
        }

     case 3://edytuj apteke
        {

            cout<<"PODAJ NAZWE APTEKI:";

            cin>>nazwa;

            edit_lek(nazwa);
            break;
        }


        case 4://wysw wszystkie
        {
            apt_disp_list();
            break;
        }

        case 5:{//zamow



            zamow_leki();



        break;
        }

        case 6:{//zakup lekow
            string naz;
            cout<<"PODAJ NAZWE APTEKI do zamowien:";
            cin>>naz;
            stan_mag(naz);



        break;
        }


}
}

void manage_drug_offer(){

cout<<" 1.dodaj lek \n";
cout<<" 2.del lek \n";
cout<<" 3.edyt lek \n";
cout<<" 4.wyswietl leki \n";


int local_menu;
string nazwa;

cin>>local_menu;

    switch(local_menu)
    {
    case 1://dodaj lek
        {
            add_lek();

            break;
        }

    case 2://zlikwiduj lek
        {
            cout<<"podaj nazwe leku \n";
            cin>>nazwa;
            del_lek(nazwa);
            break;
        }

     case 3://edytuj lek
        {
            cout<<"podaj nazwe leku \n";
            cin>>nazwa;
           edit_lek(nazwa);
            break;
        }


        case 4://wysw lek
        {
            lek_disp_list();
            break;
        }




    }

}

void network_manage(){

cout<<" 1.zarzad apt \n";
cout<<" 2.zarzad ofert \n";



int local_menu;
string nazwa;

cin>>local_menu;

    switch(local_menu)
    {
    case 1://zarzad apt
        {
            manage_farmacy();

            break;
        }

    case 2://zarzad ofert
        {

            manage_drug_offer();

            break;
        }


    }


}


void customer_service(){


cout<<" 1.sprzedaj  \n";




int local_menu;
string nazwa;

cin>>local_menu;

    switch(local_menu)
    {
    case 1://sprzedaj bez rec
        {
sprzedaj();            break;
        }




    }



}

//-------------------------------------------------------------MAIN-------------------------------------------------------


int main()

{
//---------------------------------TUTAJ JEST MENU-------------------------------------------------------------

int holder;

holder=1;
while(holder==1)
{
cout<<" Menu : \n";
cout<<" 1.zarzadzanie siecia \n";
cout<<" 2.obsluga klienta \n";
cout<<" 3.wyjscie \n";




cin>>menu;

switch(menu)
{

		case 1:			//WYSWIETL
		{
            network_manage();

			break;
		}


		case 2 :		//DODAWANIE KOLUMN
		{

            customer_service();


			break;

		}

		case 3:
		{


		holder=0;
		break;


			break;
		}







}//koniec swticha
}









	system("PAUSE");

	return 0;
}

