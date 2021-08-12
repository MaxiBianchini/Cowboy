#include "Puerta.h"

class Ventanas : public Abertura {
	Texture textura_ventana[2];
	Sprite sprite_ventana[2];

public:
	Ventanas();
	void Init_Ventanas(int _x, int _y, char numero);
	void cambiar_estado();
	void mostrar(RenderWindow &Ventana);
};
