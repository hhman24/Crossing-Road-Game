#pragma once
#ifndef CCar_h
#define CCar_h
#include"CVEHICLE.h"
#include<iostream>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

#define MAX_X 25
#define MAX_Y 81
#define MAX_C_X 3
#define MAX_C_Y 8

extern char BattleField[MAX_X][MAX_Y];
extern char Car[MAX_C_X][MAX_C_Y];

class CCAR : public CVEHICLE
{
private:
	//int _type;
	//char** _car;
	//void createCar(int i);
public:
	CCAR() {}
	CCAR(const Point& p, int _type, int _height, int _width);
	CCAR(const CCAR& car);
	CCAR& operator=(const CCAR& car);

	// tra ve mot doi tuong de ve
	//char** shapeHevicle(/**/);

	// Ham am thanh
	void soundHorn();

	// Ham di chuyen
	void move();

	// ve con xe
	void drawVehicle();

	~CCAR();
};
#endif // !CCar_h

