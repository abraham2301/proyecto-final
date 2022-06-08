#pragma once
#include "Persona.h"
#include <iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h"

using namespace std;
class Empleado : Persona{
	//atributos
private: int idEmpleado, idPuesto, genero;
	   string nombres, apellidos, direccion, DPI,fecha_nacimiento, fecha_inicio_labores, fecha_ingreso;
	   //constructor
public:
	Empleado() {}

	Empleado(string tele, string ni, int idempleado, int idpuesto, string nom, string ape, string dire, string dpi, int gene, string fechanac, string fechainiciolabores, string fechaingre):Persona(tele,ni) {
		idEmpleado = idempleado;
		idPuesto = idpuesto;
		nombres = nom;
		apellidos = ape;
		direccion = dire;
		DPI = dpi;
		genero = gene;
		fecha_nacimiento = fechanac;
		fecha_inicio_labores = fechainiciolabores;
		fecha_ingreso = fechaingre;
	}
	// set (modificador)
	void set_idEmpleado(int idempleado) { idEmpleado = idempleado; }
	void set_idPuesto(int idpuesto) { idPuesto = idpuesto; }
	void set_nombres(string nom) { nombres = nom; }
	void set_apellidos(string ape) { apellidos = ape; }
	void set_direccion(string dire) { direccion = dire; }
	void set_DPI(string dpi) { DPI = dpi; }
	void set_genero(int gene) { genero = gene; }
	void set_fecha_nacimiento(string fechanac) { fecha_nacimiento = fechanac; }
	void set_fecha_inicio_labores(string fechainiciolabores) { fecha_inicio_labores = fechainiciolabores; }
	void set_fecha_ingreso(string fechaingre) { fecha_ingreso = fechaingre; }
	void set_telefono(string tele) { telefono = tele; }
	void set_NIT(string ni) { nit = ni; }
	//get (mostrar)
	int get_idEmpleado() { return idEmpleado; }
	int get_idPuesto() { return idPuesto; }
	string get_nombres() { return nombres; }
	string get_apellidos() { return apellidos; }
	string get_direccion() { return direccion; }
	string get_DPI() { return DPI; }
	int get_genero() { return genero; }
	string get_fecha_nacimiento() { return fecha_nacimiento; }
	string get_fech_incio_labores() { return fecha_inicio_labores; }
	string get_fecha_ingreso() { return fecha_ingreso; }
	string get_telefono() { return telefono; }
	string get_NIT() { return nit; }
	//////////////////////////////////////////////////////////////////////////////////////


	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select *from empleados;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------- Empleados ----------" << endl;
				cout << endl;
				cout << "id_Empleados" << " / " << "Nombres" << " / " << "Apellidos" << " / " << "Direccion" << " / " << "Telefono" << " / " << "DPI" << " / " << "Genero" << " / " << "Fecha_Nacimiento" << " / " << "Id_Pueto" << " / " << "Fecha_incio_labores" << " / " << "Fecha_Ingreso" << endl;

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] <<" / "<<fila[1]<<" / " << fila[2] << " / " << fila[3] << " / " << fila[4] << " / " << fila[5] << " / " << fila[6] << " / " << fila[7] << " / " << fila[8] << " / " << fila[9] << " / " << fila[10] << endl;
				}
			}
			else {
				cout << "---------- Error al mostrar la informacion ----------" << endl;
			}
		}
		else {
			cout << "--------- Error en la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}


	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string gene = to_string(genero);
			string idpues = to_string(idPuesto);
			string insertar = "INSERT INTO empleados (Nombres,Apellidos,Direccion,Telefono,DPI,Fecha_Nacimiento,id_Puesto,Fecha_Inicio_Labores,Fecha_Ingreso,Genero) VALUES ('" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + DPI + "','" + fecha_nacimiento + "'," + idpues + ",'" + fecha_inicio_labores + "',now()," + gene + ");";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "---------- Ingreso exitoso -----------" << endl;
			}
			else {
				cout << "----------- Error al ingresar la informacion --------" << endl;
			}
		}
		else {
			cout << "---------- Error en la conexion ----------" << endl;
		}

		cn.cerrar_conexion();
	}
	
	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(idEmpleado);
			string eliminar = "DELETE FROM	empleados where id_Empleados=" + borrar + ";";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "---------- Eliminacion exitosa ----------" << endl;
			}
			else {
				cout << "---------- Eliminacion fallida -----------" << endl;
			}
		}
		else {
			cout << "--------- Error de conexion ---------- " << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string modificar = to_string(idEmpleado);
			string idpues = to_string(idPuesto);
			string actualizar = "UPDATE empleados SET Nombres = '" + nombres + "', Apellidos = '" + apellidos + "', Direccion = '" + direccion + "', Telefono = '" + telefono + "', DPI = '" + DPI + "',Fecha_Nacimiento = '" + fecha_nacimiento + "', id_Puesto = " + idpues + ", Fecha_Inicio_Labores = '" + fecha_inicio_labores + "', Fecha_Ingreso = '" + fecha_ingreso + "' WHERE id_Empleados = " + modificar + ";";
			const char* a = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), a);
			if (!q_estado) {
				cout << "---------- Actualizacion exitosa ----------" << endl;
			}
			else {
				cout << "------------- Error de actualizacion ------------" << endl;
			}
		}
		else {
			cout << "---------- Error de conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
};

