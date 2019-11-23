#include "Nodo.hpp"
#include "Menu.h"

// NODO DISC CLASS ************************************************************************
NodoDisc::NodoDisc()
{
    next = NULL;
    duration = 0;
}
NodoDisc::~NodoDisc()
{

}
//Sets of NodoDisc ---------------------------------------------------------------
void NodoDisc::Set_Name(string _name)
{
    name = _name;
}
void NodoDisc::Set_Artist(string _artist)
{
    artist = _artist;
}
void NodoDisc::Set_Genre(string _genre)
{
    genre = _genre;
}
void NodoDisc::Set_Year(string _year)
{
    year = _year;
}
void NodoDisc::Set_Duration(int _duration)
{
    duration = _duration;
}
void NodoDisc::Set_Next(NodoDisc *_next)
{
    next = _next;
}
//Gets of NodoDisc ---------------------------------------------------------------
string NodoDisc::Get_Name()
{
    return name;
}
string NodoDisc::Get_Artist()
{
    return artist;
}
string NodoDisc::Get_Genre()
{
    return genre;
}
string NodoDisc::Get_Year()
{
    return year;
}
int NodoDisc::Get_Duration()
{
    return duration;
}
NodoDisc *NodoDisc::Get_Next()
{
    return next;
}

// NODO SONG CLASS ************************************************************************
NodoSong::NodoSong()
{
    next = NULL;
}
NodoSong::~NodoSong()
{

}
//Sets of NodoSong ---------------------------------------------------------------
void NodoSong::Set_Name(string _name)
{
    name = _name;
}
void NodoSong::Set_Duration(int _duration)
{
    duration = _duration;
}
void NodoSong::Set_Disc(string _disc)
{
    disc = _disc;
}
void NodoSong::Set_Next(NodoSong *_next)
{
    next = _next;
}
//Gets of NodoSong ---------------------------------------------------------------
string NodoSong::Get_Name()
{
    return name;
}
int NodoSong::Get_Duration()
{
    return duration;
}
string NodoSong::Get_Disc()
{
    return disc;
}
NodoSong *NodoSong::Get_Next()
{
    return next;
}


