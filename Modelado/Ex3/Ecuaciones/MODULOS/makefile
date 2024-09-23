default: principal.o funciones.o gnuplot.o 
	gcc principal.o funciones.o gnuplot.o -o graficar.out -lm

principal.o: principal.c
	gcc -c principal.c

funciones.o: funciones.c
	gcc -c funciones.c

gnuplot.o: gnuplot.c
	gcc -c gnuplot.c

limpia:
	rm *.o
	rm *.out
	rm *~

limpia_datos:
	rm *.txt
