#pragma once
#include <SDL_mixer.h>
#include <string>
class Music
{
public:
	Music(std::string archivo, std::string efecto);
	~Music();
	void init();
	void playMusic();
	void playEffect();
	void load(std::string archivo, std::string efecto);
	void cerrar();
private:
	Mix_Music* pMusic;
	Mix_Chunk* pEffect;
};

