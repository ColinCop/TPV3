#include "Mariposa.h"
#include "PlayPG.h"


Mariposa::Mariposa(Texturas_t img, int px, int py, juegoPG* jueg)
{
	textura = img;
	juego = jueg;
	posinix = px;
	posiniy = py;
	TamTot->x = px;
	TamTot->y = px;
	TamTot->h = 100;
	TamTot->w = 100;
	
	fRect->w = 63;
	fRect->h = 58;
	fRect->x = fRect->y = 0;

}


Mariposa::~Mariposa()
{
	delete fRect;
}
void Mariposa::draw()const{
	
		juego->getTextura(textura)->draw(juego->getRender(), TamTot, fRect);//Pintamos el globo en su posicion
}
void Mariposa::update() {
	TamTot->x -= 10;
	TamTot->y -= 10;

	if (fRect->x >= 378)  fRect->x = 0; 
	else fRect->x += fRect->w;
	if (TamTot->x <= posinix-70  || TamTot->y <= posiniy-70) {
		posinix = TamTot->x = rand() % (juego->ANCHO - 200);
		posiniy = TamTot->y = rand() % (juego->ALTO - 200);
	}

		
}//441
bool Mariposa::onClick() {
	//Si esta visible y no se ha explotado
	int pmx, pmy;
	pmx = pmy = 0;
	juego->getMousePos(pmx, pmy);
	if (dentro(pmx, pmy)) {
		posinix = TamTot->x = rand() % (juego->ANCHO - 200);
		posiniy = TamTot->y = rand() % (juego->ALTO - 200);
		vida--;
		if (vida <= 0) {
			vida = 3;
			dynamic_cast<PlayPG*>(juego->getState())->newPremio(this);

		}
		return true;
	}
	
	
	return false;
}
