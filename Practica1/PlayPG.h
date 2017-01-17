#pragma once
#include "EstadoPG.h"
class PlayPG:public EstadoPG
{
public:
	PlayPG(juegoPG* juego);
	~PlayPG();
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego* po);
	void newPremio(ObjetoJuego* po);
	virtual void draw() const;
	virtual void onClick();///
	virtual void update();
	int ALTO, ANCHO;
private:
	int nGlobos = 5;
	int puntos;
	bool gameOver();
	bool initGlobos();
	void freeGlobos();
};
