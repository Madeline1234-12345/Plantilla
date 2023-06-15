#include "ObjObstaculo.h"

int ObjObstaculo::getVida() {
	return vida;
}

void ObjObstaculo::setVida(int vida_temp) {
	vida = vida_temp;
}

void ObjObstaculo::perder() {
	ObjObstaculo::perdiste = true;
}



