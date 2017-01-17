#pragma once
#include "EstadoPG.h"
#include "Boton.h"
class MenuPG: public EstadoPG
{
public:
	MenuPG(juegoPG* juego);
	~MenuPG();
	Boton* play;
	Boton* exit;
	static void playC(juegoPG* juego);
	static void exitC(juegoPG* juego);
};

