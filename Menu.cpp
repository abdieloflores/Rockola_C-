#include <iostream>
#include "Menu.h"

using namespace std;




void Menu::mainMenu()
{
    int option,finish=1;
    cout<<"hola"<<endl;
    while (finish==1)
    {   
        system("clear");
        cout<<"\t\t\t- ROCKOLA -"<<endl;
        cout<<"\t\t\"Menu Principal\"\n"<<endl;

        cout<<"\t1.- Lista de Discos"<<endl;
        cout<<"\t2.- Lista de Canciones de un Disco"<<endl;
        cout<<"\t3.- Agregar Disco"<<endl;
        cout<<"\t4.- Modificar Disco"<<endl;
        cout<<"\t5.- Eliminar Disco"<<endl;
        cout<<"\t6.- Ordenar Discos"<<endl;
        cout<<"\t7.- Mostrar Albums"<<endl;
        cout<<"\t8.- Salir\n"<<endl;
        cout<<"Opcion:\t";
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
            
                break;
            case 8:
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
}



void Menu::albumMenu()
{
    int option,finish=1;

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

                break;
            case 2:
            
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
    int option,finish=1;

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
    cout<<"Opción:\t";
    cin>>option;

    switch (option)
    {
    case 1:
        genre = 'Clasica';
        break;
    case 2:
        genre = 'Blues';
        break;
    case 3:
        genre = 'Jazz';
        break;
    case 4:
        genre = 'Rhythm and Blues';
        break;
    case 5:
        genre = 'Rock and Roll';
        break;
    case 6:
        genre = 'Gospel';
        break;
    case 7:
        genre = 'Soul';
        break;
    case 8:
        genre = 'Rock';
        break;
    case 9:
        genre = 'Metal';
        break;
    case 10:
        genre = 'Country';
        break;
    case 11:
        genre = 'Funk';
        break;
    case 12:
        genre = 'Disco';
        break;
    case 13:
        genre = 'House';
        break;
    case 14:
        genre = 'Techno';
        break;
    case 15:
        genre = 'Pop';
        break;
    case 16:
        genre = 'Ska';
        break;
    case 17:
        genre = 'Reggae';
        break;
    case 18:
        genre = 'Hip Hop';
        break;
    case 19:
        genre = 'Drumm and Bass';
        break;
    case 20:
        genre = 'Garage';
        break;
    case 21:
        genre = 'Flamenco';
        break;
    case 22:
        genre = 'Salsa';
        break;
    case 23:
        genre = 'Reggaeton';
        break;
    }
}
void Menu::songsMenu()
{
    int option,finish=1;

    while (finish == 1)
    {
        system("clear");    
        cout<<"\t\t\t- ROCKOLA -\n"<<endl;
        /*Aquí deben ir los datos del disco a modificar
        Nombre:
        Interprete:
        Genero:
        Año: 
        Duración: 
        */    
        cout<<"\t 1.- Ver Canciones"<<endl;
        cout<<"\t 2.- Agregar Canción"<<endl;
        cout<<"\t 3.- Reproducir Canción"<<endl;
        cout<<"\t 4.- Modificar Canción"<<endl;
        cout<<"\t 5.- Eliminar Canción"<<endl;
        cout<<"\t 6.- Eliminar Todas Las Canciones"<<endl;
        cout<<"\t 7.- Regresar al Menu Principal\n"<<endl;
        cout<<"Opcion: \t";
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

void Menu::modifyDiscMenu(NodoDisc* modified){
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
        cout<<"Año: " <<modified->Get_Year();
        cout<<"Duración: "<<modified->Get_Duration()/60<<" minutos, "<<modified->Get_Duration() - ((modified->Get_Duration()/60)*60)<<" segundos.";

        cout<<"\t1.- Modificar Info Completa"<<endl;
        cout<<"\t2.- Modificar Nombre"<<endl;
        cout<<"\t3.- Modificar Artista"<<endl;
        cout<<"\t4.- Modificar Genero"<<endl;
        cout<<"\t5.- Modificar Año"<<endl;
        cout<<"\t6.- Regresar Menu Principal\n"<<endl;
        cout<<"Opcion:\t";
        cin>>option;

        switch (option)
        {
            case 1:
                system("clear");
                cout<<"Ingrese Nombre: ";getline(cin,name);
                cout<<"Ingrese Artista: ";getline(cin,artist);
                cout<<"Ingrese Genero: "<<endl;genreMenu(genre);
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

void Menu::modifySongMenu(){
    int option,finish=1;

    while (finish==1)
    {
        system("clear");    
        cout<<"\t\t\t- ROCKOLA -"<<endl;
        cout<<"\t\t\"Modificando Cancion\"\n"<<endl;
        /*Aquí deben ir los datos del disco a modificar
        Nombre:
        Interprete:
        Genero:
        Año: 
        Duración: 
        */    
        cout<<"\t1.- Modificar Info Completa"<<endl;
        cout<<"\t2.- Modificar Nombre"<<endl;
        cout<<"\t3.- Modificar Duracion"<<endl;
        cout<<"\t4.- Regresar Menu Anterior\n"<<endl;
        cout<<"Opcion:\t";
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
    songsMenu();
}