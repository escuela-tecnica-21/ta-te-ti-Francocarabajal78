#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void dibujarcirculo();
//void dibujarcruz();
int arreglarTablero(char tablero[], char * posicion);
void inicializartablero(char tablero[]);
void mostrartablero(char tablero[]);
int partidaterminada(char tablero[]);
int victoria(tablero);
int empate(tablero);
int contador(char tablero[], char simbolo, int a, int b, int c);
int CasilleroOcupado(char tablero[], int posicion);
int JugadaMaquina (char tablero[]);
//int numele();
//int numeroelegido();
//int filas();
//int columnas1();
//int columnas2();
//int inicializarmáquina();
int main(int argc, char argv[]) //el argumento argc contiene el número de parametros que tiene el programa
//y el vector argv es un vector de tipo strings  que contiene un string por cada uno de los parámetros
{
    int ele_usu=0; //elección del usuario de intervalo (1,9)
    int posicion_usuario; // posiciín en el tablero correspondiente a la eleccion del usuario (0,8)
    int posicion_maquina; //posicion en el tablero correspondiente a la que elige la máquina (0,8)
    char tablero[9];
    char * posicion;
    int const tirasganadoras[][3]={{0,1,2},{3,4,5},{6,7,8},{0,4,8},{2,4,6}.{0,3,6},{1,4,7},{2,5,8}}; //son las jugadas ganadoras, esto nos servira para definir las funciones como "victoria" y "empate", se puso de tipo "const" porque va a ser constante y nunca va a cambiar
    int const esquinas[]={0,2,6,8};
    int const vertices[]={1,3,5,7};
    int const centro[]={4};
    inicializartablero(tablero);
    mostrartablero(tablero);
    while(partidaterminada(tablero)==0)
    {
    printf("elija un numero entre 1 y 9\n");
    scanf("%d", & ele_usu);
    tablero[ele_usu] = 'X';
    arreglarTablero(tablero, posicion);
    mostrartablero(tablero);
    }
    //posicion_usuario=numeroelegido(ele_usu);
    //dibujarcruz();
    //posicion_máquina=inicializarmáquina();
    //circulo();
    return 0;
}
void inicializartablero(char tablero[]) //crea al tablero para darle un valor a futuro
{
    for(int x=0; x<8; x++)
    {
        tablero[x]=' '; //lo que se hace aca es dejar todos los elementos del vector "tablero" en blanco o vacios
    }
}
void mostrartablero(char tablero[])
{
    printf("%c| %c| %c\n", tablero[0], tablero[1], tablero[2]);
    printf("---|---|---\n");
    printf("%c| %c| %c\n", tablero[3], tablero[4], tablero[5]);
    printf("---|---|---\n");
    printf("%c| %c| %c\n", tablero[6], tablero[7], tablero[8]);
}
int JugadaMaquina(char tablero[])
{
    //GANA
    for(int x=0; x<8; x++) //Esto hace que cuando falte un simbolo para ganar, que la maquina gane
    {
        if(contador(tablero, 'O', tirasganadoras[x][1], tirasganadoras[x][2], tirasganadoras[x][3]==2))
        {
            return 1;
        }
    }
    //EMPATA
    for(int x=0; x<8; x++)
    {
        if(contador(tablero, 'X', tirasganadoras[x][1], tirasganadoras[x][2], tirasganadoras[x][3]==2))
        {
            return 1;
        }
    }
    //Toma el CENTRO
    if(CasilleroOcupado(tablero, centro[4])==1)
    {
        return centro[4];
    }

    //Toma las ESQUINAS
    for(int x=0; x<8; x++)
    {
        if(CasilleroOcupado(tablero, esquinas[x])==1)
        {
            return esquinas[x];
        }
    }

    //Toma los VERTICES
    for(int x=0; x<8; x++)
    {
        if(CasilleroOcupado(tablero, vertices[x])==1)
        {
            return vertices[x];
        }
    }

    //EVITA QUE LE GANEN
    /*for(int x=0; x<9; x++)
    {
        if((tablero, 'X', tirasganadoras[x][1], tirasganadoras[x][2], tirasganadoras[x][3]==2))
        {
            printf()
        }
    }*/
}

/*void dibujarcirculo() //Esta función crea los circulos manejados por la maquina
{
    printf("%c", 79);
}
void dibujarcruz() //Esta funcion crea las cruces controladas por el usuario
{
    printf("%c", 88);
}
*/
/*int inicializarmáquina(ele_maq) //Función que representa la jugada de la máquina
{
    srand(time(NULL))
    ele_maq=rand()%(8-0+0)+0; //el valor aleatorio que va a tomar la elección de la máquina
    return ele_maq;
}*/
/*int numeroelegido(int num_ele) //Esta funcion devuelve un valor entre el intervalo (0,8)
{
  return num_ele--;
}*/
int arreglarTablero(char tablero[], char * posicion) //Funcion que modifica el tablero para que el usuario pueda elegir una posicion aleatoria del tablero y si elige una que no existe le permite volver a ingresar otro valor de vuelta
{
    if (strlen(posicion)!=9)
      {
        printf("La longitud es distinta de nueve, por favor intentelo de nuevo.\n");
        return 1;
      }
    for (int i=0; i < strlen(posicion); i++)
    {
        if ((posicion[i]=='X') || (posicion[i]=='O'))
        {
            tablero[i]=posicion[i];
	    }
        else
        {
            tablero[i] = ' ';
        }
    }
    return 0;
}
int partidaterminada(char tablero) // Esta función me dice si la partida termina en empate o victoria para que finalce el ciclo repetitivo "while"
{
    return victoria(tablero) || empate(tablero);
}
int victoria(char tablero) //Esta función me dice cuándo el juego termina en victoria
{
    for(int x=0; x<8; x++)
    {
        if(contador 'X' (tirasganadoras[x][1], tirasganadoras[x][2], tirasganadoras[x][3])==3) //Aca se pregunta si tres posiciones del tablero estan ocupadas con el mismo simbolo
        {
            return 1;
        }
        if(contador 'O' (tirasganadoras[x][1], tirasganadoras[x][2], tirasganadoras[x][3])==3)
        {
            return 1;
        }
    }
}
int contador(char tablero[], char simbolo, int a, int b, int c) //esta funcion sirve como contador para contar si los espacios ocupados son 3
{
    int resultado;
    if(tablero[a]==simbolo) //e
    {
        resultado=resultado+1;
    }
    if(tablero[b]==simbolo)
    {
        resultado=resultado+1;
    }
    if(tablero[c]==simbolo)
    {
        resultado=resultado+1;
    }
}
int empate(char tablero) //Esta funcion determina cuando el juego es empate
{
    for(int x=0; x<8; x++)
    {
        if(CasilleroOcupado(tablero)) //Aca se llama la funcion para que analize el tablero completo y decir si está completamente lleno, si es asi que devuelva un valor
        {
            return 1;
        }
    }
}
int CasilleroOcupado(char tablero[], int posicion) //Esta funcion determina si el tablero está lleno, ya que un juego se considera en empate cuando el tablero está lleno y no hay 3 simbolos consecutivos iguales
{
    for(int x=0; x<8; x++)
    {
        if(tablero[posicion]==' ') //Determina si hay un casillero ocupado o vacio
        {
            return 0;
        }
        else
        {
            return 1; //Si el casillero está ocupado, devuelve un 1, es decir, devuelve un valor.
        }
    }
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
---------------------------------------------------------------------------------------------------------------------------------------
	
	/** Primer Ejercicio de Wollock */
object jugador 
{
	var goles = 0
	method cuantosgolesmetiste() 
	{
		return goles
	}
	method metegol(gol)
	{
		goles = goles+gol
		if (goles > 30)
	    {
		  console.println("Ya meti muchos goles")
	    }
	}
	method anulaciondegoles()
	{
	 	goles = 0
	}
}


