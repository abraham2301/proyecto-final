#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>

using namespace std;
class Producto{
	//atributos
private: int idProducto, idMarca, existencia;
	   string producto, Descripcion, Imagen, fecha_ingreso;
	   float precio_costo, precio_venta;
	  //constructor
public:
	//set (modificar)
	void set_idProducto(int idproductooo) { idProducto = idproductooo; }
	void set_idMarca(int idmarcaaa) { idMarca = idmarcaaa; }
	void set_existencia(int existenciaaa) { existencia = existenciaaa; }
	void set_Producto(string productooo) { producto = productooo; }
	void set_Descripcion(string descripcionnn) { Descripcion = descripcionnn; }
	void set_Imagen(string imagennn) { Imagen = imagennn; }
	void set_fecha_ingreso(string fechaingre) { fecha_ingreso = fechaingre; }
	void set_precio_costo(float preciocosto) { precio_costo = preciocosto; }
	void set_precio_venta(float precioventa) { precio_venta = precioventa; }
	//get (mostrar)
	int get_idproducto() { return idProducto; }
	int get_idMarca() { return idMarca; }
	int get_existencia() { return existencia; }
	string get_producto() { return producto; }
	string get_Descripcion() { return Descripcion; }
	string get_imagen() { return Imagen; }
	string get_fecha_ingreso() { return fecha_ingreso; }
	float get_precio_costo() { return precio_costo; }
	float get_precio_venta() { return precio_venta; }
	//////////////////////////////////////////////////////////////////////////

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select *from productos;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------- Productos ----------" << endl;
				cout << endl;
				cout << " id_producto " << " / " << " Producto " << " / " << " id_Marca " << " / " << " Descripcion " << " / " << " Imagen " << " / " << " Precio_Costo " << " / " << " Precio_Venta " << " / " << " Existencia " << " / " << " Fecha_Ingreso " << endl;

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " / " << fila[1] << " / " << fila[2] << " / " << fila[3] << " / " << fila[4] << " / " << fila[5] << " / " << fila[6] << " / " << fila[7] << " / " << fila[8] << endl;
				}
			}
			else {
				cout << "---------- Error al mostrar la informacion ----------" << endl;
			}
		}
		else {
			cout << "--------- Error de la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string idmar = to_string(idMarca);
			string precicos = to_string(precio_costo);
			string precioven = to_string(precio_venta);
			string exist = to_string(existencia);
			string insertar = "INSERT INTO productos (Producto,id_Marca,Descripcion,Imagen,Precio_Costo,Precio_Venta,Existencia,Fecha_Ingreso) VALUES ('" + producto + "'," + idmar + ",'" + Descripcion + "','" + Imagen + "'," + precicos + "," + precioven + "," + exist + ",now());";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "--------- Ingreso exitoso ----------" << endl;
			}
			else {
				cout << "--------- Error al ingresar la informacion ----------" << endl;
			}
		}
		else {
			cout << "----------- Error de la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string borrar = to_string(idProducto);
			string eliminar = "DELETE FROM productos where id_Producto=" + borrar + ";";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "---------- Eliminacion exitosa ----------" << endl;
			}
			else {
				cout << "---------- Error al intentar eliminar comprueba tu conexion ----------" << endl;
			}
		}
		else {
			cout << "--------- Error de la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string modificar = to_string(idProducto);
			string idmar = to_string(idMarca);
			string precicos = to_string(precio_costo);
			string precioven = to_string(precio_venta);
			string exis = to_string(existencia);
			string actualizar = "UPDATE productos SET Producto = '" + producto + "',Descripcion = '" + Descripcion + "', Precio_Costo = " + precicos + ", Precio_Venta = " + precioven + ",Existencia = " + exis + ",Fecha_Ingreso = '" + fecha_ingreso + "' WHERE id_Producto = '" + modificar + "';";
			const char* a = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), a);
			if (!q_estado) {
				cout << "---------- Actualizacion exitosa ----------" << endl;
			}
			else {
				cout << "---------- Error de actualizacion ---------" << endl;
			}

		}
		else {
			cout << "--------- Error de la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
};

