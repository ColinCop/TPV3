#include "MenuPG.h"
#include "PlayPG.h"


MenuPG::MenuPG(juegoPG* juego):EstadoPG(juego)
{
	play = new Boton(playC,50);
	exit = new Boton(exitC, 80);
	pObjetos.emplace_back(play);
	pObjetos.emplace_back(exit);
}


MenuPG::~MenuPG()
{
	delete exit;
	delete play;
}

void MenuPG::playC(juegoPG* juego) {
	juego->changeState(new PlayPG(juego));
}
void MenuPG::exitC(juegoPG* juego) {
	juego->onExit();
}
