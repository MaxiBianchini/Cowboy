#include "Juego.h"

#define SALIR		0
#define MENU		1
#define JUEGO		2

Juego::Juego() {

	Ventana = new RenderWindow(VideoMode(800, 600, 32), "Wild Gunman", Style::Close);
	Ventana->setFramerateLimit(60);
	
	puntos = 0, vidas = 3, timer = 3, cont = 0, contMuertos = 0, salir = false;

	fuente.loadFromFile("datos/Nova_Mono.ttf");
	texto[0].setFont(fuente); texto[0].setCharacterSize(50); texto[0].setString("Puntaje: "); texto[0].setPosition(570, 20);
	texto[1].setFont(fuente); texto[1].setCharacterSize(50); texto[1].setString(std::to_string(puntajetotal())); texto[1].setPosition(700, 20);
	 
	fondo[0] = new Fondo("datos/imagenes/Extras/Fondo Menu.png");
	fondo[1] = new Fondo("datos/imagenes/Extras/Nuevo Juego.png", 250, 150);
	fondo[2] = new Fondo("datos/imagenes/Extras/Salir.png", 330, 250);
	fondo[3] = new Fondo("datos/imagenes/Extras/Fondo Juego.png");
	fondo[4] = new Fondo("datos/imagenes/Extras/Game Over.png", 50, 150);

	for (char i = 0; i < 3; i++) Corazon[i].loadFromFile("datos/imagenes/Extras/Corazon.png");
	for (char i = 0; i < 3; i++) sprite_corazon[i].setTexture(Corazon[i]);

	sprite_corazon[0].setPosition(120, 50);
	sprite_corazon[1].setPosition(130, 50);
	sprite_corazon[2].setPosition(140, 50);

	malo[0].Init_Hombre(215, 130, '1');
	malo[1].Init_Hombre(375, 130, '2');
	malo[2].Init_Hombre(540, 130, '3');
	malo[3].Init_Hombre(215, 380, '4');
	malo[4].Init_Hombre(540, 380, '5');
	malo[5].Init_Hombre(380, 420, '6');

	inocente[0].Init_Hombre(215, 130, '1');
	inocente[1].Init_Hombre(375, 130, '2');
	inocente[2].Init_Hombre(540, 130, '3');
	inocente[3].Init_Hombre(215, 380, '4');
	inocente[4].Init_Hombre(540, 380, '5');
	inocente[5].Init_Hombre(380, 420, '6');

	ventana[0].Init_Ventanas(168, 119, '1');
	ventana[1].Init_Ventanas(327, 119, '2');
	ventana[2].Init_Ventanas(490, 119, '3');
	ventana[3].Init_Ventanas(165, 360, '4');
	ventana[4].Init_Ventanas(490, 360, '5');
}

Juego::~Juego() {
	Ventana->close(), delete Ventana;
	for (char i = 0; i < 3; i++) delete(fondo[i]);
}

bool Juego::Click(FloatRect sprite_Rect) {

	largo = sprite_Rect.left + sprite_Rect.width;
	alto = sprite_Rect.top + sprite_Rect.height;

	if ((x > sprite_Rect.left && x <= largo) && (y > sprite_Rect.top && y <= alto)) return true;
	else return false;
}

void Juego::elegirAvertura() {
	srand(time(NULL));  valor = 0 + rand() % 6;
}

int Juego::elegirPersonaje() {
	persona = 0 + rand() % 2;
	if (persona == 0) return persona;
	else if (persona == 1) {
		persona = 0 + rand() % 2;
		if (persona == 0) return persona;
		else if (persona == 1) return persona;
	}
}

void Juego::restarvida() {
	vidas--;
}

void Juego::puntaje(int i) { //0 Matar Malo, 1 Matar Inocente o Me Dispararon
	if (i == 0) puntos++;
	if (i == 1) restarvida();
}

int Juego::puntajetotal() {
	total = puntos * 10;
	return total;
}

void Juego::cambioEstado(int i, int j) {
	if (i == 0) {
		if (valor < 5) {
			malo[valor].mostrar(*Ventana);

			fondo[3]->mostrar(*Ventana);

			ventana[valor].cambiar_estado();
			for (char i = 0; i < 5; i++) ventana[i].mostrar(*Ventana);

			puerta.mostrar(*Ventana);

			if (j == 3) contMuertos++, puntaje(0);
			else if (j == 2) puntaje(1);
		}
		else if (valor == 5) {
			malo[valor].mostrar(*Ventana);

			fondo[3]->mostrar(*Ventana);

			for (char i = 0; i < 5; i++) ventana[i].mostrar(*Ventana);

			puerta.cambiar_estado();
			puerta.mostrar(*Ventana);

			if (j == 3) puntaje(0);
			else if (j == 2) puntaje(1);
		}
	}
	else if (i == 1) {
		if (valor < 5) {
			inocente[valor].mostrar(*Ventana);

			fondo[3]->mostrar(*Ventana);

			ventana[valor].cambiar_estado();
			for (char i = 0; i < 5; i++) ventana[i].mostrar(*Ventana);

			puerta.mostrar(*Ventana);

			if (j == 3) puntaje(1);
		}
		else if (valor == 5) {
			inocente[valor].mostrar(*Ventana);

			fondo[3]->mostrar(*Ventana);

			for (char i = 0; i < 5; i++) ventana[i].mostrar(*Ventana);
			puerta.cambiar_estado();

			puerta.mostrar(*Ventana);

			if (j == 3) puntaje(1);
		}
	}
}

void Juego::cambioEstado2(int i) {
	if (i == 0) {
		if (valor == 5) {
			malo[valor].cambiar_estado();
			puerta.cambiar_estado();
		}
		else if (valor < 5) {
			malo[valor].cambiar_estado();
			ventana[valor].cambiar_estado();
		}
	}
	else if (i == 1) {
		if (valor == 5) {
			inocente[valor].cambiar_estado();
			puerta.cambiar_estado();
		}
		else if (valor < 5) {
			inocente[valor].cambiar_estado();
			ventana[valor].cambiar_estado();
		}
	}
}

char Juego::Menu(void) {

	fondo[0]->mostrar(*Ventana);
	fondo[1]->mostrar(*Ventana);
	fondo[2]->mostrar(*Ventana);

	Ventana->display();

	while (!salir) {
		while (Ventana->pollEvent(event)) {
			if (event.type == Event::MouseMoved) {
				x = event.mouseMove.x;
				y = event.mouseMove.y;
			}
			switch (event.type) {
			case Event::MouseButtonPressed:
				sprite_Rect = fondo[1]->sprite_Rect();
				if (Click(sprite_Rect)) {
					exit = JUEGO; salir = true;
				}
				else {
					sprite_Rect = fondo[2]->sprite_Rect();
					if (Click(sprite_Rect)) {
						exit = SALIR; salir = true;
					}
				}
				break;

			case Event::Closed:
				exit = SALIR; salir = true;
				break;
			}
		}
	}
	salir = false;

	return exit;
}

char Juego::Correr_juego(void) {

	clock.restart();
	Ventana->clear();

	puerta.mostrar(*Ventana);
	fondo[3]->mostrar(*Ventana);
	for (char i = 0; i < 5; i++) ventana[i].mostrar(*Ventana);
	for (char i = 0; i < vidas; i++) Ventana->draw(sprite_corazon[i]);

	texto[1].setString(std::to_string(puntajetotal()));
	for (char i = 0; i < 2; i++) Ventana->draw(texto[i]);
	
	Ventana->display();
	
	while (vidas != 0) {
		if (contMuertos == 5) timer -= 0.3, contMuertos = 0;
		tipoPersonaje = elegirPersonaje();
		while (!salir) {

			if (cont == 0) {
				elegirAvertura();
			}

			while (Ventana->pollEvent(event)) {
				if (event.type == Event::Closed) {
					salir = true, exit = SALIR; vidas = 0;
				}
				if (event.type == Event::MouseMoved) {
					x = event.mouseMove.x;
					y = event.mouseMove.y;
				}
				if (event.type == Event::MouseButtonPressed) {
					if (cont == 1) {
						sprite_Rect = malo[valor].pos_sprite();
						if (Click(sprite_Rect)) {
							Ventana->clear();

							cambioEstado2(tipoPersonaje);

							cont++;

							cambioEstado(tipoPersonaje, 3);

							for (char i = 0; i < vidas; i++) Ventana->draw(sprite_corazon[i]);
							texto[1].setString(std::to_string(puntajetotal()));
							for (char i = 0; i < 2; i++) Ventana->draw(texto[i]);

							Ventana->display();
							clock.restart();

							cambioEstado2(tipoPersonaje);
						}
					}
				}
			}
			if (clock.getElapsedTime().asSeconds() > timer) {
				Ventana->clear();

				cont++;

				cambioEstado(tipoPersonaje, cont);

				for (char i = 0; i < vidas; i++) Ventana->draw(sprite_corazon[i]);
				texto[1].setString(std::to_string(puntajetotal()));
				for (char i = 0; i < 2; i++) Ventana->draw(texto[i]);

				Ventana->display();
				clock.restart();
			}
			if (cont == 2) {
				cont = 0;
				salir = true;
			}
		}
		salir = false;
	}
	while (salir == false){
		Ventana->clear();

		fondo[0]->mostrar(*Ventana);
		fondo[4]->mostrar(*Ventana);

		texto[0].setPosition(350, 400);
		texto[1].setPosition(465, 400);

		texto[1].setString(std::to_string(puntajetotal()));
		for (char i = 0; i < 2; i++) Ventana->draw(texto[i]);

		Ventana->display();
		while (Ventana->pollEvent(event)) {
			if (event.type == Event::Closed) {
				salir = true;
			}
		}
	}
	
	return exit;
}

