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

void DiscList::Insert(NodoDisc*& _head,string _name,string _artist,string _genre,string _year,int _duration)
{
    NodoDisc *new_nodo = new NodoDisc();
    new_nodo->Set_Name(_name);
    new_nodo->Set_Artist(_artist);
    new_nodo->Set_Genre(_genre);
    new_nodo->Set_Year(_year);
    new_nodo->Set_Duration(_duration);

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

void DiscList::Delete(NodoDisc *&_head,string _name)
{
    if (_head != NULL)
    {
        NodoDisc *aux_delete;
        NodoDisc *previous = NULL;
        aux_delete = _head;
        
        while ((aux_delete != NULL) && (aux_delete->Get_Name()!=_name))
        {
            previous = aux_delete;
            aux_delete = aux_delete->Get_Next();
        }
        if (aux_delete==NULL) {
            cout<<"El disco a eliminar no existe"<<endl;
        }
        else if(previous == NULL){
            _head = _head->Get_Next();
            delete aux_delete;
        }else{
            previous->Set_Next(aux_delete->Get_Next());
            delete aux_delete;
        }
    }
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
                    cout<<aux1->Get_Duration()/60<<":"<<aux1->Get_Duration() - ((aux1->Get_Duration()/60)*60)<<" min."<<endl<<endl;
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
    int count=1,count2=0;

    if(aux1 == NULL)
    {

        cout<<"x No hay Discos agregados x\n"<<endl;

    }else{
            do
            {
                if (aux1->Get_Genre() == _gener) {
                    cout<<count<<".- "<<aux1->Get_Name()<<endl;
                    count++;
                    count2++;
                }
                aux2 = aux1;
                aux1 = aux1->Get_Next();
            }while (aux1 != NULL);
        if (count2 == 0) {
            cout<<"x No hay Discos del Genero Seleccionado x\n"<<endl;
        }
    }
}

void DiscList::ModifyDiscNameInSongs(NodoSong *_head,string previousName,string newName)
{
    NodoSong *Aux1 = _head;
    
    while (Aux1 != NULL) {
        if (Aux1->Get_Disc() == previousName) {
            Aux1->Set_Disc(newName);
            Aux1 = Aux1->Get_Next();
        }
    }
}


NodoDisc *DiscList::Get_Search(NodoDisc *_head,string _name)
{
    NodoDisc *aux1 = new NodoDisc();
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

void DiscList::Destroy(NodoDisc *&_head)
{
    NodoDisc *aux = _head;
    _head = aux;
    delete aux;
}
