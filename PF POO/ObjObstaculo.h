#pragma once
#include <iostream>
#include "Model.h"

class ObjObstaculo {
private:
	bool perdiste = false;
		int vida = 1;

public:

	int getVida();
	void setVida(int vida);
	void perder();
};
