#pragma once
#include "Cantidad.h"
#include <iostream>
using namespace std;
class Compra_detalle: Cantidad{
	//atributos
private: int idcompra_detalle, idcompra, idproducto;
	   float precio_costo_unitario;
	   //constructo
public:
	Compra_detalle() {
	}
	Compra_detalle(int cantidades, int idcmpradetalle, int idcompras, int idproductoss, float preciocostounitario):Cantidad(cantidades) {
		idcompra_detalle = idcmpradetalle;
		idcompra = idcompras;
		idproducto = idproductoss;
		precio_costo_unitario = preciocostounitario;
	}
	// set (modificar)
	void set_idcompra_detalle(int idcompradetalle) { idcompra_detalle = idcompradetalle; }
	void set_idcompra(int idcompraaa) { idcompra = idcompraaa; }
	void set_idproducto(int idproductoooo) { idproducto = idproductoooo; }
	void set_cantidad(int cantidaddd) { cantidad = cantidaddd; }
	void set_precio_costo_unitario(float preciocostounitario) { precio_costo_unitario = preciocostounitario; }
	//get (mostrar)
	int get_idcompra_detalle() { return idcompra_detalle; }
	int	get_idcompra() { return idcompra; }
	int get_idproducto() { return idproducto; }
	int get_cantidad() { return cantidad; }
	float get_precio_costo_unitario() { return precio_costo_unitario; }


};

