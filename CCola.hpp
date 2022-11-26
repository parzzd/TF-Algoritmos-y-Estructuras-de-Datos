#include <iostream>

using namespace std;

template<class T>
class Cola {
private:
    struct Nodo {
    T       elem;
    Nodo*   sig; // puntero apunta al siguiente nodo
    Nodo*   ante;//puntero al anterior nodo

    Nodo(T elem = NADA, Nodo* sig = nullptr, Nodo* ante = nullptr): elem(elem), sig(sig), ante(ante) {}
	Nodo<T>* inicio;
	Nodo<T>* fin;
};
public:
	Cola() {
		this->inicio = nullptr;
		this->fin = nullptr;
	}
	void enqueue(T v) {
		Nodo<T>* nodo = new Nodo<T>(v);
		if (esVacia()) {
			inicio = nodo;
			fin = inicio;
		}
		else {

			fin->siguiente = nodo;
			fin = nodo;
		}
		nodo = NULL;
	};


	T dequeue() {
		T dato = inicio->dato;

		if (inicio == fin) {
			inicio = NULL;
			fin = NULL;
		}
		else {
			inicio = inicio->siguiente;
		}

		return dato;
	};
	bool esVacia() {
		return (inicio == nullptr);
	};

	

};


