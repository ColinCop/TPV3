#include "TexturasSDL.h"


TexturasSDL::TexturasSDL()
{
	pTexture = nullptr;
	//Le damos valor a ancho y alto
	ancho = 0;
	alto = 0;
}
TexturasSDL::~TexturasSDL()
{
	SDL_DestroyTexture(pTexture);
}
bool TexturasSDL::load(SDL_Renderer* pRender, string const &nombArch){
	//The image we will load 
	SDL_Surface* pTempSurface = nullptr;
	bool success = true;  //Loading success flag

	//Load image
	pTempSurface = IMG_Load(nombArch.c_str());  // si usamos string: bmpName.c_str() 
	if (pTempSurface == nullptr) {
		cout << "Unable to load image " << nombArch << "! \nSDL Error: " << SDL_GetError() << '\n';
		success = false;
	}
	else {
		SDL_DestroyTexture(pTexture);
		pTexture = SDL_CreateTextureFromSurface(pRender, pTempSurface);
		SDL_QueryTexture(pTexture, NULL, NULL, &ancho, &alto);
		SDL_FreeSurface(pTempSurface);
		success = pTexture != nullptr;
	}

	return success;
}
void TexturasSDL::draw(SDL_Renderer* pRender, SDL_Rect * rect, SDL_Rect* const frect){
	SDL_RenderCopy(pRender, pTexture, frect, rect);
}
//Le damos valor al ancho y alto
void TexturasSDL::daAlto(int &_alto){
	_alto = alto;
}
void TexturasSDL::daAncho(int &_ancho){
	_ancho = ancho;
}

