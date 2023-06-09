#pragma once
#ifndef CTruck_h
#define CTruck_h
#include"CVEHICLE.h"
#include<iostream>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

#define MAX_X 25
#define MAX_Y 81
#define MAX_T_X 3
#define MAX_T_Y 8

extern char BattleField[MAX_X][MAX_Y];
extern char Truck[MAX_T_X][MAX_T_Y];

class CTRUCK : public CVEHICLE
{
private:
	//int _type;
	//char** _truck;
	//void createTruck(int i);
public:
	CTRUCK() {}
	CTRUCK(const Point& p, int _type, int _height, int _width);
	CTRUCK(const CTRUCK& truck);
	CTRUCK& operator=(const CTRUCK& truck);

	// tra ve mot doi tuong de ve
	//char** shapeHevicle(/**/);

	// Ham am thanh
	void soundHorn();

	// Ham di chuyen
	void move();

	// ve con xe
	void drawVehicle();

	~CTRUCK();
};
#endif // !CTruck_h

