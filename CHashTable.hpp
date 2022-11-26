#ifndef __HASH_TABLE_SCH__
#define __HASH_TABLE_SCH__

#include <string>
#include <cmath>
#include "ListaDE.hpp"

template<class T>
class HashTable {
public:
    HashTable(size_t capacity): _capacity(capacity) {
        _size = 0;
        _hashTable = new LDE<Element>*[capacity];
        for(int i = 0; i < capacity; ++i) _hashTable[i] = nullptr;
    }
    void Limpiar() {
        for (int i = 0; i < _capacity; ++i) delete _hashTable[i];
        for (int i = 0; i < _capacity; ++i) _hashTable[i] = nullptr;
        while (_size != 0) {
            --_size;
        }
    }
    void insert(std::string key, T value) {
        if(_size == _capacity) throw "Hash table is full";
        int index = _hashFunction(key);
        if(_hashTable[index] == nullptr) _hashTable[index] = new LDE<Element>(
            [](Element prod) -> string {
                return "0";
            }
            );
        int pos = _hashTable[index]->size() / 2;
        _hashTable[index]->insertAt(Element{key,value},pos);
        ++_size;
    }
    T& operator[](std::string key) {
        int index = _hashFunction(key);
        auto list = _hashTable[index];
        T value = _hashTable[index]->getByCriteria([&](Element e) -> bool {
            return e.key = key;
        });
        return value;
    }
    auto getCopy(std::string key) {
        int index = _hashFunction(key);
        auto list = _hashTable[index];
        auto value = list->getByCriteria([&](Element e) -> bool {
            return e.key == key;
        });
        return value;
    }
    void display(void (*show)(T)) {
        for(unsigned int i = 0; i < _capacity; ++i) {
            std::cout << "\nPos: " << i << ": ";
            if(_hashTable[i] == nullptr) {
                std::cout << "nullptr";
                continue;
            }
            _hashTable[i]->display([&](Element a) -> void {
                show(a.value);
            });
        }
    }
    size_t size() { return _size; }
    bool isBlank() { return _size == 0; }
private:
    struct Element {
        std::string key;
        T value;
    };
    LDE<Element>** _hashTable;
    size_t _size;
    size_t _capacity;
private:
    int _hashFunction(std::string key) {
        int res = 0;
        for (unsigned int i = 0; i < key.length(); ++i)
            res += pow(static_cast<int>(key[i]), i + 1);
        return res % _capacity;
    }
};

#endif