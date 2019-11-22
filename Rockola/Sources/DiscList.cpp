#include <string>
#include "DiscList.hpp"

DiscList::DiscList()
{
    head = NULL;
}
DiscList::~DiscList()
{

}
void DiscList::Set_Head(NodoDisc *_head)
{
    head = _head;
}
NodoDisc *DiscList::Get_Head()
{
    return head;
}

void DiscList::Insert(NodoDisc *&_head,string _name,string _artist,string _genre,string _year)
{
    NodoDisc *new_nodo = new NodoDisc();
    new_nodo->Set_Name(_name);
    new_nodo->Set_Artist(_artist);
    new_nodo->Set_Genre(_genre);
    new_nodo->Set_Year(_year);

    NodoDisc *aux1 = _head;
    NodoDisc *aux2 = NULL;

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

void DiscList::Modify(NodoDisc *_modified)
{
    Menu modifyMenu;
    modifyMenu.modifyDiscMenu(_modified);
    modifyMenu.~Menu();
}
void DiscList::Delete(NodoDisc *)
{

}
void Show_All(NodoDisc *_head)
{
    NodoDisc *aux1 = _head;
    NodoDisc *aux2;

    if(aux1 == NULL)
    {
        system("clear");
        cout<<"\n\n x No hay Discos agregados x";
        cin.ignore();
        cout<<"\nPresiones cualquier tecla para continuar";
        cin.get();
    }else{
            do
            {
                cout<<"Nombre: "<<_head->Get_Name()<<endl;
                cout<<"Artista: "<<_head->Get_Artist()<<endl;
                cout<<"Genero: "<<_head->Get_Genre()<<endl;
                cout<<"Año: " <<_head->Get_Year();
                cout<<"Duración: "<<_head->Get_Duration()/60<<" minutos, "<<_head->Get_Duration() - ((_head->Get_Duration()/60)*60)<<" segundos.";
                aux2 = aux1;
                aux1 = aux1->Get_Next();
            }while (aux1 != NULL);
    }
}
