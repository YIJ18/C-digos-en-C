/*
  @file: quebrados.c
  @brief: Hace la suma, resta, multiplicación y división de fracciones.
  @details: Definiremos los numeradores y denominadores dentro de la estructura.
  1. El programa hará la suma, resta, multiplicación y división de fracciones.
  2. La fracción se reducirá hasta su mínima expresión.
  3. El resultado será impreso.

  @author: Iris Yulit Jasso Cortes
  @date: 15-agosto-2023
*/

#include <stdio.h>

typedef struct def_quebrados
{
  int denominador, numerador;
} tipoQuebrados;

char Solicitar(tipoQuebrados *quebrados);
void Suma(tipoQuebrados *quebrados);
void Resta(tipoQuebrados *quebrados);
void Multi(tipoQuebrados *quebrados);
void Div(tipoQuebrados *quebrados);
void Simplifica(tipoQuebrados *quebrados);

int main(void)
{
  tipoQuebrados quebrados[3];
  char signo;
  signo = Solicitar(quebrados);

  switch (signo)
  {
  case '+':
    Suma(quebrados);
    break;

  case '-':
    Resta(quebrados);
    break;

  case '*':
    Multi(quebrados);
    break;

  case '/':
    Div(quebrados);
    break;

  default:
    printf("Ingreso de manera incorrecta los datos.\n");
  }

  Simplifica(quebrados);

  return 0;
}

char Solicitar(tipoQuebrados *quebrados)
{
  char signo;
  printf("Ingresa la fracción con el siguiente formato x/x + x/x, cuidando que el denominador no sea 0:\n");
  if (scanf("%d/%d %c %d/%d", &quebrados[0].numerador, &quebrados[0].denominador, &signo, &quebrados[1].numerador, &quebrados[1].denominador) != 5)
    signo = '.';
  else if (quebrados[0].denominador == 0 || quebrados[1].denominador == 0)
    signo = '.';
  return signo;
}

void Suma(tipoQuebrados *quebrados)
{
  quebrados[2].numerador = (quebrados[0].numerador * quebrados[1].denominador) + (quebrados[1].numerador * quebrados[0].denominador);
  quebrados[2].denominador = quebrados[0].denominador * quebrados[1].denominador;
}

void Resta(tipoQuebrados *quebrados)
{
  quebrados[2].numerador = (quebrados[0].numerador * quebrados[1].denominador) - (quebrados[1].numerador * quebrados[0].denominador);
  quebrados[2].denominador = quebrados[0].denominador * quebrados[1].denominador;
}

void Multi(tipoQuebrados *quebrados)
{
  quebrados[2].numerador = quebrados[0].numerador * quebrados[1].numerador;
  quebrados[2].denominador = quebrados[0].denominador * quebrados[1].denominador;
}

void Div(tipoQuebrados *quebrados)
{
  quebrados[2].numerador = quebrados[0].numerador * quebrados[1].denominador;
  quebrados[2].denominador = quebrados[0].denominador * quebrados[1].numerador;
}

void Simplifica(tipoQuebrados *quebrados)
{
  int i = 1;

  /*
   * Entra al bucle con un contador que inicia en 1, lo aumentaremos cuando la fracción no se pueda redicir con el número del contador.
   * Para que se pueda reducir una fracción es necesario que el denominador y numerador puedan ser divisibles entre el mismo número (i).
   * Lo que hace este if, es que si numerador y denominador son divisibles entre el contador (i), realiza la división y reinicia el contador.
   * El ciclo se detiene cuando ninguno de los números es divisible, esto ocurre cuando se alcanza el valor del denominador.
   */

  do
  {
    if (quebrados[2].numerador % i == 0 && quebrados[2].denominador % i == 0)
    {
      quebrados[2].numerador = quebrados[2].numerador / i;
      quebrados[2].denominador = quebrados[2].denominador / i;
      i = 1;
    }
    i++;
  } while (i != quebrados[2].denominador && i != quebrados[2].numerador);

  if (quebrados[2].numerador % quebrados[2].denominador == 0)
    printf("El resultado es: %d\n", quebrados[2].numerador / quebrados[2].denominador);

  else
    printf("El resultado es: %d / %d\n", quebrados[2].numerador, quebrados[2].denominador);
}
