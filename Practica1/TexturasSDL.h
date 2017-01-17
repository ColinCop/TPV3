#pragma once
#include <string>
#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
using namespace std;

class TexturasSDL
{
public:
	//Constructora y destructora
	TexturasSDL();
	~TexturasSDL();
	bool load(SDL_Renderer* pRender, string const& nombArch);//Bool que permite cargar la imagen
	void draw(SDL_Renderer* pRender, SDL_Rect * rect, SDL_Rect* const frect);//Metodo para dibujar
	
	//Metodos para dar los valores del tamaño
	void daAlto(int &_alto);
	void daAncho(int &_ancho);
private:
	SDL_Texture* pTexture;//Puntero al vector
	int ancho;
	int alto;
};


