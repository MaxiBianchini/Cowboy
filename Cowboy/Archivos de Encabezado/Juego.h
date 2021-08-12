#include "Inocente.h"

class Juego {

	Clock clock;
	Event event;
	Malo malo[6];
	Puerta puerta;
	Fondo* fondo[5];
	Texture Corazon[3];
	Ventanas ventana[5];
	Inocente inocente[6];
	FloatRect sprite_Rect;
	RenderWindow* Ventana;
	Sprite sprite_corazon[3];
	
	Font fuente;
	Text texto[2];

	char exit;
	float timer, x, y;
	bool salir, disparar;
	int valor, cont, contMuertos, vidas, persona, puntos, total;

	float largo, alto;
	int tipoPersonaje;

	bool Click(FloatRect sprite_Rect);
	int elegirPersonaje();
	void elegirAvertura();

	void restarvida();
	void puntaje(int i);
	int puntajetotal();

	void cambioEstado(int i, int j);
	void cambioEstado2(int i);

public:

	Juego();
	~Juego();
	char Menu(void);
	char Correr_juego(void);
};
