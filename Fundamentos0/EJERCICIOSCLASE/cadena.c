142 #include<stdio.h> int Mayus(char arreglo[]);
int Minus(char arreglo[]);
int Combi(char arreglo[]);

int main(void)
{
  int y;
  char arreglo[100];
  scanf("%[^\n]", arreglo);

  Mayus(arreglo);
  printf("\n");

  Combi(arreglo);
  return 0;
}
int Mayus(char arreglo[])
{
  int y;

  for (y = 0; y < arreglo[y]; y++)
  {
    if (arreglo[y] <= 'z' && arreglo[y] >= 'a')
    {
      arreglo[y] = arreglo[y] - 32;
    }
  }
  printf("%s", arreglo);
  return 0;
}

int Minus(char arreglo[])
{
  int y;

  for (y = 0; y < arreglo[y]; y++)
  {
    if (arreglo[y] <= 'Z' && arreglo[y] >= 'A')
    {
      arreglo[y] = arreglo[y] + 32;
    }
  }
  printf("%s", arreglo);
  return 0;
}

int Combi(char arreglo[])
{
  int y;
  Minus(arreglo);

  for (y = 0; y < arreglo[y]; y++)
  {

    if (arreglo[y] < 'a' && arreglo[y] > 'z')
    {

      y = y + 1;
      arreglo[y] = arreglo[y] - 32;
    }

    if (y == 0 && arreglo[y] <= 'z' && arreglo[y] >= 'a')
    {
      arreglo[y] = arreglo[y] - 32;
    }
  }
  printf("\n");
  printf("%s", arreglo);
  return 0;
}
