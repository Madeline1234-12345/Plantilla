//#ifndef __Camera
//#define __Camera
//#define TO_RAD(DEG) (DEG * 3.1416 / 180)
//#define TO_DEG(RAD) (RAD / 3.1416 * 180.0)
//#define ANGLE_INC 3.5
//#define POSITION_INC 1
//
//
//#include "VectorRR.h"
//#include <math.h>
//
//class Camera : public VectorRR
//{
//public:
//	VectorRR posc, dirc;
//	GLdouble px, py, pz, dx, dy, dz, ux, uy, uz;
//
//	float angle = 0, dir = 0;
//	float viewVectorMag = 0, magX = 0, magZ = 0;
//
//	bool ableToMove;
//
//	Camera()
//	{
//	}
//
//	void cameraInitialize()
//	{
//		px = 0, py = 23, pz = 0, dx = 0, dy = 23, dz = -25;
//		ux = 0, uy = 1, uz = 0;
//		gluLookAt(px, py, pz, dx, dy, dz, ux, uy, uz);
//		viewVectorMag = sqrt(pow(dx - px, 2) + pow(dz - pz, 2));
//		ableToMove = true;
//	}
//
//	void cameraUpdate()
//	{
//		gluLookAt(px, py, pz, dx, dy, dz, ux, uy, uz);
//	}
//
//	void move(char movDir)
//	{
//		dir = 0;
//
//		magX = dx - px;
//		magZ = dz - pz;
//
//		switch (movDir)
//		{
//		case 'f':
//			dir = TO_DEG(atan2(magZ, magX));
//			break;
//		case 'b':
//			dir = TO_DEG(atan2(magZ, magX)) - 180;
//			break;
//		case 'l':
//			dir = TO_DEG(atan2(magZ, magX)) - 90;
//			break;
//		case 'r':
//			dir = TO_DEG(atan2(magZ, magX)) + 90;
//			break;
//		}
//		if (ableToMove)
//		{
//			pz += POSITION_INC * sin(TO_RAD(dir));
//			dz += POSITION_INC * sin(TO_RAD(dir));
//			px += POSITION_INC * cos(TO_RAD(dir));
//			dx += POSITION_INC * cos(TO_RAD(dir));
//		}
//	}
//
//	void turnRight()
//	{
//		angle = angle + ANGLE_INC;
//		dx = sin(TO_RAD(angle)) * viewVectorMag + px;
//		dz = -cos(TO_RAD(angle)) * viewVectorMag + pz;
//	}
//
//	void turnLeft()
//	{
//		angle = angle - ANGLE_INC;
//		dx = sin(TO_RAD(angle)) * viewVectorMag + px;
//		dz = -cos(TO_RAD(angle)) * viewVectorMag + pz;
//	}
//
//	void turnUp()
//	{
//		if (dy < 50 + py)
//			dy += 1;
//	}
//
//	void turnDown()
//	{
//		if (dy > -50 + py)
//			dy -= 1;
//	}
//};
//#endif */

#ifndef __Camera
#define __Camera
#define TO_RAD(DEG) (DEG * 3.1416 / 180)
#define TO_DEG(RAD) (RAD / 3.1416 * 180.0)
#define ANGLE_INC 3.5
#define POSITION_INC 1
#include "Billboard.h"




#include "VectorRR.h"
#include <math.h>

class Camera : public VectorRR
{
	bool colisiones(GLdouble X1, GLdouble X2, GLdouble Z1, GLdouble Z2)
	{
		GLdouble posicionX = px, posicionZ = pz;

		posicionX += POSITION_INC * cos(TO_RAD(dir));
		posicionZ += POSITION_INC * sin(TO_RAD(dir));

		if (posicionX < X1 && posicionX > X2 && posicionZ < Z1 && posicionZ > Z2) {
			colision = true;
			return true;
		}
		else {
			return false;
		}
	}

public:
	VectorRR posc, dirc;
	GLdouble px, py, pz, dx, dy, dz, ux, uy, uz;

	float angle = 100, dir = 0;
	float viewVectorMag = 0, magX = 0, magZ = 0;
	bool colision = false;
	bool ableToMove;
	bool Validacion[5] = { false, false, false, false, false };


	Camera()
	{
	}

	void cameraInitialize()
	{
		px = 0, py = 23, pz = 0, dx = 0, dy = -23, dz = -25; //25
		ux = 0, uy = 1, uz = 0;
		gluLookAt(px, py, pz, dx, dy, dz, ux, uy, uz);
		viewVectorMag = sqrt(pow(dx - px, 2) + pow(dz - pz, 2));
		ableToMove = true;
	}

	void cameraUpdate()
	{
		gluLookAt(px, py, pz, dx, dy, dz, ux, uy, uz);
	}

	void move(char movDir)
	{
		dir = 0;

		magX = dx - px;
		magZ = dz - pz;

		switch (movDir)
		{
		case 'f':
			dir = TO_DEG(atan2(magZ, magX));
			break;
		case 'b':
			dir = TO_DEG(atan2(magZ, magX)) - 180;
			break;
		case 'l':
			dir = TO_DEG(atan2(magZ, magX)) - 90;
			break;
		case 'r':
			dir = TO_DEG(atan2(magZ, magX)) + 90;
			break;
		}
		if (ableToMove)
		{
			colision = false;


			//// Obstaculos no me funciono
			


		//Terreno



			colisiones(330, -259, -353, -404);
			colisiones(421,357,236,-312);
			colisiones(418, -350, 346, 240);
			colisiones(-307, -375, 322, -382);

			//construccion 
			colisiones(273, 194, 142, 139);
			colisiones(276, 273, 141, 18);
			colisiones(272, 195, 20, 18);
			colisiones(196, 194, 63, 17);
			colisiones(193, 192, 141, 94);
			//------//
			colisiones(191, 90, 117, 114);
			colisiones(192, 42, 39, 32);
			colisiones(91, 88, 212, 117);
			colisiones(90, -56, 218, 213);
			colisiones(-61, -156, 68, 63);
			colisiones(-56, -60, 214, 67);
			colisiones(-10,-154,34,32);
			colisiones(41, 38, 178, 33);
			colisiones(-6, -9, 181, 34);
			
			//Obstaculos
			colisiones(140,136,95,90);
			colisiones(73, 68, 61, 48);
			colisiones(67, 64, 108, 104);
			colisiones(70, 64, 178, 171);
			colisiones(-27, -32, 179, 173);
			colisiones(-46, -48, 47, 44);
			colisiones(244, 237, 121, 109);
			colisiones(214, 205, 44, 38);

			//premios
			colisiones(78, 77, 147, 145);
			colisiones(-40, -46, 105, 103);
			colisiones(-83, -85, 61, 54);
			colisiones(-149, -154, 63, 37);

			//trucos
			colisiones(49, 47, 147, 129);
			colisiones(-15, -22, 71, 64);
			colisiones(254, 232, 90, 71);

			if (colision == false)

			{
				px += POSITION_INC * cos(TO_RAD(dir));
				dx += POSITION_INC * cos(TO_RAD(dir));
				pz += POSITION_INC * sin(TO_RAD(dir));
				dz += POSITION_INC * sin(TO_RAD(dir));
			}
		}
	}

	void turnRight()
	{
		angle = angle + ANGLE_INC;
		dx = sin(TO_RAD(angle)) * viewVectorMag + px;
		dz = -cos(TO_RAD(angle)) * viewVectorMag + pz;
	}

	void turnLeft()
	{
		angle = angle - ANGLE_INC;
		dx = sin(TO_RAD(angle)) * viewVectorMag + px;
		dz = -cos(TO_RAD(angle)) * viewVectorMag + pz;
	}

	void turnUp()
	{

		if (dy < 50 + py)
			dy += 1;
	}

	void turnDown()
	{
		if (dy > -50 + py)
			dy -= 1;
	}

	void CamaraInicializar() {

		posc.X = 0;
		posc.Y = 23;
		posc.Z = 0,
			dirc.X = 0,
			dirc.Y = 30,
			dirc.Z = -25;
		ux = 0,
			uy = 1,
			uz = 0;

		gluLookAt(posc.X, posc.Y, posc.Z,
			posc.X + dirc.X, posc.Y + dirc.Y, posc.Z + dirc.Z,
			0, 1, 0);
	}

	void CamaraUpdate() {

		gluLookAt(posc.X, posc.Y, posc.Z,
			posc.X + dirc.X, posc.Y + dirc.Y, posc.Z + dirc.Z,
			0, 1, 0);
	}

	void CamaraAvanza(float vel)
	{

		posc.X = posc.X + dirc.X * vel;
		posc.Y = posc.Y + dirc.Y * vel;
		posc.Z = posc.Z + dirc.Z * vel;

		gluLookAt(posc.X, posc.Y, posc.Z,
			posc.X + dirc.X, posc.Y, posc.Z + dirc.Z,
			0, 1, 0);
	}

	void CamaraGiraY(float grados)
	{
		Transforma(dirc, grados, Ejes::EjeY);
	}
};
#endif