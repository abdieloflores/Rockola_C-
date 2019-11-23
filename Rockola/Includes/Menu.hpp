#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "Nodo.hpp"
#include "DiscList.hpp"
#include "SongList.hpp"

class Menu
{
    public:
        Menu();
        ~Menu();
        void mainMenu();
        void discMenu();
        void genreMenu(string &);
        void songsMenu(NodoDisc*);
        void modifyDiscMenu(NodoDisc*);
        void modifySongMenu(NodoSong*);
};

#endif /* Menu_hpp */
