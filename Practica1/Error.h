#pragma once
#include <string>
using namespace std;
class Error
{
public:
	Error(string mensaje);
	~Error();
	string ensenMensaje() const ;
private:
	string mensaje;
};

