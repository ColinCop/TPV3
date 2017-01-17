#pragma once
#include "ObjetoPG.h"
class Premio : public ObjetoPG
{
public:
	Premio(Texturas_t img, int px, int py, juegoPG* jueg);
	~Premio();
	int vida = 3;
	virtual void update();
	virtual void draw()const;
	virtual bool onClick();
	void reset();
	bool visible;
};

