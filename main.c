#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void dibujarcirculo();
void dibujarcruz();
void inicializartablero();
void mostrartablero();
int numele();
int filas();
int columnas1();
int columnas2();
int inicializarmáquina();
int main()
{
    int ele_usu=0; //elección del usuario de intervalo (1,9)
    int posicion_usuario; // posiciín en el tablero correspondiente a la eleccion del usuario (0,8)
    int posicion_máquina; //posicion en el tablero correspondiente a la que elige la máquina (0,8)
    char tablero[9];
    inicializartablero(tablero);
    mostrartablero(tablero);
    printf("elija un numero entre 1 y 9\n");
    scanf("%d", & ele_usu);
    posicion_usuario=numeroelegido(ele_usu);
    dibujarcruz();
    posicion_máquina=inicializarmáquina();
    circulo();
    return 0;
}
void inicializartablero(char tablero[]) //crea al tablero para darle un valor a futuro
{
    for(int x=0; x<9; x++)
    {
        tablero[x]=''; //lo que se hace aca es dejar todos los elementos del vector "tablero" en blanco o vacios
    }
}
void mostrartablero()
{
    printf("%c| %c| %c\n", tablero[0], tablero[1], tablero[2]);
    printf("---|---|---\n");
    printf("%c| %c| %c\n", tablero[3], tablero[4], tablero[5]);
    printf("---|---|---\n");
    printf("%c| %c| %c\n", tablero[6], tablero[7], tablero[8]);
}
void dibujarcirculo() //Esta función crea los circulos manejados por la maquina
{
    printf("%c", 79);
}
void dibujarcruz() //Esta funcion crea las cruces controladas por el usuario
{
    printf("%c", 88);
}
int inicializarmáquina(ele_maq) //Función que representa la jugada de la máquina
{
    srand(time(NULL))
    ele_maq=rand()%(8-0+0)+0; //el valor aleatorio que va a tomar la elección de la máquina
    return ele_maq;
}
int numeroelegido(int num_ele) //Esta funcion devuelve un valor entre el intervalo (0,8)
{
  return num_ele--;
}
/*
int filas(int fila) //Esta funcion devuelve el valor de filas del intervalo (0,8)
{
    fila=numele(fila)/3;
    return fila;
}
int columnas1(int columna1) //Esta funcion devuelve el valor de columnas 4 5 y 6 del intervalo (0,8)
{
    columna1=(numele()-filas()*3);
    return columna1;
}
int columnas2(int columna2) //Esta funcion devuelve el valor de columnas 7 8 y 9 del intervalo (0,8)
{
    columna2=(numele()-(filas()*3)*2);
    return columna2;
}
*/


