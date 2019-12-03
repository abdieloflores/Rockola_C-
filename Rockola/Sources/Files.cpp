#include <iostream>
#include "Files.hpp"
#include "Menu.hpp"
#include <cstdlib>

using namespace std;

Files::Files(NodoDisc *head1,NodoSong *head2)
{
    HeadDiscs = head1;
    HeadSongs = head2;
}

void Files::writeDiscs()
{
    fileDiscs.open("/Users/oto/Desktop/Repositorios_GIT/Rockola_C-/Rockola/Files/Discs.txt", ios::out | ios::trunc);

    if (fileDiscs.is_open()) {
        string exitText,auxInt;
        NodoDisc *aux = HeadDiscs;
        
        while (aux != NULL) {
            auxInt = to_string(aux->Get_Duration()); // Entero a String C++ 11 !!!
            exitText = exitText+aux->Get_Name()+','+aux->Get_Artist()+','+aux->Get_Genre()+','+aux->Get_Year()+','+auxInt;
            aux = aux->Get_Next();
            if (aux != NULL) {
                exitText = exitText+'\n';
            }
        }
        fileDiscs<<exitText;
        cout<<"++++  "<<exitText<<" ++++++";
        fileDiscs.close();
    }else{
        cout<<"No se encontro el archivo"<<endl;
    }
}

void Files::readDiscs(NodoDisc *&_head)
{
    string name, artist, genre, year, durationstr;
    int duration=0,cont,cont2;
    
    fileDiscs.open("/Users/oto/Desktop/Repositorios_GIT/Rockola_C-/Rockola/Files/Discs.txt", ios::in);
    if (fileDiscs.is_open()) {
        string line;
        cont2=0;
        while (getline(fileDiscs,line))
        {
            cont = 1;
            char buffer[50];
            strcpy(buffer,line.c_str());
            char *ptr;
            ptr = strtok(buffer,",");
                while(ptr != NULL)
                {
                    
                    switch (cont) {
                        case 1:
                            name = ptr;
                            break;
                        case 2:
                            artist = ptr;
                            break;
                        case 3:
                            genre = ptr;
                            break;
                        case 4:
                            year = ptr;
                            break;
                        case 5:
                            durationstr = ptr;
                            duration = stoi(durationstr);
                            break;
                    }
                    ptr = strtok(NULL, ",");
                    cont++;
                }
            
            //Insert new nodo ------------------------------------
                DiscList object;
                    object.Insert(_head, name, artist, genre, year, duration);
                object.~DiscList();
            //End Insert New Nodo -------------------------
        }
    }else{
        
        cout<<"\nNo se encontro el archivo"<<endl;
    }
}


void Files::writeSongs()
{
    fileSongs.open("/Users/oto/Desktop/Repositorios_GIT/Rockola_C-/Rockola/Files/Songs.txt", ios::out | ios::trunc);
    if (fileSongs.is_open()) {
        string exitText,auxInt;
        NodoSong *aux = HeadSongs;
        
        while (aux != NULL) {
            auxInt = to_string(aux->Get_Duration()); // Entero a String C++ 11 !!!
            exitText = exitText+aux->Get_Name()+','+auxInt+','+aux->Get_Disc();
            aux = aux->Get_Next();
            if (aux != NULL) {
                exitText = exitText+'\n';
            }
        }
        fileSongs<<exitText;
        cout<<"++++  "<<exitText<<" ++++++";
        fileSongs.close();
    }else{
        cout<<"No se encontro el archivo"<<endl;
    }
}

void Files::readSongs(NodoSong *&_head,NodoDisc *_head2)
{
    string name,disc,durationstr;
    int duration=0,cont,cont2;
    
    fileSongs.open("/Users/oto/Desktop/Repositorios_GIT/Rockola_C-/Rockola/Files/Songs.txt", ios::in);
    if (fileSongs.is_open()) {
        string line;
        cont2=0;
        while (getline(fileSongs,line))
        {
            cont = 1;
            char buffer[50];
            strcpy(buffer,line.c_str());
            char *ptr;
            ptr = strtok(buffer,",");
                while(ptr != NULL)
                {
                    
                    switch (cont) {
                        case 1:
                            name = ptr;
                            cout<<name<<endl;
                            break;
                        case 2:
                            durationstr = ptr;
                            duration = stoi(durationstr);
                            cout<<duration<<endl;
                            break;
                        case 3:
                            disc = ptr;
                            cout<<disc<<endl;
                            break;
                    }
                    ptr = strtok(NULL, ",");
                    cont++;
                }
            
            //Insert new nodo ------------------------------------
                SongList object;
                object.Insert(_head,name, duration, disc);
                object.~SongList();
            //End Insert New Nodo -------------------------
        }
    }else{
        
        cout<<"\n No se encontro el archivo"<<endl;
    }
}
