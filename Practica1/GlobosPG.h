#pragma once
#include <string>
#include <SDL.h>
#include <iostream>
#include "ObjetoPG.h"

class GlobosPG:public ObjetoPG
{
public:
	//Constructora y destructora
	GlobosPG(Texturas_t img, int px, int py, juegoPG* jueg);
	~GlobosPG();
	

protected:
	virtual void draw()const;
	virtual bool onClick();
	virtual void update();
	bool explotado;
	bool visible;
	//Valores de la probabilidad de ser visible y deshinflarse
	//Valores de los puntos y de la reduccion de los globos
	static const int PVIS = 70;
	static const int PDES = 30;
	static const int DT = 5;
	static const int AP = 5;



};

