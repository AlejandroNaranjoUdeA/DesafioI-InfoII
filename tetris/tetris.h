#ifndef TETRIS_H
#define TETRIS_H

// tablero
unsigned char** crearTablero(int alto,int ancho);
void imprimirTablero(unsigned char **tablero,int alto,int ancho);

// piezas
unsigned short obtenerPieza(int tipo,int rot);
int numRotaciones(int tipo);

// logica
bool colision(unsigned char **tablero,int ancho,int alto,
              unsigned short pieza,int x,int y);

void fijarPieza(unsigned char **tablero,
                unsigned short pieza,int x,int y);

#endif // TETRIS_H
