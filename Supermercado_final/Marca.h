#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
using namespace std;
class Marca{
	//atributos
private: int idmarca;
	   string marca;
public:
	Marca(){}
	Marca(int idmar,string marka) {
		idmarca = idmar;
		marca = marka;
	}
	//set (modificar)
	void set_idmarca(int idmarcas) { idmarca = idmarcas; }
	void setmarca(string marcas) { marca = marcas; }
	//get (mostrar)
	int get_idmarca() { return idmarca; }
	string get_marca() { return marca; }
	////////////////////////////////////////////////////////////

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select *from marcas;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------------Marcas----------" << endl;
				cout << endl;
				cout << " id_marca " <<" / "<<"Marca" << endl;

				while (fila = mysql_fetch_row(resultado)){
					cout << fila[0] << " / " << fila[1] << endl;
				}
			}
			else {
				cout << "----------Error al mostrar la informacion----------" << endl;
			}
		}
		else {
			cout << "----------Error de conexion----------";
		}
		cn.cerrar_conexion();
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insertar = "INSERT INTO marcas (Marca) VALUES('" + marca + "');";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "---------- Ingreso exitoso ----------" << endl;
			}
			else {
				cout << "---------- Error al ingresar ---------" << endl;
			}
		}
		else {
			cout << "----------Error de conexion----------" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(idmarca);
			string eliminar = "DELETE FROM marcas WHERE id_Marcas= " + borrar + ";";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "--------- Eliminacion exitosa ----------" << endl;
			}
			else {
				cout << "---------- Error al eliminar ---------" << endl;
			}
		}
		else {
			cout << "-------- Error de conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string modificar = to_string(idmarca);
			string actualizar = "UPDATE marcas SET Marca = '" + marca + "' WHERE id_Marcas = " + modificar + ";";
			const char* a = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), a);
			if (!q_estado) {
				cout << "---------- Modificacion Exitosa ---------" << endl;
			}
			else {
				cout << "---------- Error al modificar ----------" << endl;
			}
		}
		else {
			cout << "--------- Error de conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}

};

