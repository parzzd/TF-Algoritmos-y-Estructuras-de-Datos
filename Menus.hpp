#pragma once
int menu() {
	int op;
	system("cls");
	cout << "=================\n";
	cout << "Ingrese opcion:\n";
	cout << "1.Crear Cliente \n";
	cout << "2.Seleccionar Restaurante\n";
	cout << "3.Mostrar Productos de cliente\n";
	cout << "4.Valorar Restaurante\n";
	cout << "5.Comprar Productos\n";
	cout << "6.Salir\n";
	cout << ": ";
	cin >> op;

	//recursividad
	if (op > 1 || op <= 5) {
		return op;
	}
	else {
		menu();
	}
}


template<class U = CClientes<string>>
string menuClientes(U lista) {
	string op;
	cout << "==================================================\n";
	lista.toString();
	cout << "Ingrese nombre del cliente que va a comprar:\n";
	cout << ": ";
	cin >> op;
	return op;
}

template<class U = CProducto<string>, class T = CRestaurantes<string>>
U menuRestaurantes(T restaurantes) {
	int op, op2;
	do {
		cout << "==================================================\n";
		cout << "Seleccione el restaurante de su preferencia\n";
		restaurantes.toString();
		cin >> op;
	} while (op < 0 || op > restaurantes.getRestaurantes().size() - 1);

	do {
		restaurantes.getRestaurantes().at(op)->toStringProductos();
		cout << ": ";
		cin >> op2;
	} while (op2 < 0 || op2 > restaurantes.getRestaurantes().at(op)->getProductos()->size() - 1);
	return restaurantes.getRestaurantes().at(op)->getProducto(op2);
}

template<class U = CCliente<string>, class T = CRestaurantes<string>>
double menuValoracion(U lista, T restaurantes) {
	int op, op2;
	double x;

	do{
		cout<<"=========================================\n";
		cout<<"Selecciona el cliente que quiere valorar:\n";
		lista.toString();
		cout<<": "; cin>>op;	
	}while (op < 0 || op > lista.getClientes()->longitud() - 1);

	do {
		cout << "==================================================\n";
		cout << "Seleccione el restaurante de su preferencia\n";
		restaurantes.toString();
		cin >> op2;
	} while (op2 < 0 || op2 > restaurantes.getRestaurantes().size() - 1);

	do{
		cout << "\nInserte su valoracion: "; cin >> x; cout << endl;
	} while (x > 5);


	x = (x + restaurantes.getRestaurantes().at(op)->getvaloracion()) / 2;
	string s = to_string(x);
	restaurantes.getRestaurantes().at(op2)->setvaloracion(s);

	//RECURSIVIDAD
	if (x == 0) return 0;
	else return restaurantes.getRestaurantes().at(op)->getvaloracion() * 1.0;
}

template<typename T, class U = CCliente<T>>
U* crearCliente() {

	T nombre;
	T direccion;
	T telefono;
	T codigoPedido;
	T dinero;

	cout << "Ingrese su nombre: ";
	cin >> nombre;
	cout << "Ingrese su direccion: ";
	cin >> direccion;
	cout << "Ingrese su telefono:";
	cin >> telefono;
	cout << "Ingrese su dinero:";
	cin >> dinero;
	return new CCliente<T>(nombre, direccion, telefono, dinero);
}
