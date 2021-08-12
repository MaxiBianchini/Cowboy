#include "Fondo.h"

class Abertura {
protected:

	int estado;

	short x, y;
	
	virtual void mostrar(RenderWindow &Ventana) = 0;
};
