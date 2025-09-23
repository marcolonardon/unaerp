<?php
namespace App;

class Curso {
    public $id;
    public $nome;

    public function __construct($data = []) {
        $this->id = $data['id'] ?? null;
        $this->nome = $data['nome'] ?? '';
    }
}
?>
