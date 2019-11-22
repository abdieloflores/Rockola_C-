#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class NodoDisc
{
    private:
        string name;
        string artist;
        string genre;
        string year;
        int duration;
        NodoDisc *next;
    public:
        NodoDisc();
        ~NodoDisc();
        //Sets
        void Set_Name(string);
        void Set_Artist(string);
        void Set_Genre(string);
        void Set_Year(string);
        void Set_Duration(int);
        void Set_Next(NodoDisc *);
        //Gets
        string Get_Name();
        string Get_Artist();
        string Get_Genre();
        string Get_Year();
        int Get_Duration();
        NodoDisc *Get_Next();
};

class NodoSong
{
    private:
        string name;
        int duration;
        string disc;
        NodoSong *next;
    public:
        NodoSong();
        ~NodoSong();
        //Sets
        void Set_Name(string);
        void Set_Duration(int);
        void Set_Disc(string);
        void Set_Next(NodoSong *);
        //Gets
        string Get_Name();
        int Get_Duration();
        string Get_Disc();
        NodoSong *Get_Next();
};


#endif // NODO_H