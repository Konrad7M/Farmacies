#include<iostream>
#include<string>
#pragma once


class rec{

public:
int recepta;

void virtual rcpt(){

}

void virtual display()
{

}
};




class Lek:public rec
{

public:


std::string nazwa;

int cena;

int KG;

//int ilosc;



    Lek();
    ~Lek();

void edit();



void display();


};
