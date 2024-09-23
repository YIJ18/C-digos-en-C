#include<stdio.h>

int main(int argc, char*argv[]){
  int y;
  for(y=1;y<argc;y++){
    printf("%s\n", argv[y]);
  }
  return 0;
}
