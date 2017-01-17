#include "Error.h"


Error::Error(std::string mensaje) :mensaje(mensaje)
{
}


Error::~Error()
{
}

std::string Error::ensenMensaje()const {
	return mensaje;
	
}
