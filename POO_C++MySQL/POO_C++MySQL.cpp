#include "Cliente.h"
#include <iostream>
using namespace  std;

void menu();
void menu_actualizar();

int main()
{
	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono=0;
	Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
	int entrada = 0;
	do {
		system("cls");
		menu();
		cout << "Opcion: ";
		cin >> entrada;
		switch (entrada) {
		case 1:
			system("cls");
			c.leer();
			system("pause");
			break;

		case 2:
			system("cls");
			cout << "Ingrese Nit: ";
			getline(cin, nit);
			cout << "Ingrese Nombres: ";
			getline(cin, nombres);
			cout << "Ingrese Apellidos: ";
			getline(cin, apellidos);
			cout << "Ingrese Direccion: ";
			getline(cin, direccion);
			cout << "Ingrese Telefono: ";
			cin >> telefono;
			cin.ignore();
			cout << "Fecha Nacimiento: ";
			cin >> fecha_nacimiento;

			c.crear();
			c.leer();
			system("pause");
			break;

		case 3:
			system("cls");
			int op=0;
			while (op != 7) {
				menu_actualizar();
				cout << "Opcion: ";
				cin >> op;
				if (op == 1) {
					system("cls");
					c.leer();
					c.actualizar_nit();
					c.leer();
					system("pause");
				}

				if (op == 2) {
					system("cls");
					c.leer();
					c.actualizar_nombres();
					c.leer();
					system("pause");
				}

				if (op == 3) {
					system("cls");
					c.leer();
					c.actualizar_apellidos();
					c.leer();
					system("pause");
				}

				if (op == 4) {
					system("cls");
					c.leer();
					c.actualizar_direccion();
					c.leer();
					system("pause");
				}

				if (op == 5) {
					system("cls");
					c.leer();
					c.actualizar_telefono();
					c.leer();
					system("pause");
				}

				if (op == 6) {
					system("cls");
					c.leer();
					c.actualizar_fecha();
					c.leer();
					system("pause");
				}
			}
			
		break;

		case 4:
			system("cls");
			c.leer();
			c.eliminar();
			c.leer();
			system("pause");
		break;

		}
	} 	while (entrada != 5);
	
	system("pause");
	return 0;
}

void menu() {
	system("cls");
	cout << " ________________________________________" << endl;
	cout << "|                                        |" << endl;
	cout << "|             TABLA CLIENTES             |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|    1. VER DATOS                        |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|    2. AGREGAR DATOS                    |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|    3. ACTUALIZAR DATOS                 |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|    4. ELIMINAR DATOS                   |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|                5. SALIR                |" << endl;
	cout << "|________________________________________|" << endl;
}

void menu_actualizar() {
	cout << " ________________________________________" << endl;
	cout << "|                                        |" << endl;
	cout << "|              ACTUALIZAR                |" << endl;
	cout << "|________________________________________|" << endl;
	cout << "|                                        |" << endl;
	cout << "|    1. MODIFICAR NIT                    |" << endl;
	cout << "|    2. MODIFICAR NOMBRES                |" << endl;
	cout << "|    3. MODIFICAR APELLIDOS              |" << endl;
	cout << "|    4. MODIFICAR DIRECCION              |" << endl;
	cout << "|    5. MODIFICAR TELEFONO               |" << endl;
	cout << "|    6. MODIFICAR FECHA DE NACIMIENTO    |" << endl;
	cout << "|    7. REGRESAR                         |" << endl;
	cout << "|________________________________________|" << endl;
}
