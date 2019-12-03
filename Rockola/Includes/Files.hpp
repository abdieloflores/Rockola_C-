#ifndef Files_hpp
#define Files_hpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <string.h>

#include "Nodo.hpp"
#include "DiscList.hpp"
#include "SongList.hpp"


using namespace std;

class Files {
    private:
        NodoDisc *HeadDiscs;
        NodoSong *HeadSongs;
        fstream fileDiscs;
        fstream fileSongs;
    public:
        Files(NodoDisc *,NodoSong *);
        void writeDiscs();
        void readDiscs(NodoDisc *&);
        void writeSongs();
        void readSongs(NodoSong *&,NodoDisc*);
};
#endif /* Files_hpp */
