#include <iostream>

using namespace std;

Apteka* Siec::find_apt(char naz){

    for(list<A_list>::iterator l=A_list.begin(); l!=A_list.end();++l)
{
    if((*l).nazwa==naz)
        return &*l;
}



}

void Siec::disp_apt(){


for(list<A_list>::iterator l=A_list.begin(); l!=A_list.end();++l)
{
    (*l).display();
}

}

void Siec::add_apt(){


    (*A_list.push_back()).edit_data();


}

void Siec::del_apt(){

    A_list.erase(*find_apt(naz));


}

void Siec::edt_apt(){

    (*find_apt(naz)).edit_data();


}





    Lek* Siec::find_lek(){


    for(list<spis_lek>::iterator l=spis_lek.begin(); l!=spis_lek.end();++l)
{
    if((*l).nazwa==naz)
        return &*l;
}



    }

    void Siec::disp_lek(){

        for(list<spis_lek>::iterator l=spis_lek.begin(); l!=spis_lek.end();++l)
{
    (*l).display();
}


    }

    void Siec::add_lek(){

        (*spis_lek.push_back()).edit_data();


    }

    void Siec::del_lek(){

spis_lek.erase(*find_lek(naz));

    }

    void Siec::edt_lek(){

        (*find_lek(naz)).edit();

    }




