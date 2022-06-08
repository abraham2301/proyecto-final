#pragma once
#include "Cantidad.h"
#include <iostream>
using namespace std;
class Venta_detalle: Cantidad{
	//atributos
private: int idventa_detalle, idventa, idproducto;
	   float precio_unitario;
	   //constructor
public:
	Venta_detalle() {
	}
	Venta_detalle(int cantidades, int idventadetalle, int idventass, int idproductosss, float preciounitario) : Cantidad(cantidades) {
		idventa_detalle = idventadetalle;
		idventa = idventass;
		idproducto = idproductosss;
		precio_unitario = preciounitario;
	}
	//set (modificar)
	void set_idventa_detalle(int idventadetalle) { idventa_detalle = idventadetalle; }
	void set_idventa(int idventass) { idventa = idventass; }
	void set_idproducto(int idproductosss) { idproducto = idproductosss; }
	void set_cantidad(int cantidades) { cantidad = cantidades; }
	void set_precio_unitario(float preciounitario) { precio_unitario = preciounitario; }
	//get (mostrar)
	int get_idventa_detalle() { return idventa_detalle; }
	int get_idventa() { return idventa; }
	int get_idproducto() { return idproducto; }
	int get_cantidad() { return cantidad; }
	float get_precio_unitario() { return precio_unitario; }
	///////////////////////////////////////////////////////////////////////////////////
};

