#ifndef SongList_hpp
#define SongList_hpp

#include "Nodo.hpp"
#include "Menu.hpp"
#include "DiscList.hpp"

class SongList{
    private:
        NodoSong *head;
    public:
        SongList();
        ~SongList();
        void Set_Head(NodoSong *);
        NodoSong *Get_Head();

        void Insert(NodoSong *&,NodoDisc *,string,int,string);
        void Duration_Disc(NodoDisc *,NodoSong *);
        void Modify(NodoSong *);
        void Delete(NodoSong *&,string);
        void Show_Songs(NodoSong *,string);

        NodoSong *Get_Search(NodoSong *,string);
    
};

#endif /* SongList_hpp */
