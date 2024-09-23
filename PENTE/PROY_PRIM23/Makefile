programa.out: principal.o asignaSolucion.o cronometro.o funcionesDeCarga.o funcionesDeGuardado.o funcionesDeJuego.o movimiento.o
	gcc -Wall -o programa.out principal.o asignaSolucion.o cronometro.o funcionesDeCarga.o funcionesDeGuardado.o funcionesDeJuego.o movimiento.o `pkg-config --libs gtk+-2.0`

principal.o: principal.c
	gcc -c -g principal.c `pkg-config --cflags gtk+-2.0`
	
cronometro.o: cronometro.c
	gcc -c -g cronometro.c `pkg-config --cflags gtk+-2.0`

funcionesDeCarga.o: funcionesDeCarga.c
	gcc -c -g funcionesDeCarga.c `pkg-config --cflags gtk+-2.0`

funcionesDeGuardado.o: funcionesDeGuardado.c
	gcc -c -g funcionesDeGuardado.c `pkg-config --cflags gtk+-2.0`

funcionesDeJuego.o: funcionesDeJuego.c
	gcc -c -g funcionesDeJuego.c `pkg-config --cflags gtk+-2.0`

movimiento.o: movimiento.c
	gcc -c -g movimiento.c `pkg-config --cflags gtk+-2.0`

clean:
	rm *.o
	
