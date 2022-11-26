#pragma once
#include "CRestaurante.hpp"
#include "Archivos.hpp"

template<typename T, class U = CRestaurante<T>, class P = CProducto<T>>
class CRestaurantes {
private:
    vector<U*> restaurantes;
    typedef function<int(U, U)> Comp;
    Comp comparar;

public:
    CRestaurantes();
    ~CRestaurantes();

    vector<U*> getRestaurantes() { return restaurantes; }
    void setComp(Comp comparar) { this->comparar = comparar; }
    void toString();
	void ordenarBurbuja();
    U buscarRestauranteMasValorado();

};

template<typename T, class U, class P>
CRestaurantes<T,U,P>::CRestaurantes() {
    restaurantes.push_back(leerRestaurantes<T>("PizzaHut.txt"));
    restaurantes.push_back(leerRestaurantes<T>("Bembos.txt"));
    restaurantes.push_back(leerRestaurantes<T>("MadamTusan.txt"));
}

template<typename T, class U, class P>
CRestaurantes<T,U,P>::~CRestaurantes() {}

template<typename T, class U, class P>
void CRestaurantes<T,U,P>::toString() {
    for (int i = 0; i < restaurantes.size(); i++) {
        cout << "[" << i << "]" << restaurantes.at(i)->toString() << "\n";
    }
}

template<typename T, class U, class P>
void CRestaurantes<T,U,P>::ordenarBurbuja(){
    bool ordenado;
	for (int i = 0; i < restaurantes.size()- 1; i++)
	{
		ordenado = true;
		for (int j = 0; j < restaurantes.size() - (i + 1); j++)
		{
            if (mayor(restaurantes.at(j)->getvaloracion(), restaurantes.at(j + 1)->getvaloracion()))
			{
				U* aux = restaurantes.at(j);
				restaurantes.at(j) = restaurantes.at(j+1);
				restaurantes.at(j+1) = aux;
				ordenado = false;
			}
		}
		if (ordenado) break;
	}
}

template<typename T, class U, class P>
U CRestaurantes<T, U, P>::buscarRestauranteMasValorado() {
    if (comparar(a,b) == -1) {
        return a;
    }
    else if (comparar(a, b) == 0) {
        return b;
    }
    else {
        return 0;
    }
}

bool mayor(int m, int n){
    if (m == 0)
        return false;
    else
    {
        m--;
        if (m == n) return true;
        else
        {
            n++;
            if (m == n) return true;
            else return mayor(m, n);
        }
    }
}
