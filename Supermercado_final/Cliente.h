#pragma once
#include "Persona.h"
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include <mysql.h>
using namespace std;
class Cliente :Persona{
	//Atributos
private: int idCliente, genero,fechaingresoss;
	   string nombres, apellidos,correo_electronico, fechaingreso;
	   //constructor
public:
	Cliente(){}

	Cliente(string tele, string ni, int idcliente, string nom, string ape, int gene, string correoelec, string fechaingre) :Persona(tele, ni) {
		idCliente = idcliente;
		nombres = nom;
		apellidos = ape;
		genero = gene;
		correo_electronico = correoelec;
		fechaingreso = fechaingre;
	}
	// set (modificar)
	void set_idCliente(int idcliente) { idCliente = idcliente; }
	void set_nombres(string nom) { nombres = nom; }
	void set_apellido(string ape) { apellidos = ape; }
	void set_genero(int gene) { genero = gene; }
	void set_coreo_electronico(string correoelec) { correo_electronico = correoelec; }
	void set_fechaingreso(string fechaingre) { fechaingreso = fechaingre; }
	void set_telefono(string tele) { telefono = tele; }
	void set_nit(string ni) { nit = ni; }
	void set_fechareal(int fechareal) { fechaingresoss = fechareal; }
	//get (mostrar)
	int get_idCliente() { return idCliente; }
	int get_genero() { return genero; }
	string get_nombres() { return nombres; }
	string get_apellido() { return apellidos; }
	string get_correo_electronico() { return correo_electronico; }
	string get_fechaingreso() { return fechaingreso; }
	string get_telefono() { return telefono; }
	string get_nit() { return nit; }
	int get_fechareal() { return fechaingresoss; }
	//////////////////////////////////////////////////////////////////////////////////////////

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT *FROM clientes;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------- Cliente ----------" << endl;
				cout << endl;
				cout << "id_Cliente" << " / " << "Nombres" << " / " << "Apellidos" << " / " << "NIT" << " / " << "Telefono" << " / " << "Correo_electronico" << " / " << "Fecha_Ingreso" << " / " << "Genero" << endl;

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " / " << fila[1] << " / " << fila[2] << " / " << fila[3] << " / " << fila[4] << " / " << fila[5] << " / " << fila[6] << " / " << fila[7] << endl;

				}

			}
			else {
				cout << "---------- Error al mostrar la informacion ---------" << endl;
			}
		}
		else {
			cout << "--------- Error de conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string gene = to_string(genero);
			string fechaingre = to_string(fechaingresoss);
			string insertar = "insert into clientes(Nombres,Apellidos,NIT,telefono,Correo_Electronico,Fecha_Ingreso,genero) VALUES ('" + nombres + "','" + apellidos + "','" + nit + "','" + telefono + "','" + correo_electronico + "',now()," + gene + ");";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "--------- Ingreso exitoso ----------" << endl;
			}
			else {
				cout << "-------- Error al ingresar la informacion --------" << endl;
			}
		}
		else {
			cout << "--------- Error de conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(idCliente);
			string eliminar = "DELETE FROM clientes WHERE id_Cliente=" + borrar + " ;";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "--------- Eliminacion exitosa ----------" << endl;
			}
			else {
				cout << "---------- Eliminacion fallida ----------" << endl;
			}
		}else{
			cout << "--------- Error de conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string modificar = to_string(idCliente);
			string gene = to_string(genero);
			string actualizar = "UPDATE clientes SET Nombres = '" + nombres + "', Apellidos = '" + apellidos + "', NIT = '" + nit + "', genero = " + gene + ", telefono = '" + telefono + "', Correo_Electronico = '" + correo_electronico + "', Fecha_Ingreso = '" + fechaingreso + "' WHERE id_Cliente = " + modificar + ";";
			const char* a = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), a);
			if (!q_estado) {
				cout << "---------- Modifiacion exitosa ---------" << endl;
			}
			else {
				cout << "--------- Modificacion fallida ---------" << endl;
			}

		}
		else {
			cout << "--------- Error de conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}
};

