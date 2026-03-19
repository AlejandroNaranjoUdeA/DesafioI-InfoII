#ifndef TETRIS_H
#define TETRIS_H

// tablero
unsigned char** crearTablero(int alto,int ancho);
void liberarTablero(unsigned char **tablero,int alto);

// piezas
unsigned short obtenerPieza(int tipo,int rot);

// logica
bool colision(unsigned char **tablero,int ancho,int alto,
              unsigned short pieza,int x,int y);

void fijarPieza(unsigned char **tablero,
                unsigned short pieza,int x,int y);

void eliminarFilas(unsigned char **tablero,int alto,int ancho);

// visual
void imprimirConPieza(unsigned char **tablero,int alto,int ancho,
                      unsigned short pieza,int x,int y);


#endif // TETRIS_H
