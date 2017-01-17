#pragma once
#include "EstadoJuego.h"
#include "ObjetoJuego.h"
#include "juegoPG.h"
#include <vector>
class EstadoPG : public EstadoJuego
{
public:
	EstadoPG(juegoPG* juego);
	virtual ~EstadoPG();
	virtual void draw()const = 0;
	virtual void update() = 0;
	virtual void onClick() = 0;
protected:
	juegoPG * juego;
	std::vector<ObjetoJuego*> pObjetos;

};

