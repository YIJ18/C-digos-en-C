#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[]) {
  int contador=0, x=0, i,y=0;

//Con este for se reccoren los argumentos ingresados.
  for (i = 1; i < argc ; i++){

  //Se comparan los argumentos, con el primer argumento.
    if (strcmp(argv[1], argv[i])==0){
      y++;
    }
  }

/*Si todos los argumentos son iguales, y sera igual al numero de argumentos menos el argumento inicial*/
if (y==argc-1){
  printf ("Los argumentos son iguales\n");
}
  else {
    printf ("Los argumentos no son iguales\n");
  }
  
  return 0;
}