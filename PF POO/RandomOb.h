#pragma once
#include <iostream>
#include <stdlib.h>
#include "Model.h"

class Random {
private:
	EDXFramework::Model* Obj;
	const int maximum_number = 100;
	const int minimum_number = -100;
	const int maximum = 1;
	int* x;
	int* z;
	int amount;

protected:
	int RandomX;
	int RandomY;
	int RandomZ;

public:

	Random() {}

	Random(string, string, int);

	~Random();

	void DrawInRandomLocation();

	virtual int LookforX(int posX);

	virtual int LookforZ(int posZ);

	int LookforRandX(int posX);

	int LookforRandZ(int posZ);



};