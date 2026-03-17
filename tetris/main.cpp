#include <iostream>
#include <ctime>
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

    srand(time(0));

    int pieza = generarPieza();

    cout<<"Pieza generada: "<<pieza<<endl;

    imprimirTablero(tablero,alto,ancho);

}
