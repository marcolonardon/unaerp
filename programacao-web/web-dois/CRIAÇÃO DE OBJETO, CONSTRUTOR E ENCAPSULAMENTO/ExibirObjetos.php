<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <title>Exibição de Objetos</title>
</head>
<body>
    <?php
    require_once 'Hospede.php';
    require_once 'Aposento.php';
    require_once 'Consumo.php';
    require_once 'Conta.php';
    require_once 'Hospedagem.php';

    $hospede1 = new Hospede(1, 'João Silva', '123.456.789-00', 'MG123456', '99999-8888');
    $aposento1 = new Aposento(101, 200.0, 'Suite Luxo', 1);
    $consumo1 = new Consumo(1, 'Refrigerante', 2, 5.0);
    $consumo2 = new Consumo(2, 'Sanduíche', 1, 12.0);
    $conta1 = new Conta(1, 222.0, true, [$consumo1, $consumo2]);
    $hospedagem1 = new Hospedagem(1, '2025-08-20', '2025-08-25', $hospede1, $aposento1, $conta1);

    $hospede2 = new Hospede(2, 'Maria Souza', '987.654.321-00', 'SP654321', '98888-7777');
    $aposento2 = new Aposento(102, 150.0, 'Quarto Simples', 2);
    $consumo3 = new Consumo(3, 'Água', 3, 3.0);
    $conta2 = new Conta(2, 159.0, false, [$consumo3]);
    $hospedagem2 = new Hospedagem(2, '2025-08-21', '2025-08-26', $hospede2, $aposento2, $conta2);

    $hospedagens = [$hospedagem1, $hospedagem2];

    foreach ($hospedagens as $hospedagem) {
        echo '<div style="margin-bottom:20px;">';
        echo '<strong>Hospedagem Código:</strong> ' . $hospedagem->getCodigo() . '<br>';
        echo '<strong>Entrada:</strong> ' . $hospedagem->getdataEntrada() . '<br>';
        echo '<strong>Saída:</strong> ' . $hospedagem->getdataSaida() . '<br>';
        $hospede = $hospedagem->gethospede();
        echo '<strong>Hospede:</strong> ' . $hospede->getNome() . ' (CPF: ' . $hospede->getCpf() . ')<br>';
        $aposento = $hospedagem->getAposento();
        echo '<strong>Aposento:</strong> ' . $aposento->getDescricao() . ' (Valor: R$' . $aposento->getValor() . ')<br>';
        $conta = $hospedagem->getConta();
        echo '<strong>Conta:</strong> Código ' . $conta->getCodigo() . ' | Valor Total: R$' . $conta->getValorTotal() . ' | Pago: ' . ($conta->getPago() ? 'Sim' : 'Não') . '<br>';
        echo '<strong>Consumos:</strong><br>';
        foreach ($conta->getConsumos() as $consumo) {
            echo '- ' . $consumo->getNome() . ': ' . $consumo->getquantidade() . ' x R$' . $consumo->getvalorUnitario() . '<br>';
        }
        echo '</div>';
    }
    ?>
</body>
</html>
