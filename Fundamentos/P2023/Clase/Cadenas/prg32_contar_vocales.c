/*

  @file: prg32_contar_vocales.c
  @brief: Contar camtidad de vocales en una cadena
  @details: El juego consiste en lo siguiente.
El juego comienza con un tablero vacío de 8x8.

Los jugadores deben colocar alternativamente una ficha en el tablero. Las fichas son negras y blancas, y el jugador que juega con las fichas negras siempre va primero.

Para colocar una ficha, el jugador debe especificar la letra y el número correspondiente a la posición del tablero donde desea colocarla. Por ejemplo, "C4" indica que el jugador desea colocar una ficha en la casilla C4 del tablero.

Las fichas se colocan en las casillas vacías del tablero. Una vez que se coloca una ficha, todas las fichas del oponente que están encerradas entre la nueva ficha y las fichas del jugador en una línea recta en cualquier dirección (horizontal, vertical o diagonal) se voltean para que muestren el color del jugador.

Si un jugador no puede colocar una ficha, debe pasar el turno al otro jugador.

El juego continúa hasta que el tablero está lleno o ambos jugadores no pueden colocar una ficha.

El jugador con más fichas de su color en el tablero al final del juego es el ganador.

Si ambos jugadores tienen la misma cantidad de fichas al final del juego, se considera un empate.
  @author: Iris Yulit Jasso Cortes
  @date: 14-Abril-2023

Pedir Frsae(Proceso)->(salida)Frase(entrada)->Validar vocal(Proceso)->(SAlida)Cant_v(entrada)

*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>

#define MAX 61

void Pedir_frase(char *Frase);
int Validar_vocal(char *Frase);
void Imprimir_cantidad(int Vocal);

int main(void)
{
    char Frase[MAX];
    int Vocal;
    Pedir_frase(Frase);
    Vocal = Validar_vocal(Frase);
    Imprimir_cantidad(Vocal);
    return 0;
}

void Pedir_frase(char *Frase)
{
    printf("Dame frase (maximo 61 caracteres): ");
    fgets(Frase, MAX, stdin);
    Frase[strlen(Frase) - 1] = 0;
    __fpurge(stdin);
}

int Validar_vocal(char *Frase)
{
    int i;
    int Contador_vocal = 0;
    for (i = 0; i < strlen(Frase); i++)
    {
        if (Frase[i] == 'a' || Frase[i] == 'A' || Frase[i] == 'e' || Frase[i] == 'E'|| Frase[i] == 'i' || Frase[i] == 'I'|| Frase[i] == 'o' || Frase[i] == 'O'|| Frase[i] == 'u' || Frase[i] == 'U')
        {
            Contador_vocal++;
        }
    }
    return Contador_vocal;
}

void Imprimir_cantidad(int Vocal)
{
    printf("La cantidad de vocales son: %d\n", Vocal);
}

// espacios, comas, puntos, punto y coma, signo de interrogación