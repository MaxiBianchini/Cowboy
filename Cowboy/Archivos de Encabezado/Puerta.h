#include "Abertura.h"

class Puerta : public Abertura {
	Texture textura_puerta[2];
	Sprite sprite_puerta[2];

public:
	Puerta();
	void cambiar_estado();
	void mostrar(RenderWindow &Ventana);
};
