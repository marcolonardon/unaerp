<?php
namespace App;

class Disciplina {
    public $id;
    public $nome;
    public $carga_horaria;

    public function __construct($data = []) {
        $this->id = $data['id'] ?? null;
        $this->nome = $data['nome'] ?? '';
        $this->carga_horaria = $data['carga_horaria'] ?? 0;
    }
}
?>
