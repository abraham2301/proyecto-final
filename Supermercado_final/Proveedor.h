#pragma once
#include "Persona.h"
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>

using namespace std;
class Proveedor: Persona{
	//atributos
private: int idProveedore;
	  string proveedor, direccion;
	  //constructor
public:
	Proveedor() {
	}
	Proveedor(string tele, string ni, int idprove, string prove, string dire) : Persona(tele, ni) {
		idProveedore = idprove;
		proveedor = prove;
		direccion = dire;
	}

	//set (modificador)
	void set_idProveedore(int idprove) { idProveedore = idprove; }
	void set_proveedor(string prove) { proveedor = prove; }
	void set_direccion(string dire) { direccion = dire; }
	void set_telefono(string tele) { telefono = tele; }
	void set_Nit(string ni) { nit = ni; }
	//get (mostrar)
	int get_idProveedore() {return idProveedore; }
	string get_proveedor() { return proveedor; }
	string get_direccion() { return direccion; }
	string get_telefono() { return telefono; }
	string get_Nit() { return nit; }
	///////////////////////////////////////////////////////////////////////////////////

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select *from proveedores;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------- Proveedores --------" << endl;
				cout << endl;
				cout << "id Proveedores" << " / " << "Proveedor" << " / " << "Nit" << " / " << "Direccion" << " / " << "Telefono" << endl;
				
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " / " << fila[1] << " / " << fila[2] << " / " << fila[3] << " / " << fila[4] << endl;

				}
			}
			else {
				cout << "-------- Error al mostrar la informacion ---------- " << endl;
			}
		}
		else {
			cout << "---------- Error en la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insertar = "INSERT INTO proveedores (proveedor,nit,direccion,telefono) VALUES('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "');";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "------- Ingreso exitoso --------" << endl;
			}
			else {
				cout << "------- Error al ingresar la informacion -------" << endl;
			}
		}
		else {
			cout << "-------- Error en la conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(idProveedore);
			string eliminar = "delete from proveedores where id_Proveedores = " + borrar + ";";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "-------- Eliminacion exitosa ---------" << endl;
			}
			else {
				cout << "-------- Error al intentar eliminar ---------" << endl;
			}
		}
		else {
			cout << "-------- Error en la conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}
	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string modificar = to_string(idProveedore);
			string actualizar = "UPDATE proveedores SET proveedor = '" + proveedor + "', nit ='" + nit + "', direccion = '" + direccion + "', telefono ='" + telefono + "' WHERE id_Proveedores = " + modificar + ";";
			const char* a = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), a);
			if (!q_estado) {
				cout << "--------- Modificacion exitosa ---------" << endl;
			}
			else {
				cout << "--------- Error al modificar ---------" << endl;
			}
		}
		else {
			cout << "--------- Error en la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
};

