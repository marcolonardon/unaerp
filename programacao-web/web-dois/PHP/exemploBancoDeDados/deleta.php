<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "teste";

// Criando a conexão
$conn = new mysqli($servername, $username, $password, $dbname);

// Verificando a conexão
if ($conn->connect_error) {
    die("Falha na conexão: " . $conn->connect_error);
}

// ID do usuário a ser deletado
$email = "joao@pascoalini.com";

// Preparando e executando a instrução SQL
$sql = "DELETE FROM usuarios WHERE email='$email'";
if ($conn->query($sql) === TRUE) {
    echo "Registro deletado com sucesso!";
} else {
    echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Fechando a conexão
$conn->close();
?>