#ifndef H_ObjetoPG_H
#define H_ObjetoPG_H
#include "ObjetoJuego.h"
#include "juegoPG.h"

class ObjetoPG: public ObjetoJuego
{
public:

	ObjetoPG();
	bool dentro(int x, int y)const;
	virtual ~ObjetoPG();
	int puntos;
	
protected:
	
	juegoPG* juego;
	SDL_Rect* TamTot;
	Texturas_t textura;
	
};

#endif