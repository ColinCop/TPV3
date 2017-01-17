#include "Premio.h"
#include "PlayPG.h"


Premio::Premio(Texturas_t img, int px, int py, juegoPG* jueg)
{
	textura = img;
	visible = false;
	puntos = 300;
	juego = jueg;
	TamTot->x = px;
	TamTot->y = px;
	TamTot->h = 100;
	TamTot->w = 100;


}


Premio::~Premio()
{
}
void Premio::draw()const {
	if(visible)
		juego->getTextura(textura)->draw(juego->getRender(), TamTot, nullptr);
}
bool Premio::onClick() {
	int pmx, pmy;
	pmx = pmy = 0;
	juego->getMousePos(pmx, pmy);
	if (dentro(pmx, pmy) && visible) {
		dynamic_cast<PlayPG*>(juego->getState())->newPuntos(this);
		visible = false;
		return true;
	}
	else
		return false;
}

void Premio::update() {
	if (visible && vida > 0) {
		puntos -= 100;
		vida--;
		if (vida == 0) visible = false;
	}

}
void Premio::reset() {
	TamTot->x = rand() % (juego->ANCHO - 200);
	TamTot->y = rand() % (juego->ALTO - 200);
	vida = 3;
	puntos = 300;
	visible = true;
}

