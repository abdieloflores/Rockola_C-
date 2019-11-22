#ifndef DiscList_hpp
#define DiscList_hpp

#include "Nodo.hpp"
#include "Menu.hpp"

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

#endif /* DiscList_hpp */
