//
// Created by Manuel on 17/06/2020.
//

#ifndef CLIONSFML_PERSONAJES_H
#define CLIONSFML_PERSONAJES_H
#include"Tipos.h"

class Personajes {
private:
    string nombre;
    int vida;
    int nivel=1;

public:
    Personajes(string _nombre){
        nombre=_nombre;
    }
    void morir();
    int get_Nivel(){return nivel;}
    void set_Nivel(int _nivel){nivel=_nivel;}
};

#endif //CLIONSFML_PERSONAJES_H
