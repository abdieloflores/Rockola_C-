#include <string>
#include "SongList.hpp"
#include "DiscList.hpp"


SongList::SongList()
{
    head=NULL;
}

SongList::~SongList()
{
    
}
void SongList::Set_Head(NodoSong *_head)
{
    head = _head;
}
NodoSong *SongList::Get_Head()
{
    return head;
}

void Insert(NodoSong *&_head,NodoDisc *Disc,string _name,int _duration,string _disc)
{
    NodoSong *new_nodo = new NodoSong();
    new_nodo->Set_Name(_name);
    new_nodo->Set_Duration(_duration);
    new_nodo->Set_Disc(Disc->Get_Name());

    NodoSong *aux1 = _head;
    NodoSong *aux2 = NULL;

    while ((aux1 != NULL) && ((aux1->Get_Name()[0]) < (_name[0])))
    {
        aux2 = aux1;
        aux1 = aux1->Get_Next();
    }

    if (_head == aux1)
    {
        _head = new_nodo;
    }else{
        aux2->Set_Next(new_nodo);
    }
    
    new_nodo->Set_Next(aux1);
}

void Duration_Album(NodoDisc *Disc,NodoSong *_Song)
{
    NodoSong *aux1 = _Song;
    NodoSong *aux2 = NULL;
    int suma=0;
    
    

    while (aux1 != NULL)
    {
        aux2 = aux1;
        aux1 = aux1->Get_Next();
        if (aux1->Get_Disc() == Disc->Get_Name()) {
            suma += aux1->Get_Duration();
        }
    }
    Disc->Set_Duration(suma);
}

void Modify(NodoSong *_modified)
{
    Menu modifySong;
    modifySong.modifySongMenu(_modified);
    modifySong.~Menu();
}
void Delete(NodoSong *)
{
    
}
void Show_All(NodoSong *)
{
    
}

NodoDisc *Get_Search(NodoSong *,string);
