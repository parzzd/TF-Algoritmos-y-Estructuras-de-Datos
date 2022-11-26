#ifndef __ARBOLAVL_HPP__
#define __ARBOLAVL_HPP__

#include "NodoAVL.hpp"
#include <functional>
using namespace std;

template<class T>
class ArbolAVL {
private:
	Nodo<T>* raiz;
	function<void(T)> _mostrar;
	function<bool(T, T)> _comparar;
	function<int(T, string)> _compararB;
	size_t _longitud;

	//Operaciones privadas
	int _altura(Nodo<T>* nodo) {
		if (nodo == nullptr) return 0;
		return nodo->altura;
	}

	void _rotarDerecha(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->izq;
		nodo->izq = p->der;
		p->der = nodo;
		//Actualizamos la altura

		nodo = p;
	}

	void _rotarIzquierda(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->der;
		nodo->der = p->izq;
		p->izq = nodo;
		//Actualizamos la altura

		nodo = p;
	}
	void _balanceo(Nodo<T>*& nodo) {
		int hizq = _altura(nodo->izq);
		int hder = _altura(nodo->der);
		int fb = hder - hizq;

		if (fb > 1) { //rotar a la izq
			int hhizq = _altura(nodo->der->izq);
			int hhder = _altura(nodo->der->der);
			if (hhizq > hhder) { //verificar si aplica doble rotación
				_rotarDerecha(nodo->der);
			}
			_rotarIzquierda(nodo);
		}
		if (fb < -1) { //rotar a la der
			int hhizq = _altura(nodo->izq->izq);
			int hhder = _altura(nodo->izq->der);
			if (hhizq < hhder) {//verificar si aplica doble rotación 
				_rotarIzquierda(nodo->izq);
			}
			_rotarDerecha(nodo);
		}
		//Actualizar la altura del nodo raiz
		hizq = _altura(nodo->izq);
		hder = _altura(nodo->der);
		nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
	}

	T _buscar(Nodo<T>*& nodo, string n) {
		if (nodo == nullptr) throw "Error!";
		else {
			int r = _compararB(nodo->elemento, n);
			if (r == 0)return nodo->elemento;
			else if (r < 0) {
				return _buscar(nodo->der, n);
			}
			else {
				return _buscar(nodo->izq, n);
			}
		}
	}

	bool _insertar(Nodo<T>*& nodo, T e) {
		if (nodo == nullptr) {
			//Nuevo elemento
			nodo = new Nodo<T>();
			nodo->elemento = e;
			_longitud++;
			return true;
		}

		if (_comparar(nodo->elemento, e)) _insertar(nodo->izq, e);
		else _insertar(nodo->der, e);
		_balanceo(nodo);

		return true;
	}

	void _inOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrden(nodo->izq);
		_mostrar(nodo->elemento);
		_inOrden(nodo->der);
	}

	void _inOrdenH(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrdenH(nodo->izq);
		_mostrar(nodo->altura);
		_inOrdenH(nodo->der);
	}

public:
	ArbolAVL(function<void(T)> mostrar, function<bool(T, T)> comp, function<int(T, string)> comp2)
		: _mostrar(mostrar), _comparar(comp), _compararB(comp2) {
		this->raiz = nullptr;
		this->_longitud = 0;
	}

	bool Insertar(T e) {
		return _insertar(raiz, e);
	}
	T buscar(string s) {
		return _buscar(raiz, s);
	}
	size_t longitud() {
		return this->_longitud;
	}
	void inOrden() {
		_inOrden(raiz);
	}
	void inOrdenH() {
		_inOrdenH(raiz);
	}
};
#endif // !__ARBOLAVL_HPP__

