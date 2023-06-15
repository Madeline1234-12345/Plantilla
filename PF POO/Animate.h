#pragma once
#include <iostream>
#include "Model.h"


class Animate {
private:

	EDXFramework::Model* Model;

	float x, y, z, r;
	float birdRotation;
	float birdMove;
	float birdTraslation;
	bool positiveBirdRotation;
	bool sube = true, ar = true;
	float subebaja = -180, arriba = 40;
	float rocarotacion, tablarotacion;
	float pxcasco = 0, pzcasco = -110, crotacion = 40;
	float escalar1F = 1;
	bool escalar1B = true;

public:

	Animate(string, string);

	~Animate();

	void animateBird();
	void animateTabla();
	void animateRoca();
	void animateCasco();
};


