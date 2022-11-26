#pragma once
#include "CCliente.hpp"
#include "ArbolAVL.hpp"
template<typename T, class U = CCliente<T>>
class CClientes {
private:
    ArbolAVL<U*>* clientes;
public:

    CClientes();
    ~CClientes() {}
    
    void addCliente(U* n);
    void toString();
	void imprimirClientes(U* n);

	ArbolAVL<U*>* getClientes();

};
template<typename T, class U>
CClientes<T, U>::CClientes() {
	clientes = new ArbolAVL<U*>(
		[](U* a) -> void {
			cout << a->toString();
		},
		[](U* a, U* b) -> bool {
			string aux1 = a->getNombre();
			string aux2 = b->getNombre();
			int s1, s2;
			s1 = s2 = 0;
			for (char i : aux1) s1 += int(i);
			for (char i : aux2) s2 += int(i);
			return s1 > s2;
		},
		[](U* a, string b) -> int {
			string aux = a->getNombre();
			int s1, s2;
			s1 = s2 = 0;
			for (char i : aux) s1 += int(i);
			for (char i : b) s2 += int(i);

			if (s1 > s2) return 1;
			else if (s1 < s2) return -1;
			else return 0;
		}
	);
	leerClientes<string>(clientes);
}
template<typename T, class U>
void CClientes<T,U>::addCliente(U* n) { 
	clientes->Insertar(n);
}

template<typename T, class U>
ArbolAVL<U*>* CClientes<T,U>::getClientes() { 
    return clientes;
}

template<typename T, class U>
void CClientes<T, U>::imprimirClientes(U* n) {
	cout << n.toString();
}

template<typename T, class U>
void CClientes<T,U>::toString() {
	clientes->inOrden();
}

