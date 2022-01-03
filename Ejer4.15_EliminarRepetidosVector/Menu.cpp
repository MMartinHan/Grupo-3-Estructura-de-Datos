#include "Menu.h"

int Menu::menu() {
	int opc;
	int n = 0;
	fstream archivo;
	string texto, fila, fila1, fila2, fila3;
	bool continuar = true;
	system("cls");
	cout << "---------------Consulta de telefonos---------------" << endl;
	cout << "\n1.-Buscar por nombre : ";
	cout << "\n2.-Buscar por numero : ";
	cout << "\n3.-Salir.";
	cout << "\n";
	cout << "\nOpcion: ";
	cin >> opc;
	switch (opc) {
	case 1:
		cout << " Ingrese el nombre : " << endl;
		cin >> texto;
		if (!archivo.is_open()) {
			archivo.open("telefonos.txt", ios::in);
		}
		while (getline(archivo, fila)) {
			if (fila.find(texto) != string::npos) {
				cout << fila << endl;
				getline(archivo, fila1);
				cout << fila1 << endl;
				n = 1;
			}
		}
		if (n == 0) {
			cout << texto << " no encontrado " << endl;
		}
		system("pause");
		break;
	case 2:
		cout << " Ingrese el numero : " << endl;
		cin >> texto;
		if (!archivo.is_open()) {
			archivo.open("telefonos.txt", ios::in);
		}
		while (getline(archivo, fila)) {
			if (fila.find(texto) != string::npos) {
				cout << fila << endl;
				getline(archivo, fila1);
				cout << fila1 << endl;
				n = 1;
			}
		}
		if (n == 0) {
			cout << texto << " no encontrado " << endl;
		}
		break;
	case 3:
		cout << "Adios, Vuelve pronto " << char(3) << '\n';
		exit(0);
		break;
	default:
		cout << "Opcion no valida" << '\n';
	} while (opc != 3);
	return 0;
}