//proyecto de made
#ifndef __Escena
#define __Escena

#include <gl\GLU.h>
#include <gl\GL.h>
#include "SkyDome.h"
#include "Terrain.h"
#include "Model.h"
#include "Water.h"
#include "Billboard.h"
#include "Fog.h"
#include "Camera.h"
#include "Animate.h"
#include "ObjEstatico.h"
#include "RandomOb.h"


#define BILLSIZE 50

//BIENVENIDO AL ARCHIVO MAS IMPORTANTE DE TU PROYECTO

bool itemsC[5] = { false, false, false, false, false };


class Scene : public Camera
{
public:

	HWND hWnd = 0;

	short int skyIndex, lightIndex;
	float skyRotation;

	SkyDome* skyDome = new SkyDome(hWnd, 32, 32, 500, L"Imagenes//cielo.jpg");
	Terrain* terrain;
	Water* lago;
	GLfloat AmbMat[4] = { 15, 15, 10, 1 };

	//Random
	Random* flores;
	Random* miniR;

	//Animados
	Animate* bird;
	Animate* tabla;
	Animate* roca;
	Animate* casco;

	//Estaticos
	ObjEstatico* trucks;
	ObjEstatico* cono;
	ObjEstatico* bote;
	ObjEstatico* tablados;
	ObjEstatico* arbol;
	ObjEstatico* converse;
	ObjEstatico* concreto;
	ObjEstatico* tuboS;
	ObjEstatico* rampaS;
	ObjEstatico* stone;
	ObjEstatico* limitS;
	
	ObjEstatico* meta;
	ObjEstatico* construccion;
	ObjEstatico* reja;
	ObjEstatico* sillas;
	ObjEstatico* maceta;
	
	float x;

	Billboard* billBoard[8];

	
	Scene(HWND hWnd)
	{
		this->hWnd = hWnd;
		skyIndex = lightIndex, skyRotation = 0;

		GLfloat AmbPos[] = { 0, 400, 400, 1 };

		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, AmbPos);

		lago = new Water(hWnd, L"Imagenes//water.bmp", L"Imagenes//water.jpg", 1024, 1024);
		terrain = new Terrain(hWnd, L"Imagenes//terrain.bmp", L"Imagenes//cesped2.jpg", L"Imagenes//cesped2.jpg", 1024, 1024);		
		


		//Animados
		bird = new Animate("Modelos//bird//bird2.obj", "Modelos//bird//bird.bmp");
		tabla = new Animate("Modelos//boardgift//boardgift.obj", "Modelos//boardgift//boardgifttext.bmp");
		roca = new Animate("Modelos//roca//Rock_1.obj", "Modelos//roca//texroca.bmp");
		casco = new Animate("Modelos//casco//micasco.obj", "Modelos//casco//cascotex.bmp");

		//Estaticos
		trucks = new ObjEstatico("Modelos//trucks//trucks.obj", "Modelos//trucks//truckLogo.bmp");
		cono = new ObjEstatico("Modelos//cono//cono.obj", "Modelos//cono//naranja.bmp");
		bote = new ObjEstatico("Modelos//bote//elbote.obj", "Modelos//bote//textbote.bmp");
		tablados = new ObjEstatico("Modelos//tablapri//tablapri.obj", "Modelos//tablapri//skateboard_by_dommk_Base_Color.bmp");
		arbol = new ObjEstatico("Modelos//arbol//arbollobj.obj", "Modelos//arbol//texturarbol.bmp");
		converse = new ObjEstatico("Modelos//converse//converse_obj.obj", "Modelos//converse//converse.bmp");
		concreto = new ObjEstatico("Modelos//concreto//concret.obj", "Modelos//concreto//concreto.bmp");
		tuboS = new ObjEstatico("Modelos//tuboskate//16306_SkatePark_roundgrindrail_v1_NEW.obj", "Modelos//tuboskate//tubo.bmp");
		rampaS = new ObjEstatico("Modelos//scenery//uploads_files_2487604_skate+ramp.obj", "Modelos//scenery//skateramp.bmp");
		stone = new ObjEstatico("Modelos//stones//stone_5.obj", "Modelos//stones//mitextura.bmp");
		limitS = new ObjEstatico("Modelos//trash//10896_Trash_can_v3_LOD3.obj", "Modelos//trash//texture_plastic_gray.bmp");
		
		meta = new ObjEstatico("Modelos//meta//meta.obj", "Modelos//meta//meta.bmp");
		construccion = new ObjEstatico("Modelos//almacen//acomodada.obj", "Modelos//almacen//warewhouse_Diff.bmp");
		sillas = new ObjEstatico("Modelos//sillas//chairs.obj", "Modelos//sillas//chairs1.bmp");
		reja = new ObjEstatico("Modelos//reja//mireja.obj", "Modelos//reja//textreja.bmp");
		maceta = new ObjEstatico("Modelos//maceta//maceta.obj", "Modelos//maceta//text.bmp");

		//Random
		flores = new Random("Modelos//flores//flower2.obj", "Modelos//flores//flores.bmp", 1);
		miniR = new Random("Modelos//rampamini//rampamini.obj", "Modelos//rampamini//mitex.bmp", 1);

		Billboards(billBoard, hWnd);

		cameraInitialize();
	}

	void Billboards(Billboard* bills[], HWND hWnd)
	{
		bills[0] = new Billboard(hWnd, L"Imagenes//Frame1.png", 64, 64, 10, 10, 10);
		bills[1] = new Billboard(hWnd, L"Imagenes//Frame2.png", 64, 64, 10, 10, 10);
		bills[2] = new Billboard(hWnd, L"Imagenes//Frame3.png", 64, 64, 10, 10, 10);
		bills[3] = new Billboard(hWnd, L"Imagenes//Frame4.png", 64, 64, 10, 10, 10);
		bills[4] = new Billboard(hWnd, L"Imagenes//Frame5.png", 64, 64, 10, 10, 10);
		bills[5] = new Billboard(hWnd, L"Imagenes//Frame6.png", 64, 64, 10, 10, 10);
		bills[6] = new Billboard(hWnd, L"Imagenes//gameover.jpg", 64, 64, 50, 31, 117);
		bills[7] = new Billboard(hWnd, L"Imagenes//win.jpg", 64, 64, 10, 10, 10);

		
	}

	/*void DrawPerdiste(HDC hDC) {
		int vida = 
	}*/


	void render(HDC hDC)
	{
		x++;

		skyRotation < 360 ? skyRotation += 0.1f : skyRotation = 0;

		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();

		GLfloat AmbInt[] = { 0.1, 0.1, 0.1, 1 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);
		py = terrain->Superficie(px, pz) * 4 + 6;

		cameraUpdate();

		//Skydome
		glPushMatrix();
		glTranslatef(0, 8, 0);
		glRotatef(skyRotation, 0, 1, 0);
		skyDome->Draw();
		glPopMatrix();

		//Terreno
		glPushMatrix();
		glScalef(1, 4, 1);
		terrain->Draw();
		glPopMatrix();
		
		//Lago
		glPushMatrix();
		glTranslatef(0, 23.0f, 0);
		glScalef(10, 0.5, 10);
		lago->Draw();
		glPopMatrix();

		//Random
		flores->DrawInRandomLocation();
		miniR->DrawInRandomLocation();

		//Animaciones
		bird->animateBird();
		tabla->animateTabla();
		roca->animateRoca();
		casco->animateCasco();	

		//Obstaculos
		cono->draw(125, 26.0f, 54, 0,1,1);
		cono->draw(-45, 26.0f, 140, 0,1,1);
		bote->draw(66, 26.0f, 106, 0,1,1);
		concreto->draw(72, 26.0f, 55, 0, 2, 2);
		stone->draw(-49, 26.0f, 47, 0, 1, 1);
		limitS->draw(68, 26.0f, 176, 0, 1, 1);

		//Objetos a recolectar
		converse->draw(78, 26.0f, 147, 180, 1, 1);
		trucks->draw(-44, 27.0f, 105, 0,1,1);
		tablados->draw(-107, 26.0f, 59, 0, .5, .5);
		meta->draw(-158, 26.0f, 53, 90, 3, 4);
		
		//Estaticos
		construccion->draw(230, 45.0f, 80, 0, .5, .5);
		rampaS->draw(249, 26.0f, 81, 180, 3, 3);
		sillas->draw(226, 26.0f, 50, 0, 2,2);
		maceta->draw(210, 26.0f, 40, 0, .1, .1);
		tuboS->draw(48, 26.0f, 141, 0, 1, 1);
		arbol->draw(159, 26.0f, 15, 0, 2, 2);
		arbol->draw(111, 26.0f, -42, 0, 2, 2);
		arbol->draw(21, 26.0f, 7, 0, 2, 2);
		arbol->draw(17, 26.0f, 148, 0, 2, 2);
		arbol->draw(-117, 26.0f, -47, 0, 2, 2);
		arbol->draw(-252, 26.0f, 79, 0, 2, 2);
		arbol->draw(-123, 26.0f, 222, 0, 2, 2);
		arbol->draw(-70, 26.0f, -400, 0, 2, 2);
		reja->draw(66, 26.0f, 36, 0, 3);
		reja->draw(116, 26.0f, 36, 0, 3);
		reja->draw(166, 26.0f, 36, 0, 3);
		reja->draw(41, 26.0f, 58, 90, 3);
		reja->draw(41, 26.0f, 108, 90, 3);
		reja->draw(41, 26.0f, 158, 90, 3);
		reja->draw(16, 26.0f, 182, 0, 3);
		reja->draw(-8, 26.0f, 158, 90, 3);
		reja->draw(-8, 26.0f, 108, 90, 3);
		reja->draw(-8, 26.0f, 58, 90, 3);
		reja->draw(-33, 26.0f, 33, 0, 3);
		reja->draw(-83, 26.0f, 33, 0, 3);
		reja->draw(-133, 26.0f, 33, 0, 3);
		reja->draw(166, 26.0f, 116, 0, 3);
		reja->draw(116, 26.0f, 116, 0, 3);
		reja->draw(91, 26.0f, 141, 90, 3);
		reja->draw(91, 26.0f, 191, 90, 3);
		reja->draw(66, 26.0f, 216, 0, 3);
		reja->draw(16, 26.0f, 216, 0, 3);
		reja->draw(-34, 26.0f, 216, 0, 3);
		reja->draw(-59, 26.0f, 191, 90, 3);
		reja->draw(-59, 26.0f, 141, 90, 3);
		reja->draw(-59, 26.0f, 91, 90, 3);
		reja->draw(-84, 26.0f, 66, 0, 3);
		reja->draw(-134, 26.0f, 66, 0, 3);		

		

		
		

		glPushMatrix();
		for (int i = 0; i < BILLSIZE; i++)
			//Aqui puede ir algo en especial, en tu carpeta de HEADER_FILES, el primer archivo es la respuesta.
		glPopMatrix();

		//LLuvia
		if (x > 400 && x < 1208) {
			glPushMatrix();
			static int f = 0;
			billBoard[f]->setPosition(dx, 0, dz);
			billBoard[f]->Draw(px, py, pz);
			f++;
			if (f == 6)
				f = 0;

			glPopMatrix();

		}

		SwapBuffers(hDC);	
	}

	~Scene()
	{
		//NO OLVIDES PONER AQUI TODOS TUS PUNTEROS
		delete skyDome;
		delete lago;
	}
};
#endif
