/*
  @file: prg19_conv_letras.c
  @brief: Convertir una letra dada de mayúscula a minúscula o viceversa, según sea el caso
  @details: Este programa ejemplifica el uso del c+odifo ASCII. La solución del problema es que el usuario nos va a dar un caracter y va a validar si lo que nos dio es una letra mayúscula o minúscula para convertirla a su contario, es decir, si es mayúscula se transforma a minúscula o viceversa. En caso de que el usuario nos de otro caracteres que no es una letra, imprimirá un mensaje indicando que no se puede convertir.

 

  Aunado a esto, se va a incluir el tema de banderas que nos van a servir como indicadores para definir el comportamiento del programa.
  @author: Iris Yulit Jasso Cortes
  @date: 21-marzo-2023

 

 DISEÑO ARQUITECTÓNICO

 

 Diagrama IPO de alto nivel

 

 Caracter (ENTRADA) -> Convertir letra (PROCESO) -> Letra_convertida (SALIDA)

 

 Diagrama IPO de bajo nivel

 

 Pedir caracter (PROCESO) -> (SALIDA) Caracter (ENTRADA) -> Validar caracter (PROCESO) -> (SALIDA) Bandera (ENTRADA) -> Convetir letra (PROCESO) -> (SALIDA) Letra_convertida (ENTRADA) -> Imprimir resultado (PROCESO)
*/
#include <stdio.h>
#include <stdio_ext.h>

 

void Pedir_caracter (char *Caracter);
void Validar_caracter (char Caracter);
void Convertir_letra (char Caracter, int Bandera);
void Imprimir_conversion (char Letra_convertida);

 

int main (void)
{
  char Caracter, Letra_convertida;
  int Bandera;

 

  Pedir_caracter (&Caracter);
  Validar_caracter (Caracter, &Bandera);
  Convertir_letra (Caracter, Bandera, &Letra_convertida);
  if (Bandera!=2) //if (Bandera==0 || Bandera==1)
    Imprimir_conversion (Letra_convertida);

 

  return 0;
}

 

void Pedir_caracter (char *Caracter)
{
  printf ("Dame letra que quieres convertir: ");
  scanf ("%c", Caracter);
  __fpurge(stdin);
}

 

void Validar_caracter (char Caracter, int *Bandera)
{
  if (Caracter>=65 && Caracter<=90) //Mayúsculas
    *Bandera=0;
  else
    {
      if (Caracter>='a' && Caracter<='z')//Minúsculas
        *Bandera=1;
      else
        *Bandera=2; //Otros caracteres
    }
}

 

void Convertir_letra (char Caracter, int Bandera, char *Letra_convertida)
{
 if (Bandera==0) //Mayúsculas a minúscula
    *Letra_convertida=Caracter+32;
  else
    {
      if (Bandera==1)//Minúsculas a mayúsculas
        *Letra_convertida=Caracter-32;
      else
        printf ("No es una letra, por lo tanto no se puede covertir.\n");//Otros caracteres
    }
}

 

void Imprimir_conversion (char Letra_convertida)
{
  printf ("La letra convertida es: %c\n", Letra_convertida);
}