<?php
//https://www.php.net/manual/en/functions.user-defined.php
function saudacao($nome) {
  echo "Olá, $nome!";
}


function soma($a, $b) {
  return $a + $b;
}



$resultado = soma(3, 4);
echo $resultado."<br>"; // Saída: 7
saudacao("Jose");
echo "<hr>";



$texto = "Olá, Mundo!";

echo strlen($texto) . "<br>"; 

$novo_texto = str_replace("Mundo", "Unaerp", $texto);
echo $novo_texto; 

echo "<br>" . pow(2, 3);


echo "<br>" . sqrt(16); 


echo "<br>" . rand(1, 10);


echo "<br>" .date("d-m-Y-h:i:s A"); 


echo "<br>" . date ("F d, Y, g:i a");

echo "<br>" . date ("d") + 1;


?>