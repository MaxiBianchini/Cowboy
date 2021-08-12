#include "Ventanas.h"

Ventanas::Ventanas() {}

void Ventanas::Init_Ventanas(int _x, int _y, char numero) {
	x = _x, y = _y; estado = 0;
	textura_ventana[0].loadFromFile("datos/imagenes/Ventana y Puerta/Ventana1.png");
	sprite_ventana[0].setTexture(textura_ventana[0]);		
	sprite_ventana[0].setPosition(x, y);

	textura_ventana[1].loadFromFile("datos/imagenes/Ventana y Puerta/Ventana2.png");
	sprite_ventana[1].setTexture(textura_ventana[1]);
	sprite_ventana[1].setPosition(x, y);
	
}

void Ventanas::cambiar_estado() {
	switch (estado) {
	case 0: estado = 1; break;
	case 1: estado = 0; break;
	}
}

void Ventanas::mostrar(RenderWindow &Ventana) {
	switch (estado) {
	case 0: Ventana.draw(sprite_ventana[0]); break;
	case 1: Ventana.draw(sprite_ventana[1]); break;
	}
}