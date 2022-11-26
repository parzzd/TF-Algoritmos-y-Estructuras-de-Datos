#ifndef __DLL_HPP__
#define __DLL_HPP__

#include <cstdint>
#include <functional>

template<class T>
class LDE {
public:
    LDE(std::function<string(T)> show) : _show(show){
        this->_start = this->_end = nullptr;
        this->_size = 0;
    }
    void pushBack(T value) {
        Node* newNode = new Node(value);
        if (_size == 0) {
            this->_start = this->_end = newNode;
            _size = 1;
            return;
        }
        this->_end->next = newNode;
        newNode->back = this->_end;
        this->_end = this->_end->next;
        ++_size;
    }
    void insertAt(T value, int pos) {
        if (pos < 0 || pos > _size) throw "Posicion invaldia";
        if (pos == 0) { pushFront(value); return; }
        if (pos == _size) { pushBack(value); return; }
        Node* aux = this->_start;
        Node* newNode = new Node(value);
        for (int i = 0; i < pos - 1; ++i) aux = aux->next;
        // Enlazar el nodo a insertar con el nodo en la posición pos (aux->next)
        newNode->next = aux->next;
        aux->next->back = newNode;
        // Enlazamos el nodo a insertar con el nodo anterior al de la posición pos (aux)
        aux->next = newNode;
        newNode->back = aux;
        ++this->_size;
    }

    void pushFront(T value) {
        Node* newNode = new Node(value);
        if (_size == 0) {
            this->_start = this->_end = newNode;
            this->_size = 1;
            return;
        }
        newNode->next = this->_start;
        this->_start->back = newNode;
        this->_start = this->_start->back;
        ++this->_size;
    }
    
    string displayS() {
        string s;
        Node* aux = this->_start;
        while (aux){
            s += _show(aux->value);
            aux = aux->next;
        }
        return s;
    }
    void display(std::function<void(T)> show) {
        Node* aux = this->_start;
        while (aux) {
            show(aux->value);
            aux = aux->next;
        }
    }
    void popBack() {
        if (this->_size == 0) throw "lista ya vacia";
        if (this->_size == 1) {
            delete _start;
            _start = _end = nullptr;
            _size = 0;
            return;
        }
        _end = _end->back;
        _end->next->back = nullptr;
        delete _end->next;
        _end->next = nullptr;
        --_size;
    }
    void popFront() {
        if (this->_size == 0) throw "Cannot erase in empty list";
        if (this->_size == 1) {
            delete _start;
            _start = _end = nullptr;
            _size = 0;
            return;
        }
        _start = _start->next;
        _start->back->next = nullptr;
        delete _start->back;
        _start->back = nullptr;
        --_size;
    }
    void eraseAt(int pos) {
        if (pos < 0 || pos >= _size) throw "no existe valor en ese rango";
        if (pos == 0) {
            popFront();
            return;
        }
        if (pos == _size - 1) {
            popBack();
            return;
        }
        Node* aux = _start;
        for (unsigned int i = 0; i < pos - 1; ++i) aux = aux->next;
        Node* toErase = aux->next;

        aux->next = aux->next->next;
        aux->next->back = aux->next->back->back;

        toErase->next = toErase->back = nullptr;

        delete toErase;
        --_size;
    }
    void modifyAt(int pos, std::function<void(T&)> modify) {
        if (pos < 0 || pos >= _size) throw "no existe";
        Node* aux = _start;
        for (size_t i = 0; i < pos; ++i) aux = aux->next;
        modify(aux->value);
    }
    bool isEmpty() {
        return this->_size == 0;
    }
    size_t size() {
        return this->_size;
    }
    T getByCriteria(std::function<bool(T)> criteria) {
        Node* aux = this->_start;
        while (aux) {
            if (criteria(aux->value)) return aux->value;
            aux = aux->next;
        }
        return aux->value;
    }
    T getByIndex(int n) {
        Node* aux = this->_start;
        int i = 0;
        while (i < n) {
            aux = aux->next;
            i++;
        }
        return aux->value;
    }
    void swap(T& a, T& b) {
        T c = a;
        a = b;
        b = c;
    }
private:
    struct Node {
        T value;
        Node* next;
        Node* back;
        Node(T value) : value(value), next(nullptr), back(nullptr) {}
    };
    Node* _start;
    Node* _end;
    size_t _size;
    std::function<string(T)> _show;
};


#endif
/*
POSIBLE SOLUCION AL SWAP PERO HACE USO DE ESTA LIBRERIA:
#include <bits/stdc++.h>


template<typename T>
pair<Node*, Node*> find(Node*& head, T x, T y)
{
    Node* N1 = NULL;
    Node* N2 = NULL;
    Node* temp = head;

    // Traversing the list
    while (temp != NULL) {
        if (temp->data == x)
            N1 = temp;
        else if (temp->data == y)
            N2 = temp;
        temp = temp->next;
    }
    return make_pair(N1, N2);
}

template<typename T>
void swap(Node*& head, Node*& tail,
          T x, T y)
{

    // Edge Cases
    if (head == NULL || head->next == NULL
        || x == y)
        return;

    // Finding the Nodes
    pair<Node*, Node*> p = find(head, x, y);

    Node* Node1 = p.first;
    Node* Node2 = p.second;

    if (Node1 == head)
        head = Node2;
    else if (Node2 == head)
        head = Node1;
    if (Node1 == tail)
        tail = Node2;
    else if (Node2 == tail)
        tail = Node1;

    // Swapping Node1 and Node2
    Node* temp;
    temp = Node1->next;
    Node1->next = Node2->next;
    Node2->next = temp;

    if (Node1->next != NULL)
        Node1->next->prev = Node1;
    if (Node2->next != NULL)
        Node2->next->prev = Node2;

    temp = Node1->prev;
    Node1->prev = Node2->prev;
    Node2->prev = temp;

    if (Node1->prev != NULL)
        Node1->prev->next = Node1;
    if (Node2->prev != NULL)
        Node2->prev->next = Node2;
}*/