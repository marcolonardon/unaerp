<?php
namespace App;

class Funcionario extends Pessoa {
    public $admissao;
    public $salario;

    public function __construct($data = []) {
        parent::__construct($data);
        $this->admissao = $data['admissao'] ?? null;
        $this->salario = $data['salario'] ?? 0;
    }
}
?>
