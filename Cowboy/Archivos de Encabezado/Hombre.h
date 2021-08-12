#include "Ventanas.h"

class Hombre {
	protected:
		Texture textura_hombre[2];
		Sprite sprite_hombre[2];
		int estado;
		short x, y;
		float cambiarTamaño(Texture &textura, Sprite &sprite, float altura_nueva);

	public:
	
		Hombre();
		void cambiar_estado();
		virtual void Init_Hombre(int _x, int _y, char numero) = 0;

		FloatRect pos_sprite();
		void mostrar(RenderWindow &Ventana);

	};
