#pragma once
#ifndef UNTITLED10_CPILA_H
#define UNTITLED10_CPILA_H

#endif //UNTITLED10_CPILA_H
#include <functional>
template <class T>
class CPila {
    template<class G>
    class Nodo {
    public:
        G elemento;
        Nodo<G>* ant;

        Nodo(G e) {
            elemento = e;
            ant = nullptr;
        }
    };
    Nodo<T>* ultimo;
    size_t t;

public:
    CPila() {
        ultimo = nullptr;
        t = 0;
    }

    void push(T e) {
        Nodo<T>* n = new Nodo<T>(e);
        if(t == 0) ultimo = n;
        else {
            n->ant = ultimo;
            ultimo = n;
        }
        ++t;
    }
    
    void recorrer(std::function<void(T)> r_nodo) {
        Nodo<T>* n = ultimo;
        if(n == nullptr) return;
        while(n->ant != nullptr) {
            r_nodo(n->elemento);
            n = n->ant;
        }
        r_nodo(n->elemento);
    }
};
