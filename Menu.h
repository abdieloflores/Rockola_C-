#ifndef MENU_H
#define MENU_H

#include "Nodo.h"

class Menu
{
    public:
        Menu();
        ~Menu();
        void mainMenu();
        void albumMenu();
        void genreMenu(string &);
        void songsMenu();
        void modifyDiscMenu(NodoDisc*);
        void modifySongMenu();
};

#endif // MENU_H