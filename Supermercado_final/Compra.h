#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
#include <vector>

using namespace std;
class Compra{
	//atributos
private: int idcompra, no_orden_compra, idproveedor;
	   int  cantidad, preciocosto;
	   string fecha_orden, fechaingreso;
	   string idproducto;
public:
	//set (modificar)
	void set_idcompra(int idcompraaa) { idcompra = idcompraaa; }
	void set_no_orden_compra(int noordencompra) { no_orden_compra = noordencompra; }
	void set_idproveedor(int idproveedorrr) { idproveedor = idproveedorrr; }
	void set_fecha_orden(string fechaorden) { fecha_orden = fechaorden; }
	void set_fechaingreso(string fechaingresooo) { fechaingreso = fechaingresooo; }
	void set_idproducto(string idpro) { idproducto = idpro; }
	void set_cantiad(int canti) { cantidad = canti; }
	void precio_costo(int preciocost) { preciocosto = preciocost; }
	// get (mostrat)
	int get_idcompra() { return idcompra; }
	int get_no_orden_compra() { return no_orden_compra; }
	int get_idproveedor() { return idproveedor; }
	string get_fecha_orden() { return fecha_orden; }
	string get_fechaingreso() { return fechaingreso; }
	string get_idproducto() { return idproducto; }
	int get_cantidad() { return cantidad; }
	int get_precio_costo() { return preciocosto; }
	/////////////////////////////////////////////////////////////////////////////////////////////
	void crear(vector<string> idProductos, vector<int> cantidades, vector<double> precios) {
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string idCompra = to_string(idcompra);
			string no_orden_comp = to_string(no_orden_compra);
			string idProveedor = to_string(idproveedor);

			string sql = "INSERT INTO compras(no_orden_compra,idproveedor,fecha_orden,fechaingreso) Select max(no_orden_compra)+1, " + idProveedor + ",now(), now() from compras;";
			const char* i = sql.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				string consulta = "SELECT @@identity AS id";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
					string idMaster = "";
					resultado = mysql_store_result(cn.getConectar());
					while (fila = mysql_fetch_row(resultado)) {
						idMaster = fila[0];
					}
					for (int i = 0; i < idProductos.size(); i++) {
						string insertarDetalle = "INSERT INTO compras_detalle (idcompra,idProducto,cantidad,precio_costo_unitario) VALUES (" + idMaster + "," + idProductos.at(i) + "," + to_string(cantidades.at(i)) + "," + to_string(precios.at(i)) + ");";
						const char* inser = insertarDetalle.c_str();
						mysql_query(cn.getConectar(), inser);
					}
				}
				else {
					cout << "---------- Error al leer id compras ----------" << endl;
				}
			}
			else {
				cout << "--------- Error al ingresar la informacion en master compra----------" << endl;
			}
		}
		else {
			cout << "----------- Error de la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select *from compras;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "--------- Compras ----------" << endl;
				cout << endl;
				cout << " id_compras " << " / " << "No_orden_compra" << " / " << " id_proveedor " << " / " << "Fecha_orden" << " / " << "Fecha_Ingeso" << endl;

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " / " << fila[1] << " / " << fila[2] << " / " << fila[3] << " / " << fila[4] << endl;
				}
			}
		}
		else {
			cout << "---------- Error de la conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string idprove = to_string(idproveedor);
			string modificar = to_string(idcompra);
			string actualizar = "UPDATE compras SET idproveedor = " + idprove + ", WHERE id_compras = " + modificar + ";";
			const char* m = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), m);

			if (!q_estado) {
				string cantidaddd = to_string(cantidad);
				string preciocostoo = to_string(preciocosto);
				string actualizar2 = "UPDATE compras_detalle SET idProducto = '"+idproducto+"', cantidad = " + cantidaddd + ", precio_costo_unitario = " + preciocostoo + " WHERE idcompra = " + modificar + ";";
				const char* m2 = actualizar2.c_str();
				q_estado = mysql_query(cn.getConectar(), m2);

			}
			if (!q_estado) {
				cout << "Modificacion exitosa" << endl;
			}
		}
		else {
			cout << "---------- Error de la conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(idcompra);
			string eliminar = "DELETE FROM compras WHERE id_compras=" + borrar + ";";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				string eliminar2 = "DELETE FROM compras_detalle WHERE idcompra = " + borrar + ";";
				const char* e2 = eliminar2.c_str();
				q_estado = mysql_query(cn.getConectar(), e2);
			}
			if (!q_estado) {
				cout << "Eliminacion exitosa" << endl;
			}
		}
		else {
			cout << "---------- Error de la conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

};

