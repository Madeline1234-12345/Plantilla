#pragma once
#include <iostream>
#include "Model.h"

class ObjEstatico {
private:

	EDXFramework::Model* Model;
	float x, y, z, r, s, s2;


public: 

	ObjEstatico(string, string);

	~ObjEstatico();

	void draw(int x, int y, int z, int r, float s, float s2);
	void draw(int x, int y, int z, int r, float s);
	
};

