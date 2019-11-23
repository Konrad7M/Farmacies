#include <iostream>
#include"Apteka.h"

using namespace std;


Apteka::Apteka(){

}

Apteka::~Apteka(){

}


void Apteka::edit_data(){

    cout<<"podaj nazwe apteki:";
    cin>>nazwa;
    cout<<"podaj adres apteki:";
    cin>>adres;


}

void Apteka::display(){

    cout<<nazwa<<"\n";
    cout<<adres<<"\n";

}

