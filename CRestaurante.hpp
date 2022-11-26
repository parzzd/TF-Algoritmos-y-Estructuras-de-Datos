#pragma once
#include "CProducto.hpp"
#include <cstdint>
#include <functional>
#include <vector>

template<typename T, class U = CProducto<T>>
class CRestaurante {
private:
	T nombre;
	T valoracion;
	vector<U>* productos;
public:
	CRestaurante() {}
	CRestaurante(T nombre, T valoracion, vector<U>* prod);
	~CRestaurante() {}
	
	T getnombre();
	int getvaloracion();
	void setnombre(T nombre);
	void setvaloracion(T valoracion);
	vector<U>* getProductos();

	U getProducto(int n);
	T toString();
	void addProducto(U n);
	void toStringProductos();

	
	void ordenarShellProductos();

};

template<typename T, class U>
CRestaurante<T, U>::CRestaurante(T nombre, T valoracion,vector<U>* prod) {
	this->nombre = nombre;
	this->valoracion = valoracion;
	this->productos = prod;
}

template<typename T, class U>
T CRestaurante<T, U>::getnombre() {
	return this->nombre;
}

template<typename T, class U>
int CRestaurante<T, U>::getvaloracion() {
	return stoi(this->valoracion);
}

template<typename T, class U>
vector<U>* CRestaurante<T, U>::getProductos() {
	return productos;
}

template<typename T, class U>
void CRestaurante<T, U>::addProducto(U n) { 
	productos->push_back(n); 
}

template<typename T, class U>
void CRestaurante<T, U>::setnombre(T n) {
	this->nombre = n;
}

template<typename T, class U>
void CRestaurante<T, U>::setvaloracion(T n) {
	this->valoracion = n;
}

template<typename T, class U>
U CRestaurante<T, U>::getProducto(int n) {
	return productos->at(n);
}

template<typename T, class U>
T CRestaurante<T, U>::toString() { 
	return "Nombre:\t" + nombre + "  \tValorancion:\t" + valoracion;
}

template<typename T, class U>
void CRestaurante<T, U>::toStringProductos() {
	for (short i = 0; i < productos->size(); i++) {
		cout << "[" << i << "]" << productos->at(i).toString();
	}
}



template<typename T, class U>
void CRestaurante<T, U>::ordenarShellProductos() {
	int i, j, k, intervalo = productos->longitud() / 2;
	int temp;

	auto compare = [](CProducto<T>* a, CProducto<T>* b) -> bool {
		return a->getPrecio() <= b->getPrecio();
	};

	while (intervalo > 0)
	{
		for (i = intervalo; i <= productos->longitud(); i++)
		{
			j = i - intervalo;
			while (j >= 0)
			{
				k = j + intervalo; 
				
				if (compare(productos->obtenerPos(j)
					,productos->obtenerPos(k)) == 0) j = -1;
				else {
					productos->swap(productos->obtenerPos(j)
						, productos->obtenerPos(k));
					j -= intervalo;
				}
			}
		}
		intervalo = intervalo / 2;
	}
}