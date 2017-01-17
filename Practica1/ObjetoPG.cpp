#include "ObjetoPG.h"

ObjetoPG::ObjetoPG()
{
	TamTot = new SDL_Rect;
}

bool ObjetoPG::dentro(int x, int y) const
{
	return (y >= TamTot->y && y <= TamTot->y + TamTot->h &&  x >= TamTot->x && x <= TamTot->x + TamTot->w);
	return false;
}

ObjetoPG::~ObjetoPG()
{
	delete TamTot;
}
