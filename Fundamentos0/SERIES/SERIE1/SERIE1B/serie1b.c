/*
@file: Ejercicio B
@brief: Devuelve el cambio 
@details:Programa que descompone en sus componentes exponenciales un número introducido por el usuario 
@author:Iris Yulit Jasso Cortes 
@date: 20-Octubre-2022   
*/

 #include <stdio.h>

void billetes(int  bi50, int bi20,int bi10,int bi5,int bi2, int can,int mo10, int mo5, int mo2, int mo1);
/*@Parametro main: Es esta variable leemos todos los valores que el usuario introduce y llamamos a la función billetes que es la que usamos para poder*/
int main(void) {
int bi50, bi20, bi10, bi5, bi2, mo10, mo5, mo2, mo1;
int x, can;
printf("Introduce la cantidad de Billetes de 500: ");
  scanf("%d",&bi50);
printf("Introduce la cantidad de Billetes de 200: ");
  scanf("%d",&bi20);
printf("Introduce la cantidad de Billetes de 100: ");
  scanf("%d",&bi10);
printf("Introduce la cantidad de Billetes de 50: ");
  scanf("%d",&bi5);
printf("Introduce la cantidad de Billetes de 20: ");
  scanf("%d",&bi2);
printf("Introduce la cantidad de Monedas de 10: ");
  scanf("%d",&mo10);
printf("Introduce la cantidad de Monedas de 5: ");
  scanf("%d",&mo5);
printf("Introduce la cantidad de Monedas de 2: ");
  scanf("%d",&mo2);
printf("Introduce la cantidad de Monedas de 1: ");
  scanf("%d",&mo1);
printf("Cantidad para dar: ");
  scanf("%d",&can);
billetes(bi50, bi20, bi10, bi5, bi2, can, mo10, mo5, mo2, mo1);
/*Retorna un 0, eso indica que funciona bien ell rpoceso que hacemos dentro de esta función*/
  return 0;
}

/*@Parametro vacio billetes, esta función lo que hace es que con el número que el usuario introduce se calcula la cantidad de cambio que va  a devolver, si el usuario no cuenta con suficine dinero este le marca que es insuficiente*/
void billetes(int  bi50, int bi20,int bi10,int bi5,int bi2, int can, int mo10, int mo5, int mo2, int mo1){
int a, b, c, d, e;
int f, g, h, i;
int y, re, r;
int z;
a=bi50*500; b=bi20*200; c=bi10*100; d=bi5*50; e=bi2*20;
f=mo10*10; g=mo5*5; h=mo2*2; i=mo1*1;
z=a;
/*@Si la multiplicación de a, es diferente a 0, core esta parte del programa y da un residuo para ir a la siguiete cantidad*/
if(a!=0){
  if(can>=500){
    re=can/500;
    r=can%500;
    printf("%d de $500\n",re);
  }
/*@Si la multiplicación de b, es mayor a la cantidad o mayor al residuo de la anterior, corre esta parte del programa y da un residuo para ir a la siguiete cantidad*/
if(b>=can||b>=r){
  if(can>=200 && can<500){
      re=can/200;
      r=can%200;
      printf("%d de $200\n",re);
      }
  
      else if (r>=200){
      re=r/200;
      r=r%200;
      printf("%d de $200\n",re);
    }
  }
/*@Si la multiplicación de b, es mayor a la cantidad o mayor al residuo de la anterior, corre esta parte del programa y da un residuo para ir a la siguiete cantidad*/
if(c>=can||c>=r){
  if(can>=100 && can<200){
      re=can/100;
      r=can%100;
      printf("%d de $100\n",re);
      }

    else if (r>=100){
      re=r/100;
      r=r%100;
      printf("%d de $100\n",re);
      }
  }
/*@Si la multiplicación de b, es mayor a la cantidad o mayor al residuo de la anterior, corre esta parte del programa y da un residuo para ir a la siguiete cantidad*/
if(d>=can||d>=r){
  if(can>=50 && can<100){
      re=can/50;
      r=can%50;
      printf("%d de $50\n",re);
      }
    
    else if (r>=50){
      re=r/50;
      r=r%50;
      printf("%d de $50\n",re);
      }
  }
/*@Si la multiplicación de b, es mayor a la cantidad o mayor al residuo de la anterior, corre esta parte del programa y da un residuo para ir a la siguiete cantidad*/
if(e>=can||e>=r){ 
  if(can>=20 && can<50){
    re=can/20;
    r=can%20;
    printf("%d de $20\n",re);
    }
  
  else if (r>=20){
    re=r/20;
    r=r%20;
    printf("%d de $20\n",re);
    }
  } 
/*@Si la multiplicación de b, es mayor a la cantidad o mayor al residuo de la anterior, corre esta parte del programa y da un residuo para ir a la siguiete cantidad*/
if(f>=can||f>=r){ 
  if(can>=10 && can<20){
    re=can/10;
    r=can%10;
    printf("%d de $10\n",re);
    }
  
  else if (r>=10){
    re=r/10;
    r=r%10;
    printf("%d de $10\n",re);
    }
  }
/*@Si la multiplicación de b, es mayor a la cantidad o mayor al residuo de la anterior, corre esta parte del programa y da un residuo para ir a la siguiete cantidad*/
  if(g>=can||g>=r){ 
  if(can>=5 && can<10){
    re=can/5;
    r=can%5;
    printf("%d de $5\n",re);
    }
  
  else if (r>=5){
    re=r/5;
    r=r%5;
    printf("%d de $5\n",re);
    }
  }
  /*@Si la multiplicación de b, es mayor a la cantidad o mayor al residuo de la anterior, corre esta parte del programa y da un residuo para ir a la siguiete cantidad*/
if(h>=can||h>=r){ 
  if(can>=2 && can<5){
    re=can/2;
    r=can%2;
    printf("%d de $2\n",re);
    }
  
  else if (r>=2){
    re=r/2;
    r=r%2;
    printf("%d de $2\n",re);
    }
  }
/*@Si la multiplicación de b, es mayor a la cantidad o mayor al residuo de la anterior, corre esta parte del programa y da un residuo para ir a la siguiete cantidad*/
if(i>=can||i>=r){   
  if(can>=1 && can<2){
    re=can/1;
    r=can%1;
    printf("%d de $1\n",re);
    }
  
  else if (r>=1){
    re=r/1;
    r=r%1;
    printf("%d de $1\n",re);
    }
  }

/*@Si la multiplicación de a, eses igual a 0, corre esta parte del programa y da un residuo para ir a la siguiete cantidad*/
if(r!=0){
printf("No cuentas con suficiente cambio para completar esa cantidad. ");
  }
}

else if(a==0){
  if(can>=200){
      re=can/200;
      r=can%200;
      printf("%d de $200\n",re);
      }
  
      else if (r>=200){
      re=r/200;
      r=r%200;
      printf("%d de $200\n",re);
    }
  }
if(c>=can||c>=r){
  if(can>=100 && can<200){
      re=can/100;
      r=can%100;
      printf("%d de $100\n",re);
      }

    else if (r>=100){
      re=r/100;
      r=r%100;
      printf("%d de $100\n",re);
      }
  }
if(d>=can||d>=r){
  if(can>=50 && can<100){
      re=can/50;
      r=can%50;
      printf("%d de $50\n",re);
      }
    
    else if (r>=50){
      re=r/50;
      r=r%50;
      printf("%d de $50\n",re);
      }
  }
if(e>=can||e>=r){ 
  if(can>=20 && can<50){
    re=can/20;
    r=can%20;
    printf("%d de $20\n",re);
    }
  
  else if (r>=20){
    re=r/20;
    r=r%20;
    printf("%d de $20\n",re);
    }
  } 
if(f>=can||f>=r){ 
  if(can>=10 && can<20){
    re=can/10;
    r=can%10;
    printf("%d de $10\n",re);
    }
  
  else if (r>=10){
    re=r/10;
    r=r%10;
    printf("%d de $10\n",re);
    }
  }
  if(g>=can||g>=r){ 
  if(can>=5 && can<10){
    re=can/5;
    r=can%5;
    printf("%d de $5\n",re);
    }
  
  else if (r>=5){
    re=r/5;
    r=r%5;
    printf("%d de $5\n",re);
    }
  }
if(h>=can||h>=r){ 
  if(can>=2 && can<5){
    re=can/2;
    r=can%2;
    printf("%d de $2\n",re);
    }
  
  else if (r>=2){
    re=r/2;
    r=r%2;
    printf("%d de $2\n",re);
    }
  }
if(i>=can||i>=r){   
  if(can>=1 && can<2){
    re=can/1;
    r=can%1;
    printf("%d de $1\n",re);
    }
  
 
  
if(r!=0){
printf("No cuentas con suficiente cambio para completar esa cantidad. ");
  }
  
}
/*@No retorna nada la función de este código*/
  }
    
