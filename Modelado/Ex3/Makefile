principal.out: principal.o integrales.o ecuaciones.o gnuplot.o
	gcc -o principal.out integrales.o ecuaciones.o gnuplot.o principal.o -lm

principal.o: principal.c
	gcc -c principal.c

integrales.o: integrales.c
	gcc -c integrales.c

ecuaciones.o: ecuaciones.c
	gcc -c ecuaciones.c

gnuplot.o: gnuplot.c
	gcc -c gnuplot.c

clean:
	rm *.o
	rm *.out
	rm *~
