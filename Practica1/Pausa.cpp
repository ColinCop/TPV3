#include "Pausa.h"
#include "MenuPG.h"

Pausa::Pausa(juegoPG* juego):EstadoPG(juego)
{
	resume = new Boton(resumeC, 50);
	menu = new Boton(menuC, 80);
	pObjetos.emplace_back(resume);
	pObjetos.emplace_back(menu);
}


Pausa::~Pausa()
{
	delete resume;
	delete menu;
}
void Pausa::resumeC(juegoPG* juego) {
	juego->popState();
}
void Pausa::menuC(juegoPG* juego) {

	juego->changeState(new MenuPG(juego));
}
