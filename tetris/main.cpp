#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tetris.h"

using namespace std;

int main(){

    int alto = 20;
    int ancho = 16;

    unsigned char **tablero = crearTablero(alto,ancho);

    int tipo = 0;
    int rot = 0;

    int x = ancho/2;
    int y = 0;

    char tecla;

    while(true){

        system("cls"); // en windows

        unsigned short pieza = obtenerPieza(tipo,rot);

        imprimirConPieza(tablero,alto,ancho,pieza,x,y);

        cin >> tecla;

        if(tecla == 'a'){ // izquierda
            if(!colision(tablero,ancho,alto,pieza,x-1,y))
                x--;
        }

        if(tecla == 'd'){ // derecha
            if(!colision(tablero,ancho,alto,pieza,x+1,y))
                x++;
        }

        if(tecla == 's'){ // bajar
            if(!colision(tablero,ancho,alto,pieza,x,y+1))
                y++;
            else{
                fijarPieza(tablero,pieza,x,y);

                eliminarFilas(tablero,alto,ancho);

                tipo = (tipo+1)%3;
                rot = 0;
                x = ancho/2;
                y = 0;
            }
        }

        if(tecla == 'w'){ // rotar
            int nuevaRot = (rot+1)%4;
            if(!colision(tablero,ancho,alto,
                          obtenerPieza(tipo,nuevaRot),x,y))
                rot = nuevaRot;
        }
    }

    liberarTablero(tablero,alto);

    return 0;
}
