<?php

$operacion = $_POST['operacion'];
$usuario = $_POST['nombre'];
$numero = $_POST['numero'];

$resultado = 1;

print "Hola $usuario<br><br>";


// Factorial
if($operacion == 1){
    
    
    for($i = 1; $i<=$numero; $i++){
        $resultado *= $i;
    }
    
    print "El factorial de $numero es $resultado<br>";
}
// Potencia
else{
    $exponente = $_POST['exponente'];
    
    for($i = 1; $i<=$exponente; $i++){
        $resultado *= $numero;
    }
    
    print "$numero a la $exponente es $resultado<br>";
}



?>