#include <stdio.h>
/*@file:Tarea 4
@brief: Imprime caracteres del número ascci
@details: Con a n y N; el código imprime del 0 al 9 en ascci: Con la m imprime el abecedario de la a a la z: Con la M imprime el abecedario de la A a la Z
@author:Iris Yulit Jasso Cortes
@date: 29-septiembre-2022  */

void a(void);
void b(void);
void c(char Var);
char d(void);
void e(void);

/*Esta función, llama dentro de ella a la función d, que se le da el valor a la variable error y si esta es igual a 0 te imprime el texto*/
int main(void)
{
    char error;

    error = d();
    if (error == 0)
    {
        printf("Hasta crees que con el error te voy a decir que hago! :D\n");
        return 0;
    }

    c(error);
}

/*Esta función crea una lista de los caracteres A-Z*/
void a(void)
{
    char i;
    for (i = 'A'; i <= 'Z'; i++)
    {
        printf("%c\n", i);
    }
}

/*Esta función crea una lista de los caracteres a-z*/
void b(void)
{
    char i;
    for (i = 'a'; i <= 'z'; i++)
    {
        printf("%c\n", i);
    }
}

/*Esta función crea una lista de los caracteres 0-9*/
void e(void)
{
    char i;
    for (i = '0'; i <= '9'; i++)
    {
        printf("%c\n", i);
    }
}

/*Esta función llama a las otras funciones si es que pertece a alguna de las letras seleccionadas*/
void c(char Var)
{
    if (Var == 'M')
    {
        a();
    }
    if (Var == 'm')
    {
        b();
    }
    if (Var == 'n' || Var == 'N')
    {
        e();
    }
}

/*Lo que hace esta función es que cuando la letra sea diferente a n, N, m, M; regesara un 0, pero si es alguna de estas letras, regresa el caracter*/

char d(void)
{
    char mi;

    printf("Nunca confíes en una computadora que no puedas aventar por la ventana :) : ");
    mi = getchar();

    if (mi != 'm' && mi != 'M' && mi != 'n' && mi != 'N')
    {
        return 0;
    }

    return mi;
}
