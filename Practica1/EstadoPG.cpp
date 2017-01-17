#include "EstadoPG.h"


EstadoPG::EstadoPG(juegoPG* juego) :juego(juego)
{
}


EstadoPG::~EstadoPG()
{
}
void EstadoPG::update() {

	for each(ObjetoJuego* obj in pObjetos)
		obj->update(); //Cada vez que se destruye un globo restamos al numero de globos

}

void EstadoPG::onClick() {
		//Miramos si hemos hecho click en un globo
		bool clickeado = false;
		unsigned int i = 0;
		while (i <pObjetos.size() && !clickeado) {
			if (pObjetos[i]->onClick()) {
				clickeado = true;
			}
			i++;
		}
	
}
void EstadoPG::draw()const {
		SDL_Renderer* pRender = juego->getRender();
		SDL_RenderClear(pRender);//Borramos lo que esta pintado
		juego->getTextura(TFondo)->draw(pRender, nullptr, nullptr);

		for each(ObjetoJuego* obj in pObjetos) {
			obj->draw(); //Mandamos a dibujar cada globo
		}
		SDL_RenderPresent(pRender);//Los pintamos
	}

