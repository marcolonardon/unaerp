<?php
namespace App;

class Endereco {
    public $id;
    public $logradouro;
    public $complemento;
    public $cep;
    public $bairro;
    public $cidade;
    public $uf;

    public function __construct($data = []) {
        $this->id = $data['id'] ?? null;
        $this->logradouro = $data['logradouro'] ?? '';
        $this->complemento = $data['complemento'] ?? '';
        $this->cep = $data['cep'] ?? '';
        $this->bairro = $data['bairro'] ?? '';
        $this->cidade = $data['cidade'] ?? '';
        $this->uf = $data['uf'] ?? '';
    }
}
?>
