#pragma once
#include <iostream>
#include <mysql.h>
#include "Marca.h"
#include "Puesto.h"
#include "Proveedor.h"
#include "Producto.h"
#include "Empleado.h";
#include "Cliente.h"
#include "Venta.h"
#include <vector>
#include "Compra.h"
#include <Windows.h>
#include <stdlib.h>
#include <fstream>


using namespace std;
int main(){
    system("color 3F");
    int escoger;
    int eleccion=0;
    int eleccion_principal, eleccionventa;
    char cargando = 219;
    cout << "   Bienvenido de nuevo" << endl;
    cout << "   Que deseas hacer: " << endl;
    cout << "lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll" << endl;
    cout << "ll          Modificar tablas Solo personar autorizado = 1      llllll" << endl;
    cout << "lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll" << endl;
    cout << endl;
    cout << "   Hacer venta = 2" << endl;
    cout << "   Hacer compra = 3" << endl;
    cout << "   Respuesta = ";
    cin >> eleccion_principal;
    if (eleccion_principal == 1) {
        do {
            system("cls");
            cout << "Que tablas quieres Modificar: " << endl;
            cout << "Marcas: 1" << endl;
            cout << "Producto: 2" << endl;
            cout << "Proveedores: 3" << endl;
            cout << "Clientes: 4" << endl;
            cout << "Puesto: 5" << endl;
            cout << "Empleado: 6" << endl;
            cout << "Respuesta: ";
            cin >> escoger;
            if (escoger == 1) {
                int marcaeleccion;
                int idmark;
                string marka;
                system("cls");
                cout << "Leer marcas: 1" << endl;
                cout << "Crear marcas: 2" << endl;
                cout << "eliminar marcas: 3" << endl;
                cout << "Modiciar marcas: 4" << endl;
                cout << "Respuesta: ";
                cin >> marcaeleccion;

                if (marcaeleccion == 1) {
                    system("cls");
                    cout << "Cargando ";
                    for (int q = 0; q <= 60; q++) {
                        Sleep(60);
                        cout << cargando;
                    }
                    system("cls");
                    Marca l = Marca();
                    l.leer();
                }
                else {
                    if (marcaeleccion == 2) {
                        system("cls");
                        cout << "Cargando ";
                        for (int q = 0; q <= 60; q++) {
                            Sleep(60);
                            cout << cargando;
                        }
                        system("cls");
                        cin.ignore();
                        cout << "Ingresa el nombre de la marca: ";
                        getline(cin, marka);
                        cin.ignore();
                        cout << endl;
                        Marca i = Marca();
                        i.setmarca(marka);
                        i.crear();
                        i.leer();

                    }
                    else {
                        if (marcaeleccion == 3) {
                            system("cls");
                            cout << "Cargando ";
                            for (int q = 0; q <= 60; q++) {
                                Sleep(60);
                                cout << cargando;
                            }
                            system("cls");
                            cout << "Ingresa el id para eliminar la marca: ";
                            cin >> idmark;
                            Marca e = Marca();
                            e.set_idmarca(idmark);
                            e.eliminar();
                            e.leer();
                        }
                        else {
                            if (marcaeleccion == 4) {
                                system("cls");
                                cout << "Cargando ";
                                for (int q = 0; q <= 60; q++) {
                                    Sleep(60);
                                    cout << cargando;
                                }
                                system("cls");
                                cout << "Ingresa el id de la marca para poder modificar: ";
                                cin >> idmark;
                                cin.ignore();
                                cout << "Ingresa la marca para poder modificar: ";
                                getline(cin, marka);
                                cin.ignore();
                                Marca m = Marca();
                                m.set_idmarca(idmark);
                                m.setmarca(marka);
                                m.modificar();
                                m.leer();
                            }
                        }
                    }
                }

            }
            if (escoger == 2) {
                int productoeleccion;
                int idproduc, idmarc, exis;
                string product, descri, fechaingre;
                float preciocost, preciovent;
                system("cls");
                cout << "Leer Producto: 1" << endl;
                cout << "Crear Producto: 2" << endl;
                cout << "eliminar Producto: 3" << endl;
                cout << "Modiciar Producto: 4" << endl;
                cout << "Respuesta: ";
                cin >> productoeleccion;

                if (productoeleccion == 1) {
                    system("cls");
                    cout << "Cargando ";
                    for (int q = 0; q <= 60; q++) {
                        Sleep(60);
                        cout << cargando;
                    }
                    system("cls");
                    Producto l = Producto();
                    l.leer();
                }
                else {
                    if (productoeleccion == 2) {
                        system("cls");
                        cout << "Cargando ";
                        for (int q = 0; q <= 60; q++) {
                            Sleep(60);
                            cout << cargando;
                        }
                        system("cls");
                        cin.ignore();
                        cout << "Ingresa el nombre del producto: ";
                        getline(cin, product);
                        cin.ignore();
                        cout << "Ingresa el id de la marca: ";
                        cin >> idmarc;
                        cin.ignore();
                        cout << "Ingresa la descripcion del producto: ";
                        getline(cin, descri);
                        cin.ignore();
                        cout << "Ingresa el precio de costo por el producto: ";
                        cin >> preciocost;
                        cin.ignore();
                        cout << "Ingresa el precio de la venta por el producto: ";
                        cin >> preciovent;
                        cin.ignore();
                        cout << "Ingresa la existencia del producto: ";
                        cin >> exis;
                        cin.ignore();
                        Producto i = Producto();
                        i.set_idProducto(idproduc);
                        i.set_Producto(product);
                        i.set_idMarca(idmarc);
                        i.set_Descripcion(descri);
                        i.set_precio_costo(preciocost);
                        i.set_precio_venta(preciovent);
                        i.set_existencia(exis);
                        i.crear();
                        i.leer();
                    }
                    else {
                        if (productoeleccion == 3) {
                            system("cls");
                            cout << "Cargando ";
                            for (int q = 0; q <= 60; q++) {
                                Sleep(60);
                                cout << cargando;
                            }
                            system("cls");
                            cout << "Ingresa el id del producto a eliminar: ";
                            cin >> idproduc;
                            Producto e = Producto();
                            e.set_idProducto(idproduc);
                            e.eliminar();
                            e.leer();
                        }
                        else {
                            if (productoeleccion == 4) {
                                system("cls");
                                cout << "Cargando ";
                                for (int q = 0; q <= 60; q++) {
                                    Sleep(60);
                                    cout << cargando;
                                }
                                system("cls");
                                cout << "Ingresa el id del producto que quieres modificar ";
                                cin >> idproduc;
                                cin.ignore();
                                cout << "Ingresa el nombre del producto: ";
                                getline(cin, product);
                                cin.ignore();
                                cout << "Ingresa el id de la marca: ";
                                cin >> idmarc;
                                cin.ignore();
                                cout << "Ingresa la descripcion del producto: ";
                                getline(cin, descri);
                                cin.ignore();
                                cout << "Ingresa el precio de costo por el producto: ";
                                cin >> preciocost;
                                cin.ignore();
                                cout << "Ingresa el precio de la venta por el producto: ";
                                cin >> preciovent;
                                cin.ignore();
                                cout << "Ingresa la existencia del producto: ";
                                cin >> exis;
                                cin.ignore();
                                Producto m = Producto();
                                m.set_idProducto(idproduc);
                                m.set_Producto(product);
                                m.set_idMarca(idmarc);
                                m.set_Descripcion(descri);
                                m.set_precio_costo(preciocost);
                                m.set_precio_venta(preciovent);
                                m.set_existencia(exis);
                                m.modificar();
                                m.leer();
                            }
                        }
                    }
                }
            }
            if (escoger == 3) {
                int proveedoreleccion;
                int idprove;
                string prove, ni, dire, tele;

                system("cls");
                cout << "Leer Proveedores: 1" << endl;
                cout << "Crear Proveedores: 2" << endl;
                cout << "eliminar Proveedores: 3" << endl;
                cout << "Modiciar Proveedores: 4" << endl;
                cout << "Respuesta: ";
                cin >> proveedoreleccion;

                if (proveedoreleccion == 1) {
                    system("cls");
                    cout << "Cargando ";
                    for (int q = 0; q <= 60; q++) {
                        Sleep(60);
                        cout << cargando;
                    }
                    system("cls");
                    Proveedor l = Proveedor();
                    l.leer();
                }
                else {
                    if (proveedoreleccion == 2) {
                        system("cls");
                        cout << "Cargando ";
                        for (int q = 0; q <= 60; q++) {
                            Sleep(60);
                            cout << cargando;
                        }
                        system("cls");
                        cout << "Ingresa el nombre del proveedor: ";
                        getline(cin, prove);
                        cin.ignore();
                        cout << "Ingresa el nit del proveedor: ";
                        getline(cin, ni);
                        cin.ignore();
                        cout << "Ingresa la direccion del proveedor: ";
                        getline(cin, dire);
                        cin.ignore();
                        cout << "Ingresa el telefono del proveedor: ";
                        getline(cin, tele);
                        cin.ignore();
                        Proveedor i = Proveedor(tele, ni, idprove, prove, dire);
                        i.crear();
                        i.leer();
                    }
                    else {
                        if (proveedoreleccion == 3) {
                            system("cls");
                            cout << "Cargando ";
                            for (int q = 0; q <= 60; q++) {
                                Sleep(60);
                                cout << cargando;
                            }
                            system("cls");
                            cout << "Ingresa el id del proveedor a eliminar: ";
                            cin >> idprove;
                            Proveedor e = Proveedor();
                            e.set_idProveedore(idprove);
                            e.eliminar();
                            e.leer();
                        }
                        else {
                            if (proveedoreleccion == 4) {
                                system("cls");
                                cout << "Cargando ";
                                for (int q = 0; q <= 60; q++) {
                                    Sleep(60);
                                    cout << cargando;
                                }
                                system("cls");
                                cout << "Ingresa el Id del Proveedor para poder realizar la modificacion: ";
                                cin >> idprove;
                                cin.ignore();
                                cout << "Ingresa el nombre del proveedor: ";
                                getline(cin, prove);
                                cin.ignore();
                                cout << "Ingresa el nit del proveedor: ";
                                getline(cin, ni);
                                cin.ignore();
                                cout << "Ingresa la direccion del proveedor: ";
                                getline(cin, dire);
                                cin.ignore();
                                cout << "Ingresa el telefono del proveedor: ";
                                getline(cin, tele);
                                cin.ignore();
                                Proveedor m = Proveedor(tele, ni, idprove, prove, dire);
                                m.modificar();
                                m.leer();
                            }
                        }
                    }
                }

            }
            if (escoger == 4) {
                int clienteeleccion;
                int idclient, genero;
                string nom, ape, ni, tele, correo, fechaingre;
                char generotecla;
                system("cls");
                cout << "Leer Cliente: 1" << endl;
                cout << "Crear Cliente: 2" << endl;
                cout << "eliminar Cliente: 3" << endl;
                cout << "Modiciar Cliente: 4" << endl;
                cout << "Respuesta: ";
                cin >> clienteeleccion;

                if (clienteeleccion == 1) {
                    system("cls");
                    cout << "Cargando ";
                    for (int q = 0; q <= 60; q++) {
                        Sleep(60);
                        cout << cargando;
                    }
                    system("cls");
                    Cliente l = Cliente();
                    l.leer();
                }
                else {
                    if (clienteeleccion == 2) {
                        system("cls");
                        cout << "Cargando ";
                        for (int q = 0; q <= 60; q++) {
                            Sleep(60);
                            cout << cargando;
                        }
                        system("cls");
                        cin.ignore();
                        cout << "Ingresa los nombres del cliente: ";
                        getline(cin, nom);
                        cin.ignore();
                        cout << "Ingresa los apellidos del cliente: ";
                        getline(cin, ape);
                        cin.ignore();
                        cout << "Ingresa el nit del cliente: ";
                        getline(cin, ni);
                        cin.ignore();
                        cout << "Ingresa el genero del cliente (M/F): ";
                        cin >> generotecla;
                        if (generotecla == 'M' || generotecla == 'm') {
                            genero = 0;
                        }
                        else {
                            if (generotecla == 'F' || generotecla == 'f') {
                                genero = 1;
                            }
                        }
                        cout << endl;
                        cin.ignore();
                        cout << "Ingresa el telefono del cliente: ";
                        getline(cin, tele);
                        cin.ignore();
                        cout << "Ingresa el correo del cliente: ";
                        getline(cin, correo);
                        cin.ignore();
                        Cliente i = Cliente();
                        i.set_nombres(nom);
                        i.set_apellido(ape);
                        i.set_nit(ni);
                        i.set_genero(genero);
                        i.set_telefono(tele);
                        i.set_coreo_electronico(correo);
                        i.crear();
                        i.leer();
                    }
                    else {
                        if (clienteeleccion == 3) {
                            system("cls");
                            cout << "Cargando ";
                            for (int q = 0; q <= 60; q++) {
                                Sleep(60);
                                cout << cargando;
                            }
                            system("cls");
                            cout << "Ingresa el id del cliente a eliminar: ";
                            cin >> idclient;
                            Cliente e = Cliente();
                            e.set_idCliente(idclient);
                            e.eliminar();
                            e.leer();
                        }
                        else {
                            if (clienteeleccion == 4) {
                                system("cls");
                                cout << "Cargando ";
                                for (int q = 0; q <= 60; q++) {
                                    Sleep(60);
                                    cout << cargando;
                                }
                                system("cls");
                                cin.ignore();
                                cout << "Ingresa el id del cliente para realizar la modificacion ";
                                cin >> idclient;
                                cin.ignore();
                                cout << "Ingresa los nombres del cliente: ";
                                getline(cin, nom);
                                cin.ignore();
                                cout << "Ingresa los apellidos del cliente: ";
                                getline(cin, ape);
                                cin.ignore();
                                cout << "Ingresa el nit del cliente: ";
                                getline(cin, ni);
                                cin.ignore();
                                cout << "Ingresa el genero del cliente: ";
                                cout << "Ingresa el genero del cliente (M/F): ";
                                cin >> generotecla;
                                if (generotecla == 'M' || generotecla == 'm') {
                                    genero = 0;
                                }
                                else {
                                    if (generotecla == 'F' || generotecla == 'f') {
                                        genero = 1;
                                    }
                                }
                                cout << endl;
                                cin.ignore();
                                cout << "Ingresa el telefono del cliente: ";
                                getline(cin, tele);
                                cin.ignore();
                                cout << "Ingresa el correo del cliente: ";
                                getline(cin, correo);
                                cin.ignore();
                                Cliente m = Cliente();
                                m.set_idCliente(idclient);
                                m.set_nombres(nom);
                                m.set_apellido(ape);
                                m.set_nit(ni);
                                m.set_genero(genero);
                                m.set_telefono(tele);
                                m.set_coreo_electronico(correo);
                                m.modificar();
                                m.leer();
                            }
                        }
                    }
                }
            }
            if (escoger == 5) {
                int puestoeleccion, idpues;
                string pues;
                system("cls");
                cout << "Leer Empleado: 1" << endl;
                cout << "Crear Empleado: 2" << endl;
                cout << "eliminar Empleado: 3" << endl;
                cout << "Modiciar Empleado: 4" << endl;
                cout << "Respuesta: ";
                cin >> puestoeleccion;

                if (puestoeleccion == 1) {
                    system("cls");
                    cout << "Cargando ";
                    for (int q = 0; q <= 60; q++) {
                        Sleep(60);
                        cout << cargando;
                    }
                    system("cls");
                    Puesto l = Puesto();
                    l.leer();
                }
                else {
                    if (puestoeleccion == 2) {
                        system("cls");
                        cout << "Cargando ";
                        for (int q = 0; q <= 60; q++) {
                            Sleep(60);
                            cout << cargando;
                        }
                        system("cls");
                        cin.ignore();
                        cout << "Ingresa el puesto del empleado: ";
                        getline(cin, pues);
                        cin.ignore();
                        cout << endl;
                        Puesto i = Puesto();
                        i.set_puesto(pues);
                        i.crear();
                        i.leer();
                    }
                    else {
                        if (puestoeleccion == 3) {
                            system("cls");
                            cout << "Cargando ";
                            for (int q = 0; q <= 60; q++) {
                                Sleep(60);
                                cout << cargando;
                            }
                            system("cls");
                            cout << "Ingresa el id del puesto a eliminar: ";
                            cin >> idpues;
                            Puesto e = Puesto();
                            e.set_idpuesto(idpues);
                            e.eliminar();
                            e.leer();
                        }
                        else {
                            if (puestoeleccion == 4) {
                                system("cls");
                                cout << "Cargando ";
                                for (int q = 0; q <= 60; q++) {
                                    Sleep(60);
                                    cout << cargando;
                                }
                                system("cls");
                                cout << "Ingresa el id del puesto a modificar: ";
                                cin >> idpues;
                                cin.ignore();
                                cout << "Ingresa el puesto del empleado: ";
                                getline(cin, pues);
                                cin.ignore();
                                Puesto m = Puesto();
                                m.set_idpuesto(idpues);
                                m.set_puesto(pues);
                                m.modificar();
                                m.leer();
                            }
                        }
                    }
                }

            }
            if (escoger == 6) {
                int empleadoeleccion, idEmple, idpues, genero;
                string nom, ape, dire, tele, dpii, fechanac, fechainic, fechaingre, ni;
                char generoteclado;
                system("cls");
                cout << "Leer Empleado: 1" << endl;
                cout << "Crear Empleado: 2" << endl;
                cout << "eliminar Empleado: 3" << endl;
                cout << "Modiciar Empleado: 4" << endl;
                cout << "Respuesta: ";
                cin >> empleadoeleccion;
                if (empleadoeleccion == 1) {
                    system("cls");
                    cout << "Cargando ";
                    for (int q = 0; q <= 60; q++) {
                        Sleep(60);
                        cout << cargando;
                    }
                    system("cls");
                    Empleado l = Empleado();
                    l.leer();
                }
                else {
                    if (empleadoeleccion == 2) {
                        system("cls");
                        cout << "Cargando ";
                        for (int q = 0; q <= 60; q++) {
                            Sleep(60);
                            cout << cargando;
                        }
                        system("cls");
                        cin.ignore();
                        cout << "Ingresa los nombres del empleado: ";
                        getline(cin, nom);
                        cin.ignore();
                        cout << "Ingresa los apellidos del empleado: ";
                        getline(cin, ape);
                        cin.ignore();
                        cout << "Ingresa la direccion del empleado: ";
                        getline(cin, dire);
                        cin.ignore();
                        cout << "Ingresa el numero telefonico del empleado: ";
                        getline(cin, tele);
                        cin.ignore();
                        cout << "Ingresa el DPI del empleado: ";
                        getline(cin, dpii);
                        cin.ignore();
                        cout << "Ingresa la fecha de nacimiento del empleado: ";
                        getline(cin, fechanac);
                        cin.ignore();
                        cout << "Ingresa el id del puesto del empleado: ";
                        cin >> idpues;
                        cin.ignore();
                        cout << "Ingresa la fecha de inicio de labores del empleado: ";
                        getline(cin, fechainic);
                        cin.ignore();
                        cout << "Ingresa el genero del empleado: ";
                        cout << "Ingresa el genero del cliente (M/F): ";
                        cin >> generoteclado;
                        if (generoteclado == 'M' || generoteclado == 'm') {
                            genero = 0;
                        }
                        else {
                            if (generoteclado == 'F' || generoteclado == 'f') {
                                genero = 1;
                            }
                        }
                        cout << endl;
                        cin.ignore();

                        Empleado c = Empleado();
                        c.set_nombres(nom);
                        c.set_apellidos(ape);
                        c.set_direccion(dire);
                        c.set_telefono(tele);
                        c.set_DPI(dpii);
                        c.set_fecha_nacimiento(fechanac);
                        c.set_idPuesto(idpues);
                        c.set_fecha_inicio_labores(fechainic);
                        c.set_genero(genero);
                        c.crear();
                        c.leer();
                    }
                    else {
                        if (empleadoeleccion == 3) {
                            system("cls");
                            cout << "Cargando ";
                            for (int q = 0; q <= 60; q++) {
                                Sleep(60);
                                cout << cargando;
                            }
                            system("cls");
                            cout << "Ingresa el id del empleado a eliminar: ";
                            cin >> idEmple;
                            Empleado e = Empleado();
                            e.set_idEmpleado(idEmple);
                            e.eliminar();
                            e.leer();
                        }
                        else {
                            if (empleadoeleccion == 4) {
                                system("cls");
                                cout << "Cargando ";
                                for (int q = 0; q <= 60; q++) {
                                    Sleep(60);
                                    cout << cargando;
                                }
                                system("cls");
                                cout << "ingresa el id del Empleado que quieres modificar: ";
                                cin >> idEmple;
                                cin.ignore();
                                cout << "Ingresa los nombres del empleado: ";
                                getline(cin, nom);
                                cin.ignore();
                                cout << "Ingresa los apellidos del empleado: ";
                                getline(cin, ape);
                                cin.ignore();
                                cout << "Ingresa la direccion del empleado: ";
                                getline(cin, dire);
                                cin.ignore();
                                cout << "Ingresa el numero del empleado: ";
                                getline(cin, tele);
                                cin.ignore();
                                cout << "Ingresa el DPI del empleado: ";
                                getline(cin, dpii);
                                cin.ignore();
                                cout << "Ingresa el genero del empleado: ";
                                cout << "Ingresa el genero del cliente (M/F): ";
                                cin >> generoteclado;
                                if (generoteclado == 'M' || generoteclado == 'm') {
                                    genero = 0;
                                }
                                else {
                                    if (generoteclado == 'F' || generoteclado == 'f') {
                                        genero = 1;
                                    }
                                }
                                cout << endl;
                                cin.ignore();
                                cout << "Ingresa la fecha de nacimiento del empleado: ";
                                getline(cin, fechanac);
                                cin.ignore();
                                cout << "Ingresa el id del puesto del empleado: ";
                                cin >> idpues;
                                cin.ignore();
                                cout << "Ingresa la fecha de inicio de labores del empleado: ";
                                getline(cin, fechainic);
                                cin.ignore();
                                Empleado m = Empleado();
                                m.set_nombres(nom);
                                m.set_apellidos(ape);
                                m.set_direccion(dire);
                                m.set_telefono(tele);
                                m.set_DPI(dpii);
                                m.set_fecha_nacimiento(fechanac);
                                m.set_idPuesto(idpues);
                                m.set_fecha_inicio_labores(fechainic);
                                m.set_genero(genero);
                                m.modificar();
                                m.leer();
                            }
                        }
                    }
                }
            }
            cout << endl;
            cout << endl;
            cout << "Deseas regresar al menu principal" << endl;
            cout << "Si = 1" << endl;
            cout << "NO = 2" << endl;
            cout << "Respuesta = ";
            cin >> eleccion;
        } while (eleccion == 1);

    }
else {
if (eleccion_principal == 2) {
    do {
        system("cls");
        cout << "Verficar Nit guardado del cliente= 1 " << endl;
        cout << "Crear Venta= 2" << endl;
        cout << "Eliminar Venta= 3" << endl;
        cout << "Mofidicar Venta= 4" << endl;
        cout << "Respuesta: ";
        cin >> escoger;

        if (escoger == 1) {
            string nit;
            int crear_cliente;
            int clienteeleccion;
            int idclient, genero;
            string nom, ape, ni, tele, correo, fechaingre;
            char generotecla;
            system("cls");
            cout << "Cargando ";
            for (int q = 0; q <= 60; q++) {
                Sleep(60);
                cout << cargando;
            }
            system("cls");
            cout << "Ingresa el para verificar: ";
            cin >> nit;
            Cliente i = Cliente();
            Venta n = Venta();
            n.set_nitt(nit);
            n.consulta_nit();
            cout << "---------- Nota ----------" << endl;
            cout << "Si la informacion no aparece no esta guardado el nit del cliente" << endl;
            cout << "Desea Guardarlo:" << endl;
            cout << " Si = 1" << endl;
            cout << " No = 2" << endl;
            cout << "Respuesta = ";
            cin >> crear_cliente;
            if (crear_cliente == 1) {
                system("cls");
                system("cls");
                cin.ignore();
                cout << "Ingresa los nombres del cliente: ";
                getline(cin, nom);
                cin.ignore();
                cout << "Ingresa los apellidos del cliente: ";
                getline(cin, ape);
                cin.ignore();
                cout << "Ingresa el nit del cliente: ";
                getline(cin, ni);
                cin.ignore();
                cout << "Ingresa el genero del cliente (M/F): ";
                cin >> generotecla;
                if (generotecla == 'M' || generotecla == 'm') {
                    genero = 0;
                }
                else {
                    if (generotecla == 'F' || generotecla == 'f') {
                        genero = 1;
                    }
                }
                cout << endl;
                cin.ignore();
                cout << "Ingresa el telefono del cliente: ";
                getline(cin, tele);
                cin.ignore();
                cout << "Ingresa el correo del cliente: ";
                getline(cin, correo);
                cin.ignore();
                Cliente i = Cliente();
                i.set_nombres(nom);
                i.set_apellido(ape);
                i.set_nit(ni);
                i.set_genero(genero);
                i.set_telefono(tele);
                i.set_coreo_electronico(correo);
                i.crear();
                i.leer();
            }

        }
        if (escoger == 2) {
            int vermenu;
            int finalizar;
            vector<string> idProductos;
            vector<int> cantidades;
            vector<double> precio_unitario;
            int nofactura, idcliente,idempleado, cantidadesssss;
            string idproductosssss;
            double preciunitariosss;
            system("cls");
            cout << "Cargando ";
            for (int q = 0; q <= 60; q++) {
                Sleep(60);
                cout << cargando;
            }
            system("cls");
            cout << "Quieres ver el menu de los productos para guiarte en la venta" << endl;
            cout << "Si = 1" << endl;
            cout << "No = 2" << endl;
            cout << "Respuesta: ";
            cin >> vermenu;
            if (vermenu == 1) {
                Venta l = Venta();
                l.consulta_producto();
            }
            cout << endl;
            cin.ignore();
            cout << "Ingresa el id del empleado: ";
            cin >> idempleado;
            cin.ignore();
            cout << "Ingresa el id del cliente: ";
            cin >> idcliente;
            cin.ignore();

            do {
                cout << "Ingresa el id del producto: ";
                cin >> idproductosssss;
                cout << "Ingresa las cantidades del producto: ";
                cin >> cantidadesssss;
                cout << "Ingresa el precio unitario del producto: ";
                cin >> preciunitariosss;
                idProductos.push_back(idproductosssss);
                cantidades.push_back(cantidadesssss);
                precio_unitario.push_back(preciunitariosss);
                cout << "Quieres agregar mas prodcutos: "<<endl;
                cout << "Si = 1" << endl;
                cout << "No = 2" << endl;
                    cin >> finalizar;
            } while (finalizar == 1);

            Venta c = Venta();
            c.set_idempleado(idempleado);
            c.set_idcliente(idcliente);
            c.crear(idProductos, cantidades, precio_unitario);

        }
        if (escoger == 3) {
            int eliminar;
            system("cls");
            cout << "Cargando ";
            for (int q = 0; q <= 60; q++) {
                Sleep(60);
                cout << cargando;
            }
            system("cls");
            cout << "Ingresa el id de la venta a eliminar: ";
            cin >> eliminar;
            Venta e = Venta();
            e.set_idVenta(eliminar);
            e.eliminar();
        }
        if (escoger == 4) {
            int idvent,idemple,idclint;
            int idproduct, canti, preci;
            int modificar;
            system("cls");
            cout << "Cargando: ";
            for (int q = 0; q <= 60; q++) {
                Sleep(60);
                cout << cargando;
            }
            system("cls");
            cout << "Ingresa el id de la venta a modificar: ";
            cin >> modificar;
            cout << "Ingresa el id del cliente a modificar: ";
            cin >> idclint;
            cout << "Ingresa el id del empleado a modificar: ";
            cin >> idemple;
            cout << "Ingresa el id del porducto a modificar: ";
            cin >> idproduct;
            cout << "Ingresa la cantidad del producto a modificar: ";
            cin >> canti;
            cout << "Ingresa el precio unitario del producto a modificar: ";
            cin >> preci;
            Venta m = Venta();
            m.set_idVenta(modificar);
            m.set_idcliente(idclint);
            m.set_idempleado(idemple);
            m.set_producto(idproduct);
            m.set_precio_unitario(preci);
            m.modificar();

        }
        cout << endl;
        cout << endl;
        cout << "Deseas regresar al menu " << endl;
        cout << " Si = 1" << endl;
        cout << " No = 2 " << endl;
        cout << "Respuesta = ";
        cin >> eleccion;




    }while (eleccion == 1);



}
else {
if (eleccion_principal == 3) {
    do {
        int eleccioncompra;
        system("cls");
        cout << "Que quieres hacer " << endl;;
        cout << "Realizar compra = 1  " << endl;;
        cout << "Eliminar compra = 2 " << endl;;
        cout << "Modiciar compra = 3 " << endl;;
        cout << "Buscar compra = 4 " << endl;;
        cout << "Respuesta: ";
        cin >> escoger;
        if (escoger == 1) {
            int idproveedor,cantidaddd,preciocosstoo;
            string idproductorrr;
            vector<int> cantidad;
            vector<double>precio_costo;
            vector<string>idproducto;
            system("cls");
            cout << "Cargando: ";
            for (int q = 0; q <= 60; q++) {
                Sleep(60);
                cout << cargando;
            }
            system("cls");
            cout << "Ingresa el id del producto: ";
            cin >> idproductorrr;
            cout << "Ingresa la cantidad del producto: ";
            cin >> cantidaddd;
            cout << "Ingresa el precio del costo por unidad: ";
            cin >> preciocosstoo;
            cantidad.push_back(cantidaddd);
            precio_costo.push_back(preciocosstoo);
            idproducto.push_back(idproductorrr);
            Compra i = Compra();
            i.set_cantiad(cantidaddd);
            i.precio_costo(preciocosstoo);
            i.set_idproducto(idproductorrr);
            i.crear(idproducto, cantidad, precio_costo);
        }
        if (escoger == 2) {
            int elimiar;
            system("cls");
            cout << "Cargando: ";
            for (int q = 0; q <= 60; q++) {
                Sleep(60);
                cout << cargando;
            }
            system("cls");
            cout << "Ingresa el id de la compra a eliminar: ";
            cin >> elimiar;
            Compra e = Compra();
            e.set_idcompra(elimiar);
            e.eliminar();
        }
        if (escoger == 3) {
            int idprove, modificar, cantidad, preciocost,idcompra;
            system("cls");
            cout << "Cargando: ";
            for (int q = 0; q <= 60; q++) {
                Sleep(60);
                cout << cargando;
            }
            system("cls");
            cout << "Ingresa el id del proveedor a modificar: ";
            cin >> idprove;
            cout << "Ingresa la cantidad a modificar: ";
            cin >> cantidad;
            cout << "Ingresa el precio costo a moficiar: ";
            cin >> preciocost;
            cout << "Ingresa el id de la compra para modificar: ";
            cin >> idcompra;

            Compra m = Compra();
            m.set_idproveedor(idprove);
            m.set_cantiad(cantidad);
            m.precio_costo(preciocost);
            m.set_idcompra(idcompra);
            m.modificar();

        }
        cout << endl;
        cout << endl;
        cout << "Deseas regresar al menu " << endl;
        cout << " Si = 1" << endl;
        cout << " No = 2 " << endl;
        cout << "Respuesta = ";
        cin >> eleccion;

    } while (eleccion == 1);

}
}
}



    return 0;
}
