#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void circulo();
void cruz();
void rayahori();
void rayaverti();
int numele();
int filas();
int columnas1();
int columnas2();
int m�quina();
int main()
{
    int ele_usu=0; //elecci�n del usuario de intervalo (1,9)
    int posicion_usuario; // posici�n en el tablero correspondiente a la eleccion del usuario (0,8)
    int posicion_m�quina; //posicion en el tablero correspondiente a la que elige la m�quina (0,8)
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
    cruz();
    posicion_m�quina=m�quina();
    circulo();
    return 0;
}
void rayahori() //Funci�n para crear l�neas horizontales del tablero
{
    for(int i=0; i<15; i++)
    {
        printf("%c", 196);
    }
}
void rayaverti() //Funcion para crear l�neas verticales del tablero
{
    for(int i=0; i<8; i++)
    {
        printf("\n");
        printf("%c", 179);
    }
}
void circulo() //Esta funci�n crea los circulos manejados por la maquina
{
    printf("%c", 79);
}
void cruz() //Esta funcion crea las cruces controladas por el usuario
{
    printf("%c", 88);
}
int m�quina(ele_maq) //Funci�n que representa la jugada de la m�quina
{
    srand(time(NULL))
    ele_maq=rand()%(8-0+0)+0; //el valor aleatorio que va a tomar la elecci�n de la m�quina
    return ele_maq;
}
int numele(int num_ele) //Esta funcion devuelve un valor entre el intervalo (0,8)
{
  return num_ele--;
}
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


