#pragma once
#include "EstadoPG.h"
#include "Boton.h"
class Pausa: public EstadoPG

{
public:
	Pausa(juegoPG* juego);
	~Pausa();
	Boton* resume;
	Boton* menu;
	static void menuC(juegoPG* juego);
	static void resumeC(juegoPG* juego);
};

