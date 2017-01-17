#include "Boton.h"
Boton::Boton(Callback_t * callback,int py):cb(callback)
{
	textura = TBoton;
	TamTot->x = juego->getWWidth() / 2;
	TamTot->y = py;
	juego->getTextura(textura)->daAlto(TamTot->h);
	juego->getTextura(textura)->daAlto( TamTot->w);
}

Boton::~Boton()
{
}
void Boton::draw()const {
	juego->getTextura(textura)->draw(juego->getRender(), TamTot, nullptr);
	
}

void Boton::update() {
		//Implementar si sobra tiempo
		
}

bool Boton::onClick() {
	int x, y;
	juego->getMousePos(x, y);
	if (dentro(x, y))
		 cb;
	
}