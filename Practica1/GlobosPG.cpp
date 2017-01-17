#include "GlobosPG.h"
#include "PlayPG.h"


GlobosPG::GlobosPG(Texturas_t img, int px, int py, juegoPG* jueg)
{
	textura = img;

	juego = jueg;
	if (rand() % 100 < PVIS){//Si el numero aleatorio que sacamos es menor que PVIS(70)
		visible = true;
	}
	else{
		visible = false;	
	}
	puntos = 10;
	
	//Inicializamos las variables
	explotado = false;
	//Coordenadas de los globos
	TamTot->x = px;
	TamTot->y = py;
	TamTot->w = 60;
	TamTot->h = 90;
	//Ancho y alto de la imagen de los globos
	
}
GlobosPG::~GlobosPG()
{
	
}
void GlobosPG::draw()const{
	if (visible){
		juego->getTextura(textura)->draw(juego->getRender(), TamTot,nullptr);//Pintamos el globo en su posicion
	}
}
void GlobosPG::update(){
	
	if (visible && !explotado){
		if (rand() % 100 < PDES){//Si el numero aleatorio que sacamos es menor que PDES(30)
			puntos += AP;//Sumamos los puntos
			//Disminuimos el tamaño del globo
			TamTot->h -= DT*2;
			TamTot->w -= DT*2;
			if (TamTot->h <= 0 || 0 >= TamTot->w){//Si se ha deshinflado completamente
				visible = false;
				explotado = true;
				dynamic_cast<PlayPG*>(juego->getState())->newBaja(this);
				
			}
		}
	}
	if (!explotado){
		if (rand() % 100 < PVIS)//Los globos que no se pintaron antes pueden pintarse ahora
			visible = true;
		else visible = false;
	}
	
}
bool GlobosPG::onClick(){
	//Si esta visible y no se ha explotado
	int pmx, pmy;
	pmx = pmy = 0;
	juego->getMousePos(pmx, pmy);
	if (visible && !explotado && dentro(pmx, pmy)) {
		visible = false;// El globo desaparece
		explotado = true;// Y lo explotamos
		juego->musica->playEffect(); //suena el efecto de sonido
		dynamic_cast<PlayPG*>(juego->getState())->newBaja(this);
		dynamic_cast<PlayPG*>(juego->getState())->newPuntos(this);
		return true;
	}
	else
		return false; 
	}


