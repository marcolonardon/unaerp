<?php
class Conta {
    private $codigo;
    private $valorTotal;
    private $pago;
    private $consumos;

    public function __construct($codigo, $valorTotal, $pago, $consumos) {
        $this -> codigo = $codigo;
        $this -> valorTotal = $valorTotal;
        $this -> pago = $pago;
        $this -> consumos = $consumos;
    }

    public function setCodigo($codigo) {
        $this -> codigo = $codigo;
    }

    public function setValorTotal($valorTotal) {
        $this->valorTotal = $valorTotal;
    }

    public function setConsumo($consumo) {
        $this -> consumos[] = $consumo;
    }

    public function setPago($pago) {
        $this -> pago = $pago;
    }

    public function getCodigo() {
        return $this -> codigo;
    }

    public function getValorTotal() {
        return $this -> valorTotal;
    }

    public function getPago() {
        return $this -> pago;
    }

    public function getConsumos() {
        return $this -> consumos;
    }
}
?>
