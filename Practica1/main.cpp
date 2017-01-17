// Colin Ulrich Cop

#include "SDL.h"
#include "juegoPG.h"
#include <iostream>
int main(int argc, char* argv[]){
	system("chcp 1252");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Practica 2", "Empezar?" , nullptr);
	juegoPG* juego = new juegoPG();
	//Antes de comenzar a jugar nos aseguramos de que no hay errores
	juego->run();
	delete juego;
	system("PAUSE");
	return 0;
}