#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "Nodo.hpp"

class Menu
{
    public:
        /*Menu();
        ~Menu();*/
        void mainMenu();
        void albumMenu();
        void genreMenu(string &);
        void songsMenu();
        void modifyDiscMenu(NodoDisc*);
        void modifySongMenu();
};

#endif /* Menu_hpp */
