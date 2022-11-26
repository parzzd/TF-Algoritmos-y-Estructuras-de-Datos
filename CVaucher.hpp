#pragma once
#include<string>
#include <iostream>
#include "CCliente.hpp"
#include "ListaDE.hpp"
#include "CHashTable.hpp"
#include "CProducto.hpp"
#include "QuickSort.hpp"
using namespace std;
class CVaucher {
private:
	
	int codigo;
	int importe;
	int cant;
	string metodoPago;
	LDE<CProducto<string>>* productos;
	HashTable<CProducto<string>>* ht;

public:

	CVaucher(int importe, string metodoPago) {
		this->codigo = 1000 + rand() % 8999;
		this->cant = 0;
		productos = new LDE<CProducto<string>>(
			[](CProducto<string> prod) -> string {
				return prod.toString();
			}
		);
		this->importe = importe;

		this->metodoPago = metodoPago;

	}
	~CVaucher() {}

	void setImporte() { this->importe = importe; }
	void setCant() { this->cant = cant; }
	void setmetodoPago() { this->metodoPago = metodoPago; }

	int getImporte() { return this->importe; }

	void anadirProducto(CProducto<string> prod) { 
		productos->pushBack(prod); 
		this->cant++;
	}

	string imprimirVoucher(){
		return "\nCodigo: " + to_string(codigo) +
			"\nImporte: " + to_string(importe) +
			"\nCantidad: " + to_string(cant) +
			"\nMetodo de pago: " + metodoPago +
			"\nProductos: \n" + productos->displayS();
	}

	
};