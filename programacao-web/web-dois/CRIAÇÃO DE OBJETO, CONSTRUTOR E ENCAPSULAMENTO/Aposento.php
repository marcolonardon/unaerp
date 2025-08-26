<?php
class Aposento {
    private $codigo;
    private $valor;
    private $descricao;
    private $numero;

    public function __construct($codigo, $valor, $descricao, $numero){
        $this -> codigo = $codigo;
        $this -> valor = $valor;
        $this -> descricao = $descricao;
        $this -> numero = $numero;
    }

    public function setCodigo($codigo){
        $this -> codigo = $codigo;
    }

    public function setValor($valor){
        $this -> valor = $valor;
    }

    public function setDescricao($descricao){
        $this -> descricao = $descricao;
    }

    public function setNumero($numero){
        $this -> numero = $numero;
    }

    public function getCodigo(){
        return $this->codigo;
    }

    public function getValor(){
        return $this->valor;
    }

    public function getDescricao(){
        return $this->descricao;
    }

    public function getNumero(){
        return $this->numero;
    }

}



?>