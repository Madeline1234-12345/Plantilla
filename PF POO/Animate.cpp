#include "Animate.h"

Animate::Animate(string modelo, string textura) {


	Model = new EDXFramework::Model(modelo, textura, 1);

}

Animate::~Animate() {
	delete Model;
}


void Animate::animateBird() {
	birdRotation < 360 ? birdRotation += 3.0f : birdRotation = 0;
	if (birdMove == 5.0f)
		positiveBirdRotation = false;
	if (birdMove == -5.0f)
		positiveBirdRotation = true;
	positiveBirdRotation == true ? birdMove += 0.5f : birdMove -= 0.5f;
	glPushMatrix();
	glRotatef(birdMove, 0, 0, 1);
	glRotatef(birdRotation, 0, -1, 0);
	glTranslatef(0, 2.0f, 0);
	Model->Draw();
	glPopMatrix();
}

void Animate::animateTabla() {
	if (tablarotacion < 360) {
			tablarotacion += 0.5f;
		}
		else {
			tablarotacion = 0;
		}
		if (ar == true) {
			arriba += 0.3;
			if (arriba >= 34) {
				ar = false;
			}
		}
		if (ar == false) {
			arriba -= 0.3;
			if (arriba <= 29) {
				ar = true;
			}
		}
		glPushMatrix();
		glTranslatef(16, arriba, 206);
		glScalef(1, 1, 1);
		glRotatef(tablarotacion, 0, 1, 0);
		Model->Draw();
		glPopMatrix();
}

void Animate::animateRoca() {
		if (rocarotacion < 360) {
			rocarotacion += 0.3f;
		}
		else {
			rocarotacion = 0;
		}

		if (sube == true) {
			subebaja += 0.5;
			if (subebaja >= 80) {
				sube = false;
			}

		}
		if (sube == false) {
			subebaja -= 0.5;
			if (subebaja <= 30) {
				sube = true;
			}
		}
		glPushMatrix();
		glTranslatef(subebaja, 40.0f, -50);
		glScalef(1, 1, 1);
		glRotatef(rocarotacion, 0, 1, 0);
		Model->Draw();
		glPopMatrix();
}

void Animate::animateCasco() {
		if (rocarotacion < 360) {
			rocarotacion += 0.3f;
		}
		else {
			rocarotacion = 0;
		}
		if (sube == true) {
			subebaja += 0.5;
			if (subebaja >= 80) {
				sube = false;
			}
		}
		if (sube == false) {
			subebaja -= 0.5;
			if (subebaja <= 30) {
				sube = true;
			}
		}
		if (escalar1B == true)
		{
			escalar1F += 0.01;
			if (escalar1F >= 2) escalar1B = false;
		}
		if (escalar1B == false)
		{
			escalar1F -= 0.01;
			if (escalar1F <= 1) escalar1B = true;
		}

		glPushMatrix();
		glTranslatef(-20, 30.0f, 50);
		glRotatef(rocarotacion, 0, 1, 0);
		glScalef(escalar1F, escalar1F, escalar1F);
		Model->Draw();
		glPopMatrix();
}


