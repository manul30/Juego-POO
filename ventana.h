//
// Created by Manuel on 18/06/2020.
//

#ifndef CLIONSFML_VENTANA_H
#define CLIONSFML_VENTANA_H

#include "Tipos.h"
#include"Personajes.h"

//CLASE VENTANA
class ventana {
private:
    RenderWindow *panel;
    int altura=800, ancho=600,fps=60;
    string titulo;
    Texture Archivo;
    Sprite sprite1;
    Font fuente1,fuente2;
    Text texto_bienvenida, titulo0;
    Music cancion1;
    Event evento_menu;
    Personajes *personaje_principal;
public:
    ventana(int x, int y, string _titulo);
    void Abrir();
    void setFps(int);
    void Editar();
    void Proceso_Eventos();
    int get_altura(){return altura;};
    int get_ancho(){return ancho;};
    void setPersonaje(Personajes* ppersonaje){personaje_principal=ppersonaje;}

};



#endif //CLIONSFML_VENTANA_H
