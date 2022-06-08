#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
using namespace std;
class Puesto{
	//atributos
private: int idPuesto;
	   string puesto;
	  //constructor
public:
	Puesto() {
	}
	//set (modificar)
	void set_idpuesto(int idpuestoo) { idPuesto = idpuestoo; }
	void set_puesto(string puestoo) { puesto = puestoo; }
	//get (mostrar)
	int get_idpuesto() { return idPuesto; }
	string get_puesto() { return puesto; }
	///////////////////////////////////////////////////////////////////////////////////

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select *from puestos;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout<<"---------- Puesto ----------" << endl;
				cout << endl;
				cout << " id_puesto " <<" / " << " Puesto " << endl;

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " / " << fila[1] << endl;
				}
			}
			else {
				cout << "--------- Error al mostrar la informacion ---------" << endl;
			}
		}
		else {
			cout << "---------- Error de la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insertar = "INSERT INTO puestos (Puesto) VALUES('" + puesto + "');";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "--------- Ingreso exitoso ---------" << endl;    
			}
			else {
				cout << "--------- Error al ingresar la informacion ---------" << endl;
			}
		}
		else {
			cout << "------- Error de conexion -------" << endl;
		}
		cn.cerrar_conexion();
	}
	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(idPuesto);
			string eliminar = "DELETE FROM puestos WHERE id_Puesto= " + borrar + ";";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "----------- Eliminacion exitosa ----------" << endl;
			}
			else {
				cout << "---------- Error al eliminar ----------" << endl;
			}
		}
		else {
			cout << "---------- Error de conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string modificar = to_string(idPuesto);
			string actualizar = "UPDATE puestos SET Puesto = '" + puesto + "' WHERE id_Puesto = " + modificar + ";";
			const char* a = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), a);
			if (!q_estado) {
				cout << "---------- Modificacion exitosa ----------" << endl;
			}
			else {
				cout << "---------- Error al modificar ----------" << endl;
			}
		}
		cn.cerrar_conexion();
	}
};

