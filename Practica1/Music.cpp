#include "Music.h"



Music::Music(std::string archivo, std::string efecto)
{
	init();
	load(archivo, efecto);
}
Music::~Music()
{
}
void Music::load(std::string musica, std::string efecto) {
	pMusic = Mix_LoadMUS(musica.c_str());
	pEffect = Mix_LoadWAV(efecto.c_str());
}

void Music::init() {
	Mix_Init(27);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

void Music::playMusic() {
	if (Mix_PlayMusic(pMusic, -1) == -1)
		printf("Mix_PlayMusic: %s\n", Mix_GetError());

}

void Music::playEffect() {
	Mix_PlayChannel(-1, pEffect, 0);
}

void Music::cerrar() {
	Mix_Quit();
}