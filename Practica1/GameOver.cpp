#include "GameOver.h"
#include "MenuPG.h"

GameOver::GameOver(juegoPG* juego):EstadoPG(juego)
{
	score = new Boton(scoreC, 50);
	menu = new Boton(menuC, 80);
	pObjetos.emplace_back(score);
	pObjetos.emplace_back(menu);
}


GameOver::~GameOver()
{
	delete score;
	delete menu;
}
void GameOver::scoreC(juegoPG * juego) {
	int puntos = juego->getPuntos();
	juego->muestraMensaje("Puntos: " + puntos, "Felicidades!");
}
void GameOver::menuC(juegoPG * juego) {
	juego->changeState(new MenuPG(juego));
}
