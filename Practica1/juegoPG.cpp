#include "juegoPG.h"
#include <typeinfo>
#include "GlobosPG.h"
#include "Mariposa.h"
#include "Premio.h"
#include "MenuPG.h"
#include "PlayPG.h"
#include "GameOver.h"
#include "Pausa.h"

using namespace std;

juegoPG::juegoPG(){
	//Tamaño de la ventana
	ANCHO = 1080;
	ALTO = 720;
	//Inicializamos las variable principales del juego
	initSDL();
	rellena();
	initMedia();
	error = exit = false; //Flags de nuestro juego
}


juegoPG::~juegoPG()
{
	freeMedia();

	closeSDL();
}
void juegoPG::run(){
	if (!error) {

		musica->playMusic(); //empieza la musica
		Uint32 MSxUpdate = 500;
		cout << "PLAY \n";
		Uint32 lastUpdate = SDL_GetTicks();
		muestraMensaje("PLAY", "Ready?");
		pilaEstados.push(new MenuPG(this));
		
		handle_event();
		while (!exit && !gameOver()) {//Mientras no queramos salir del juego o hayamos terminado la partida
			pilaEstados.top()->update();
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate){ // while(elapsed >= MSxUpdate)
				//update();
				lastUpdate = SDL_GetTicks();
			}
			handle_event();
			pilaEstados.top()->draw();
			pilaEstados.top()->onClick();
		
		}
		if (exit) cout << "EXIT \n";
		else {
			std::string puntoss = std::to_string(puntos);
			muestraMensaje("Felicidades", "Has obtenido" + puntoss);
		}
		SDL_Quit();
		SDL_Delay(1000);
	
	}
}
bool juegoPG::initSDL() {

	bool success = true; //Initialization flag

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		pWindow = SDL_CreateWindow("Pincha Globitos", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ANCHO, ALTO, SDL_WINDOW_SHOWN);
		if (pWindow == nullptr) {
			cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRender = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //Set background color to black 
			if (pRender == nullptr) {
				cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}
	return success;
}
void juegoPG::closeSDL(){
	SDL_DestroyRenderer(pRender);
	pRender = nullptr;
	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;
	SDL_Quit();
	delete musica;
}

void juegoPG::handle_event(){
	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		//Si pulsamos Exit salimos del juego, si no, lo contamos como CLICK
		if (e.type == SDL_QUIT) onExit();
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				cout << "CLICK \n";
				mx = e.button.x;
				my = e.button.y;
			
			}
		}
	}
}
void juegoPG::onExit() {
	exit = true;//Activamos el flag de salida
	popState();
}
bool juegoPG::gameOver(){
	return nGlobos < 1;//Activamos el flag de salida
}

void juegoPG::getMousePos(int & mpx, int & mpy)const {
	mpx = mx;
	mpy = my;
	
}

void juegoPG::initMedia() {
	musica = new Music("..\\sonidos\\archivo.wav", "..\\sonidos\\efecto.wav");

	//Creamos  espacios en nuestro vector pTexts 
	for (int i = 0; i < nTexturas; i++) {
		pTexts.emplace_back(new TexturasSDL());
		pTexts[i]->load(pRender, pStrings[i]);
	}
	//Le asignamos en su posicion en el vector las imagenes que queremos subir
	//Nuestra ventana del juego
	fondo = new SDL_Rect();
	fondo->w = ANCHO;
	fondo->h = ALTO;
	fondo->x = fondo->y = 0;

}
void juegoPG::freeMedia() {
	//Liberamos tambien el vector pTexts
	for (unsigned int i = 0; i < pTexts.size(); i++) {
		delete pTexts[i];
		pTexts[i] = nullptr;
	}
	musica->cerrar(); //quitamos la musica


}
void juegoPG::rellena() {
	pStrings.emplace_back("..\\bmps\\globitp.png");
	pStrings.emplace_back("..\\bmps\\fondo.png");
	pStrings.emplace_back("..\\bmps\\mariposa.png");
	pStrings.emplace_back("..\\bmps\\premio.png");
	pStrings.emplace_back("..\\bmps\\globoa.png");

}
void juegoPG::changeState(EstadoJuego* nEst) {
	popState();
	pushState(nEst);
}

void juegoPG::pushState(EstadoJuego* nEst) {
	pilaEstados.push(nEst);
}
void juegoPG::popState() {
	pilaEstados.pop();
}
void juegoPG::muestraMensaje(std::string info, std::string boton) {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, info.c_str(), boton.c_str(), nullptr);
	SDL_Quit();
}
