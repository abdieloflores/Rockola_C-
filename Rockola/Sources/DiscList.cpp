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
    head = _head;
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


void DiscList::Show_All(NodoDisc *_head)
{
    NodoDisc *aux1 = _head;
    NodoDisc *aux2;

    if(aux1 == NULL)
    {

        cout<<"x No hay Discos agregados x\n"<<endl;

    }else{
            do
            {
                cout<<"Nombre: "<<aux1->Get_Name()<<endl;
                cout<<"Artista: "<<aux1->Get_Artist()<<endl;
                cout<<"Genero: "<<aux1->Get_Genre()<<endl;
                cout<<"Año: " <<aux1->Get_Year()<<endl;
                cout<<"Duración: ";
                if(aux1->Get_Duration()>0){
                    cout<<aux1->Get_Duration()/60<<":"<<aux1->Get_Duration() - ((aux1->Get_Duration()/60)*60)<<" min."<<endl;
                }else{
                    cout<<"0:0 min."<<endl<<endl;
                }
                aux2 = aux1;
                aux1 = aux1->Get_Next();
            }while (aux1 != NULL);
    }
}

void DiscList::Show_All_Names(NodoDisc *_head)
{
    NodoDisc *aux1 = _head;
    NodoDisc *aux2;
    int count=1;

    if(aux1 == NULL)
    {

        cout<<"x No hay Discos agregados x\n"<<endl;

    }else{
            do
            {
                cout<<count<<".- "<<aux1->Get_Name()<<endl;
                
                aux2 = aux1;
                aux1 = aux1->Get_Next();
                count++;
            }while (aux1 != NULL);
    }
}

void DiscList::Show_For_Genre(NodoDisc *_head,string _gener)
{
    NodoDisc *aux1 = _head;
    NodoDisc *aux2;
    int count=1;

    if(aux1 == NULL)
    {

        cout<<"x No hay Discos agregados x\n"<<endl;

    }else{
            do
            {
                if (aux1->Get_Genre() == _gener) {
                    cout<<count<<".- "<<aux1->Get_Name()<<endl;
                    count++;
                }
                aux2 = aux1;
                aux1 = aux1->Get_Next();
            }while (aux1 != NULL);
    }
}



NodoDisc *DiscList::Get_Search(NodoDisc *_head,string name)
{
    NodoDisc *aux1 = _head;
    NodoDisc *aux2 = NULL;

    while (aux1 != NULL && _head->Get_Name() != name)
    {
            aux2 = aux1;
            aux1 = aux1->Get_Next();

    }
    
    if (aux1 == NULL)
    {
        return NULL;
    }else{
        return aux1;
    }
}
