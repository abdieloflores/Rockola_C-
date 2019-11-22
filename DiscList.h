#ifndef DISCLIST_H
#define DISCLIST_H

#include "Nodo.h"
#include "Menu.h"

class DiscList
{
    private:
        NodoDisc *head;
    public:
        DiscList();
        ~DiscList();
        void Set_Head(NodoDisc *);
        NodoDisc *Get_Head();

        void Insert(NodoDisc *&,string,string,string,string);
        void Modify(NodoDisc *);
        void Delete(NodoDisc *);
        void Show_All(NodoDisc *);

        NodoDisc *Get_Search(string);
};

#endif // DISCLIST_H