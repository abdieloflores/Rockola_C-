#include <iostream>
#include <stdlib.h>

using namespace std;

#include "Menu.hpp"

int main(){
    Menu menu1;
    system("afplay /Users/abdiel/Desktop/Repositorios_GIT/Rockola_C-/Rockola/Music/Start.mp3  &>/dev/null &");
    
    while (1) {
        menu1.mainMenu();
    }
    return 0;
}
