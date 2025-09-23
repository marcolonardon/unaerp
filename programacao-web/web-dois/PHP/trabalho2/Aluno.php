<?php
namespace App;

class Aluno extends Pessoa {
    public $matricula;
    public $curso_id;

    public function __construct($data = []) {
        parent::__construct($data);
        $this->matricula = $data['matricula'] ?? '';
        $this->curso_id = $data['curso_id'] ?? null;
    }
}
?>
