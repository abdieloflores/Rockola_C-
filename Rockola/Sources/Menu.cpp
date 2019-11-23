#include <iostream>
#include "Menu.hpp"
#include "DiscList.hpp"
#include "SongList.hpp"

using namespace std;

NodoDisc *Aux = NULL;
DiscList *Discs = new DiscList();

NodoSong *Aux2 = NULL;
SongList *Songs = new SongList();

Menu::Menu()
{
    
}

Menu::~Menu()
{
    
}

void Menu::mainMenu()
{
    Discs->Set_Head(Aux);
    int option,finish=1;
    string name, artist, genre, year;
    while (finish==1)
    {
        system("clear");
        cout<<"\t\t\t- ROCKOLA -"<<endl;
        cout<<"\t\t  \"Menu Principal\"\n"<<endl;

        cout<<"\t1.- Lista de Discos"<<endl;
        cout<<"\t2.- Reproducir Disco"<<endl;
        cout<<"\t3.- Agregar Disco"<<endl;
        cout<<"\t4.- Modificar Disco"<<endl;
        cout<<"\t5.- Eliminar Disco"<<endl;
        cout<<"\t6.- Mostrar Albums"<<endl;
        cout<<"\t7.- Salir\n"<<endl;
        cout<<"Opcion: ";
        cin>>option;

        switch (option)
        {
            case 1:
                discMenu();
                break;
            case 2:
                
                break;
            case 3:
                system("clear");
                cout<<"\t\t\t- ROCKOLA -"<<endl;
                cout<<"\t\t\"Agregando Disco\"\n"<<endl;
                
                cin.ignore();
                cout<<"Ingrese Nombre: ";getline(cin,name);
                cout<<"Ingrese Artista: ";getline(cin,artist);
                cout<<"Ingrese Genero: "<<endl;genreMenu(genre);
                cin.ignore();
                cout<<"Ingrese Año: ";getline(cin,year);
                
                Discs->Insert(Aux, name, artist, genre, year);
                
                cout<<"\n✔ Agregado con Éxito ✔"<<endl;
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                
                break;
            case 4:
                system("clear");
                cout<<"\t\t\t- ROCKOLA -"<<endl;
                cout<<"\t\t\"Modificando Disco\"\n"<<endl;
                Discs->Show_All_Names(Aux);
                cout<<endl<<endl;
                cin.ignore();
                cout<<"Ingrese el nombre del disco: ";getline(cin,name);
                if (Discs->Get_Search(Aux,name)==NULL) {
                    system("clear");
                    cout<<"x No se encontro el disco a modificar x"<<endl<<endl;
                    cout<<"\"Favor de escribir el nombre del disco\ncomo aparece en la lista o verifique que\neste agregado el disco.\"";
                    
                    cout<<"\nPresiones cualquier tecla para continuar";
                    cin.get();
                }else{
                    modifyDiscMenu(Discs->Get_Search(Aux,name));
                }
                break;
            case 5:
            
                break;
            case 6:
            
                break;
            case 7:
                finish=0;
                exit(1);
                break;
            default:
                system("clear");
                cout<<"\n\t\tNo existe la opción"<<endl<<endl;
                cout<<"Presione cualquier tecla para continuar";
                cin.get();
                break;
        }
    }
}



void Menu::discMenu()
{
    int option,finish=1;
    string genre;
    
    while (finish==1)
    {
        system("clear");
        cout<<"\t\t\t- ROCKOLA -"<<endl;
        cout<<"\t\t\"Lista de Discos\"\n"<<endl;

        cout<<"\t1.- Ver lista completa"<<endl;
        cout<<"\t2.- Filtrar discos por genero."<<endl;
        cout<<"\t3.- Regresar al Menu Principal\n"<<endl;
        cout<<"Opcion:\t";
        cin>>option;

        switch (option)
        {
            case 1:
                system("clear");
                Discs->Show_All(Aux);
                cin.ignore();
                cout<<"\n¿Dese Reproducir un Disco?";
                cout<<"1.-SI\n2.-NO"<<endl;
                cin>>option;
                switch (option) {
                    case 1:

                        break;
                    case 2:
                        
                        break;
                }
                break;
            case 2:
                cout<<"Selecciones el genero: ";
                genreMenu(genre);
                Discs->Show_For_Genre(Aux,genre);
                break;
            case 3:
                finish=0;
                break;
            default:
                system("clear");
                cout<<"\n\t\tNo existe la opción"<<endl<<endl;
                cout<<"Presione cualquier tecla para continuar";
                cin.get();
                break;
        }
    }
    mainMenu();
}

void Menu::genreMenu(string &genre)
{
    int option;

    cout<<"\t 1.- Clasica"<<endl;
    cout<<"\t 2.- Blues"<<endl;
    cout<<"\t 3.- Jazz"<<endl;
    cout<<"\t 4.- Rhythm and Blues (R&B)"<<endl;
    cout<<"\t 5.- Rock and Roll"<<endl;
    cout<<"\t 6.- Gospel"<<endl;
    cout<<"\t 7.- Soul"<<endl;
    cout<<"\t 8.- Rock"<<endl;
    cout<<"\t 9.- Metal"<<endl;
    cout<<"\t10.- Country"<<endl;
    cout<<"\t11.- Funk"<<endl;
    cout<<"\t12.- Disco"<<endl;
    cout<<"\t13.- House"<<endl;
    cout<<"\t14.- Techno"<<endl;
    cout<<"\t15.- Pop"<<endl;
    cout<<"\t16.- Ska"<<endl;
    cout<<"\t17.- Reggae"<<endl;
    cout<<"\t18.- Hip Hop"<<endl;
    cout<<"\t19.- Drum and Bass"<<endl;
    cout<<"\t20.- Garage"<<endl;
    cout<<"\t21.- Flamenco"<<endl;
    cout<<"\t22.- Salsa"<<endl;
    cout<<"\t23.- Reggaeton\n"<<endl;
    cout<<"Opción: ";
    cin>>option;

    switch (option)
    {
    case 1:
        genre = "Clasica";
        break;
    case 2:
        genre = "Blues";
        break;
    case 3:
        genre = "Jazz";
        break;
    case 4:
        genre = "Rhythm and Blues";
        break;
    case 5:
        genre = "Rock and Roll";
        break;
    case 6:
        genre = "Gospel";
        break;
    case 7:
        genre = "Soul";
        break;
    case 8:
        genre = "Rock";
        break;
    case 9:
        genre = "Metal";
        break;
    case 10:
        genre = "Country";
        break;
    case 11:
        genre = "Funk";
        break;
    case 12:
        genre = "Disco";
        break;
    case 13:
        genre = "House";
        break;
    case 14:
        genre = "Techno";
        break;
    case 15:
        genre = "Pop";
        break;
    case 16:
        genre = "Ska";
        break;
    case 17:
        genre = "Reggae";
        break;
    case 18:
        genre = "Hip Hop";
        break;
    case 19:
        genre = "Drumm and Bass";
        break;
    case 20:
        genre = "Garage";
        break;
    case 21:
        genre = "Flamenco";
        break;
    case 22:
        genre = "Salsa";
        break;
    case 23:
        genre = "Reggaeton";
        break;
    }
}
void Menu::songsMenu(NodoDisc *Disc)
{
    int option,finish=1;

    while (finish == 1)
    {
        system("clear");
        cout<<"\t\t\t- ROCKOLA -\n"<<endl;
        
        cout<<"Nombre: "<<Disc->Get_Name()<<endl;
        cout<<"Artista: "<<Disc->Get_Artist()<<endl;
        cout<<"Genero: "<<Disc->Get_Genre()<<endl;
        cout<<"Año: " <<Disc->Get_Year()<<endl;
        cout<<"Duración: ";
            if(Disc->Get_Duration()>0){
                cout<<Disc->Get_Duration()/60<<":"<<Disc->Get_Duration() - ((Disc->Get_Duration()/60)*60)<<" min."<<endl;
            }else{
                cout<<"0:0 min."<<endl<<endl;
            }
        
        cout<<"\t 1.- Ver Canciones"<<endl;
        cout<<"\t 2.- Agregar Canción"<<endl;
        cout<<"\t 3.- Reproducir Canción"<<endl;
        cout<<"\t 4.- Modificar Canción"<<endl;
        cout<<"\t 5.- Eliminar Canción"<<endl;
        cout<<"\t 6.- Eliminar Todas Las Canciones"<<endl;
        cout<<"\t 7.- Regresar al Menu Principal\n"<<endl;
        cout<<"Opcion: ";
        cin>>option;

        switch (option)
        {
            case 1:

                break;
            case 2:
            
                break;
            case 3:
            
                break;
            case 4:
            
                break;
            case 5:
            
                break;
            case 6:
            
                break;
            case 7:
                finish=0;
                break;
            default:
                system("clear");
                cout<<"\n\t\tNo existe la opción"<<endl<<endl;
                cout<<"Presione cualquier tecla para continuar";
                cin.get();
                break;
        }
    }
    mainMenu();
}

void Menu::modifyDiscMenu(NodoDisc *modified){
    int option,finish=1;
    string name, artist, genre, year;

    while (finish==1)
    {
        system("clear");
        cout<<"\t\t\t- ROCKOLA -"<<endl;
        cout<<"\t\t\"Modificando Disco\"\n"<<endl;
        
        cout<<"Nombre: "<<modified->Get_Name()<<endl;
        cout<<"Artista: "<<modified->Get_Artist()<<endl;
        cout<<"Genero: "<<modified->Get_Genre()<<endl;
        cout<<"Año: " <<modified->Get_Year()<<endl;
        cout<<"Duración: ";
        if(modified->Get_Duration()>0){
            cout<<modified->Get_Duration()/60<<":"<<modified->Get_Duration() - ((modified->Get_Duration()/60)*60)<<" min."<<endl;
        }else{
            cout<<"0:0 min."<<endl<<endl;
        }

        cout<<"\t1.- Modificar Info Completa"<<endl;
        cout<<"\t2.- Modificar Nombre"<<endl;
        cout<<"\t3.- Modificar Artista"<<endl;
        cout<<"\t4.- Modificar Genero"<<endl;
        cout<<"\t5.- Modificar Año"<<endl;
        cout<<"\t6.- Regresar Menu Principal\n"<<endl;
        cout<<"Opcion: ";
        cin>>option;

        switch (option)
        {
            case 1:
                system("clear");
                cin.ignore();
                cout<<"Ingrese Nombre: ";getline(cin,name);
                cout<<"Ingrese Artista: ";getline(cin,artist);
                cout<<"Ingrese Genero: "<<endl;genreMenu(genre);
                cin.ignore();
                cout<<"Ingrese Año: ";getline(cin,year);
                modified->Set_Name(name);
                modified->Set_Artist(artist);
                modified->Set_Genre(genre);
                modified->Set_Year(year);

                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                break;
            case 2:
                system("clear");
                cout<<"Ingrese Nombre: ";getline(cin,name);
                modified->Set_Name(name);
                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                break;
            case 3:
                system("clear");
                cout<<"Ingrese Artista: ";getline(cin,artist);
                modified->Set_Artist(artist);
                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                break;
            case 4:
                system("clear");
                cout<<"Ingrese Genero: "<<endl;genreMenu(genre);
                modified->Set_Genre(genre);
                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                break;
            case 5:
                system("clear");
                cout<<"Ingrese Año: ";getline(cin,year);
                modified->Set_Year(year);
                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                break;
            case 6:
                finish=0;
                break;
            default:
                system("clear");
                cout<<"\n\t\tNo existe la opción"<<endl<<endl;
                cout<<"Presione cualquier tecla para continuar";
                cin.get();
                break;
        }
    }
    mainMenu();
}

void Menu::modifySongMenu(NodoSong *modified){
    int option,finish=1, duration;
    string name, disc;

    while (finish==1)
    {
        system("clear");
        cout<<"\t\t\t- ROCKOLA -"<<endl;
        cout<<"\t\t\"Modificando Cancion\"\n"<<endl;
        cout<<"Nombre: "<<modified->Get_Name()<<endl;
        cout<<"Duración: ";
        if(modified->Get_Duration()>0){
            cout<<modified->Get_Duration()/60<<":"<<modified->Get_Duration() - ((modified->Get_Duration()/60)*60)<<" min."<<endl;
        }else{
            cout<<"0:0 min."<<endl<<endl;
        }
        
        cout<<"\t1.- Modificar Info Completa"<<endl;
        cout<<"\t2.- Modificar Nombre"<<endl;
        cout<<"\t3.- Modificar Duracion"<<endl;
        cout<<"\t4.- Regresar Menu Anterior\n"<<endl;
        cout<<"Opcion: ";
        cin>>option;

        switch (option)
        {
            case 1:
                system("clear");
                cin.ignore();
                cout<<"Ingrese Nombre: ";getline(cin,name);
                cout<<"Ingrese Duracion: ";cin>>duration;
                cin.ignore();
                modified->Set_Name(name);
                modified->Set_Duration(duration);

                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                break;
            case 2:
                system("clear");
                cin.ignore();
                cout<<"Ingrese Nombre: ";getline(cin,name);
                modified->Set_Name(name);
                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                break;
            case 3:
                system("clear");
                cin.ignore();
                cout<<"Ingrese Duracion: ";cin>>duration;
                modified->Set_Duration(duration);
                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                break;
            case 4:
                finish=0;
                break;
            default:
                system("clear");
                cout<<"\n\t\tNo existe la opción"<<endl<<endl;
                cout<<"Presione cualquier tecla para continuar";
                cin.get();
                break;
        }
    }
    songsMenu(Discs->Get_Search(Aux,modified->Get_Name()));
}
