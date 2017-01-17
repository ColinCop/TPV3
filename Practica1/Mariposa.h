#pragma once
#include "ObjetoPG.h"
class Mariposa: public ObjetoPG
{
public:
	Mariposa(Texturas_t img, int px, int py, juegoPG* jueg);
	~Mariposa();
	virtual void draw()const;
	virtual bool onClick();
	virtual void update();
	int vida = 3;
	int posinix, posiniy;
	SDL_Rect* fRect = new SDL_Rect;
	
};

