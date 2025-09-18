<?php
session_start();
require_once __DIR__ . '/functions.php';

if (empty($_SESSION['valid']) || empty($_SESSION['username'])) {
    header('Location: login.php');
    exit;
}

$username = $_SESSION['username'];
$safe = htmlspecialchars($username, ENT_QUOTES, 'UTF-8');
$data = get_user_registration($username);

// função simples para verificar se a seção está preenchida
function section_filled($arr) {
    if (!is_array($arr)) return false;
    foreach ($arr as $v) {
        if (is_string($v) && trim($v) !== '') return true;
        if (is_array($v)) {
            if (section_filled($v)) return true;
        }
    }
    return false;
}

$personal_done = section_filled($data['personal']);
$address_done = section_filled($data['address']);
$courses_done = section_filled($data['courses']);
?>
<!doctype html>
<html lang="pt-BR">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width,initial-scale=1">
  <title>Inscrição — Dashboard</title>
  <style>
    body{font-family:Arial,Helvetica,sans-serif;background:#f5f6f8;margin:0;padding:0;}
    header{background:#1d72b8;color:#fff;padding:12px 20px;}
    .wrap{max-width:900px;margin:20px auto;padding:20px;}
    .card{background:#fff;padding:16px;border-radius:6px;box-shadow:0 1px 6px rgba(0,0,0,0.06);margin-bottom:12px;}
    .actions a{display:inline-block;margin-right:8px;padding:8px 12px;background:#1d72b8;color:#fff;border-radius:4px;text-decoration:none;}
    .status{font-size:0.9rem;color:#555;}
    .done{color:green;font-weight:bold;}
    .notdone{color:#c0392b;font-weight:bold;}
  </style>
</head>
<body>
  <header>
    <div style="max-width:900px;margin:0 auto;display:flex;justify-content:space-between;align-items:center;">
      <div>Sistema de Inscrição - Vestibular</div>
      <div>Usuário: <strong><?= $safe ?></strong> — <a href="logout.php" style="color:#ffd;text-decoration:underline;">Sair</a></div>
    </div>
  </header>

  <div class="wrap">
    <div class="card">
      <h2>Bem-vindo, <?= $safe ?></h2>
      <p class="status">Complete as etapas abaixo. Você pode salvar e sair a qualquer momento e voltar depois para editar.</p>
      <div class="actions" style="margin-top:12px;">
        <a href="step1.php">1) Dados pessoais <?= $personal_done ? '<span class="done">✓</span>' : '<span class="notdone">●</span>' ?></a>
        <a href="step2.php">2) Endereço <?= $address_done ? '<span class="done">✓</span>' : '<span class="notdone">●</span>' ?></a>
        <a href="step3.php">3) Opções de curso <?= $courses_done ? '<span class="done">✓</span>' : '<span class="notdone">●</span>' ?></a>
        <a href="summary.php">Resumo</a>
      </div>
    </div>

    <div class="card">
      <h3>Status atual</h3>
      <ul>
        <li>Dados pessoais: <?= $personal_done ? '<span class="done">Preenchido</span>' : '<span class="notdone">Pendente</span>' ?></li>
        <li>Endereço: <?= $address_done ? '<span class="done">Preenchido</span>' : '<span class="notdone">Pendente</span>' ?></li>
        <li>Opções de curso: <?= $courses_done ? '<span class="done">Preenchido</span>' : '<span class="notdone">Pendente</span>' ?></li>
      </ul>
    </div>
  </div>
</body>
</html>
