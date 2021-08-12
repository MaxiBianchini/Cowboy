#include "Juego.h"

#define SALIR		0
#define MENU		1
#define JUEGO		2

int main(int argc, char *argv[]) {
	Juego* WildGunman = new Juego();
	
	char opcion = MENU;

	while (opcion != SALIR) {
		if (opcion == MENU) opcion = WildGunman->Menu();
		if (opcion == JUEGO) opcion = WildGunman->Correr_juego();
	}
	delete WildGunman;
	return 0;
}