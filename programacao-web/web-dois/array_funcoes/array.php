<?php
//https://www.php.net/manual/en/book.array.php
// 3 tipos de arrays. Indexados, associativos e multidimensionais.

//indexados:

echo "<center><h1>Array Indexado</h1></center>";
$frutas = array("Maçã", "Banana", "Laranja");


echo $frutas[0] . "<br>"; 
echo $frutas[1] . "<br>"; 
echo $frutas[2] . "<br>"; 


$frutas[] = "Uva";
echo $frutas[3] . "<br>"; 



for ($i=0; $i < sizeof($frutas); $i++ )
  echo $frutas[$i] . " ";
echo "<hr>";

foreach ($frutas as $f) {
    echo $f . " ";
}


$numeros = array(1, 2, 3, 4, 5);

echo "<br>".count($numeros)."<br>"; 

$mais_numeros = array(6, 7, 8);
$todos_numeros = array_merge($numeros, $mais_numeros);
print_r($todos_numeros);




echo "<hr><hr>";

echo "<center><h1>Array Associativo</h1></center>";

$idade = array("Pedro" => 35, "Ana" => 27, "João" => 42);


echo $idade["Pedro"] . "<br>"; 
echo $idade["Ana"] . "<br>"; 
echo $idade["João"] . "<br>";

$idade["Maria"] = 30;
echo $idade["Maria"]  . "<br>";

foreach ($idade as $indice => $valor) {
    echo "$indice tem $valor anos. ";
}



echo "<hr><hr>";

echo "<center><h1>Array MultiIndexado</h1></center>";

$matriz = array(
  array(1, 2, 3),
  array(4, 5, 6),
  array(7, 8, 9)
);


echo $matriz[0][0] . "<br>"; 
echo $matriz[1][1] . "<br>"; 
echo $matriz[2][2] . "<br>"; 


foreach ($matriz as $linha) {
  foreach ($linha as $elemento) {
      echo $elemento . " ";
  }
  echo "<br>";
}

echo "<hr>";
for ($i=0 ; $i < 3;  $i++) {
  for ($j=0 ; $j <3; $j++) {
      echo $matriz[$i][$j] . " ";
  }
  echo "<br>";
}

echo "<hr>";
$m=array();
$m[0]=array(2);
$m[0][0]=10;
$m[0][1]=20;
$m[1][0]=30;
$m[1][1]=40;


foreach ($m as $linha) {
  foreach ($linha as $elemento) {
      echo $elemento . " ";
  }
  echo "<br>";
}


echo "<hr><hr>";

?>
