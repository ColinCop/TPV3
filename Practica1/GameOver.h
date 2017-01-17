#pragma once
#include "EstadoPG.h"
#include "Boton.h"
class GameOver: public EstadoPG

{
public:
	GameOver(juegoPG* juego);
	~GameOver();
	Boton* score;
	Boton* menu;
	static void scoreC(juegoPG * juego);
	static void menuC(juegoPG * juego);
};

