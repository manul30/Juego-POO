
#include "ventana.h"
#include"Tipos.h"

//CONSTRUCTOR
ventana::ventana(int x, int y, string titulo){
    Personajes principal("Mario");
    setPersonaje(&principal);
    panel= new RenderWindow (VideoMode(x,y),titulo);
    setFps(fps);
    cancion1.openFromFile("C:\\Users\\Manuel\\CLionProjects\\ClionSFML\\sountrack_juego\\musica1.ogg");
    cancion1.setVolume(20);
    Archivo.loadFromFile("C:\\Users\\Manuel\\CLionProjects\\ClionSFML\\fondo_menu.jpg");//Cargando archivo
    sprite1.setTexture(Archivo);//creando sprite1 desde la textura(archivo)
    sprite1.setScale((float)x/sprite1.getTexture()->getSize().x,(float)y/sprite1.getTexture()->getSize().y);
    fuente1.loadFromFile("C:\\Users\\Manuel\\CLionProjects\\ClionSFML\\Minecraft.ttf");
    fuente2.loadFromFile("C:\\Users\\Manuel\\CLionProjects\\ClionSFML\\8_bit.ttf");
    titulo0.setFont(fuente2);
    titulo0.setString("Chupetin Trujillo: The Game");
    titulo0.setScale((float)4.5*x/sprite1.getTexture()->getSize().x,(float)4.5*y/sprite1.getTexture()->getSize().y);
    titulo0.setOrigin((float)titulo0.getGlobalBounds().width/2,(float)titulo0.getGlobalBounds().height/2);
    titulo0.setPosition((float)x*0.86,(float)y/5);
    texto_bienvenida.setFont(fuente1);
    texto_bienvenida.setString("Pulsa cualquier tecla para continuar");
    texto_bienvenida.setOrigin((float)texto_bienvenida.getGlobalBounds().width/2,(float)texto_bienvenida.getGlobalBounds().height/2);
    texto_bienvenida.setPosition(x/2,y/2);
    texto_bienvenida.setFillColor(Color::Yellow);
    Abrir();
}

//MÉTODO PARA EDITAR LA PANTALLA (LA CLAVE DE TODO)
void ventana::Editar(){
    panel->clear();
    Proceso_Eventos();
    panel->draw(sprite1);
    panel->draw(titulo0);
    panel->draw(texto_bienvenida);
    panel->display();
}

//METODO PARA ABRIR LA VENTANA
void ventana::Abrir() {
    cancion1.play();
    while(panel->isOpen()){
        Editar();
    }
}

//METODO PARA FIJAR LOS FPS´s
void ventana::setFps(int x) {
    fps=x;
    panel->setFramerateLimit(fps);
}

void ventana::Proceso_Eventos() {
    while(panel->pollEvent(evento_menu)){
        switch(evento_menu.type){
            case Event::Closed:
                panel->close();
                break;
            case Event::KeyPressed:
                if(!Keyboard::isKeyPressed(Keyboard::Escape)){
                    personaje_principal->set_Nivel((personaje_principal->get_Nivel())+1);
                   cancion1.stop();
                   cancion1.openFromFile("C:\\Users\\Manuel\\CLionProjects\\ClionSFML\\sountrack_juego\\musica"+to_string(personaje_principal->get_Nivel())+".ogg");
                   cancion1.play();
                   Archivo.loadFromFile("C:\\Users\\Manuel\\CLionProjects\\ClionSFML\\fondo.jpg");
                   sprite1.setTexture(Archivo);
                    sprite1.setScale((float)800/sprite1.getTexture()->getSize().x,(float)600/sprite1.getTexture()->getSize().y);
                }else{
                    exit(1);
                }
        }
    }
}

