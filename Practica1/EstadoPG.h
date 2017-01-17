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
	virtual void draw()const ;
	virtual void update() ;
	virtual void onClick() ;
protected:
	juegoPG * juego;
	std::vector<ObjetoJuego*> pObjetos;

};

