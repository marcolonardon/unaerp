<?php
session_start();
require_once __DIR__ . '/functions.php';

if (empty($_SESSION['valid']) || empty($_SESSION['username'])) {
    header('Location: login.php');
    exit;
}

$username = $_SESSION['username'];
$data = get_user_registration($username);
$safe = htmlspecialchars($username, ENT_QUOTES, 'UTF-8');

$personal = $data['personal'];
$address = $data['address'];
$courses = $data['courses'];

function showValue($v)
{
    return htmlspecialchars($v ?? '', ENT_QUOTES, 'UTF-8');
}
?>
<!doctype html>
<html lang="pt-BR">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">
    <title>Resumo da Inscrição</title>
    <style>
        :root {
            --bg: #f5f6f8;
            --card: #ffffff;
            --accent: #1d72b8;
            --muted: #6c757d;
            --success: #27ae60;
            --danger: #c0392b;
            --radius: 8px;
            --gap: 18px;
        }

        * {
            box-sizing: border-box
        }

        body {
            font-family: Inter, "Arial", Helvetica, sans-serif;
            background: var(--bg);
            margin: 0;
            color: #222;
        }

        header {
            background: var(--accent);
            color: #fff;
            padding: 14px 18px;
        }

        header .inner {
            max-width: 1100px;
            margin: 0 auto;
            display: flex;
            align-items: center;
            justify-content: space-between;
        }

        header h1 {
            font-size: 1.05rem;
            margin: 0;
        }

        header .user {
            font-size: 0.95rem;
            opacity: 0.95
        }

        .wrap {
            max-width: 1100px;
            margin: 22px auto;
            padding: 0 16px;
        }

        .top-summary {
            display: flex;
            gap: var(--gap);
            align-items: center;
            margin-bottom: 18px;
            flex-wrap: wrap;
        }

        .top-card {
            background: var(--card);
            padding: 14px 16px;
            border-radius: var(--radius);
            box-shadow: 0 6px 18px rgba(17, 24, 39, 0.06);
            display: flex;
            gap: 12px;
            align-items: center;
        }

        .top-card .title {
            font-weight: 600;
            color: #111;
        }

        .badge {
            display: inline-block;
            padding: 6px 10px;
            border-radius: 999px;
            font-size: 0.85rem;
            font-weight: 600;
            color: #fff;
            background: var(--muted);
        }

        .badge.done {
            background: var(--success);
        }

        .badge.pending {
            background: var(--danger);
        }

        .summary-grid {
            display: grid;
            grid-template-columns: 1fr 360px;
            gap: var(--gap);
            align-items: start;
        }

        @media (max-width:980px) {
            .summary-grid {
                grid-template-columns: 1fr;
            }
        }

        .card {
            background: var(--card);
            padding: 18px;
            border-radius: var(--radius);
            box-shadow: 0 6px 18px rgba(17, 24, 39, 0.04);
        }

        .card h2 {
            margin: 0 0 10px 0;
            font-size: 1.05rem;
        }

        .card .edit {
            float: right;
            text-decoration: none;
            font-size: 0.9rem;
            color: var(--accent);
            border: 1px solid transparent;
            padding: 6px 8px;
            border-radius: 6px;
        }

        .card .edit:hover {
            background: #f0f8ff;
            border-color: rgba(29, 114, 184, 0.12)
        }

        dl.datalist {
            display: grid;
            grid-template-columns: 160px 1fr;
            gap: 10px 18px;
            align-items: start;
            margin: 8px 0 0 0;
        }

        dl.datalist dt {
            color: var(--muted);
            font-weight: 600;
            font-size: 0.9rem;
        }

        dl.datalist dd {
            margin: 0;
            font-size: 0.95rem;
            color: #111;
            word-break: break-word;
        }

        .right-col .mini {
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 12px;
        }

        .actions {
            display: flex;
            gap: 8px;
            flex-wrap: wrap;
        }

        .btn {
            display: inline-block;
            padding: 10px 12px;
            background: var(--accent);
            color: #fff;
            border-radius: 8px;
            text-decoration: none;
            font-weight: 600;
            font-size: 0.95rem;
        }

        .btn.ghost {
            background: transparent;
            color: var(--accent);
            border: 1px solid rgba(29, 114, 184, 0.14)
        }

        .small {
            font-size: 0.9rem;
            color: var(--muted)
        }

        .courses-list {
            list-style: none;
            padding: 0;
            margin: 8px 0 0 0;
        }

        .courses-list li {
            background: #fbfcff;
            border-left: 4px solid rgba(29, 114, 184, 0.12);
            padding: 10px 12px;
            margin-bottom: 8px;
            border-radius: 6px;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }

        .courses-list li strong {
            font-weight: 700;
        }

        .courses-list li span {
            color: var(--muted);
            font-size: 0.9rem
        }

        .footer {
            margin-top: 18px;
            display: flex;
            justify-content: space-between;
            gap: 12px;
            align-items: center;
            flex-wrap: wrap;
        }

        .muted-link {
            color: var(--muted);
            text-decoration: none
        }

        @media print {

            header,
            .btn,
            .edit {
                display: none;
            }

            body {
                background: #fff;
            }

            .summary-grid {
                grid-template-columns: 1fr;
            }
        }
    </style>
</head>

<body>
    <header>
        <div class="inner">
            <h1>Sistema de Inscrição — Resumo</h1>
            <div class="user">Usuário: <strong><?= $safe ?></strong> — <a href="logout.php" style="color:#fff; text-decoration:underline;">Sair</a></div>
        </div>
    </header>

    <main class="wrap">
        <div class="top-summary">
            <h2 class="title">Resumo rápido</h2>
        </div>

        <div class="summary-grid">
            <div>
                <section class="card" aria-labelledby="personal-heading">
                    <h2 id="personal-heading">Dados Pessoais
                        <a class="edit" href="step1.php" title="Editar dados pessoais">Editar</a>
                    </h2>

                    <dl class="datalist">
                        <dt>Nome</dt>
                        <dd><?= showValue($personal['full_name']) ?: '<span class="small">— não preenchido —</span>' ?></dd>

                        <dt>Data de Nasc.</dt>
                        <dd><?= showValue($personal['birthdate']) ?: '<span class="small">— não preenchido —</span>' ?></dd>

                        <dt>E-mail</dt>
                        <dd><?= showValue($personal['email']) ?: '<span class="small">— não preenchido —</span>' ?></dd>

                        <dt>Telefone</dt>
                        <dd><?= showValue($personal['phone']) ?: '<span class="small">— não preenchido —</span>' ?></dd>
                    </dl>
                </section>

                <div style="height:var(--gap)"></div>

                <section class="card" aria-labelledby="address-heading">
                    <h2 id="address-heading">Endereço
                        <a class="edit" href="step2.php" title="Editar endereço">Editar</a>
                    </h2>

                    <dl class="datalist">
                        <dt>Logradouro</dt>
                        <dd>
                            <?php
                            $ln = trim(($address['street'] ?? ''));
                            $num = trim(($address['number'] ?? ''));
                            $comp = trim(($address['complement'] ?? ''));
                            $line1 = $ln ? htmlspecialchars($ln, ENT_QUOTES, 'UTF-8') : '';
                            $line1 .= $num ? ', ' . htmlspecialchars($num, ENT_QUOTES, 'UTF-8') : '';
                            $line1 .= $comp ? ' — ' . htmlspecialchars($comp, ENT_QUOTES, 'UTF-8') : '';
                            echo $line1 ?: '<span class="small">— não preenchido —</span>';
                            ?>
                        </dd>

                        <dt>Cidade / Estado</dt>
                        <dd><?= ($address['city'] || $address['state']) ? (showValue($address['city']) . ' / ' . showValue($address['state'])) : '<span class="small">— não preenchido —</span>' ?></dd>

                        <dt>CEP</dt>
                        <dd><?= showValue($address['zip']) ?: '<span class="small">— não preenchido —</span>' ?></dd>
                    </dl>
                </section>
            </div>

            <aside class="right-col">
                <div class="card">
                    <div class="mini">
                        <strong>Opções de Curso</strong>
                        <a class="edit" href="step3.php" title="Editar opções">Editar</a>
                    </div>

                    <ul class="courses-list">
                        <li>
                            <div>
                                <strong><?= showValue($courses['choice1']) ?: '— não preenchido —' ?></strong>
                                <div class="small">1ª opção</div>
                            </div>
                            <span><?= ($courses['choice1']) ? '' : '' ?></span>
                        </li>

                        <li>
                            <div>
                                <strong><?= showValue($courses['choice2']) ?: '<span class="small">— opcional —</span>' ?></strong>
                                <div class="small">2ª opção</div>
                            </div>
                        </li>

                        <li>
                            <div>
                                <strong><?= showValue($courses['choice3']) ?: '<span class="small">— opcional —</span>' ?></strong>
                                <div class="small">3ª opção</div>
                            </div>
                        </li>
                    </ul>
                </div>

                <div style="height:12px"></div>

                <div class="card">
                    <div style="display:flex; justify-content:space-between; align-items:center; gap:12px;">
                        <div>
                            <div style="font-weight:700; margin-top:4px;"><?=
                                                                            (trim($personal['full_name'] ?? '') !== '') ? 'Dados salvos' : 'Nenhum dado salvo ainda';
                                                                            ?></div>
                        </div>

                        <div class="actions">
                            <a class="btn" href="step1.php">Editar</a>
                            <a class="btn ghost" href="dashboard.php">Voltar</a>
                        </div>
                    </div>

                    <div class="footer" style="margin-top:12px;">
                        <div class="small">Você pode editar qualquer etapa a qualquer momento.</div>
                    </div>
                </div>
            </aside>
        </div>
    </main>
</body>

</html>