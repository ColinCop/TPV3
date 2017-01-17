#include "PlayPG.h"
#include "GlobosPG.h"
#include "Mariposa.h"
#include "Premio.h"

PlayPG::PlayPG(juegoPG* juego) :EstadoPG(juego)
{
	ALTO = 1080;
	ANCHO = 720;
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
		pObjetos.emplace_back(new Premio(TPremio, rand() % (ANCHO - 300), rand() % (ALTO - 300), juego));
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
		
		pObjetos.emplace_back(new GlobosPG(TGlobo, rand() % (ANCHO - 100), rand() % (ALTO - 100), juego));// Posiciones aleatorias
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




