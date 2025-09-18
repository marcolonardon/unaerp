<?php
session_start();
require_once __DIR__ . '/functions.php';

if (empty($_SESSION['valid']) || empty($_SESSION['username'])) {
    header('Location: login.php');
    exit;
}

$username = $_SESSION['username'];
$data = get_user_registration($username);

$msg = '';
$errors = [];

$courses_list = [
    '',
    'Administração',
    'Arquitetura',
    'Ciência da Computação',
    'Direito',
    'Educação Física',
    'Engenharia Civil',
    'Engenharia Elétrica',
    'Medicina',
    'Odontologia',
    'Psicologia',
    'Design'
];

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $choice1 = trim($_POST['choice1'] ?? '');
    $choice2 = trim($_POST['choice2'] ?? '');
    $choice3 = trim($_POST['choice3'] ?? '');

    if ($choice1 === '') $errors[] = 'Escolha a primeira opção de curso.';
    $unique = array_filter([$choice1, $choice2, $choice3]);
    if (count(array_unique($unique)) < count($unique)) {
        $errors[] = 'As opções de curso devem ser diferentes entre si.';
    }

    if (empty($errors)) {
        $data['courses'] = [
            'choice1' => $choice1,
            'choice2' => $choice2,
            'choice3' => $choice3
        ];
        save_user_registration($username, $data);
        $msg = 'Opções de curso salvas com sucesso.';
        if (isset($_POST['finish'])) {
            header('Location: summary.php');
            exit;
        }
    }
}

$safe = htmlspecialchars($username, ENT_QUOTES, 'UTF-8');
$courses = $data['courses'];
?>
<!doctype html>
<html lang="pt-BR">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <title>3 — Opções de Curso</title>
    <style>
        body {
            font-family: Arial, Helvetica, sans-serif;
            background: #f5f6f8;
            margin: 0;
            padding: 0;
        }

        header {
            background: #1d72b8;
            color: #fff;
            padding: 12px 20px;
        }

        .wrap {
            max-width: 700px;
            margin: 20px auto;
            padding: 16px;
        }

        .card {
            background: #fff;
            padding: 16px;
            border-radius: 6px;
            box-shadow: 0 1px 6px rgba(0, 0, 0, 0.06);
        }

        label {
            display: block;
            margin-top: 12px;
        }

        select {
            width: 100%;
            padding: 8px;
            margin-top: 6px;
            box-sizing: border-box;
        }

        .btn {
            margin-top: 12px;
            padding: 10px 14px;
            background: #1d72b8;
            color: #fff;
            border: none;
            border-radius: 4px;
            cursor: pointer;
        }

        .secondary {
            background: #6c757d;
        }

        .msg {
            color: green;
        }

        .error {
            color: #c0392b;
        }
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
            <h2>3) Opções de Curso (escolha até 3)</h2>

            <?php if ($msg): ?><p class="msg"><?= htmlspecialchars($msg) ?></p><?php endif; ?>
            <?php if (!empty($errors)): ?>
                <div class="error">
                    <ul><?php foreach ($errors as $e) echo '<li>' . htmlspecialchars($e) . '</li>'; ?></ul>
                </div>
            <?php endif; ?>

            <form method="post" action="">
                <label>1ª opção
                    <select name="choice1">
                        <?php foreach ($courses_list as $c): ?>
                            <option value="<?= htmlspecialchars($c) ?>" <?= ($courses['choice1'] === $c) ? 'selected' : '' ?>><?= $c === '' ? '-- selecione --' : htmlspecialchars($c) ?></option>
                        <?php endforeach; ?>
                    </select>
                </label>

                <label>2ª opção
                    <select name="choice2">
                        <?php foreach ($courses_list as $c): ?>
                            <option value="<?= htmlspecialchars($c) ?>" <?= ($courses['choice2'] === $c) ? 'selected' : '' ?>><?= $c === '' ? '-- opcional --' : htmlspecialchars($c) ?></option>
                        <?php endforeach; ?>
                    </select>
                </label>

                <label>3ª opção
                    <select name="choice3">
                        <?php foreach ($courses_list as $c): ?>
                            <option value="<?= htmlspecialchars($c) ?>" <?= ($courses['choice3'] === $c) ? 'selected' : '' ?>><?= $c === '' ? '-- opcional --' : htmlspecialchars($c) ?></option>
                        <?php endforeach; ?>
                    </select>
                </label>

                <div style="margin-top:12px;">
                    <button type="submit" name="save" class="btn">Salvar</button>
                    <button type="submit" name="finish" class="btn" style="margin-left:8px;">Salvar e ver Resumo</button>
                    <a href="dashboard.php" class="btn secondary" style="text-decoration:none;color:#fff;margin-left:8px;padding:10px 12px;">Voltar</a>
                </div>
            </form>
        </div>
    </div>
</body>

</html>