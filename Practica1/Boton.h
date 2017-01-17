#pragma once
#include "ObjetoPG.h"

class Boton : public ObjetoPG
{
public:
	typedef void Callback_t(juegoPG* jg);
	Boton(Callback_t * callback, int py);
	~Boton();
	virtual void draw()const;
	virtual void update();
	virtual bool onClick();
protected:
	Callback_t * cb;

};


