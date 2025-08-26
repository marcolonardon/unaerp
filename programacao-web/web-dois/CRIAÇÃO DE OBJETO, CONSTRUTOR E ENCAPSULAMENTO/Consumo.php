<?php
class Consumo {
    private $codigo;
    private $descricao;
    private $quantidade;
    private $valorUnitario;

    public function __construct($codigo, $descricao, $quantidade, $valorUnitario){
        $this -> codigo = $codigo;
        $this -> descricao = $descricao;
        $this -> quantidade = $quantidade;
        $this -> valorUnitario = $valorUnitario;
    }

    public function setCodigo($codigo){
        $this -> codigo = $codigo;
    }

    public function setNome($descricao){
        $this -> descricao = $descricao;
    }

    public function setquantidade($quantidade){
        $this -> quantidade = $quantidade;
    }

    public function setvalorUnitario($valorUnitario){
        $this -> valorUnitario = $valorUnitario;
    }

    public function getCodigo(){
        return $this->codigo;
    }

    public function getNome(){
        return $this->descricao;
    }

    public function getquantidade(){
        return $this->quantidade;
    }

    public function getvalorUnitario(){
        return $this->valorUnitario;
    }
}
?>