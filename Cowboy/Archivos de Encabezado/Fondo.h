#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

using namespace sf;

class Fondo {

	Texture textura_fondo;
	Sprite sprite_fondo;

public:

	Fondo(std::string direccion);
	Fondo(std::string direccion, int x, int y);

	FloatRect sprite_Rect();

	void mostrar(RenderWindow &Ventana);
};