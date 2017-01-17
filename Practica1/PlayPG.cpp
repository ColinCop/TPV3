#include "PlayPG.h"
#include "GlobosPG.h"
#include "Mariposa.h"
#include "Premio.h"

PlayPG::PlayPG(juegoPG* juego) :EstadoPG(juego)
{
}


PlayPG::~PlayPG()
{
}
void  PlayPG::newBaja(ObjetoJuego* po) { //SON LOS OBJETOS LOS QUE MANEJAN, GLOBOS Y PREMIO
	if (typeid(*po) == typeid(GlobosPG)) {

		nGlobos--;//Restamos el numero de globos

	}
}
void  PlayPG::newPuntos(ObjetoJuego* po) { // GLOBO Y PREMIO
	puntos += dynamic_cast<ObjetoPG*>(po)->puntos;//Sumamos los puntos

}
void  PlayPG::newPremio(ObjetoJuego* po) { // LA MARIPOSA LO LLAMA
	if (typeid(*po) == typeid(Mariposa)) {
		pObjetos.emplace_back(new Premio(TPremio, rand() % (ANCHO - 300), rand() % (ALTO - 300), this));
		dynamic_cast<Premio*>(pObjetos[pObjetos.size() - 1])->reset();
	}

}
bool PlayPG::initGlobos() {
	srand(SDL_GetTicks());
	//En el vector pGlobos creamos las posiciones para cada globo

	/*for (int i = 0; i < nMariposas; i++) {
		pObjetos.emplace_back(new Mariposa(TMariposa, rand() % (ANCHO - 300), rand() % (ALTO - 300), this));
	}
	*/
	for (int i = 0; i < nGlobos; i++) {
		
	 pObjetos.emplace_back(new GlobosPG(TGlobo, rand() % (ANCHO - 100), rand() % (ALTO - 100), this));// Posiciones aleatorias
	}

	return true;
}
void PlayPG::freeGlobos() {
	//Liberamos memoria 
	for (unsigned int i = 0; i < pObjetos.size(); i++) {
		delete pObjetos[i];
		pObjetos[i] = nullptr;
	}
}
bool PlayPG::gameOver() {
	return nGlobos < 1;//Activamos el flag de salida
}
void PlayPG::update() {

	for each(ObjetoJuego* obj in pObjetos)
		obj->update(); //Cada vez que se destruye un globo restamos al numero de globos

}
void PlayPG::onClick() {
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


