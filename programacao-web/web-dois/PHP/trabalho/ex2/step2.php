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

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $street = trim($_POST['street'] ?? '');
    $number = trim($_POST['number'] ?? '');
    $complement = trim($_POST['complement'] ?? '');
    $city = trim($_POST['city'] ?? '');
    $state = trim($_POST['state'] ?? '');
    $zip = trim($_POST['zip'] ?? '');

    if ($street === '') $errors[] = 'Logradouro (rua) é obrigatório.';
    if ($city === '') $errors[] = 'Cidade é obrigatória.';
    if ($state === '') $errors[] = 'Estado é obrigatório.';

    if (empty($errors)) {
        $data['address'] = [
            'street' => $street,
            'number' => $number,
            'complement' => $complement,
            'city' => $city,
            'state' => $state,
            'zip' => $zip
        ];
        save_user_registration($username, $data);
        $msg = 'Endereço salvo com sucesso.';
        if (isset($_POST['continue'])) {
            header('Location: step3.php');
            exit;
        }
    }
}

$safe = htmlspecialchars($username, ENT_QUOTES, 'UTF-8');
$address = $data['address'];
?>
<!doctype html>
<html lang="pt-BR">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <title>2 — Endereço</title>
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

        input[type="text"] {
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
            <h2>2) Endereço</h2>

            <?php if ($msg): ?><p class="msg"><?= htmlspecialchars($msg) ?></p><?php endif; ?>
            <?php if (!empty($errors)): ?>
                <div class="error">
                    <ul><?php foreach ($errors as $e) echo '<li>' . htmlspecialchars($e) . '</li>'; ?></ul>
                </div>
            <?php endif; ?>

            <form method="post" action="">
                <label>Logradouro (rua)
                    <input type="text" name="street" value="<?= htmlspecialchars($address['street'] ?? '') ?>">
                </label>

                <label>Número
                    <input type="text" name="number" value="<?= htmlspecialchars($address['number'] ?? '') ?>">
                </label>

                <label>Complemento
                    <input type="text" name="complement" value="<?= htmlspecialchars($address['complement'] ?? '') ?>">
                </label>

                <label>Cidade
                    <input type="text" name="city" value="<?= htmlspecialchars($address['city'] ?? '') ?>">
                </label>

                <label>Estado
                    <input type="text" name="state" value="<?= htmlspecialchars($address['state'] ?? '') ?>">
                </label>

                <label>CEP
                    <input type="text" name="zip" value="<?= htmlspecialchars($address['zip'] ?? '') ?>">
                </label>

                <div style="margin-top:12px;">
                    <button type="submit" name="save" class="btn">Salvar</button>
                    <button type="submit" name="continue" class="btn" style="margin-left:8px;">Salvar e continuar</button>
                    <a href="dashboard.php" class="btn secondary" style="text-decoration:none;color:#fff;margin-left:8px;padding:10px 12px;">Voltar</a>
                </div>
            </form>
        </div>
    </div>
</body>

</html>