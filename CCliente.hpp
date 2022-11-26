#pragma once
#include "CProducto.hpp"
#include"CVaucher.hpp"
#include"ArbolBB.hpp"
#include "CHashTable.hpp"
#include <vector>
using namespace std;


template<typename T,class U = CProducto<T>>
class CCliente {
private:
	T nombre;
	T direccion;
	T telefono;
	T dinero;
	T MetododePago;

	vector<T>* codigos;
	HashTable<U>* prod;
	ArbolBB<CVaucher*>* vauchers;
	
public:

	CCliente() {}
	CCliente(T nombre, T direccion, T telefono, T dinero);
	~CCliente();

	void setNombre(T nombre);
	void setDireccion(T direccion);
	void setTelefono(T telefono);
	void addProducto(U producto);
	void setDinero(T dinero);
	void quickSortCodigos();

	T getNombre();
	T getDireccion();
	T getTelefono();
	T toString();
	T getDinero();

	void toStringPedidos();
	void crearVaucher();
	
};

template<typename T, class U>
CCliente<T, U>::CCliente(T nombre, T direccion, T telefono, T dinero) {
	this->nombre = nombre;
	this->direccion = direccion;
	this->telefono = telefono;
	this->dinero = dinero;

	prod = new HashTable<U>(50);
	codigos = new vector<T>();

	vauchers = new ArbolBB<CVaucher*>(
		[](CVaucher* vau) -> void {
			cout << vau->imprimirVoucher() << "\n\n";
		},
		[](CVaucher* a, CVaucher* b) -> bool {
			return a->getImporte() < b->getImporte();
		}
		);
}

template<typename T, class U>
CCliente<T,U>::~CCliente() {}

template<typename T, class U>
void CCliente<T,U>::setNombre(T nombre) { 
	this->nombre = nombre; 
}

template<typename T, class U>
void CCliente<T,U>::setDireccion(T direccion) { 
	this->direccion = direccion; 
}

template<typename T, class U>
void CCliente<T,U>::setTelefono(T telefono) { 
	this->telefono = telefono; 
}

template<typename T, class U>
void CCliente<T, U>::setDinero(T dinero) {
	this->dinero = dinero;
}

template<typename T, class U>
void CCliente<T,U> ::addProducto(U producto) { 
	prod->insert(producto.getCodPedido(), producto);
	codigos->push_back(producto.getCodPedido());
}

template<typename T, class U>
T CCliente<T,U>::getNombre() { 
	return nombre; 
}
template<typename T, class U>
T CCliente<T,U>::getDinero() { 
	return dinero; 
}
template<typename T, class U>
T CCliente<T,U>::getDireccion() { 
	return direccion; 
}

template<typename T, class U>
T CCliente<T,U>::getTelefono() { 
	return telefono; 
}

template<typename T, class U>
T CCliente<T,U>::toString() {
	return "Nombre:\t " + this->nombre + " |direccion:\t " + this->direccion
		+ " |telefono:\t " + this->telefono + "|dinero: " + this->dinero + "\n";
}

template<typename T, class U>
void CCliente<T, U>::toStringPedidos() {
	prod->display([](U v) -> void {
		cout << v.toString();
		});
}

template<typename T, class U>
void CCliente<T, U>::quickSortCodigos() {
	auto compare1 = [](T a, T b) -> bool {
		return a > b;
	};
	auto compare2 = [](T a, T b) -> bool {
		return a < b;
	};
	QuickSort<T>::quickSort(this->codigos, compare1, compare2, 0, this->codigos->size() - 1);
	for (T& i : codigos) cout << i << "-";
}

template<typename T, class U>
void CCliente<T, U>::crearVaucher() {

	//Pregunta el metodo de pago del cliente
	cout <<"Inserte su metodo de pago: ";
	cin >> MetododePago;
	
	//crea nuevo vaucher de los productos ya seleccionados
	//1. calcular importe
	int imp = 0;
	for (size_t i = 0; i < codigos->size(); i++) {
		auto aux = prod->getCopy(codigos->at(i));
		U aux2 = aux.value;
		imp += stoi(aux2.getPrecio());
	}
	
	//2. guardado
	CVaucher* vau = new CVaucher(imp, MetododePago);

	//guarda el vaucher creado en el arbol
	for (size_t i = 0; i < codigos->size(); i++) {
		auto aux = prod->getCopy(codigos->at(i));
		U aux2 = aux.value;
		vau->anadirProducto(aux2);
	}

	this->vauchers->insert(vau);

	//limpia los productos del cliente
	prod->Limpiar();

	//mostrar vauchers en preOrden
	vauchers->preOrder();
}
