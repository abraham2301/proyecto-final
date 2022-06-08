#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "ConexionBD.h"
#include <vector>
#include "Cliente.h"
#include <stdlib.h>
#include <fstream>
using namespace std;
class Venta{
	//atributos
private: int idVenta, nofactura, idcliente, idempleado;
	   int generocliente, idproducto,cantidad,precio_unitario;
	   string serie, fechafactura, fechaingreso, nittt, total;
	   string nomcliente, apellidocliente, telefonocliente, correoelectronicocliente;
	   double total_de_venta;
public:
	//set (modificar)
	void set_idVenta(int idventaaa) { idVenta = idventaaa; }
	void set_nofactura(int nofacturasss) { nofactura = nofacturasss; }
	void set_idcliente(int idclienteeee) { idcliente = idclienteeee; }
	void set_idempleado(int idempleadooooo) { idempleado = idempleadooooo; }
	void set_serie(string seriesss) { serie = seriesss; }
	void set_fechafactura(string fechafacturaaaaa) { fechafactura = fechafacturaaaaa; }
	void set_fechaingreso(string fechaingresooooo) { fechaingreso = fechaingresooooo; }
	void set_nitt(string nit22) { nittt = nit22; }
	void set_nombre_cliente(string nomcle) { nomcliente = nomcle; }
	void set_apellido_cliente(string apelliclient) { apellidocliente = apelliclient; }
	void set_telefono_cliente(string teleclient) { telefonocliente = teleclient; }
	void set_correo_cliente(string correoclient) { correoelectronicocliente = correoclient; }
	void set_genero_cliente(int geneclient) { generocliente = geneclient; }
	void set_total_de_venta(double totalventtt) { total_de_venta = totalventtt; }
	void set_producto(int produ) { idproducto = produ; }
	void set_cantidad(int canti) { cantidad = canti; }
	void set_precio_unitario(int preciou) { precio_unitario = preciou; }
	// get (mostrar)
	int get_idVenta() {return idVenta; }
	int get_nofactura() {return nofactura; }
	int get_idcliente() { return idcliente; }
	int get_idempleado() { return idempleado; }
	string get_serie() { return serie; }
	string get_fechafactura() { return fechafactura; }
	string get_fechaingreso() { return fechaingreso; }
	string get_nitt() { return nittt; }
	string get_nombre_cliente() { return nomcliente; }
	string get_apellido_cliente() { return apellidocliente; }
	string get_telefono_cliente() { return telefonocliente; }
	string get_correo_cliente() { return correoelectronicocliente; }
	int get_genero_cliente() { return generocliente; }
	double get_total_De_venta() { return total_de_venta; }
	int get_producto() {return idproducto; }
	///////////////////////////////////////////////////////////////////////////////////
	void crear(vector<string> idProductos, vector<int> cantidades, vector<double> precios) {
		ofstream factura;
		factura.open("Factura.txt", ios::out);
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string sidVenta = to_string(idVenta);
			string no_factura = to_string(nofactura);
			string idCliente = to_string(idcliente);
			string idEmpleado = to_string(idempleado);

			string sql = "INSERT INTO ventas(No_Factura,Serie,Fecha_facturada,id_Cliente,id_Empleado,Fecha_ingreso) Select max(No_factura)+1, 'A',now()," + idCliente + "," + idEmpleado + ", now() from ventas;";
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
					double total_venta = 0;
					for (int i = 0; i < idProductos.size(); i++) {
						//total_venta = total_venta + (cantidades.at(i) * precios.at(i));
						total_de_venta = total_de_venta + (cantidades.at(i) * precios.at(i));
						string insertarDetalle = "INSERT INTO ventas_detalle (id_Venta,id_Producto,Cantidad, Precio_Unitario) VALUES (" + idMaster + "," + idProductos.at(i) + "," + to_string(cantidades.at(i)) + "," + to_string(precios.at(i)) + ");";
						const char* inser = insertarDetalle.c_str();
						mysql_query(cn.getConectar(), inser);

					}
					if (!q_estado) {
						string dato_final = "Select ventas.No_Factura,ventas.Serie,ventas.Fecha_facturada,ventas.fecha_Ingreso,clientes.Nombres,clientes.Apellidos,clientes.NIT,productos.Producto,productos.Precio_Venta,ventas_detalle.cantidad,ventas_detalle.Precio_unitario from ventas inner join clientes on ventas.id_Cliente=clientes.id_Cliente inner join ventas_detalle on ventas.id_ventas=ventas_detalle.id_Venta inner join productos on ventas_detalle.id_Producto=productos.id_Producto where id_ventas= (Select max(id_ventas) from ventas);";
						const char* d = dato_final.c_str();
						q_estado = mysql_query(cn.getConectar(), d);
						if (!q_estado) {
							system("cls");
							resultado = mysql_store_result(cn.getConectar());
							fila = mysql_fetch_row(resultado);
							factura << "--------- Factura final ---------" << endl;
							factura << "Fecha: ";
							factura << fila[2] << endl;
							factura << "No_Factura: ";
							factura << fila[0] << endl;
							factura << endl;
							factura << "Nit: ";
							factura << fila[6] << endl;
							factura << "Cliente: ";
							factura << fila[4];
							factura << " ";
							factura << fila[5] << endl;
							factura << "--------- Productos ----------" << endl;

							cout << "--------- Factura final ---------" << endl;
							cout << "Fecha: ";
							cout << fila[2] << endl;
							cout << "No_Factura: ";
							cout << fila[0] << endl;
							cout << endl;
							cout << "Nit: ";
							cout << fila[6] << endl;
							cout << "Cliente: ";
							cout << fila[4];
							cout << " ";
							cout << fila[5] << endl;
							cout << "--------- Productos ----------" << endl;

							do {
								factura << "Producto: ";
								factura << fila[7];
								factura << " ";
								factura << fila[8] << endl;

								cout << "Producto: ";
								cout << fila[7];
								cout << " ";
								cout << fila[8] << endl;
							} while (fila=mysql_fetch_row(resultado));
							cout << endl;
							factura << "Total a pagar: ";
							factura << total_de_venta << endl;
							factura << "Gracias por su compra vuelva pronto";
							cout << "Total a pagar: ";
							cout << total_de_venta;
							cout << endl;
							cout << "Gracias por su compra vuelta pronto";
						}
					}
					factura.close();
				}
				else {
					cout << "---------- Error al leer id ventas ----------" << endl;
				}
			}
			else {
				cout << "--------- Error al ingresar la informacion en master venta----------" << endl;
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
			string consulta = "select *from ventas;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "--------- Ventas ---------" << endl;
				cout << endl;
				cout << " id_Ventas " << " / " << "No_Factura" << " / " << " Serie " << " / " << "Fecha_Facturada" << " / " << "Id_Cliente" << " / " << "Id_Empleo" << " / " << "Fecha_ingreso" << endl;
				
				while (fila = mysql_fetch_row(resultado)) {
					
					cout << fila[0] << " / " << fila[1] << fila[2] << " / " << fila[3] << " / " << fila[4] << " / " << fila[5] << " / " << fila[6] << endl;
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

	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string modificar = to_string(idVenta);
			string idemple = to_string(idempleado);
			string idclint = to_string(idcliente);
			string actualizar = "UPDATE ventas SET id_Cliente = " + idclint + ", id_Empleado = " + idemple + " WHERE id_ventas = " + modificar + ";";
			const char* a = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), a);
			if (!q_estado) {
				string idproducttt = to_string(idproducto);
				string canti = to_string(cantidad);
				string precis = to_string(precio_unitario);
				string actualizar2 = "UPDATE ventas_detalle SET id_Producto = " + idproducttt + ", Cantidad = " + canti + ", Precio_Unitario = " + precis + " WHERE id_Venta = " + modificar + ";";
				const char* a2 = actualizar2.c_str();
				q_estado = mysql_query(cn.getConectar(), a2);
			}
			if (!q_estado) {
				cout<<"---------Modificacion exitosa----------"<<endl;
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
			string borrar = to_string(idVenta);
			string eliminar = "delete from ventas where id_ventas=" + borrar + ";";
			const char* e = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				string eliminar2 = "DELETE FROM ventas_detalle WHERE id_ventas= " + borrar + ";";
				const char* e2 = eliminar2.c_str();
				q_estado = mysql_query(cn.getConectar(), e2);
			}
			if (!q_estado) {
				cout << "--------- Eliminacion exitosa ----------" << endl;

				string eliminar1 = "delete from ventas_detalle where id_Venta=" + borrar + ";";
				const char* e1 = eliminar1.c_str();
				q_estado = mysql_query(cn.getConectar(), e1);
			}
			else {
				cout << "------------ Eliminacion fallida ----------" << endl;
			}
		}
		else {
			cout << "---------- Error de la conexion ---------" << endl;
		}
		cn.cerrar_conexion();
	}
	void consulta_nit() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta_nit = "select  id_Cliente,Nombres, Apellidos,NIT from clientes where NIT ='" + nittt + "';";
			const char* c = consulta_nit.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				int crear;
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------- Busqueda de Nit ---------- " << endl;
				cout << endl;
				cout << "id_Cliente" << " / " << "Nombres" << " / " << "Apellidos" << " / " << "Nit" << endl;

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " / " << fila[1] << " / " << fila[2] << " / " << fila[3] << endl;

				}
				cout << endl;
			}
			else {
				cout << endl;
				cout << "---------- Error nit no registrado ---------" << endl;
				cout << "Tienes que registrar el nit" << endl;
			}

		}
		else {
			cout << "--------- Error de la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}

	void consulta_producto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta_menu = "select id_Producto,Producto,id_Marca,Precio_Venta from productos;";
			const char* c = consulta_menu.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "---------- Ayuda de productos ---------" << endl;
				cout << endl;
				cout << "Id_Producto" << " / " << "Producto" << " / " << " / " << "id_Marca" << " / " << "Precio_Venta" << endl;

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " / " << fila[1] << " / " << fila[2] << " / " << fila[3] << endl;
				}
			}
		}
		else {
			cout << "-------- Error de la conexion ----------" << endl;
		}
		cn.cerrar_conexion();
	}
};

