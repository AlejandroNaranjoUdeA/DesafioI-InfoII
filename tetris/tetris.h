#ifndef TETRIS_H
#define TETRIS_H

unsigned char** crearTablero(int alto,int ancho);
void imprimirTablero(unsigned char **tablero,int alto,int ancho);
int generarPieza();

#endif // TETRIS_H
