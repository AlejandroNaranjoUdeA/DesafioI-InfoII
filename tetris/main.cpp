#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tetris.h"

using namespace std;

int main(){

    int ancho, alto;
    do{
        cout << "Ingrese ancho (multiplo de 8): ";
        cin >> ancho;

        cout << "Ingrese alto: ";
        cin >> alto;

    } while(ancho < 8 || ancho % 8 != 0 || alto < 8);

    unsigned char **tablero = crearTablero(alto,ancho);

    srand(time(0));

    int tipo = rand()%7;
    int rot = 0;

    int x = ancho/2;
    int y = 0;

    char tecla;

    while(true){

        system("cls");

        unsigned short pieza = obtenerPieza(tipo,rot);

        imprimirConPieza(tablero,alto,ancho,pieza,x,y);

        cin >> tecla;

        if(tecla == 'a'){
            if(!colision(tablero,ancho,alto,pieza,x-1,y))
                x--;
        }

        if(tecla == 'd'){
            if(!colision(tablero,ancho,alto,pieza,x+1,y))
                x++;
        }

        if(tecla == 's'){
            if(!colision(tablero,ancho,alto,pieza,x,y+1))
                y++;
            else{
                fijarPieza(tablero,pieza,x,y);

                eliminarFilas(tablero,alto,ancho);

                tipo = rand()%7;
                rot = 0;
                x = ancho/2;
                y = 0;

                // GAME OVER
                if(colision(tablero,ancho,alto,
                             obtenerPieza(tipo,rot),x,y)){

                    system("cls");
                    imprimirConPieza(tablero,alto,ancho,
                                     obtenerPieza(tipo,rot),x,y);

                    cout << "\nGAME OVER\n";
                    break;
                }
            }
        }

        if(tecla == 'w'){
            int nuevaRot = (rot+1)%4;
            if(!colision(tablero,ancho,alto,
                          obtenerPieza(tipo,nuevaRot),x,y))
                rot = nuevaRot;
        }
    }

    liberarTablero(tablero,alto);

    return 0;
}
