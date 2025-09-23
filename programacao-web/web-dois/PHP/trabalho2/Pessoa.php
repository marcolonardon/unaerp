<?php
namespace App;

class Pessoa {
    public $id;
    public $nome;
    public $telefone;
    public $celular;
    public $tipo; // 'F' = fisica, 'J' = juridica

    public function __construct($data = []) {
        $this->id = $data['id'] ?? null;
        $this->nome = $data['nome'] ?? '';
        $this->telefone = $data['telefone'] ?? '';
        $this->celular = $data['celular'] ?? '';
        $this->tipo = $data['tipo'] ?? 'F';
    }
}
?>
