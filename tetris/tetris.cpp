#include <iostream>
#include "tetris.h"

using namespace std;

// ---------------- TABLERO ----------------

unsigned char** crearTablero(int alto,int ancho){

    int bytes = ancho/8;

    unsigned char **tablero = new unsigned char*[alto];

    for(int i=0;i<alto;i++){
        tablero[i] = new unsigned char[bytes];

        for(int j=0;j<bytes;j++)
            tablero[i][j] = 0;
    }

    return tablero;
}

void liberarTablero(unsigned char **tablero,int alto){
    for(int i=0;i<alto;i++)
        delete[] tablero[i];

    delete[] tablero;
}

// ---------------- PIEZAS ----------------

unsigned short obtenerPieza(int tipo,int rot){

    // I
    if(tipo==0){
        if(rot%2==0) return 0x0F00;
        else return 0x2222;
    }

    // O
    if(tipo==1){
        return 0x6600;
    }

    // T
    if(tipo==2){
        if(rot==0) return 0x0E40;
        if(rot==1) return 0x4C40;
        if(rot==2) return 0x4E00;
        if(rot==3) return 0x4640;
    }

    return 0;
}

// ---------------- COLISION ----------------

bool colision(unsigned char **tablero,int ancho,int alto,
              unsigned short pieza,int x,int y){

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){

            int bit = (pieza >> (15 - (i*4 + j))) & 1;

            if(bit){

                int tx = x + j;
                int ty = y + i;

                if(tx < 0 || tx >= ancho || ty >= alto)
                    return true;

                if(ty >= 0){
                    int byte = tx/8;
                    int bitPos = 7 - (tx%8);

                    if(tablero[ty][byte] & (1<<bitPos))
                        return true;
                }
            }
        }
    }

    return false;
}

// ---------------- FIJAR PIEZA ----------------

void fijarPieza(unsigned char **tablero,
                unsigned short pieza,int x,int y){

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){

            int bit = (pieza >> (15 - (i*4 + j))) & 1;

            if(bit){

                int tx = x + j;
                int ty = y + i;

                if(ty >= 0){

                    int byte = tx/8;
                    int bitPos = 7 - (tx%8);

                    tablero[ty][byte] |= (1<<bitPos);
                }
            }
        }
    }
}

// ---------------- IMPRIMIR ----------------

void imprimirConPieza(unsigned char **tablero,int alto,int ancho,
                      unsigned short pieza,int x,int y){

    for(int i=0;i<alto;i++){

        for(int j=0;j<ancho;j++){

            int ocupado = 0;

            int byte = j/8;
            int bitPos = 7 - (j%8);

            if(tablero[i][byte] & (1<<bitPos))
                ocupado = 1;

            // pieza encima
            for(int pi=0;pi<4;pi++){
                for(int pj=0;pj<4;pj++){

                    int bit = (pieza >> (15 - (pi*4 + pj))) & 1;

                    if(bit){
                        if(i == y+pi && j == x+pj)
                            ocupado = 1;
                    }
                }
            }

            if(ocupado) cout<<"#";
            else cout<<".";
        }

        cout<<endl;
    }
}


void eliminarFilas(unsigned char **tablero,int alto,int ancho){

    int bytes = ancho/8;

    for(int i=0;i<alto;i++){

        bool llena = true;

        // revisar si la fila está llena
        for(int j=0;j<bytes;j++){
            if(tablero[i][j] != 255){
                llena = false;
                break;
            }
        }

        // si está llena
        if(llena){

            // bajar todas las filas superiores
            for(int k=i;k>0;k--){
                for(int j=0;j<bytes;j++){
                    tablero[k][j] = tablero[k-1][j];
                }
            }

            // limpiar la fila de arriba
            for(int j=0;j<bytes;j++)
                tablero[0][j] = 0;

            //ojo
            i--;
        }
    }
}
