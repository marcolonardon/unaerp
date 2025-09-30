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

// Dados a serem atualizados
$novo_nome = "Joao Pascoalini";
$email = "joao@pascoalini.com";

// Preparando e executando a instrução SQL
$sql = "UPDATE usuarios SET nome='$novo_nome' WHERE email='$email'";
if ($conn->query($sql) === TRUE) {
    echo "Registro atualizado com sucesso!";
} else {
    echo "Erro: " . $sql . "<br>" . $conn->error;
}

// Fechando a conexão
$conn->close();
?>