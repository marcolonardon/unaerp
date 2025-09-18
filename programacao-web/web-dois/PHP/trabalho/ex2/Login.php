<?php
session_start();

if (!empty($_SESSION['valid']) && !empty($_SESSION['username'])) {
    header('Location: dashboard.php');
    exit;
}

$users = [
    'admin' => 'admin',
    'adm'   => 'adm'
];

$msg = '';
$enteredUser = '';

if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['login'])) {
    $enteredUser = trim($_POST['username'] ?? '');
    $enteredPass = $_POST['password'] ?? '';

    if ($enteredUser === '' || $enteredPass === '') {
        $msg = 'Preencha usuário e senha.';
    } elseif (array_key_exists($enteredUser, $users) && $users[$enteredUser] === $enteredPass) {
        session_regenerate_id(true);
        $_SESSION['valid'] = true;
        $_SESSION['username'] = $enteredUser;
        header('Location: dashboard.php');
        exit;
    } else {
        $msg = 'Usuário ou senha incorretos.';
    }
}
?>
<!doctype html>
<html lang="pt-BR">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <title>Login</title>
    <style>
        body {
            font-family: Arial, Helvetica, sans-serif;
            background: #f5f5f5;
            padding: 40px;
        }

        .box {
            background: #fff;
            padding: 20px;
            border-radius: 6px;
            max-width: 420px;
            margin: auto;
            box-shadow: 0 2px 8px rgba(0, 0, 0, 0.08);
        }

        label {
            display: block;
            margin-top: 12px;
        }

        input[type="text"],
        input[type="password"] {
            width: 100%;
            padding: 8px;
            margin-top: 6px;
            box-sizing: border-box;
        }

        button {
            margin-top: 16px;
            padding: 10px 16px;
            cursor: pointer;
        }

        .msg {
            color: #c00;
            margin-top: 12px;
        }

        .note {
            font-size: 0.9rem;
            color: #666;
            margin-top: 14px;
        }
    </style>
</head>

<body>
    <div class="box">
        <h2>Entrar</h2>

        <?php if ($msg): ?>
            <div class="msg"><?= htmlspecialchars($msg, ENT_QUOTES, 'UTF-8') ?></div>
        <?php endif; ?>

        <form method="post" action="">
            <label for="username">Usuário:</label>
            <input id="username" name="username" type="text" value="<?= htmlspecialchars($enteredUser ?? '', ENT_QUOTES, 'UTF-8') ?>">

            <label for="password">Senha:</label>
            <input id="password" name="password" type="password">

            <button type="submit" name="login">Login</button>
        </form>

        <p class="note">Usuários de teste: <strong>admin</strong> / senha <strong>admin</strong> — <strong>adm</strong> / senha <strong>adm</strong></p>
    </div>
</body>

</html>