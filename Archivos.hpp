#pragma once
#include "CRestaurante.hpp"
#include"CClientes.hpp"
#include<fstream>
#include<string>
#include<iostream>


void lectura() {
    ifstream archivo;
    string cadena;
    archivo.open("prueba.txt", ios::in);

    if (archivo.is_open()) {
        getline(archivo, cadena);
        while (!archivo.eof()) {
            getline(archivo, cadena);
        }
        archivo.close();
    }
}

template<typename T, class U = CRestaurante<T>, class P = CProducto<T>>
U* leerRestaurantes(string txt){
    ifstream archivo;
    string cadena;
    
    vector<P>* productos = new vector<P>();
    U restaurante;
    string valoracion;
    string codigo;
    string nombre;
    string nombreR;
    string precio;

    archivo.open(txt,ios::in);
    if(archivo.is_open()){
        getline(archivo,cadena);
        nombreR = cadena;
        getline(archivo, cadena);
        valoracion = cadena;
        while (!archivo.eof()) {
            getline(archivo, cadena);
            codigo = cadena;
            getline(archivo, cadena);
            nombre = cadena;
            getline(archivo, cadena);
            precio = cadena;
            productos->push_back(P(codigo, nombre, precio));
        }
        archivo.close();
    }
    
    return new U(nombreR, valoracion, productos);
}

template<typename T, class U = CCliente<T>>
void leerClientes(ArbolAVL<U*>* clientes) {
    ifstream lectura;
    lectura.open("clientes.csv");
    T line;
    int i = 0;
    while (getline(lectura, line, '\n')) {
        stringstream s(line);
        T aux;

        T nombre;
        T direccion;
        T telefono;
        T dinero;

        getline(s, aux, ',');
        nombre = aux;
        getline(s, aux, ',');
        direccion = aux;
        getline(s, aux, ',');
        telefono = aux;
        getline(s, aux, ',');
        dinero = aux;

        clientes->Insertar(new CCliente<T>(nombre, direccion, telefono, dinero));
        i++;
        //ALTERAR CANTIDAD DE DATOS LEIDOS
        if (i == 5) {
            lectura.close();
            return;
        }
    }
    lectura.close();
}