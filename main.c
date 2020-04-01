#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int ele_usu=0; //elección del usuario de intervalo (1,9)
    int posicion_usuario; // posiciín en el tablero correspondiente a la eleccion del usuario (0,8)
    gotoxy(45,12);
    rayahori();
    gotoxy(45,14);
    rayahori();
    gotoxy(3,10);
    rayaverti();
    gotoxy(3,1);
    rayaverti();
    printf("elija un numero entre 1 y 9\n");
    scanf("%d", & ele_usu);
    posicion_usuario=numele(ele_usu);
    return 0;
}
void rayahori() //Función para crear líneas horizontales del tablero
{
    for(int i=0; i<15; i++)
    {
        printf("%c", 196);
    }
}
void rayaverti() //Funcion para crear líneas verticales del tablero
{
    for(int i=0; i<8; i++)
    {
        printf("\n");
        printf("%c", 179);
    }
}
int numele(int num_ele) //Esta funcion devuelve un valor entre el intervalo (0,8)
{
  return num_ele--;
}
int filas(int fila) //Esta funcion devuelve el valor de filas del intervalo (0,8)
{
    fila=numele()/3;
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


