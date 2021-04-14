#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"

using namespace std;

class Cliente : Persona {
private: string nit;
	   // constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}

	// METODOS
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES ('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso . . ." << endl;
			}
			else {
				cout << "Error al Ingresar . . ." << endl;
			}
		}
		else {
			cout << "Error en la Conexion . . ." << endl;
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

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}
			}
			else {
				cout << "Error al Consultar . . ." << endl;
			}
		}
		else {
			cout << "Error en la Conexion . . ." << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar_nit() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento;
			char s;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> idaux;
			string consulta = "select * from Clientes where id_clientes=" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id Cliente: " << fila[0] << endl;
					cout << ("NIT: ") << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese el nuevo nit del cliente: ";
						getline(cin, nit);
						string modificar = "update clientes set nit = '" + nit + "' where id_clientes =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_nombres() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento;
			char s;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> idaux;
			string consulta = "select * from clientes where id_clientes=" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id Cliente: " << fila[0] << endl;
					cout << ("Nombre: ") << fila[2] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese los nuevos nombres del cliente: ";
						getline(cin, nombres);
						string modificar = "update clientes set nit = '" + nombres + "' where id_clientes =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_apellidos() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento;
			char s;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> idaux;
			string consulta = "select * from clientes where id_clientes=" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id Cliente: " << fila[0] << endl;
					cout << ("Apellidos: ") << fila[3] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese los nuevos apellidos del cliente: ";
						getline(cin, apellidos);
						string modificar = "update clientes set nit = '" + apellidos + "' where id_clientes =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_direccion() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento;
			char s;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> idaux;
			string consulta = "select * from clientes where id_clientes=" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id Cliente: " << fila[0] << endl;
					cout << ("Direccion: ") << fila[4] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese la nueva direcion del cliente: ";
						getline(cin, direccion);
						string modificar = "update clientes set nit = '" + direccion + "' where id_clientes =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_telefono() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento;
			char s;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> idaux;
			string consulta = "select * from clientes where id_clientes=" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id Cliente: " << fila[0] << endl;
					cout << ("Telefono: ") << fila[5] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese el nuevo telefono del cliente: ";
						getline(cin, telefono);
						string modificar = "update clientes set nit = '" + telefono + "' where id_clientes =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
		}
		cn.cerrar_conexion();
	}

	void actualizar_fecha() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idaux, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento;
			char s;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> idaux;
			string consulta = "select * from clientes where id_clientes=" + idaux + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id Cliente: " << fila[0] << endl;
					cout << ("Fecha de Nacimiento: ") << fila[6] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nIngrese la nueva fecha de nacimiento del cliente: ";
						getline(cin, fecha_nacimiento);
						string modificar = "update clientes set nit = '" + fecha_nacimiento + "' where id_clientes =" + idaux + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << "Actualizacion exitosa . . ." << endl;
					}
				}
			}
			else {
				cout << "Error al actualizar . . .";
			}
		}
		else {
			cout << "Error en la conexion . . .";
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
		string idaux;
		cout << "Ingrese el id del registro que desea eliminar: ";
		cin >> idaux;
		string eliminar = "delete from Clientes where id_clientes = (" + idaux + ")";
		const char* i = eliminar.c_str();
		// executar el query
		q_estado = mysql_query(cn.getConectar(), i);
		if (!q_estado) {
			cout << "Eliminacion Exitosa . . ." << endl;
		}
		else {
			cout << "Error al eliminar . . ." << endl;
		}
	}
	else {
		cout << "Error en la Conexion . . ." << endl;
	}
	cn.cerrar_conexion();
}
};

