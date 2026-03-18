#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tetris.h"

using namespace std;

int main(){

    int ancho,alto;

    cout<<"Ancho (multiplo de 8): ";
    cin>>ancho;

    cout<<"Alto: ";
    cin>>alto;

    unsigned char **tablero = crearTablero(alto,ancho);

    srand(time(0));

    int tipo = rand()%3; // por ahora 3 piezas
    int rot = 0;

    int x = ancho/2;
    int y = 0;

    while(true){

        system("cls"); // limpiar consola (Windows)

        unsigned short pieza = obtenerPieza(tipo,rot);

        imprimirTablero(tablero,alto,ancho);

        cout<<"\nControles: a izq | d der | s bajar | w rotar\n";

        char c;
        cin>>c;

        if(c=='a'){
            if(!colision(tablero,ancho,alto,pieza,x-1,y))
                x--;
        }

        if(c=='d'){
            if(!colision(tablero,ancho,alto,pieza,x+1,y))
                x++;
        }

        if(c=='s'){
            if(!colision(tablero,ancho,alto,pieza,x,y+1))
                y++;
            else{
                fijarPieza(tablero,pieza,x,y);

                tipo = rand()%3;
                rot = 0;
                x = ancho/2;
                y = 0;
            }
        }

        if(c=='w'){
            int nuevaRot = (rot+1)%numRotaciones(tipo);

            if(!colision(tablero,ancho,alto,
                          obtenerPieza(tipo,nuevaRot),x,y))
                rot = nuevaRot;
        }
    }

    return 0;
}
