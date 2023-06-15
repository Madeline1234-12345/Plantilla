#include "RandomOb.h"

Random::Random(string model, string texture, int amount) {

	this->amount = amount;

	x = new int[amount];
	z = new int[amount];


	Obj = new EDXFramework::Model(model, texture, 1);
	for (int i = 0; i < amount; i++) {
		x[i] = (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
		z[i] = (rand() % (maximum_number + 1 - minimum_number)) + minimum_number;
	}

}
Random::~Random() {
	delete Obj;
	delete[] x;
	delete[] z;
}

void Random::DrawInRandomLocation() {
	for (int i = 0; i < amount; i++) {
		glPushMatrix();
		glTranslatef(x[i], 26.0f, z[i]);
		Obj->Draw();
		glPopMatrix();


	}
}
int Random::LookforX(int posX)
{
	return RandomX;

}

int Random::LookforZ(int posZ)
{
	return RandomZ;

}

int Random::LookforRandX(int posX)
{

	return this->LookforX(posX);
}

int Random::LookforRandZ(int posZ)
{
	return this->LookforZ(posZ);
}




