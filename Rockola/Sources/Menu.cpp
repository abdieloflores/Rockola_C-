#include <iostream>
#include "Menu.hpp"
#include "DiscList.hpp"
#include "SongList.hpp"
#include "Nodo.hpp"
#include "Files.hpp"

using namespace std;

NodoDisc *Disc = NULL;
DiscList *Discs = new DiscList();

NodoSong *Song = NULL;
SongList *Songs = new SongList();

Menu::Menu()
{
    
}

Menu::~Menu()
{
    
}

void Menu::mainMenu()
{
    Discs->Set_Head(Disc);
    Songs->Set_Head(Song);
    Files file(Disc,Song);
    
    int option,finish=1,finish2;
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
        cout<<"\t6.- Cargar Info"<<endl;
        cout<<"\t7.- Guardar Info"<<endl;
        cout<<"\t8.- Salir\n"<<endl;
        cout<<"Opcion: ";
        cin>>option;

        switch (option)
        {
            case 1:
                if (Disc == NULL) {
                    system("clear");
                    finish2 = 0;
                    cout<<" x No hay discos agregados x"<<endl;
                    cin.get();
                    cout<<"\nPresione cualquier tecla para continuar";
                    cin.get();
                }else{
                    discMenu();
                    
                }
                break;
            case 2:
                finish2=1;
                while (finish2 == 1)
                {
                    if (Disc == NULL) {
                        system("clear");
                        finish2 = 0;
                        cout<<" x No hay discos agregados x"<<endl;
                        cin.get();
                        cout<<"\nPresione cualquier tecla para continuar";
                        cin.get();
                    }else{
                    system("clear");
                    Discs->Show_All_Names(Disc);
                    cin.ignore();
                    cout<<"\nEscriba el nombre del disco: ";
                    getline(cin,name);
                    if(Discs->Get_Search(Disc,name)!= NULL)
                    {
                        songsMenu(Discs->Get_Search(Disc,name));
                        finish2 = 0;
                    }else{
                        system("clear");
                        cout<<" x No escribio correctamente el nombre x"<<endl;
                        cout<<"\nPresiones cualquier tecla para continuar";
                        cin.get();
                    }
                    }
                }
                
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
                
                Discs->Insert(Disc,name, artist, genre, year,0);
                
                cout<<"\n✔ Agregado con Éxito ✔"<<endl;
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                
                break;
            case 4:
                if (Disc == NULL) {
                    system("clear");
                    finish2 = 0;
                    cout<<" x No hay discos agregados x"<<endl;
                    cin.get();
                    cout<<"\nPresione cualquier tecla para continuar";
                    cin.get();
                }else{
                    system("clear");
                    cout<<"\t\t\t- ROCKOLA -"<<endl;
                    cout<<"\t\t\"Modificando Disco\"\n"<<endl;
                    Discs->Show_All_Names(Disc);
                    cout<<endl<<endl;
                    cin.ignore();
                    cout<<"Ingrese el nombre del disco: ";getline(cin,name);
                    if (Discs->Get_Search(Disc,name)==NULL) {
                        system("clear");
                        cout<<"x No se encontro el disco a modificar x"<<endl<<endl;
                        cout<<"\"Favor de escribir el nombre del disco como aparece en la lista o verifique que este agregado el disco.\"";
                        
                        cout<<"\nPresiones cualquier tecla para continuar";
                        cin.get();
                    }else{
                        modifyDiscMenu(Discs->Get_Search(Disc,name));
                    }
                }
                break;
            case 5:
                if (Disc == NULL) {
                    system("clear");
                    cout<<" x No hay disco agregados x"<<endl;
                    cin.get();
                    cout<<"\nPresione cualquier tecla para continuar";
                    cin.get();
                }else{
                    system("clear");
                    cout<<"\t\t\t- ROCKOLA -"<<endl;
                    cout<<"\t\t\"Eliminando Disco\"\n";
                    Discs->Show_All_Names(Disc);
                    cout<<endl<<endl;
                    cin.ignore();
                    cout<<"Ingrese el nombre del disco: ";getline(cin,name);
                    if (Discs->Get_Search(Disc,name)==NULL)
                    {
                        system("clear");
                        cout<<"x No se encontro el disco a eliminar x"<<endl<<endl;
                        cout<<"\"Favor de escribir el nombre del disco como aparece en la lista o verifique que este agregado el disco.\"";
                        
                        cout<<"\nPresiones cualquier tecla para continuar";
                        cin.get();
                    }else{
                        system("clear");
                        Songs->Delete(Discs->Get_Search(Disc,name)->Get_Name());
                        Discs->Delete(Disc,name);
                        cout<<"\n✔ Eliminado con Éxito ✔"<<endl;
                        cout<<"\nPresiones cualquier tecla para continuar";
                        cin.get();
                    }
                }
                break;
            case 6:
                file.readSongs();
                file.readDiscs();
                break;
            case 7:
                file.writeSongs();
                file.writeDiscs();
                break;
            case 8:
                Songs->Destroy(Song);
                Discs->Destroy(Disc);
                
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
                Discs->Show_All(Disc);
                cin.ignore();
                cout<<"Presione cualquier tecla para continuar";
                cin.get();
                break;
            case 2:
                cout<<"Selecciones el genero: ";
                genreMenu(genre);
                system("clear");
                Discs->Show_For_Genre(Disc,genre);
                cin.ignore();
                cout<<"Presione cualquier tecla para continuar";
                cin.get();
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
    int option,finish=1,finish2,duration;
    string _name;

    while (finish == 1)
    {
        finish2 =
        system("clear");
        cout<<"\t\t\t- ROCKOLA -\n"<<endl;
        
        cout<<"Nombre: "<<Disc->Get_Name()<<endl;
        cout<<"Artista: "<<Disc->Get_Artist()<<endl;
        cout<<"Genero: "<<Disc->Get_Genre()<<endl;
        cout<<"Año: " <<Disc->Get_Year()<<endl;
        cout<<"Duración: ";
            if(Disc->Get_Duration()>0){
                cout<<Disc->Get_Duration()/60<<":";
                if ((Disc->Get_Duration() - ((Disc->Get_Duration()/60)*60))<10) {
                  cout<<"0"<<Disc->Get_Duration() - ((Disc->Get_Duration()/60)*60)<<" min."<<endl<<endl;
                }else{
                    cout<<Disc->Get_Duration() - ((Disc->Get_Duration()/60)*60)<<" min."<<endl<<endl;
                    
                }
            }else{
                cout<<"0:00 min."<<endl<<endl;
            }
        
        cout<<"\t 1.- Ver Canciones"<<endl;
        cout<<"\t 2.- Agregar Canción"<<endl;
        cout<<"\t 3.- Reproducir Canción"<<endl;
        cout<<"\t 4.- Modificar Canción"<<endl;
        cout<<"\t 5.- Eliminar Canción"<<endl;
        cout<<"\t 6.- Regresar al Menu Principal\n"<<endl;
        cout<<"Opcion: ";
        cin>>option;

        switch (option)
        {
            case 1:
                system("clear");
                Songs->Show_Songs(Song,Disc->Get_Name());
                cin.ignore();
                cout<<"\nPresione cualquier tecla para continuar";
                cin.get();
                break;
            case 2:
                system("clear");
                cout<<"\t\t\t- ROCKOLA -"<<endl;
                cout<<"\t\t\"Agregando Canción\"\n"<<endl;
                
                cin.ignore();
                cout<<"Ingrese Nombre: ";getline(cin,_name);
                cout<<"Ingrese Duración en Segundos: ";cin>>duration;
                
                Songs->Insert(Song,Disc, _name,duration,Disc->Get_Name());
                
                Songs->Duration_Disc(Disc,Song);
                
                cout<<"\n✔ Agregado con Éxito ✔"<<endl;
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                
                break;
            case 3:
                system("clear");
                cout<<" Reproduciendo canción "<<endl<<endl;
                cin.ignore();
                cout<<"Presione cualquier tecla para terminar de reproducir"<<endl;
                cin.get();
                break;
            case 4:
                if (Song == NULL) {
                    system("clear");
                    cout<<" x No hay canciones agregadas x"<<endl;
                    cin.get();
                    cout<<"\nPresione cualquier tecla para continuar";
                    cin.get();
                }else{
                    system("clear");
                    cout<<"\t\t\t- ROCKOLA -"<<endl;
                    cout<<"\t\t\"Modificando Canción\"\n";
                    Songs->Show_Songs(Song, Disc->Get_Name());
                    cout<<endl<<endl;
                    cin.ignore();
                    cout<<"Ingrese el nombre de la cancion: ";getline(cin,_name);
                    if (Songs->Get_Search(Song,_name)==NULL)
                    {
                        system("clear");
                        cout<<"x No se encontro la cancion a modificar x"<<endl<<endl;
                        cout<<"\"Favor de escribir el nombre del disco como aparece en la lista o verifique que este agregado el disco.\"";
                        
                        cout<<"\nPresiones cualquier tecla para continuar";
                        cin.get();
                    }else{
                        modifySongMenu(Songs->Get_Search(Song,_name));
                    }
                }
                Songs->Duration_Disc(Disc,Song);
                break;
            case 5:
                if (Song == NULL) {
                    system("clear");
                    cout<<" x No hay canciones agregadas x"<<endl;
                    cin.get();
                    cout<<"\nPresione cualquier tecla para continuar";
                    cin.get();
                }else{
                    system("clear");
                    cout<<"\t\t\t- ROCKOLA -"<<endl;
                    cout<<"\t\t\"Eliminando Canción\"\n";
                    Songs->Show_Songs(Song, Disc->Get_Name());
                    cout<<endl<<endl;
                    cin.ignore();
                    cout<<"Ingrese el nombre de la cancion: ";getline(cin,_name);
                    if (Songs->Get_Search(Song,_name) == NULL)
                    {
                        system("clear");
                        cout<<"x No se encontro la cancion a eliminar x"<<endl<<endl;
                        cout<<"\"Favor de escribir el nombre del disco como aparece en la lista o verifique que este agregado el disco.\"";
                        
                        cout<<"\nPresiones cualquier tecla para continuar";
                        cin.get();
                    }else{
                        Songs->Delete(_name);
                        cout<<"\n✔ Eliminada con Éxito ✔"<<endl;
                        cout<<"\nPresiones cualquier tecla para continuar";
                        cin.get();
                    }
                }
                Songs->Duration_Disc(Disc,Song);
                
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
}

void Menu::modifyDiscMenu(NodoDisc *modified){
    int option,finish=1;
    string name,nameAux, artist, genre, year;

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
            cout<<modified->Get_Duration()/60<<":";
            if ((modified->Get_Duration() - ((modified->Get_Duration()/60)*60))<10) {
              cout<<"0"<<modified->Get_Duration() - ((modified->Get_Duration()/60)*60)<<" min."<<endl<<endl;
            }else{
                cout<<modified->Get_Duration() - ((modified->Get_Duration()/60)*60)<<" min."<<endl<<endl;
                
            }
        }else{
            cout<<"0:00 min."<<endl<<endl;
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
                nameAux = modified->Get_Name();
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
                
                
                Discs->ModifyDiscNameInSongs(Song, nameAux, name);
                
                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                finish=0;
                break;
            case 2:
                system("clear");
                cin.ignore();
                cout<<"Ingrese Nombre: ";getline(cin,name);
                modified->Set_Name(name);
                
                Discs->ModifyDiscNameInSongs(Song, nameAux, name);
                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                finish=0;
                break;
            case 3:
                system("clear");
                cin.ignore();
                cout<<"Ingrese Artista: ";getline(cin,artist);
                modified->Set_Artist(artist);
                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                finish=0;
                break;
            case 4:
                system("clear");
                cin.ignore();
                cout<<"Ingrese Genero: "<<endl;genreMenu(genre);
                modified->Set_Genre(genre);
                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                finish=0;
                break;
            case 5:
                system("clear");
                cin.ignore();
                cout<<"Ingrese Año: ";getline(cin,year);
                modified->Set_Year(year);
                cout<<"\n\n✔ Modificado con Éxito ✔"<<endl;
                cin.ignore();
                cout<<"\nPresiones cualquier tecla para continuar";
                cin.get();
                finish=0;
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
            cout<<modified->Get_Duration()/60<<":";
            if ((modified->Get_Duration() - ((modified->Get_Duration()/60)*60))<10) {
              cout<<"0"<<modified->Get_Duration() - ((modified->Get_Duration()/60)*60)<<" min."<<endl<<endl;
            }else{
                cout<<modified->Get_Duration() - ((modified->Get_Duration()/60)*60)<<" min."<<endl<<endl;
                
            }
        }else{
            cout<<"0:00 min."<<endl<<endl;
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
}
