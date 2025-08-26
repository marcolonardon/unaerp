<?php
class Hospedagem {
    private $codigo;
    private $dataEntrada;
    private $dataSaida;
    private $hospede;
    private $aposento;
    private $conta; 

    public function __construct($codigo, $dataEntrada, $dataSaida, $hospede, $aposento, $conta){
        $this -> codigo = $codigo;
        $this -> dataEntrada = $dataEntrada;
        $this -> dataSaida = $dataSaida;
        $this -> hospede = $hospede;
        $this -> aposento = $aposento;
        $this -> conta = $conta;
    }

    public function setCodigo($codigo){
        $this -> codigo = $codigo;
    }

    public function setdataEntrada($dataEntrada){
        $this -> dataEntrada = $dataEntrada;
    }

    public function setdataSaida($dataSaida){
        $this -> dataSaida = $dataSaida;
    }

    public function sethospede($hospede){
        $this -> hospede = $hospede;
    }

    public function setAposento($aposento){
        $this -> aposento = $aposento;
    }

    public function setConta($conta){
        $this -> conta = $conta;
    }

    public function getCodigo(){
        return $this -> codigo;
    }

    public function getdataEntrada(){
        return $this -> dataEntrada;
    }

    public function getdataSaida(){
        return $this -> dataSaida;
    }

    public function gethospede(){
        return $this -> hospede;
    }

    public function getAposento(){
        return $this -> aposento;
    }

    public function getConta(){
        return $this -> conta;
    }
}
?>