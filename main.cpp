#include <iostream>
#include "CClientes.hpp"
#include "CCliente.hpp"
#include "CProducto.hpp"
#include "Menus.hpp"
#include "Archivos.hpp"
#include "CRestaurantes.hpp"
#include "CPila.hpp"
#include <sstream>
#include <iomanip>
#include <conio.h>
using namespace std;

int main() {
	CClientes<string> lista;
	CRestaurantes<string> res;
	res.ordenarBurbuja();
	do {
		system("cls");
		switch (menu()) {
			
		case 1:
			//crear cliente
			lista.addCliente(crearCliente<string>());
			/*escritura(lista);*/
			lectura();
			break;
		case 2:
			//añadir producto a cliente del restaurante
			lista.getClientes()->buscar(menuClientes(lista))->addProducto(menuRestaurantes(res));
			break;
		case 3:
			//mostrar pedidos del cliente
			lista.getClientes()->buscar(menuClientes(lista))->toStringPedidos();
			_getch();
			break;
		case 4:
			//valoracion del restaurante
			menuValoracion(lista, res);
			_getch();
			break;
		case 5:
			//comprar-crea voucher- elimina de hash table
			lista.getClientes()->buscar(menuClientes(lista))->crearVaucher();
			_getch();
			break;
		case 6:
			return 0;
			break;
		}
	} while (true);
	
	return 0;
}