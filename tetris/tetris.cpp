#include <iostream>
#include "tetris.h"

using namespace std;

// ================= TABLERO =================

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

// ================= PIEZAS =================

// I
unsigned short I[2] = {
    0b0000111100000000,
    0b0010001000100010
};

// O
unsigned short O[1] = {
    0b0000011001100000
};

// T
unsigned short T[4] = {
    0b0000011100100000,
    0b0000001001100010,
    0b0000001001110000,
    0b0000001000110010
};

// ================= FUNCIONES PIEZAS =================

unsigned short obtenerPieza(int tipo,int rot){

    switch(tipo){
    case 0: return I[rot % 2];
    case 1: return O[0];
    case 2: return T[rot % 4];
    }

    return O[0];
}

int numRotaciones(int tipo){

    if(tipo==0) return 2;
    if(tipo==1) return 1;
    if(tipo==2) return 4;

    return 1;
}

// ================= COLISION =================

bool colision(unsigned char **tablero,int ancho,int alto,
              unsigned short pieza,int x,int y){

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){

            int bit = (pieza >> (15 - (i*4 + j))) & 1;

            if(bit){

                int fila = y + i;
                int col  = x + j;

                if(fila>=alto || col<0 || col>=ancho)
                    return true;

                int byte = col/8;
                int bitPos = 7 - (col%8);

                if(tablero[fila][byte] & (1<<bitPos))
                    return true;
            }
        }
    }

    return false;
}

// ================= FIJAR PIEZA =================

void fijarPieza(unsigned char **tablero,
                unsigned short pieza,int x,int y){

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){

            int bit = (pieza >> (15 - (i*4 + j))) & 1;

            if(bit){

                int fila = y+i;
                int col  = x+j;

                int byte = col/8;
                int bitPos = 7 - (col%8);

                tablero[fila][byte] |= (1<<bitPos);
            }
        }
    }
}
