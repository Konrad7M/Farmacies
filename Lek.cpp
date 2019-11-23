#include <iostream>
#include"Lek.h"


using namespace std;

void Lek::edit(){


cout<<"podaj nazwe leku:";
    std::cin>>nazwa;
cout<<"podaj cene leku:";
    cin>>cena;

    cout<<"recepta - 1, bezrecepty - 0:";
        cin>>recepta;

}


    Lek::Lek(){


    }
    Lek::~Lek(){



    }





void Lek::display(){

    cout<<"NAZWA:"<<nazwa<<"\n";
    cout<<"CENA"<<cena<<"\n";

}

