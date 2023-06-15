#include "ObjEstatico.h"

ObjEstatico::ObjEstatico(string modelo, string textura) {


	Model = new EDXFramework::Model(modelo, textura, 1);

}

ObjEstatico::~ObjEstatico() {
	delete Model;
}

void ObjEstatico::draw(int x, int y, int z, int r, float s, float s2) {


	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(r, 0, 1, 0);
	glScalef(s, s2, s);
	Model->Draw();
	glPopMatrix();

}

void ObjEstatico::draw(int x, int y, int z, int r, float s) {


	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(r, 0, 1, 0);
	glScalef(s, 1, 1);
	Model->Draw();
	glPopMatrix();

}




