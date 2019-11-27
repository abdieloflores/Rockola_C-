#include <string>
#include "SongList.hpp"
#include "DiscList.hpp"
#include "Nodo.hpp"


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

void SongList::Insert(NodoSong*& _head,NodoDisc *Disc,string _name,int _duration,string _disc)
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

void SongList::Duration_Disc(NodoDisc *Disc,NodoSong *_Song)
{
    NodoSong *aux1 = _Song;
    int suma=0;

    while (aux1 != NULL)
    {
        if (aux1->Get_Disc() == Disc->Get_Name()) {
            suma = suma + aux1->Get_Duration();
        }
        aux1 = aux1->Get_Next();
    }
    Disc->Set_Duration(suma);
}

void SongList::Modify(NodoSong *_modified)
{
    Menu modifySong;
    modifySong.modifySongMenu(_modified);
    modifySong.~Menu();
}

void SongList::Delete(string _name)
{
    if (head != NULL)
    {
        NodoSong *aux_delete;
        NodoSong *previous = NULL;
        aux_delete = head;
        
        while ((aux_delete != NULL) && (aux_delete->Get_Name()!=_name))
        {
            previous = aux_delete;
            aux_delete = aux_delete->Get_Next();
        }
        if (aux_delete==NULL) {
            cout<<"La canción a eliminar no existe";
        }
        else if(previous == NULL){
            head = head->Get_Next();
            delete aux_delete;
        }else{
            previous->Set_Next(aux_delete->Get_Next());
            delete aux_delete;
        }
    }
}

void SongList::Delete_All(NodoSong *&_head,string _disc)
{
    if (_head != NULL)
    {
        NodoSong *aux_delete = _head;
        NodoSong *previous = NULL;
        aux_delete = _head;
        
        while ((aux_delete != NULL))
        {
            if (aux_delete->Get_Disc()==_disc) {
                if(previous == NULL){
                    _head = _head->Get_Next();
                    delete aux_delete;
                    aux_delete = _head;
                    Delete_All(aux_delete,_disc);
                }else{
                    previous->Set_Next(aux_delete->Get_Next());
                    delete aux_delete;
                    aux_delete = previous->Get_Next();
                }
            }else{
                previous = aux_delete;
                aux_delete = aux_delete->Get_Next();
            }
        }
    }
}

void SongList::Show_Songs(NodoSong *_head,string disc)
{
        NodoSong *aux1 = _head;
        NodoSong *aux2;
        int cont=1;

       if(aux1 == NULL)
       {

           cout<<"x No hay canciones agregadas en el Discox\n"<<endl;

       }else{
           if ((aux1 != NULL) && disc == aux1->Get_Disc()) {
               do
               {
                   cout<<cont<<".- "<<aux1->Get_Name()<<endl;
                   aux2 = aux1;
                   aux1 = aux1->Get_Next();
                   cont++;
               }while (aux1 != NULL);
           }
           
           if (cont == 0)
           {
               cout<<"x No hay canciones agregadas en el disco x\n"<<endl;
           }
       }
}

NodoSong *SongList::Get_Search(NodoSong *_head,string _name)
{
    NodoSong *aux1 = new NodoSong();
    aux1 = _head;
    bool band = false;

    while ((aux1 != NULL) && (_head->Get_Name() <= _name))
    {
        if (aux1->Get_Name() == _name)
        {
            band = true;
            break;
        }else{
            aux1 = aux1->Get_Next();
        }
    }
    if (band == true) {
        return aux1;
    }else{
        return NULL;
    }
}

void SongList::Destroy(NodoSong *&_head)
{
    NodoSong *aux = _head;
    _head = aux;
    delete aux;
}
