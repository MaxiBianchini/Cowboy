#include "Fondo.h"

Fondo::Fondo(std::string direccion) {
	textura_fondo.loadFromFile(direccion);
	sprite_fondo.setTexture(textura_fondo);
}

Fondo::Fondo(std::string direccion, int x, int y) {
	textura_fondo.loadFromFile(direccion);
	sprite_fondo.setTexture(textura_fondo);
	sprite_fondo.setPosition((float)x, (float)y);
}

FloatRect Fondo::sprite_Rect() {
	return sprite_fondo.getGlobalBounds();
}

void Fondo::mostrar(RenderWindow &Ventana) {
	Ventana.draw(sprite_fondo);
}