
#ifndef H_JuegoPG_H
#define H_JuegoPG_H
#include <SDL.h>
#include <vector>
#include "Music.h"
#include "TexturasSDL.h"
#include "EstadoJuego.h"
#include <stack>
enum Texturas_t { TGlobo, TFondo, TMariposa, TPremio, TGloboA, TBoton };
class juegoPG
{
public:
	//Constructora y destructora
	juegoPG();
	~juegoPG();
	void run();//Bucle principal del juego
	
	
	enum Estado {Emenu, Ejuego, Egameover, Epausa};
	std::vector<std::string> pStrings;
	TexturasSDL* getTextura(Texturas_t et) const { return pTexts[et]; };
	SDL_Renderer* getRender() const { return pRender; };
	void getMousePos(int &mpx, int & mpy) const;
	void initMedia();
	void freeMedia();
	void changeState(EstadoJuego* nEst);
	void pushState(EstadoJuego* newState);
	void popState();
	int ALTO, ANCHO;
	int getWWidth()const { return ANCHO; };
	int getPuntos()const { return puntos; };
	
	int nGlobos = 4;
	int nMariposas = 2;
	Music* musica;
	void muestraMensaje(std::string info, std::string boton);
	void onExit();
	

private:
	std::stack<EstadoJuego *> pilaEstados;
	SDL_Renderer* pRender;
	SDL_Window* pWindow;
	std::vector<TexturasSDL*> pTexts;
	SDL_Rect* fondo;
	
	
	int nTexturas = 5;
	void rellena();
	
	
	int time;
	int puntos, mx,my;
	bool exit, error;
	bool initSDL();
	void closeSDL();
	void handle_event();
	
	bool gameOver();

	
	
};

#endif 
