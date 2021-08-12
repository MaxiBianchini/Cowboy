#include "Malo.h"

Malo::Malo() : Hombre() {}

void Malo::Init_Hombre(int _x, int _y, char numero) {
	x = _x, y = _y; estado = 0;

	textura_hombre[0].loadFromFile("datos/imagenes/Bandido/Bandido1.png");
	sprite_hombre[0].setTexture(textura_hombre[0]);
	sprite_hombre[0].setPosition(x, y);

	textura_hombre[1].loadFromFile("datos/imagenes/Bandido/Bandido2.png");
	sprite_hombre[1].setTexture(textura_hombre[1]);
	sprite_hombre[1].setPosition(x, y);

	cambiarTamaño(textura_hombre[0], sprite_hombre[0], 130);
	cambiarTamaño(textura_hombre[1], sprite_hombre[1], 130);
}