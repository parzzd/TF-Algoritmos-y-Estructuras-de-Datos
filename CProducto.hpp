#pragma once
#include <string.h>
#include "CLista.hpp"

using namespace std;

template<typename T>
class CProducto {
private:
	T codpedido;
	T nompedido;
	T precio;

public:
	CProducto() {}
	CProducto(T codpedido, T nompedido, T precio);
	~CProducto() {}
	void setNomPedido(T nompedido);
	void setCodPedido(T codpedido);

	T getNomPedido();
	T getCodPedido();
	T getPrecio();
	
	T toString();
};

template<typename T>
CProducto<T>::CProducto(T codpedido, T nompedido, T precio) {
	this->codpedido = codpedido;
	this->nompedido = nompedido;
	this->precio = precio;
}

template<typename T>
void CProducto<T>::setNomPedido(T nompedido) { 
	this->nompedido = nompedido; 
}
template<typename T>
void CProducto<T>::setCodPedido(T codpedido) { 
	this->codpedido = codpedido; 
}
template<typename T>
T CProducto<T>::getNomPedido() { 
	return nompedido; 
}
template<typename T>
T CProducto<T>::getCodPedido() { 
	return codpedido; 
}
template<typename T>
T CProducto<T>::getPrecio() {
	return precio;
}

template<typename T>
T CProducto<T>::toString() { 
	return " |NomPedido:\t" + this->nompedido +
		"\t |CodPedido:\t " + this->codpedido +
		"|Precio:\t" + this->precio + " \n";
}
