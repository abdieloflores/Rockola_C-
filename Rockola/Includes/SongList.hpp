#ifndef SongList_hpp
#define SongList_hpp

#include "Nodo.hpp"
#include "Menu.hpp"

class SongList{
    private:
        NodoSong *head;
    public:
        SongList();
        ~SongList();
        void Set_Head(NodoSong *);
        NodoSong *Get_Head();

        void Insert(NodoSong *&,NodoDisc *,string,int,string);
        void Duration_Disc(NodoDisc *);
        void Modify(NodoSong *);
        void Delete(NodoSong *);
        void Show_All(NodoSong *);

        NodoDisc *Get_Search(NodoSong *,string);
    
};

#endif /* SongList_hpp */
