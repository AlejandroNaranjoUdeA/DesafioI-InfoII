#include <iostream>
#include <cstdlib>
#include "tetris.h"

using namespace std;

unsigned char** crearTablero(int alto,int ancho){

    int bytes = ancho/8;

    unsigned char **tablero = new unsigned char*[alto];

    for(int i=0;i<alto;i++){

        tablero[i] = new unsigned char[bytes];

        for(int j=0;j<bytes;j++)
            tablero[i][j]=0;
    }

    return tablero;
}

void imprimirTablero(unsigned char **tablero,int alto,int ancho){

    int bytes = ancho/8;

    for(int i=0;i<alto;i++){

        for(int j=0;j<bytes;j++){

            for(int bit=7;bit>=0;bit--){

                if(tablero[i][j] & (1<<bit))
                    cout<<"#";
                else
                    cout<<".";
            }

        }

        cout<<endl;
    }
}

int generarPieza(){

    return rand()%7;
}
