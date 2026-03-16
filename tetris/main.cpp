#include <iostream>
#include "tetris.h"

using namespace std;

int main()
{

    int ancho,alto;

    cout<<"Ingrese ancho: ";
    cin>>ancho;

    cout<<"Ingrese alto: ";
    cin>>alto;

    unsigned char **tablero = crearTablero(alto,ancho);

    imprimirTablero(tablero,alto,ancho);

}
