#include "Hombre.h"

Hombre::Hombre(){}

void Hombre::cambiar_estado() {
	switch (estado) {
	case 0: estado = 1; break;
	case 1: estado = 0; break;
	}
}

float Hombre::cambiarTamaño(Texture &textura, Sprite &sprite, float altura_nueva) {
	float escala, altura, ancho;
	ancho = (float)textura.getSize().x;
	altura = (float)textura.getSize().y;
	escala = altura_nueva / altura;
	sprite.setScale(escala, escala);
	textura.setSmooth(true);
	ancho = ancho * altura_nueva / altura;
	return ancho;
}

void Hombre::mostrar(RenderWindow &Ventana) {
	switch (estado) {
	case 0: Ventana.draw(sprite_hombre[0]); break;
	case 1: Ventana.draw(sprite_hombre[1]); break;
	}
}

FloatRect Hombre::pos_sprite() {
	return sprite_hombre[0].getGlobalBounds();
}

