#include "Files.hpp"
#include "Menu.hpp"
#include <cstdlib>

Files::Files(NodoDisc *head1,NodoSong *head2)
{
    HeadDiscs = head1;
    HeadSongs = head2;
}

void Files::writeDiscs()
{
    fileDiscs.open("/Users/abdiel/Desktop/Repositorios_GIT/Rockola_C-/Rockola/Files/Discs.txt", ios::out | ios::trunc);
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
        fileDiscs.close();
    }else{
        cout<<"No se encontro el archivo"<<endl;
    }
}

void Files::readDiscs()
{
    string name, artist, genre, year;
    int duration;
    
    fileDiscs.open("/Users/abdiel/Desktop/Repositorios_GIT/Rockola_C-/Rockola/Files/Discs.txt", ios::in);
    if (fileDiscs.is_open()) {
        char a;
        while (!fileDiscs.eof()) {
        
            a = fileDiscs.get();
        }
    }else{
        cout<<"\nNo se encontro el archivo"<<endl;
    }
}

void Files::writeSongs()
{
    fileSongs.open("/Users/abdiel/Desktop/Repositorios_GIT/Rockola_C-/Rockola/Files/Songs.txt", ios::out | ios::trunc);
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
        fileSongs.close();
    }else{
        cout<<"No se encontro el archivo"<<endl;
    }
}

void Files::readSongs()
{
    
}
