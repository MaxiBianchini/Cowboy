#include "Puerta.h"

Puerta::Puerta() {
	estado = 0, x = 327, y = 372;
	textura_puerta[0].loadFromFile("datos/imagenes/Ventana y Puerta/Puerta1.png");
	
	textura_puerta[1].loadFromFile("datos/imagenes/Ventana y Puerta/Puerta2.png");

	for (char i = 0; i < 2; i++) {
		sprite_puerta[i].setTexture(textura_puerta[i]);
		sprite_puerta[i].setPosition(x, y);
	}
}

void Puerta::cambiar_estado() {
	switch (estado) {
	case 0: estado = 1; break;
	case 1: estado = 0; break;
	}
}

void Puerta::mostrar(RenderWindow &Ventana) {
	switch (estado) {
	case 0: Ventana.draw(sprite_puerta[0]); break;
	case 1: Ventana.draw(sprite_puerta[1]); break;
	}
}