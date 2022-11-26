#ifndef __NODOAVL_HPP__
#define __NODOAVL_HPP__

template<class T>
class Nodo {
public:
	T elemento;
	Nodo* izq;
	Nodo* der;
	int altura;

	Nodo() {
		izq = nullptr;
		der = nullptr;
		altura = 0;
	}
};

#endif // !__NODOAVL_HPP__

