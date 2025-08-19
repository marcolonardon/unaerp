<?php
//https://www.php.net/manual/en/ref.filter.php

// https://www.php.net/manual/en/function.filter-var.php

//https://www.php.net/manual/en/function.htmlspecialchars.php

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $nome = $_POST['nome'];
  $email = $_POST['email'];
  $mensagem = $_POST['mensagem'];
 
 // $nome = filter_var($_POST['nome'], FILTER_SANITIZE_STRING);
 // $email = filter_var($_POST['email'], FILTER_SANITIZE_EMAIL);
 // $mensagem = filter_var($_POST['mensagem'], FILTER_SANITIZE_STRING);
 
  $erros = array();

  if (empty($nome)) {
      $erros[] = "O nome é obrigatório.";
  }


  if (empty($email)) {
      $erros[] = "O e-mail é obrigatório.";
  } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
      $erros[] = "O e-mail não é válido.";
  }


  if (empty($mensagem)) {
      $erros[] = "A mensagem é obrigatória.";
  }

  if (empty($erros)) {
      echo "Nome: " . htmlspecialchars($nome) . "<br>";
      echo "E-mail: " . htmlspecialchars($email) . "<br>";
      echo "Mensagem: " . htmlspecialchars($mensagem) . "<br>";
  } else {
      foreach ($erros as $erro) {
          echo $erro . "<br>";
      }
  }
}
?>