﻿DELIMITER $$


CREATE PROCEDURE `mejorPromedio`(OUT mejor_promedio DECIMAL(4,2), OUT mejor_alumno CHAR(50))
BEGIN
  DECLARE salida, calif, contador INT;
  DECLARE nombreAlumno CHAR(25);
  DECLARE promedio, calTotal DECIMAL(4,2);
  DECLARE curAlumnos CURSOR FOR SELECT nombre FROM alumnos;
  DECLARE curCalif CURSOR FOR SELECT calificacion FROM vcalificaciones WHERE nombre = nombreAlumno;
  DECLARE CONTINUE HANDLER FOR NOT FOUND
    SET salida = 1;

  SET promedio = 0;  -- Inicializamos las variables
  SET calTotal = 0;
  SET contador = 0;
  SET salida = 0;

  OPEN curAlumnos;   -- Abrimos el cursor del primer query

  al_loop: REPEAT
    FETCH curAlumnos INTO nombreAlumno;   -- Obtenemos el nombre del primer alumno

    IF salida = 1 THEN
      LEAVE al_loop;
    END IF;

    OPEN curCalif; --
                     -- Para cada uno de los nombres obtenidos en el primer query
                     -- obtenemos su calificacion de la vista a la que accede
                     -- el segundo cursor
                     --
    cal_loop: REPEAT
      FETCH curCalif INTO calif;     -- Para cada alumno, obtenemos sus calificaciones

      IF salida = 1 THEN
        LEAVE cal_loop;
      END IF;

      SET calTotal = calTotal + calif; -- Vamos sumando cada una de las calificaciones del alumno
      SET contador = contador + 1;

    UNTIL salida = 1
    END REPEAT cal_loop;

    CLOSE curCalif; -- Cerramos el cursor de las calificaciones

    SET salida = 0;

    IF contador > 0 THEN
      SET calTotal = calTotal / contador;   -- Obtenemos el promedio del alumno
    END IF;

    IF promedio < calTotal THEN
      SET mejor_alumno = nombreAlumno;
      SET promedio = calTotal;
    END IF;

    SET calTotal = 0;
    SET contador = 0;

  UNTIL salida = 1
  END REPEAT al_loop;

  CLOSE curAlumnos;  -- Cerramos el cursor de los alumnos

  SET mejor_promedio = promedio; -- Fijamos el mejor promedio en la variable de salida

END $$

DELIMITER ;
