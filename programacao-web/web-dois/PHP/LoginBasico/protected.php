<?php
session_start();

if (empty($_SESSION['valid']) || empty($_SESSION['username'])) {
    header('Location: login.php');
    exit;
}

$username = $_SESSION['username'];
?>
<!doctype html>
<html lang="pt-BR">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width,initial-scale=1">
  <title>Área Protegida</title>
  <style>
    body{font-family: Arial, Helvetica, sans-serif; background:#f0f7ff; padding:40px;}
    .card{background:#fff; padding:20px; border-radius:6px; max-width:600px; margin:auto; box-shadow:0 2px 8px rgba(0,0,0,0.06);}
    a{color:#0077cc; text-decoration:none;}
  </style>
</head>
<body>
  <div class="card">
    <h2>Bem-vindo, <?=htmlspecialchars($username, ENT_QUOTES, 'UTF-8')?>!</h2>
    <p>Esta é uma página protegida — apenas usuários logados conseguem ver isto.</p>

    <p>
      <a href="logout.php">Sair</a>
    </p>
  </div>
</body>
</html>
